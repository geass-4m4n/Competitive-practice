Sure, let's complete the demonstration process step by step to ensure the OAuth flow works seamlessly.

### Running the Demo

1. **Start the Authorization Server:**

   Ensure you are in the `authorization-server` directory and run:
   ```bash
   mvn spring-boot:run -Dspring-boot.run.jvmArguments="-Dserver.port=8080"
   ```

2. **Start the Client Application:**

   Navigate to the `client-app` directory and run:
   ```bash
   mvn spring-boot:run -Dspring-boot.run.jvmArguments="-Dserver.port=8081"
   ```

3. **Start the Resource Server:**

   Navigate to the `resource-server` directory and run:
   ```bash
   mvn spring-boot:run -Dspring-boot.run.jvmArguments="-Dserver.port=8082"
   ```

### Usage

1. **Navigate to the Client Application:**

   Open your web browser and go to `http://localhost:8081/`. This is your client application.

2. **Initiate Login:**

   Click the login link on the client application, which will redirect you to the authorization server for authentication.

3. **Authenticate User:**

   You will be directed to the authorization server's login page. Enter the credentials:

   - **Username:** `user`
   - **Password:** `password`

   After successful authentication, you'll be redirected back to the client application at `http://localhost:8081/` with an authorization code.

4. **Authorization Code Exchange:**

   The client application will use the authorization code to request an access token from the authorization server. This process is typically handled automatically by the OAuth client library in your application.

5. **Access Protected Resource:**

   With the access token received, navigate to the resource server endpoint by visiting `http://localhost:8082/resource` in your browser. Make sure to include the access token in the request header as a bearer token.

   For example, you can use `curl` to access the protected resource:
   ```bash
   curl -H "Authorization: Bearer YOUR_ACCESS_TOKEN" http://localhost:8082/resource
   ```

   Replace `YOUR_ACCESS_TOKEN` with the actual access token obtained from the client application. The resource server should return the protected resource data, confirming the OAuth 2.0 flow works as intended.

### Additional Configuration for Testing

To simplify the testing, let's update the Client Application to automatically display the access token and provide a link to access the protected resource.

#### Update `ClientApplication.java`:

Add a controller to handle the OAuth callback and display the access token.

```java
package com.example.clientapp;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.security.oauth2.client.registration.ClientRegistration;
import org.springframework.security.oauth2.client.registration.ClientRegistrationRepository;
import org.springframework.security.oauth2.core.oidc.user.DefaultOidcUser;
import org.springframework.security.oauth2.core.user.OAuth2User;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import java.security.Principal;

@SpringBootApplication
@Controller
public class ClientApplication {

    private final ClientRegistrationRepository clientRegistrationRepository;

    public ClientApplication(ClientRegistrationRepository clientRegistrationRepository) {
        this.clientRegistrationRepository = clientRegistrationRepository;
    }

    public static void main(String[] args) {
        SpringApplication.run(ClientApplication.class, args);
    }

    @GetMapping("/login")
    public String login() {
        ClientRegistration clientRegistration = clientRegistrationRepository.findByRegistrationId("oauth2-client");
        String authorizationRequestUri = clientRegistration.getProviderDetails().getAuthorizationUri() +
                "?response_type=code" +
                "&client_id=" + clientRegistration.getClientId() +
                "&scope=read+write" +
                "&redirect_uri=" + clientRegistration.getRedirectUri();
        return "redirect:" + authorizationRequestUri;
    }

    @GetMapping("/login/oauth2/code/oauth2-client")
    public String callback(Principal principal, Model model) {
        OAuth2User oauth2User = (DefaultOidcUser) principal;
        String accessToken = ((DefaultOidcUser) oauth2User).getIdToken().getTokenValue();
        model.addAttribute("accessToken", accessToken);
        return "home";
    }
}
```

#### Create `home.html` in `src/main/resources/templates/`:

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head>
    <title>OAuth2 Client</title>
</head>
<body>
<h1>OAuth2 Client Application</h1>
<p>Access Token: <span th:text="${accessToken}"></span></p>
<p><a th:href="'http://localhost:8082/resource?access_token=' + ${accessToken}">Access Protected Resource</a></p>
</body>
</html>
```

#### Update `application.properties`:

Ensure the redirect URI matches the one configured in the authorization server and client registration.

```properties
spring.security.oauth2.client.registration.oauth2-client.client-id=client-id
spring.security.oauth2.client.registration.oauth2-client.client-secret=client-secret
spring.security.oauth2.client.registration.oauth2-client.scope=read,write
spring.security.oauth2.client.registration.oauth2-client.authorization-grant-type=authorization_code
spring.security.oauth2.client.registration.oauth2-client.redirect-uri=http://localhost:8081/login/oauth2/code/oauth2-client
spring.security.oauth2.client.registration.oauth2-client.authorization-uri=http://localhost:8080/oauth/authorize
spring.security.oauth2.client.registration.oauth2-client.token-uri=http://localhost:8080/oauth/token
spring.security.oauth2.client.registration.oauth2-client.user-info-uri=http://localhost:8080/userinfo
spring.security.oauth2.client.registration.oauth2-client.client-name=OAuth2 Client
```

Now, you can run the demo again following the same steps. After logging in, you will be redirected to a page showing the access token and a link to access the protected resource on the resource server. This setup provides a more complete and user-friendly demonstration of the OAuth 2.0 flow.
