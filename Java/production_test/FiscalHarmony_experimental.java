// FISCAL_HARMONY JAVA
// VERSION FI$CAL.EXP




//                  PURPOSE

// THIS EXPERIMENTATION AS TO ADD PASSWORD HASHING
// TO COLLECT IN THE CSV FILES TO ENSURE SECURITY
// AND TRUST




import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.util.*;
import java.io.*;

public class FiscalHarmony_experimental {
    private static final String FILE_NAME = "user_data/user_data.csv";
    private static final String FILE_NAME2 = "user_data/user_history.csv";
    
    private static LinkedList<Double> income = new LinkedList<>();
    private static LinkedList<Double> expense = new LinkedList<>();
    private static LinkedList<String> historyLog = new LinkedList<>();
    private static double currentFunds = 0; 
    private static double totalIncome = 0;
    private static double totalExpenses = 0;
    
    public static void main(String[] args) {   
    Scanner scanner = new Scanner(System.in);

//===================================================INSTRUCTIONS===================================================================        
        
clearUserData(); 
System.out.println("==============================================");
System.out.println("         Welcome to Fiscal Harmony!");
System.out.println("==============================================");
int choice;

do {
    System.out.println("Select an option:");
    System.out.println("[1]. Read Instructions for Income and Expenses Allocation,\nEmergency Fund Calculator, Tax Calculator, and Privacy Act");
    System.out.println("[2]. Exit");
    System.out.print("> ");

    while (!scanner.hasNextInt()) {
        System.out.println("Invalid input. Please enter a number (1 or 2):");
        System.out.print("> ");
        scanner.next(); 
    }

    choice = scanner.nextInt();
    scanner.nextLine(); 

    if (choice == 1) {
        showCombinedInstructions();
        askIfDone(scanner);
    } else if (choice == 2) {
        System.out.println("Exiting the program. Thank you!");
    } else {
        System.out.println("Invalid choice. Please select a valid option.");
    }
} while (choice != 2);
    }

    private static void showCombinedInstructions() {
        System.out.println("====================================================================================");
        System.out.println("                   INSTRUCTIONS PLEASE READ BEFORE PROCEEDING                 ");
        System.out.println("====================================================================================");

        System.out.println("   INCOME AND EXPENSES ALLOCATION");
        System.out.println("   - Access the Feature: Navigate to the 'Income and Expenses Allocation' section.");
        System.out.println("   - Input Income: Enter your total income for the month.");
        System.out.println("   - Enter Expenses: List all your monthly expenses.");
        System.out.println("   - Review Allocation: Click 'Calculate' to see how your income is allocated.");

        System.out.println("   EMERGENCY FUND CALCULATOR");
        System.out.println("   - Access the Feature: Select 'Emergency Fund Calculator' from the menu.");
        System.out.println("   - Set Savings Goal: Enter your desired savings goal.");
        System.out.println("   - Determine Monthly Contribution: Specify how much you can contribute monthly.");
        System.out.println("   - Calculate Timeframe: Press 'Calculate' to see how long it will take to reach your goal.");

        System.out.println("   TAX CALCULATOR");
        System.out.println("   - Access the Feature: Go to the 'Tax Calculator' section.");
        System.out.println("   - Input Income: Enter your total Annual Salary income.");
        System.out.println("   - Enter Deductions: List any deductions you qualify for.");
        System.out.println("   - Calculate Tax: Click 'Calculate' to see the estimated tax you need to pay.");
        System.out.println("====================================================================================\n");
        
        System.out.println("                               DATA PRIVACY NOTICE                                ");
        System.out.println("                             REPUBLIC ACT NO. 10173                               ");
        System.out.println("                           REPUBLIC OF THE PHILIPPINES                            ");
        System.out.println("");
        System.out.println("   The Republic Act 10173, officially known as the Data Privacy Act of 2012 (DPA).");
        System.out.println("   We request your consent to use this program for managing your finances. " +
                "\n   Your permission allows us to assist you with budgeting and tracking expenses.\n");
        System.out.println("====================================================================================");
    }

    private static void askIfDone(Scanner scanner) {
        while (true) {
            System.out.println("Are you done reading the instructions? [1] Yes [2] No");
            System.out.print("> ");
            String response = scanner.nextLine();

            if (response.equals("1")) {
                askPrivacyActQuestion(scanner);
                break; 
            } else if (response.equals("2")) {
                System.out.println("Feel free to review the instructions again.");
                break; 
            } else {
                System.out.println("Invalid response. Please answer with [1] for Yes or [2] for No.");
            }
        }
    }

    private static void askPrivacyActQuestion(Scanner scanner) {
        while (true) {
            System.out.println("Do you understand how your data will be used and the privacy policies in place? [1] Yes [2] No");
            System.out.print("> ");
            String response = scanner.nextLine();

            if (response.equals("1")) {
                System.out.println("Thank you for your understanding!");
                break; 
            } else if (response.equals("2")) {
                System.out.println("Please review our privacy policy for more information.");
                break; 
            } else {
                System.out.println("Invalid response. Please answer with [1] for Yes or [2] for No.");
            }
        }
    
    
        
//===================================================INSTRUCTIONS===================================================================
    
        
//===================================================LOGIN AND REGISTRATION===================================================================
        boolean goBackToSignUp = true;
        String userEmail = "", userPassword = "";
        String userRegisterEmail = "", userRegisterPassword = "";
        int signInAttempts = 0;


        while (goBackToSignUp) {
            System.out.println("\n");
            System.out.println("                                ███████╗██╗███████╗ ██████╗ █████╗ ██╗             ");
            System.out.println("                                ██╔════╝██║██╔════╝██╔════╝██╔══██╗██║             ");
            System.out.println("                                █████╗  ██║███████╗██║     ███████║██║             ");
            System.out.println("                                ██╔══╝  ██║╚════██║██║     ██╔══██║██║             ");
            System.out.println("                                ██║     ██║███████║╚██████╗██║  ██║███████╗        ");
            System.out.println("                                ╚═╝     ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝        ");
            System.out.println("                                                                                   ");
            System.out.println("                    ██╗  ██╗ █████╗ ██████╗ ███╗   ███╗ ██████╗ ███╗   ██╗██╗   ██╗");
            System.out.println("                    ██║  ██║██╔══██╗██╔══██╗████╗ ████║██╔═══██╗████╗  ██║╚██╗ ██╔╝");
            System.out.println("                    ███████║███████║██████╔╝██╔████╔██║██║   ██║██╔██╗ ██║ ╚████╔╝ ");
            System.out.println("                    ██╔══██║██╔══██║██╔══██╗██║╚██╔╝██║██║   ██║██║╚██╗██║  ╚██╔╝  ");
            System.out.println("                    ██║  ██║██║  ██║██║  ██║██║ ╚═╝ ██║╚██████╔╝██║ ╚████║   ██║   ");
            System.out.println("                    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ");
            System.out.println("                                                               ");
            System.out.println("                        Planning your future for a financially free life.\n");
            System.out.println("╔═[1]. Sign In [2]. Sign Up");
            System.out.println("║");
            System.out.print("╚═══> ");

            int userOption = getValidOption(scanner, 1, 2);

            switch (userOption) {
                case 1:
                    System.out.println("                    ═════════════════════════════════════════════════════════════════");
                    System.out.println("                    You are now signing in...");

                    do {
                        System.out.print("                    Username: ");
                        userEmail = scanner.next();
                        System.out.print("                    Password: ");
                        userPassword = scanner.next();
                        System.out.println("                    ═════════════════════════════════════════════════════════════════");

                        if (!isValidUser(userEmail, userPassword)) {
                            signInAttempts++;
                            System.out.println("                    ***********************************************");
                            System.out.println("                    Invalid password or username, please try again!");
                            System.out.println("                    ***********************************************");
                        }
                    } while (!isValidUser(userEmail, userPassword) && signInAttempts < 2);

                    if (signInAttempts == 2) {
                        System.out.println("                    ********************************************************");
                        System.out.println("                    You have reached the maximum number of sign-in attempts.");
                        System.out.println("                    ********************************************************");
                        System.out.println("                    ═════════════════════════════════════════════════════════════════");
                        System.out.println("╔═[1]. Go back to Sign-up Terminal [2]. Exit");
                        System.out.print("╚═══> ");

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
                    System.out.println("                    ═════════════════════════════════════════════════════════════════");
                    System.out.println("                    You are now creating an account");

                    do {
                        System.out.print("                    Username: ");
                        userRegisterEmail = scanner.next();

                        if (isEmailRegistered(userRegisterEmail)) {
                            System.out.println("                    ***********************************************");
                            System.out.println("                    Email is already in use, please create another.");
                            System.out.println("                    ***********************************************");
                        }
                    } while (isEmailRegistered(userRegisterEmail));

                    System.out.print("                    Password: ");
                    userRegisterPassword = scanner.next();
                    saveUserCredentials(userRegisterEmail, userRegisterPassword);

                    System.out.println("                    You have successfully created an account, would you like to sign in?");
                    System.out.println("╔═[1]. Yes [2]. Exit");
                    System.out.print("╚═══> ");

                    int userSignIn = getValidOption(scanner, 1, 2);
                    System.out.println("                    ═════════════════════════════════════════════════════════════════");

                    if (userSignIn == 1) {
                        do {
                            System.out.print("Username: ");
                            userEmail = scanner.next();
                            System.out.print("Password: ");
                            userPassword = scanner.next();
                            System.out.println("                    ═════════════════════════════════════════════════════════════════");

                            if (!isValidUser(userEmail, userPassword)) {
                                System.out.println("                    You have entered the wrong username or password, please try again!");
                            }
                        } while (!isValidUser(userEmail, userPassword));

                        showFeaturesMenu(scanner, userEmail);
                    } else {
                        System.out.println("                    Have a great day ahead!");
                        System.exit(0);
                    }
                    break;
            }
        }
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

    private static boolean isValidUser(String email, String password) {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] credentials = line.split(",");
                if (credentials[0].equals(email)) {
                    // Extract the stored hash (salt + hash)
                    String storedHash = credentials[1];
    
                    // Decode the stored hash from Base64
                    byte[] decoded = Base64.getDecoder().decode(storedHash);
    
                    // Extract the salt from the decoded data (first 16 bytes)
                    byte[] salt = new byte[16];
                    System.arraycopy(decoded, 0, salt, 0, 16);
    
                    // Hash the entered password with the same salt
                    MessageDigest digest = MessageDigest.getInstance("SHA-256");
                    digest.update(salt);
                    byte[] hashedInput = digest.digest(password.getBytes());
    
                    // Extract the stored hash part (the part after the salt)
                    byte[] storedHashBytes = new byte[decoded.length - salt.length];
                    System.arraycopy(decoded, salt.length, storedHashBytes, 0, storedHashBytes.length);
    
                    // Compare the re-hashed input with the stored hash
                    if (MessageDigest.isEqual(hashedInput, storedHashBytes)) {
                        return true; // Password match
                    }
                }
            }
        } catch (IOException | NoSuchAlgorithmException e) {
            System.out.println("Error reading user file: " + e.getMessage());
        }
        return false;  // Invalid user
    }
    
    
    private static boolean isEmailRegistered(String email) {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] credentials = line.split(",");
                if (credentials[0].equals(email)) {
                    return true; 
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading user file: " + e.getMessage());
        }
        return false; 
    }
    
    private static void saveUserCredentials(String email, String password) {
        try (BufferedWriter writer1 = new BufferedWriter(new FileWriter(FILE_NAME, true));
             BufferedWriter writer2 = new BufferedWriter(new FileWriter(FILE_NAME2, true))) {
    
            // Hash the password with salt before saving
            String hashedPassword = hashPasswordWithSalt(password);
    
            if (hashedPassword != null) {
                // Debugging print statement to confirm what is being saved
                System.out.println("Saving to file: " + email + "," + hashedPassword);
    
                // Store email and the combined salt + hash password in the user file
                writer1.write(email + "," + hashedPassword);
                writer1.newLine();
    
                // Store an empty history log for the user in user_history.csv
                writer2.write(email + ",\"\""); 
                writer2.newLine();
    
                System.out.println("User credentials saved successfully with hashed password.");
            } else {
                System.out.println("Error: Password hashing failed.");
            }
    
        } catch (IOException e) {
            System.out.println("Error saving user credentials: " + e.getMessage());
        }
    }
    
    
    
    
//===================================================LOGIN AND REGISTRATION===================================================================

//===================================================HOME & FEATURES===================================================================


    private static void showFeaturesMenu(Scanner scanner, String userEmail) { 
        loadDataFromCSV(userEmail);
        boolean loggedIn = true;

        while (loggedIn) {
            System.out.println("\n\n                    ╔════════════════════════════════════════════════════════════════╗");
            System.out.println("                    ║           Welcome, " + userEmail + "! I hope you have a great time!        ║");
            System.out.printf("                               Your Total funds left: PHP %.2f                      \n", currentFunds);
            System.out.println("                    ╚════════════════════════════════════════════════════════════════╝");
            System.out.println("                         Here are our current available features, check them out!:\n");
            System.out.println("             ╔════[1]. Income and Expense Allocation");
            System.out.println("          ╔══╩══[2]. Emergency Fund Calculator");
            System.out.println("       ╔══╩═══[3]. Salary Calculator");
            System.out.println("      ╔╩════[4]. Log out");
            System.out.println("      ║");
            System.out.print("      ╚═══> ");
            int featureOption = getValidOption(scanner, 1, 4);

            switch (featureOption) {
                case 1:
                    incomeExpensesAllocationModule();
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
                    saveDataToCSV(userEmail);
                    clearUserData();
                    break;
            }
        }
    }

    

//===================================================HOME & FEATURES===================================================================

//===================================================INCOME & EXPENSE ALLOCATION===================================================================

    private static void incomeExpensesAllocationModule() {
        Scanner scanner = new Scanner(System.in);
        boolean goBackToFeature = true;

        while (goBackToFeature) {
            totalIncome = calculateTotal(income);
            totalExpenses = calculateTotal(expense);
            currentFunds = totalIncome - totalExpenses;

            System.out.println("                        **************************************************");
            System.out.println("                            \tIncome and Expenses Allocation");
            System.out.println("                        **************************************************");
            System.out.printf("                                Total funds left: PHP %.2f\n", currentFunds);
            System.out.println("                        **************************************************");
            System.out.println("                              Kindly choose one of the following: ");
            System.out.println("");
            System.out.println("             ╔════[1]. Income");
            System.out.println("          ╔══╩══[2]. Expenses");
            System.out.println("       ╔══╩═══[3]. History Log");
            System.out.println("      ╔╩════[4]. Home");
            System.out.println("      ║");
            System.out.print("      ╚═══> ");

            int userFeatureChoice = getValidChoice(scanner, 1, 4);

            switch (userFeatureChoice) {
                case 1:
                    handleIncome(scanner);
                    break;
                case 2:
                    handleExpenses(scanner);
                    break;
                case 3:
                    showHistoryLog();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    return;
            }
        }

        scanner.close();
    }

    private static void handleIncome(Scanner scanner) {
        String userInput = "";
        List<String> incomeCategories = new ArrayList<>();
        do {
            System.out.print("Enter income category: ");
            String category = scanner.nextLine();

            if (category.trim().isEmpty()) {
                System.out.println("Invalid input. Category cannot be empty. Please try again.");
                return; 
            }

            if (category.matches(".*\\d.*")) {
                System.out.println("Invalid input. Category cannot contain numbers. Please try again.");
                return; 
            }
            
            System.out.print("Enter amount for " + category + ": PHP ");
            double amount = getValidAmount(scanner);
            income.add(amount);
            incomeCategories.add(category);

            historyLog.add("Income: PHP " + amount + " from " + category); 
            System.out.print("Do you want to enter another income? (y/n): ");
            userInput = scanner.next();
            scanner.nextLine(); 
        } while (userInput.equalsIgnoreCase("y"));

        double totalIncome = calculateTotal(income);
        System.out.println("_________________________________");
        System.out.printf("Total Income: PHP %.2f\n", totalIncome);

        printIncomeSummary(totalIncome, income, incomeCategories);
    }

    private static void printIncomeSummary(double totalIncome, List<Double> income, List<String> incomeCategories) {
        for (int i = 0; i < incomeCategories.size(); i++) {
            double percentage = (totalIncome == 0) ? 0 : (income.get(i) / totalIncome) * 100;
            System.out.printf(" %.2f%% \t| %s Income: PHP %.2f\n", percentage, incomeCategories.get(i), income.get(i));
        }
        System.out.printf("_________________________________\nTotal Income: PHP %.2f\n", totalIncome);
    }

    private static void handleExpenses(Scanner scanner) {
        String userInput = "";
        List<String> expenseCategories = new ArrayList<>();
        do {
            System.out.print("Enter expense category: ");
            String category = scanner.nextLine();

        if (category.trim().isEmpty()) {
            System.out.println("Invalid input. Category cannot be empty. Please try again.");
            return; 
        }

        if (category.matches(".*\\d.*")) {
            System.out.println("Invalid input. Category cannot contain numbers. Please try again.");
            return; 
        }

            System.out.print("Enter amount for " + category + ": PHP ");
            double amount = getValidAmount(scanner);

            double totalIncome = calculateTotal(income);
            if (amount > totalIncome) {
                System.out.println("Insufficient funds! Please add more income.");
                break;
            }

            expense.add(amount); 
            expenseCategories.add(category); 
            historyLog.add("Expense: PHP " + amount + " for " + category); 

            System.out.print("Do you want to enter another expense? (y/n): ");
            userInput = scanner.next();
            scanner.nextLine();  
        } while (userInput.equalsIgnoreCase("y"));

        double totalExpenses = calculateTotal(expense);
        double totalIncome = calculateTotal(income); 
        System.out.println("_________________________________");
        System.out.printf("Total Expenses: PHP %.2f\n", totalExpenses);

        printExpenseSummary(totalExpenses, totalIncome, expense, expenseCategories);
    }

    private static void printExpenseSummary(double totalExpenses, double totalIncome, List<Double> expense, List<String> expenseCategories) {
        for (int i = 0; i < expenseCategories.size(); i++) {
            double percentage = (totalExpenses == 0) ? 0 : (expense.get(i) / totalExpenses) * 100;
            System.out.printf(" %.2f%% \t| %s Expense: PHP %.2f\n", percentage, expenseCategories.get(i), expense.get(i));
        }
        System.out.printf("_________________________________\nTotal Expenses: PHP %.2f\n", totalExpenses);
        System.out.printf("Total Funds: PHP %.2f\n", totalIncome - totalExpenses);
    }

    private static int getValidChoice(Scanner scanner, int min, int max) {
        int choice;
        while (true) {
            if (scanner.hasNextInt()) {
                choice = scanner.nextInt();
                scanner.nextLine();  
                if (choice >= min && choice <= max) {
                    break;
                }
            } else {
                scanner.nextLine();  
            }
            System.out.println("Invalid input. Please enter a valid number (" + min + "-" + max + "): ");
        }
        return choice;
    }

    private static double getValidAmount(Scanner scanner) {
        double amount;
        while (true) {
            if (scanner.hasNextDouble()) {
                amount = scanner.nextDouble();
                scanner.nextLine();  
                if (amount >= 0) {
                    break;
                }
            } else {
                scanner.nextLine();  
            }
            System.out.print("Invalid input. Please enter a valid amount: PHP ");
        }
        return amount;
    }

    private static double calculateTotal(LinkedList<Double> list) {
        double total = 0;
        for (double value : list) {
            total += value;
        }
        return total;
    }

    private static void showHistoryLog() {
        System.out.println("History Log:");
        for (String entry : historyLog) {
            System.out.println(entry);
        }
    }


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& - LOADER-SAVER CSV - &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&



private static String hashPasswordWithSalt(String password) {
    try {
        // Generate a random salt
        SecureRandom random = new SecureRandom();
        byte[] salt = new byte[16];  // 16 bytes for the salt
        random.nextBytes(salt);

        // Hash the password with the salt using SHA-256
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        digest.update(salt);  // Add salt to the password
        byte[] hashBytes = digest.digest(password.getBytes());

        // Combine the salt and hash
        byte[] combined = new byte[salt.length + hashBytes.length];
        System.arraycopy(salt, 0, combined, 0, salt.length);
        System.arraycopy(hashBytes, 0, combined, salt.length, hashBytes.length);

        // Encode the combined result to Base64 (so we can store it as a string)
        String base64Result = Base64.getEncoder().encodeToString(combined);

        // Debugging output to verify the result
        System.out.println("Salt: " + Base64.getEncoder().encodeToString(salt));
        System.out.println("Hashed Password (with salt): " + base64Result);

        return base64Result;
    } catch (Exception e) {
        System.out.println("Error hashing password with salt: " + e.getMessage());
    }
    return null;
}

    private static void saveDataToCSV(String email) {
        StringBuilder updatedData = new StringBuilder();
        boolean userFound = false;
    
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;

            while ((line = reader.readLine()) != null) {
                String[] data = line.split(",");

                if (data.length >= 2 && data[0].equals(email)) {
                    userFound = true;
                    updatedData.append(email).append(",").append(data[1]).append(","); 

                    for (Double inc : income) {
                        updatedData.append("Income: PHP ").append(inc).append(";");
                    }
                    for (Double exp : expense) {
                        updatedData.append("Expense: PHP ").append(exp).append(";");
                    }
    
                    updatedData.append("\n");
                } else {
                    updatedData.append(line).append("\n");
                }
            }

            if (!userFound) {
                updatedData.append(email).append(",<password>,"); 
    
                for (Double inc : income) {
                    updatedData.append("Income: PHP ").append(inc).append(";");
                }
                for (Double exp : expense) {
                    updatedData.append("Expense: PHP ").append(exp).append(";");
                }
    
                updatedData.append("\n");
            }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_NAME))) {
            writer.write(updatedData.toString());
        }

        StringBuilder combinedHistoryLog = new StringBuilder();
        for (String history : historyLog) {
            combinedHistoryLog.append(history).append("; ");
        }

        if (combinedHistoryLog.length() > 2) {
            combinedHistoryLog.setLength(combinedHistoryLog.length() - 2);
        }

        File historyFile = new File(FILE_NAME2);
        StringBuilder historyFileData = new StringBuilder();
        boolean userHistoryFound = false;

        try (BufferedReader historyReader = new BufferedReader(new FileReader(FILE_NAME2))) {
            String historyLine;
            while ((historyLine = historyReader.readLine()) != null) {
                String[] historyData = historyLine.split(",", 2);
                if (historyData.length >= 2 && historyData[0].equals(email)) {
                    userHistoryFound = true;
                    historyFileData.append(email).append(",").append(combinedHistoryLog.toString()).append("\n");
                } else {
                    historyFileData.append(historyLine).append("\n");
                }
            }

            if (!userHistoryFound) {
                historyFileData.append(email).append(",").append(combinedHistoryLog.toString()).append("\n");
            }

            try (BufferedWriter historyWriter = new BufferedWriter(new FileWriter(FILE_NAME2))) {
                historyWriter.write(historyFileData.toString());
            }

        }

    } catch (IOException e) {
        System.out.println("Error saving data to CSV: " + e.getMessage());
    }
}

    private static void loadDataFromCSV(String email) {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            boolean userFound = false;

            while ((line = reader.readLine()) != null) {
                String[] data = line.split(",");

                if (data.length >= 3 && data[0].equals(email)) {
                    userFound = true;
    
                    String[] transactions = data[2].split(";"); 
                    double totalIncomeForUser = 0.0;
                    double totalExpensesForUser = 0.0;
    
                    for (String transaction : transactions) {
                        if (transaction.startsWith("Income")) {
                            String incomeStr = transaction.split(": PHP ")[1].split(" ")[0]; 
                            double incomeValue = Double.parseDouble(incomeStr);
    
                            if (incomeValue > 0.0) {
                                totalIncomeForUser += incomeValue;
                            }
                        }
                        else if (transaction.startsWith("Expense")) {
                            String expenseStr = transaction.split(": PHP ")[1].split(" ")[0]; 
                            double expenseValue = Double.parseDouble(expenseStr);
    
                            if (expenseValue > 0.0) {
                                totalExpensesForUser += expenseValue;
                            }
                        }
                    }
    
                    income.add(totalIncomeForUser);
                    expense.add(totalExpensesForUser);
                    totalIncome += totalIncomeForUser;
                    totalExpenses += totalExpensesForUser;
    
                    currentFunds = totalIncome - totalExpenses;
    
                    break; 
                }
            }
    
            if (!userFound) {
                System.out.println("User not found in user_data.csv. Initializing new data.");
            }
    
        } catch (IOException e) {
            System.out.println("Error loading income and expense data from user_data.csv: " + e.getMessage());
        }

        loadUserHistory(email);

        // FOR DEBUGGING | CHECKING ERRORS
        // ONLY INCLUDE THIS CODE FOR DEBUG/ERRORS
        //
        // System.out.println("Income List: " + income);
        // System.out.println("Expense List: " + expense);
        // System.out.println("Total Income: PHP " + totalIncome);
        // System.out.println("Total Expenses: PHP " + totalExpenses);
        // System.out.println("Current Funds: PHP " + currentFunds);
        // System.out.println("User History: " + historyLog); 
        //
        // FOR DEBUGGING | CHECKING ERRORS
    }
    
    private static void loadUserHistory(String email) {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME2))) {
            String line;
            boolean userFound = false;
    
            while ((line = reader.readLine()) != null) {
                String[] data = line.split(",", 2); 
    
                if (data.length >= 2 && data[0].equals(email)) {
                    userFound = true;

                    String historyLogData = data[1].trim();

                    if (!historyLogData.isEmpty() && !historyLogData.equals("\"\"")) {
                        String[] historyEntries = historyLogData.split(";");

                        for (String history : historyEntries) {
                            if (!history.isEmpty()) {
                                historyLog.add(history.trim());
                            }
                        }
                    }
    
                    break; 
                }
            }
    
            if (!userFound) {
                System.out.println("User not found in user_history.csv. No history log available.");
            }
    
        } catch (IOException e) {
            System.out.println("Error loading history log from user_history.csv: " + e.getMessage());
        }
    }

    

    private static void clearUserData() {
        income.clear();
        expense.clear();
        historyLog.clear();
        currentFunds = 0;
        totalIncome = 0;
        totalExpenses = 0;
    
        System.out.println("All user data has been cleared and reset to default values.");
    }
    
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& - LOADER-SAVER CSV - &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&




//===================================================INCOME & EXPENSE ALLOCATION===================================================================

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
        System.out.println("[1]. Back to Home [2]. Log out");
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
