import com.microsoft.azure.keyvault.KeyVaultClient;
import com.microsoft.azure.keyvault.authentication.KeyVaultCredentials;
import com.microsoft.azure.keyvault.models.SecretBundle;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

@SpringBootApplication
public class KeyVaultExampleApplication {

    @Value("${azure.keyvault.uri}")
    private String keyVaultUri;

    @Value("${azure.keyvault.client-id}")
    private String clientId;

    @Value("${azure.keyvault.client-key}")
    private String clientSecret;

    public static void main(String[] args) {
        SpringApplication.run(KeyVaultExampleApplication.class, args);
    }

    @Bean
    public KeyVaultClient getKeyVaultClient() {
        return new KeyVaultClient(new KeyVaultCredentials() {
            @Override
            public String doAuthenticate(String authorization, String resource, String scope) {
                return authorization;
            }

            @Override
            public String getAuthenticationToken(String authorization, String resource, String scope) {
                return authorization;
            }
        });
    }

    public String getSecretValue(String secretName) {
        String secretUri = keyVaultUri + "/secrets/" + secretName;
        SecretBundle secretBundle = getKeyVaultClient().getSecret(secretUri);
        return secretBundle.value();
    }

}
