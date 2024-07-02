 -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>

    <!-- Spring Boot Starter Security -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-security</artifactId>
    </dependency>

    <!-- Spring Boot Starter OAuth2 Client -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-oauth2-client</artifactId>
    </dependency>
</dependencies>
```

#### `client-application/src/main/java/com/example/clientapplication/ClientApplication.java`

```java
package com.example.clientapplication;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class ClientApplication {
    public static void main(String[] args) {
        SpringApplication.run(ClientApplication.class, args);
    }
}
```

#### `client-application/src/main/java/com/example/clientapplication/config/SecurityConfig.java`

```java
package com.example.clientapplication.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;

@Configuration
@EnableWebSecurity
public class SecurityConfig extends WebSecurityConfigurerAdapter {

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .authorizeRequests()
                .antMatchers("/login").permitAll()
                .anyRequest().authenticated()
                .and()
            .oauth2Login();
    }
}
```

#### `client-application/src/main/java/com/example/clientapplication/config/OAuth2ClientConfig.java`

```java
package com.example.clientapplication.config;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.autoconfigure.security.oauth2.client.EnableOAuth2Sso;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;

@Configuration
@EnableOAuth2Sso
public class OAuth2ClientConfig extends WebSecurityConfigurerAdapter {

    @Value("${spring.security.oauth2.client.provider.custom.user-info-uri}")
    private String userInfoUri;

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .authorizeRequests()
                .antMatchers("/").permitAll()
                .anyRequest().authenticated()
                .and()
            .logout()
                .logoutSuccessUrl("/")
                .permitAll()
                .and()
            .csrf().disable();
    }
}
```

#### `client-application/src/main/resources/application.yml`

```yaml
spring:
  security:
    oauth2:
      client:
        registration:
          custom:
            client-id: client-id
            client-secret: client-secret
            authorization-grant-type: authorization_code
            redirect-uri: "{baseUrl}/login/oauth2/code/{registrationId}"
            scope: read,write
        provider:
          custom:
            authorization-uri: http://localhost:8080/oauth2/authorize
            token-uri: http://localhost:8080/oauth2/token
            user-info-uri: http://localhost:8080/userinfo
```

### 3. Resource Server

#### `resource-server/pom.xml`

```xml
<dependencies>
    <!-- Spring Boot Starter Web -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>

    <!-- Spring Boot Starter Security -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-security</artifactId>
    </dependency>

    <!-- Spring Boot Starter OAuth2 Resource Server -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-oauth2-resource-server</artifactId>
    </dependency>
</dependencies>
```

#### `resource-server/src/main/java/com/example/resourceserver/ResourceServerApplication.java`

```java
package com.example.resourceserver;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class ResourceServerApplication {
    public static void main(String[] args) {
        SpringApplication.run(ResourceServerApplication.class, args);
    }
}
```

#### `resource-server/src/main/java/com/example/resourceserver/config/SecurityConfig.java`

```java
package com.example.resourceserver.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.oauth2.server.resource.authentication.JwtAuthenticationConverter;
import org.springframework.security.oauth2.server.resource.authentication.JwtGrantedAuthoritiesConverter;

@Configuration
@EnableWebSecurity
public class SecurityConfig {

    @Bean
    public JwtAuthenticationConverter jwtAuthenticationConverter() {
        JwtAuthenticationConverter converter = new JwtAuthenticationConverter();
        JwtGrantedAuthoritiesConverter authoritiesConverter = new JwtGrantedAuthoritiesConverter();
        authoritiesConverter.setAuthorityPrefix("ROLE_");
        authoritiesConverter.setAuthoritiesClaimName("roles");
        converter.setJwtGrantedAuthoritiesConverter(authoritiesConverter);
        return converter;
    }

    @Bean
    public UserDetailsService userDetailsService() {
        return new UserDetailsServiceImpl();
    }

    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
        http
            .authorizeRequests()
                .antMatchers("/public/**").permitAll()
                .anyRequest().authenticated()
                .and()
            .oauth2ResourceServer()
                .jwt()
                .jwtAuthenticationConverter(jwtAuthenticationConverter());
        return http.build();
    }
}
```

#### `resource-server/src/main/java/com/example/resourceserver/config/KeycloakRealmRoleConverter.java`

```java
package com.example.resourceserver.config;

import org.springframework.core.convert.converter.Converter;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.oauth2.jwt.Jwt;

import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class KeycloakRealmRoleConverter implements Converter<Jwt, Collection<SimpleGrantedAuthority>> {
    @Override
    public Collection<SimpleGrantedAuthority> convert(final Jwt jwt) {
        final List<String> roles = (List<String>) jwt.getClaims().getOrDefault("realm_access", Collections.emptyMap())
                                                      .getOrDefault("roles", Collections.emptyList());

        return roles.stream()
                    .map(roleName -> new SimpleGrantedAuthority("ROLE_" + roleName))
                    .collect(Collectors.toList());
    }
}
```

#### `resource-server/src/main/java/com/example/resourceserver/controller/ResourceController.java`

```java
package com.example.resourceserver.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.security.Principal;
import java.util.Collections;
import java.util.Map;

@RestController
@RequestMapping("/resource")
public class ResourceController {

    @GetMapping("/public")
    public Map<String, String> publicEndpoint() {
        return Collections.singletonMap("message", "This is a public endpoint.");
    }

    @GetMapping("/protected")
    public Map<String, String> protectedEndpoint(Principal principal) {
        return Collections.singletonMap("message", "This is a protected endpoint. Welcome, " + principal.getName() + "!");
    }
}
```

### Running the Applications

1. **Start the Authorization Server:**
   - Run `AuthorizationServerApplication.java`.
   - Ensure it is running on `http://localhost:8080`.

2. **Start the Client Application:**
   - Run `ClientApplication.java`.
   - Access the client application on `http://localhost:8082`.

3. **Start the Resource Server:**
   - Run `ResourceServerApplication.java`.
   - Access the resource server on `http://localhost:8083`.

### Testing the Setup

1. **Access Client Application:**
   - Navigate to `http://localhost:8082`.
   - Log in using the credentials configured in the Authorization Server.

2. **Access Protected Resource:**
   - After logging in, try accessing the protected endpoint at `http://localhost:8083/resource/protected`.
   - You should see a message confirming access with your username.

This setup demonstrates a basic OAuth 2.0 flow with Spring Boot applications for Authorization Server, Client Application, and Resource Server, ensuring secure authentication and authorization across the applications. Adjustments can be made based on specific requirements and additional features like token storage, more complex authorization rules, etc.
