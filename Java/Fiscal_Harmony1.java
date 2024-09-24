import java.util.*;

class Fiscal {
  public static void main(String[] args) {
  Scanner scanner = new Scanner(System.in);


System.out.println("=============================================================");
System.out.println("\t\tWelcome to Fiscal Harmony");
System.out.println("=============================================================");
System.out.println("Planning your future for a financially free life.");
System.out.println("[1]. Sign In [2]. Sign Up");
System.out.print("> ");
int UserLoginOption = scanner.nextInt();
    
    
    switch (UserLoginOption) {
        case 1: 
            System.out.println("Enter your Credentials");
            System.out.print("Username: ");
            String Username = scanner.nextLine();
            
            System.out.print("Password: ");
            String Password = scanner.nextLine();
            
            System.out.println("Welcome! " + Username);
        case 2:
            System.out.println("Register");
            break;
    }
    









  }
}
