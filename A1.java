Creating a fully working OAuth 2.0 setup in Java 11 involves setting up three main components: Authorization Server, Client Application, and Resource Server. Below is a complete example with project structure, dependencies, and configuration for each component.

### Project Structure

```
oauth2-example
├── authorization-server
│   ├── src
│   │   ├── main
│   │   │   ├── java
│   │   │   │   └── com
│   │   │   │       └── example
│   │   │   │           └── authorizationserver
│   │   │   │               ├── AuthorizationServerApplication.java
│   │   │   │               ├── config
│   │   │   │               │   ├── AuthorizationServerConfig.java
│   │   │   │               │   └── WebSecurityConfig.java
│   │   │   │               └── user
│   │   │   │                   ├── User.java
│   │   │   │                   ├── UserRepository.java
│   │   │   │                   └── UserDetailsServiceImpl.java
│   │   │   └── resources
│   │   │       └── application.yml
│   │   └── test
│   └── pom.xml
├── client-application
│   ├── src
│   │   ├── main
│   │   │   ├── java
│   │   │   │   └── com
│   │   │   │       └── example
│   │   │   │           └── clientapplication
│   │   │   │               ├── ClientApplication.java
│   │   │   │               ├── config
│   │   │   │               │   ├── SecurityConfig.java
│   │   │   │               │   └── OAuth2ClientConfig.java
│   │   │   └── resources
│   │   │       └── application.yml
│   │   └── test
│   └── pom.xml
├── resource-server
│   ├── src
│   │   ├── main
│   │   │   ├── java
│   │   │   │   └── com
│   │   │   │       └── example
│   │   │   │           └── resourceserver
│   │   │   │               ├── ResourceServerApplication.java
│   │   │   │               ├── config
│   │   │   │               │   ├── SecurityConfig.java
│   │   │   │               │   └── KeycloakRealmRoleConverter.java
│   │   │   │               └── controller
│   │   │   │                   └── ResourceController.java
│   │   └── resources
│   └── pom.xml
└── pom.xml
```

### 1. Authorization Server

#### `authorization-server/pom.xml`

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

    <!-- Spring Security OAuth2 Autoconfigure -->
    <dependency>
        <groupId>org.springframework.security.oauth.boot</groupId>
        <artifactId>spring-security-oauth2-autoconfigure</artifactId>
        <version>2.3.8.RELEASE</version>
    </dependency>

    <!-- Spring Boot Starter Data JPA -->
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-data-jpa</artifactId>
    </dependency>

    <!-- H2 Database -->
    <dependency>
        <groupId>com.h2database</groupId>
        <artifactId>h2</artifactId>
    </dependency>
</dependencies>
```

#### `authorization-server/src/main/java/com/example/authorizationserver/AuthorizationServerApplication.java`

```java
package com.example.authorizationserver;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class AuthorizationServerApplication {
    public static void main(String[] args) {
        SpringApplication.run(AuthorizationServerApplication.class, args);
    }
}
```

#### `authorization-server/src/main/java/com/example/authorizationserver/config/AuthorizationServerConfig.java`

```java
package com.example.authorizationserver.config;

import com.example.authorizationserver.user.UserDetailsServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.oauth2.config.annotation.builders.ClientDetailsServiceBuilder;
import org.springframework.security.oauth2.config.annotation.configurers.ClientDetailsServiceConfigurer;
import org.springframework.security.oauth2.config.annotation.web.configuration.AuthorizationServerConfigurerAdapter;
import org.springframework.security.oauth2.config.annotation.web.configuration.EnableAuthorizationServer;
import org.springframework.security.oauth2.config.annotation.web.configurers.AuthorizationServerEndpointsConfigurer;

@Configuration
@EnableAuthorizationServer
public class AuthorizationServerConfig extends AuthorizationServerConfigurerAdapter {

    @Autowired
    private AuthenticationManager authenticationManager;

    @Autowired
    private UserDetailsServiceImpl userDetailsService;

    @Bean
    public PasswordEncoder passwordEncoder() {
        return new BCryptPasswordEncoder();
    }

    @Override
    public void configure(ClientDetailsServiceConfigurer clients) throws Exception {
        clients
            .inMemory()
                .withClient("client-id")
                .secret(passwordEncoder().encode("client-secret"))
                .authorizedGrantTypes("authorization_code", "refresh_token", "password")
                .scopes("read", "write")
                .redirectUris("http://localhost:8082/login/oauth2/code/custom");
    }

    @Override
    public void configure(AuthorizationServerEndpointsConfigurer endpoints) throws Exception {
        endpoints
            .authenticationManager(authenticationManager)
            .userDetailsService(userDetailsService);
    }
}
```

#### `authorization-server/src/main/java/com/example/authorizationserver/config/WebSecurityConfig.java`

```java
package com.example.authorizationserver.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

@Configuration
@EnableWebSecurity
public class WebSecurityConfig extends WebSecurityConfigurerAdapter {

    @Bean
    public PasswordEncoder passwordEncoder() {
        return new BCryptPasswordEncoder();
    }

    @Bean
    @Override
    public AuthenticationManager authenticationManagerBean() throws Exception {
        return super.authenticationManagerBean();
    }

    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth
            .inMemoryAuthentication()
                .withUser("user")
                .password(passwordEncoder().encode("password"))
                .roles("USER");
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .authorizeRequests()
                .anyRequest().authenticated()
                .and()
            .formLogin()
                .permitAll()
                .and()
            .csrf().disable();
    }
}
```

#### `authorization-server/src/main/java/com/example/authorizationserver/user/User.java`

```java
package com.example.authorizationserver.user;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class User {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String username;
    private String password;

    // Getters and setters
}
```

#### `authorization-server/src/main/java/com/example/authorizationserver/user/UserRepository.java`

```java
package com.example.authorizationserver.user;

import org.springframework.data.jpa.repository.JpaRepository;

public interface UserRepository extends JpaRepository<User, Long> {
    User findByUsername(String username);
}
```

#### `authorization-server/src/main/java/com/example/authorizationserver/user/UserDetailsServiceImpl.java`

```java
package com.example.authorizationserver.user;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

@Service
public class UserDetailsServiceImpl implements UserDetailsService {

    @Autowired
    private UserRepository userRepository;

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        User user = userRepository.findByUsername(username);
        if (user == null) {
            throw new UsernameNotFoundException("User not found");
        }
        return new org.springframework.security.core.userdetails.User(user.getUsername(), user.getPassword(), Collections.emptyList());
    }
}
```

#### `authorization-server/src/main/resources/application.yml`

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

### 2. Client Application

#### `client-application/pom.xml`

```xml
<dependencies>
    <!-- Spring Boot Starter Web
