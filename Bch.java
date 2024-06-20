Creating a user login system using blockchain in Java is a bit more complex and involves several steps, including user registration, login, and retrieving user data. For simplicity, this example will use a basic blockchain to store user data, and we'll handle user registration and login. 

We'll create three main classes:

1. **Block**: Represents a block in the blockchain.
2. **Blockchain**: Manages the chain and includes methods to add new blocks.
3. **UserLoginSystem**: Handles user registration and login, and stores user data in the blockchain.

### Block.java

```java
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Block {
    public String hash;
    public String previousHash;
    private String data; // User data stored as a simple string for this example.
    private long timestamp;

    // Block Constructor.
    public Block(String data, String previousHash) {
        this.data = data;
        this.previousHash = previousHash;
        this.timestamp = System.currentTimeMillis();
        this.hash = calculateHash(); // Making sure we do this after we set the other values.
    }

    // Calculate new hash based on block's contents.
    public String calculateHash() {
        String input = previousHash + Long.toString(timestamp) + data;
        return applySha256(input);
    }

    // Apply SHA-256 to a string and return the result.
    public static String applySha256(String input) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(input.getBytes("UTF-8"));
            StringBuffer hexString = new StringBuffer(); // This will contain hash as hexadecimal
            for (int i = 0; i < hash.length; i++) {
                String hex = Integer.toHexString(0xff & hash[i]);
                if(hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    // Getters for the block's data
    public String getData() {
        return data;
    }
}
```

### Blockchain.java

```java
import java.util.ArrayList;

public class Blockchain {
    public static ArrayList<Block> blockchain = new ArrayList<Block>();

    // Create the genesis block
    public static void initializeBlockchain() {
        blockchain.add(new Block("Genesis Block", "0"));
    }

    // Add a new block to the chain
    public static void addBlock(Block newBlock) {
        blockchain.add(newBlock);
    }

    // Get the last block in the chain
    public static Block getLastBlock() {
        return blockchain.get(blockchain.size() - 1);
    }

    // Print the entire blockchain
    public static void printBlockchain() {
        for (Block block : blockchain) {
            System.out.println("Block:");
            System.out.println("Hash: " + block.hash);
            System.out.println("Previous Hash: " + block.previousHash);
            System.out.println("Data: " + block.getData());
            System.out.println("Timestamp: " + block.timestamp);
            System.out.println();
        }
    }
}
```

### UserLoginSystem.java

```java
import java.util.Scanner;

public class UserLoginSystem {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        Blockchain.initializeBlockchain();
        
        while (true) {
            System.out.println("Choose an option:");
            System.out.println("1. Register");
            System.out.println("2. Login");
            System.out.println("3. Print Blockchain");
            System.out.println("4. Exit");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    registerUser();
                    break;
                case 2:
                    loginUser();
                    break;
                case 3:
                    Blockchain.printBlockchain();
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }

    private static void registerUser() {
        System.out.println("Enter username:");
        String username = scanner.nextLine();
        System.out.println("Enter password:");
        String password = scanner.nextLine();
        
        // In a real application, you should hash passwords before storing them
        String userData = "username:" + username + ";password:" + password;
        Block newBlock = new Block(userData, Blockchain.getLastBlock().hash);
        Blockchain.addBlock(newBlock);

        System.out.println("User registered successfully!");
    }

    private static void loginUser() {
        System.out.println("Enter username:");
        String username = scanner.nextLine();
        System.out.println("Enter password:");
        String password = scanner.nextLine();
        
        // In a real application, you should hash the password and compare it
        String loginData = "username:" + username + ";password:" + password;

        boolean userFound = false;
        for (Block block : Blockchain.blockchain) {
            if (block.getData().equals(loginData)) {
                userFound = true;
                break;
            }
        }

        if (userFound) {
            System.out.println("Login successful!");
        } else {
            System.out.println("Invalid username or password.");
        }
    }
}
```

### Explanation

1. **Block Class**:
    - Stores user data, previous block hash, current block hash, and timestamp.
    - `calculateHash()` and `applySha256()` methods handle hashing.

2. **Blockchain Class**:
    - Manages the list of blocks and methods to add and print blocks.
    - Contains methods to initialize the blockchain with a genesis block and to add new blocks.

3. **UserLoginSystem Class**:
    - Provides a simple text-based interface for user registration and login.
    - Stores user data in the blockchain during registration and checks the blockchain for user login.

### How to Run

1. Compile the classes:
    ```bash
    javac Block.java Blockchain.java UserLoginSystem.java
    ```
2. Run the `UserLoginSystem` class:
    ```bash
    java UserLoginSystem
    ```

This setup provides a very basic demonstration of how user data can be stored in a blockchain. For real-world applications, consider using proper cryptographic techniques to hash passwords, secure communication channels, and potentially more sophisticated data structures and storage mechanisms.
