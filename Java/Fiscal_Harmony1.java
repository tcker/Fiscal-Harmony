import java.util.*;

public class FiscalHarmony {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean goBackToSignUp = true;
        String userEmail = "", userPassword = "";
        String userRegisterEmail = "", userRegisterPassword = "";
        int signInAttempts = 0;

//===================================================LOGIN AND REGISTRATION===================================================================

        while (goBackToSignUp) {
            System.out.println("=============================================================");
            System.out.println("\t\tWelcome to Fiscal Harmony");
            System.out.println("=============================================================");
            System.out.println("Planning your future for a financially free life.");
            System.out.println("[1]. Sign In [2]. Sign Up");
            System.out.print("> ");

            int userOption = getValidOption(scanner, 1, 2);

            switch (userOption) {
                case 1: 
                    System.out.println("_________________________________");
                    System.out.println("You are now signing in...");

                    do {
                        System.out.print("Username: ");
                        userEmail = scanner.next();
                        System.out.print("Password: ");
                        userPassword = scanner.next();
                        System.out.println("_________________________________");

                        if (!userEmail.equals("admin") || !userPassword.equals("password")) {
                            signInAttempts++;
                            System.out.println("Invalid password or username, please try again!");
                        }
                    } while ((!userEmail.equals("admin") || !userPassword.equals("password")) && signInAttempts < 2);

                    if (signInAttempts == 2) {
                        System.out.println("You have reached the maximum number of sign-in attempts.");
                        System.out.println("=======================================================");
                        System.out.println("[1]. Go back to Sign-up Terminal [2]. Exit");
                        System.out.print("> ");

                        int finalOption = getValidOption(scanner, 1, 2);

                        if (finalOption == 1) {
                            signInAttempts = 0;
                            goBackToSignUp = true;
                            continue;
                        } else {
                            System.out.println("Have a great day ahead!");
                            System.exit(0);
                        }
                    } else {
                        goBackToSignUp = false;
                        showFeaturesMenu(scanner, userEmail);  
                    }
                    break;

                case 2: 
                    System.out.println("_________________________________");
                    System.out.println("You are now creating an account");
                    System.out.print("Username: ");
                    userRegisterEmail = scanner.next();
                    System.out.print("Password: ");
                    userRegisterPassword = scanner.next();
                    System.out.println("You have successfully created an account, would you like to sign in?");
                    System.out.println("[1]. Yes [2]. Exit");
                    System.out.print("> ");

                    int userSignIn = getValidOption(scanner, 1, 2);
                    System.out.println("_________________________________");

                    if (userSignIn == 1) {
                        do {
                            System.out.print("Username: ");
                            userEmail = scanner.next();
                            System.out.print("Password: ");
                            userPassword = scanner.next();
                            System.out.println("_________________________________");

                            if (!userEmail.equals(userRegisterEmail) || !userPassword.equals(userRegisterPassword)) {
                                System.out.println("You have entered the wrong username or password, please try again!");
                            }
                        } while (!userEmail.equals(userRegisterEmail) || !userPassword.equals(userRegisterPassword));

                        showFeaturesMenu(scanner, userEmail); 
                    } else {
                        System.out.println("Have a great day ahead!");
                        System.exit(0);
                    }
                    break;
            }
        }

        scanner.close();
    }

    private static int getValidOption(Scanner scanner, int min, int max) {
        int option = -1;
        while (true) {
            try {
                option = scanner.nextInt();
                if (option >= min && option <= max) {
                    break;
                } else {
                    System.out.println("Invalid input. Please enter a valid number (" + min + " or " + max + ").");
                    System.out.print("> ");
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a valid number (" + min + " or " + max + ").");
                System.out.print("> ");
                scanner.next(); 
            }
        }
        return option;
    }

//===================================================LOGIN AND REGISTRATION===================================================================

//===================================================MAIN MENU & FEATURES===================================================================

    private static void showFeaturesMenu(Scanner scanner, String userEmail) {
        boolean loggedIn = true;

        while (loggedIn) {
            System.out.println("================================================================");
            System.out.println("Welcome, " + userEmail + "! I hope you have a great time!");
            System.out.println("Here are our current available features, check them out!:");
            System.out.println("[1]. Income and Expense Allocation");
            System.out.println("[2]. Emergency Fund Calculator");
            System.out.println("[3]. Salary Calculator");
            System.out.println("[4]. Log out");
            System.out.println("================================================================");
            System.out.print("> ");

            int featureOption = getValidOption(scanner, 1, 4);

            switch (featureOption) {
                case 1:
                    System.out.println("Income and Expense Allocation.");
                    break;
                case 2:
                    runEmergencyFundCalculator(scanner);
                    break;
                case 3:
                    System.out.println("Salary Calculator.");
                    break;
                case 4:
                    System.out.println("Logging out...");
                    loggedIn = false;
                    break;
            }
        }
    }

//===================================================MAIN MENU & FEATURES===================================================================

//===================================================EMERGENCY CALCULATOR===================================================================

    private static void runEmergencyFundCalculator(Scanner scanner) {
        System.out.println("+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+");
        System.out.println("\tYour Trusty Emergency Fund Calculator");
        System.out.println("\t\tNon negative Values only");
        System.out.println("+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+");

        double totalExpensesPerMonth;
        int numberOfMonths;

        totalExpensesPerMonth = getValidInput(scanner, "Enter your total monthly expenses: PHP ");
        numberOfMonths = getValidInputInt(scanner, "Enter the number of months you want to cover: ");

        System.out.println("You entered: " + numberOfMonths + " months \n");

        double emergencyFund = totalExpensesPerMonth * numberOfMonths + 50;
        System.out.printf("\nYour recommended emergency fund is: PHP %.2f%n", emergencyFund);

        System.out.println("=============================================================");
        System.out.println("[1]. Back to Main Menu [2]. Log out");
        System.out.print("> ");

        int backOrLogOut = getValidChoice(scanner);

        if (backOrLogOut == 1) {
            return; 
        } else if (backOrLogOut == 2) {
            System.out.println("Logging Out! Bye have a good time!");
            System.exit(0);
        }
    }

    private static double getValidInput(Scanner scanner, String prompt) {
        while (true) {
            try {
                System.out.print(prompt);
                double input = scanner.nextDouble();
                if (input < 0) {
                    System.out.println("Invalid input. Please enter a non-negative numerical value.");
                } else {
                    return input;
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a valid numerical value.");
                scanner.next();
            }
        }
    }

    private static int getValidInputInt(Scanner scanner, String prompt) {
        while (true) {
            try {
                System.out.print(prompt);
                int input = scanner.nextInt();
                if (input < 0) {
                    System.out.println("Invalid input. Please enter a non-negative numerical value.");
                } else {
                    return input;
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a valid numerical value.");
                scanner.next(); 
            }
        }
    }

    private static int getValidChoice(Scanner scanner) {
        while (true) {
            try {
                int choice = scanner.nextInt();
                if (choice == 1 || choice == 2) {
                    return choice;
                } else {
                    System.out.println("Invalid input. Please enter a valid choice (1 or 2).");
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a valid choice (1 or 2).");
                scanner.next(); 
            }
        }
    }
}

//===================================================EMERGENCY CALCULATOR===================================================================
