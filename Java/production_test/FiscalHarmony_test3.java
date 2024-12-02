package production_test;

// FISCAL_HARMONY JAVA test3
// VERSION FI$CAL 2.0

import java.util.*;
import java.io.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class FiscalHarmony_test3 {
    private static final String FILE_NAME = "user_data/user_data.csv";
    private static final String FILE_NAME2 = "user_data/user_history.csv";
    
    private static LinkedList<Double> income = new LinkedList<>();
    private static LinkedList<Double> expense = new LinkedList<>();
    private static LinkedList<String> historyLog = new LinkedList<>();
    private static double currentFunds = 0; 
    private static double totalIncome = 0;
    private static double totalExpenses = 0;
    
    public static void main(String[] args) {   
    System.setProperty("file.encoding", "UTF-8");
    Scanner scanner = new Scanner(System.in);

//===================================================INSTRUCTIONS===================================================================        
        
clearUserData(); 
int choice;

do {
    System.out.println("\n");
    System.out.println("                        ======================================================");
    System.out.println("                                        Welcome to Fiscal Harmony!");
    System.out.println("                        ======================================================");

    System.out.println("\t\t\t\t\tSelect an option:");
    System.out.println("\t\t\t[1]. Read Instructions for Income and Expenses Allocation,\n\t\t\tSaving Funds, and Privacy Act");
    System.out.println("\t\t\t[2]. Exit");
    System.out.print("\t\t\t> ");

    while (!scanner.hasNextInt()) {
        System.out.println("\t\t\tInvalid input. Please enter a number (1 or 2):");
        System.out.print("\t\t\t> ");
        scanner.next(); 
    }

    choice = scanner.nextInt();
    scanner.nextLine(); 

    if (choice == 1) {
        showCombinedInstructions();
        askIfDone(scanner);
    } else if (choice == 2) {
        System.out.println("\t\t\tExiting the program. Thank you!");
    } else {
        System.out.println("\t\t\tInvalid choice. Please select a valid option.");
    }
} while (choice != 2);
    }

    private static void showCombinedInstructions() {
        String instructions = 
            "\t\t\t====================================================================================\n" +
            "\t\t\t\t\t\tINSTRUCTIONS PLEASE READ BEFORE PROCEEDING                 \n" +
            "\t\t\t====================================================================================\n" +
            "\t\t\t\n" +
            "\t\t\tINCOME AND EXPENSES ALLOCATION\n" +
            "\t\t\t- Access the Feature: Navigate to the 'Income and Expenses Allocation' section.\n" +
            "\t\t\t- Input Income: Enter your income category, then input how many pesos\n" +
            "\t\t\t- Enter Expenses: Enter your expense category, then input how many pesos\n" +
            "\t\t\t- Review Allocation: Click [4] to check your history log\n" +
            "\t\t\t\n" +
            "\t\t\tSAVINGS FUND\n" +
            "\t\t\t- Access the Feature: Select [2] 'Saving Funds' from the menu.\n" +
            "\t\t\t- Saving Goals is set to 6 months prior\n" +
            "\t\t\t- Calculate Timeframe: Your current funds will automatically\n\t\t\t calculate the details it should be shown your the Savings\n" +
            // "\n" +
            // "   TAX CALCULATOR\n" +
            // "   - Access the Feature: Go to the 'Tax Calculator' section.\n" +
            // "   - Input Income: Enter your total Annual Salary income.\n" +
            // "   - Enter Deductions: List any deductions you qualify for.\n" +
            // "   - Calculate Tax: Click 'Calculate' to see the estimated tax you need to pay.\n" +
            "\t\t\t====================================================================================\n" +
            "\t\t\t\n" +
            "                                                   DATA PRIVACY NOTICE                                \n" +
            "                                                 REPUBLIC ACT NO. 10173                               \n" +
            "                                               REPUBLIC OF THE PHILIPPINES                            \n" +
            "\t\t\t\n" +
            "\t\t\tThe Republic Act 10173, officially known as the Data Privacy Act of 2012 (DPA).\n" +
            "\t\t\t    We request your consent to use this program for managing your finances. " +
            "\n\t\t\tYour permission allows us to assist you with budgeting and tracking expenses.\n" +
            "\t\t\t====================================================================================";
    
        try {
            for (int i = 0; i < instructions.length(); i++) {
                System.out.print(instructions.charAt(i)); 
                Thread.sleep(1); 
                // BRUH DOESNT WORK
            }
        } catch (InterruptedException e) {
            e.printStackTrace(); 
        }
    }
    

    private static void askIfDone(Scanner scanner) {
        while (true) {
            System.out.println("\n\t\t\tAre you done reading the instructions? [1] Yes [2] No");
            System.out.print("\t\t\t> ");
            String response = scanner.nextLine();

            if (response.equals("1")) {
                askPrivacyActQuestion(scanner);
                break; 
            } else if (response.equals("2")) {
                System.out.println("\t\t\tFeel free to review the instructions again.");
                break; 
            } else {
                System.out.println("\t\t\tInvalid response. Please answer with [1] for Yes or [2] for No.");
            }
        }
    }

    private static void askPrivacyActQuestion(Scanner scanner) {
        while (true) {
            System.out.println("\t\t\tDo you understand how your data will be used and the privacy policies in place? [1] Yes [2] No");
            System.out.print("\t\t\t> ");
            String response = scanner.nextLine();

            if (response.equals("1")) {
                System.out.println("\t\t\tThank you for your understanding!");
                break; 
            } else if (response.equals("2")) {
                System.out.println("\t\t\tPlease review our privacy policy for more information.");
                break; 
            } else {
                System.out.println("\t\t\tInvalid response. Please answer with [1] for Yes or [2] for No.");
            }
        }
    
    
        
//===================================================INSTRUCTIONS===================================================================
    
        
//===================================================LOGIN AND REGISTRATION===================================================================
        boolean goBackToSignUp = true;
        String userEmail = "", userPassword = "";
        String userRegisterEmail = "", userRegisterPassword = "";
        int signInAttempts = 0;


        while (goBackToSignUp) {
            // PROGRESS BAR | SCRAP
            //
            // for (int i = 0; i <= 100; i++) {
            //     System.out.print("\rLoading: [" + "#".repeat(i / 2) + " ".repeat(50 - i / 2) + "] " + i + "%");
            //     try {
            //         Thread.sleep(50);  
            //     } catch (InterruptedException e) {
            //         e.printStackTrace();
            //     }
            // }
            // PROGRESS BAR | SCRAP
    
            try {
                System.out.println("\n");
                Thread.sleep(10); 
                System.out.println("                                ███████╗██╗███████╗ ██████╗ █████╗ ██╗             ");
                Thread.sleep(10);
                System.out.println("                                ██╔════╝██║██╔════╝██╔════╝██╔══██╗██║             ");
                Thread.sleep(10);
                System.out.println("                                █████╗  ██║███████╗██║     ███████║██║             ");
                Thread.sleep(10);
                System.out.println("                                ██╔══╝  ██║╚════██║██║     ██╔══██║██║             ");
                Thread.sleep(10);
                System.out.println("                                ██║     ██║███████║╚██████╗██║  ██║███████╗        ");
                Thread.sleep(10);
                System.out.println("                                ╚═╝     ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝        ");
                Thread.sleep(20); 
                System.out.println("                                                                                   ");
                Thread.sleep(10);
                System.out.println("                    ██╗  ██╗ █████╗ ██████╗ ███╗   ███╗ ██████╗ ███╗   ██╗██╗   ██╗");
                Thread.sleep(10);
                System.out.println("                    ██║  ██║██╔══██╗██╔══██╗████╗ ████║██╔═══██╗████╗  ██║╚██╗ ██╔╝");
                Thread.sleep(10);
                System.out.println("                    ███████║███████║██████╔╝██╔████╔██║██║   ██║██╔██╗ ██║ ╚████╔╝ ");
                Thread.sleep(10);
                System.out.println("                    ██╔══██║██╔══██║██╔══██╗██║╚██╔╝██║██║   ██║██║╚██╗██║  ╚██╔╝  ");
                Thread.sleep(10);
                System.out.println("                    ██║  ██║██║  ██║██║  ██║██║ ╚═╝ ██║╚██████╔╝██║ ╚████║   ██║   ");
                Thread.sleep(10);
                System.out.println("                    ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ");
                Thread.sleep(20); 
                System.out.println("                                                               ");
                Thread.sleep(10);
                System.out.println("                        Planning your future for a financially free life.\n");
                Thread.sleep(10); 
                System.out.println("\t╔═[1]. Sign In [2]. Sign Up [3] Go Back to Instructions");
                Thread.sleep(100);
                System.out.println("\t║");
                Thread.sleep(100);
                System.out.print("\t╚═══> ");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            int userOption = getValidOption(scanner);

            switch (userOption) {
                case 1:
                    System.out.println("\t\t\t═════════════════════════════════════════════════════════════════");
                    System.out.println("\t\t\tYou are now signing in...");

                    do {
                        System.out.print("\t\t\tUsername: ");
                        userEmail = scanner.next();
                        System.out.print("\t\t\tPassword: ");
                        userPassword = scanner.next();
                        System.out.println("\t\t\t═════════════════════════════════════════════════════════════════");

                        if (!isValidUser(userEmail, userPassword)) {
                            signInAttempts++;
                            System.out.println("\t\t\t***********************************************");
                            System.out.println("\t\t\tInvalid password or username, please try again!");
                            System.out.println("\t\t\t***********************************************");
                        }
                    } while (!isValidUser(userEmail, userPassword) && signInAttempts < 2);

                    if (signInAttempts == 2) {
                        System.out.println("\t\t\t********************************************************");
                        System.out.println("\t\t\tYou have reached the maximum number of sign-in attempts.");
                        System.out.println("\t\t\t********************************************************");
                        System.out.println("\t\t\t═════════════════════════════════════════════════════════════════");
                        System.out.println("\t\t\t╔═[1]. Go back to Sign-up Terminal [2]. Exit");
                        System.out.print("\t\t\t╚═══> ");

                        int finalOption = getValidOption(scanner);

                        if (finalOption == 1) {
                            signInAttempts = 0;
                            goBackToSignUp = true;
                            continue;
                        } else {
                            System.out.println("\t\t\tHave a great day ahead!");
                            System.exit(0);
                        }
                    } else {
                        goBackToSignUp = false;
                        showFeaturesMenu(scanner, userEmail);
                    }
                    break;

                case 2:
                    System.out.println("\t\t\t═════════════════════════════════════════════════════════════════");
                    System.out.println("\t\t\tYou are now creating an account");

                    do {
                        System.out.print("                    Username: ");
                        userRegisterEmail = scanner.next();

                        if (isEmailRegistered(userRegisterEmail)) {
                            System.out.println("\t\t\t***********************************************");
                            System.out.println("\t\t\tEmail is already in use, please create another.");
                            System.out.println("\t\t\t***********************************************");
                        }
                    } while (isEmailRegistered(userRegisterEmail));

                    System.out.print("\t\t\tPassword: ");
                    userRegisterPassword = scanner.next();
                    saveUserCredentials(userRegisterEmail, userRegisterPassword);

                    System.out.println("\t\t\tYou have successfully created an account, would you like to sign in?");
                    System.out.println("\t\t\t╔═[1]. Yes [2]. Exit");
                    System.out.print("\t\t\t╚═══> ");

                    int userSignIn = getValidOption(scanner);
                    System.out.println("\t\t\t ═════════════════════════════════════════════════════════════════");

                    if (userSignIn == 1) {
                        do {
                            System.out.print("\t\t\tUsername: ");
                            userEmail = scanner.next();
                            System.out.print("\t\t\tPassword: ");
                            userPassword = scanner.next();
                            System.out.println("\t\t\t═════════════════════════════════════════════════════════════════");

                            if (!isValidUser(userEmail, userPassword)) {
                                System.out.println("\t\t\tYou have entered the wrong username or password, please try again!");
                            }
                        } while (!isValidUser(userEmail, userPassword));

                        showFeaturesMenu(scanner, userEmail);
                    } else {
                        System.out.println("\t\t\tHave a great day ahead!");
                        System.exit(0);
                    }
                    break;
                    case 3:
                        return;
                    
            }
        }
    }

    private static int getValidOption(Scanner scanner) {
        int option = -1;
        while (true) {
            try {
                option = scanner.nextInt();
                if (option == 1 || option == 2 || option == 3) {
                    break;
                } else {
                    System.out.println("\t\t\tInvalid input. Please enter a valid number (1, 2, or 3).");
                    System.out.print("\t\t\t> ");
                }
            } catch (InputMismatchException e) {
                System.out.println("\t\t\tInvalid input. Please enter a valid number (1, 2, or 3).");
                System.out.print("\t\t\t> ");
                scanner.next(); // Clear the invalid input
            }
        }
        return option;
    }

    private static boolean isValidUser(String email, String password) {
        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] credentials = line.split(",");
                if (credentials[0].equals(email) && credentials[1].equals(password)) {
                    return true;
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading user file: " + e.getMessage());
        }
        return false;
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

            writer1.write(email + "," + password); 
            writer1.newLine();

            writer2.write(email + ",\"\""); 
            writer2.newLine();
            
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
            System.out.println("                               Welcome, " + userEmail + "! I hope you have a great time!        ");
            System.out.printf("                               Your Total funds left: PHP %.2f                      \n", currentFunds);
            System.out.println("                    ╚════════════════════════════════════════════════════════════════╝");
            System.out.println("                         Here are our current available features, check them out!:\n");
            System.out.println("             ╔════[1]. Income and Expense Allocation");
            System.out.println("          ╔══╩══[2]. Savings Planner");
            // System.out.println("       ╔══╩═══[3]. Salary Calculator");
            System.out.println("      ╔═══╩═[3]. Log out");
            System.out.println("      ║");
            System.out.print("      ╚═══> ");
            int featureOption = getValidOption(scanner);

            switch (featureOption) {
                case 1:
                    incomeExpensesAllocationModule();
                    break;
                case 2:
                    runSavingsPlanner(scanner);
                    break;
                // case 3:
                //     System.out.println("Salary Calculator.");
                //     break;
                case 3:
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

    private static void incomeCategoryMenu() {
        String incomeMenu =
        "\t\t==================================================================\n" +
        "\t\t1. Salary/Wages        | 2. Business Income   | 3. Freelancing\n" +
        "\t\t4. Interest Income     | 5. Rental Income     | 6. Dividends\n" +
        "\t\t7. Sales Revenue       | 8. Gifts/Donations   | 9. Bonuses\n" +
        "\t\t==================================================================\n\n";

        try {
            for (int i = 0; i < incomeMenu.length(); i++) {
                System.out.print(incomeMenu.charAt(i)); 
                Thread.sleep(1); 
                // BRUH DOESNT WORK
            }
        } catch (InterruptedException e) {
            e.printStackTrace(); 
        }
    }
    
    private static void handleIncome(Scanner scanner) {
        String userInput = "";
        List<String> incomeCategories = new ArrayList<>();
        DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");

        do {
            incomeCategoryMenu();
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

            String timestamp = LocalDateTime.now().format(dateTimeFormatter);
            historyLog.add("[" + timestamp + "] Income: PHP " + amount + " from " + category);

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

    private static void expenseCategoryMenu() {
        String expenseMenu =
        "\t\t==================================================================\n" +
        "\t\t1. Meralco (Electricity) | 2. Water Bill       | 3. Internet Bill\n" +
        "\t\t4. Rent/Mortgage         | 5. Groceries        | 6. Transportation\n" +
        "\t\t7. Healthcare/Medical    | 8. Insurance        | 9. School Fees\n" +
        "\t\t10. Dining Out           | 11. Entertainment   | 12. Miscellaneous\n" +
        "\t\t==================================================================\n\n";

        try {
            for (int i = 0; i < expenseMenu.length(); i++) {
                System.out.print(expenseMenu.charAt(i)); 
                Thread.sleep(1); 
            }
        } catch (InterruptedException e) {
            e.printStackTrace(); 
        }
    }
    

    private static void handleExpenses(Scanner scanner) {
        String userInput = "";
        List<String> expenseCategories = new ArrayList<>();
        DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");

        do {
            expenseCategoryMenu();
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
                System.out.println("===========================================");
                System.out.println("INSUFFICIENT FUNDS!. PLEASE ADD MORE INCOME!");
                System.out.println("===========================================");
                break;
            }

            expense.add(amount);
            expenseCategories.add(category);

            String timestamp = LocalDateTime.now().format(dateTimeFormatter);
            historyLog.add("[" + timestamp + "] Expense: PHP " + amount + " for " + category);

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
    
        } catch (IOException e) {
            System.out.println("Error saving data to user_data.csv: " + e.getMessage());
        }

        StringBuilder combinedHistoryLog = new StringBuilder();
        for (String history : historyLog) {
            combinedHistoryLog.append(history).append("; ");
        }
    
        if (combinedHistoryLog.length() > 2) {
            combinedHistoryLog.setLength(combinedHistoryLog.length() - 2);
        }
    
        try {
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
            }
    
            if (!userHistoryFound) {
                historyFileData.append(email).append(",").append(combinedHistoryLog.toString()).append("\n");
            }
    
            try (BufferedWriter historyWriter = new BufferedWriter(new FileWriter(FILE_NAME2))) {
                historyWriter.write(historyFileData.toString());
            }
    
        } catch (IOException e) {
            System.out.println("Error saving data to user_history.csv: " + e.getMessage());
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
                        } else if (transaction.startsWith("Expense")) {
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
    
        } catch (IOException e) {
            System.out.println("Error loading income and expense data from user_data.csv: " + e.getMessage());
        }
    
        loadUserHistory(email);
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
    
        // USE ONLY FOR DEBUG | INCLUDE THIS TO DEBUG
        //
        // System.out.println("All user data has been cleared and reset to default values.");
        //
        // USE ONLY FOR DEBUG | INCLUDE THIS TO DEBUG
        
    }
    
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& - LOADER-SAVER CSV - &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&




//===================================================INCOME & EXPENSE ALLOCATION===================================================================

//===================================================EMERGENCY CALCULATOR===================================================================

private static void runSavingsPlanner(Scanner scanner) {

    while (true) { 
        System.out.println("\t\t\t+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+");
        System.out.println("\t\t\t                 Emergency Fund Planner");
        System.out.println("\t\t\t+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+");
        System.out.println("\t\t\t        Current Savings today: PHP " + currentFunds);
        System.out.println("\t\t\t+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+");

        int recommendedMonths = 6;

        // Emergency fund goal
        double emergencyFundGoal = currentFunds * recommendedMonths + 50;
        System.out.printf("\n\t\t\tYou must have a total of PHP %.2f \n\t\t\tsaved in the next few months to ensure financial security.%n",
                emergencyFundGoal);

        System.out.println("\t\t\t=============================================================");
        System.out.println("\t\t\t[1] How much emergency fund do I need?");
        System.out.println("\t\t\t[2] Back to Home");
        System.out.println("\t\t\t[3] Exit Savings Fund");
        System.out.print("\t\t\tChoose an option: ");

        int userChoice = getValidChoice(scanner);

        switch (userChoice) {
            case 1 -> calculateEmergencyFund(scanner); 
            case 2 -> {
                System.out.println("\t\t\tReturning to Home...");
                return; 
            }
            case 3 -> {
                System.out.println("\t\t\tExiting Program... Goodbye!");
                System.exit(0); 
            }
        }
    }
}

public static void calculateEmergencyFund(Scanner scanner) {
    System.out.println("\t\t\t=============================================================");
    System.out.print("\t\t\tEnter your average monthly expenses (PHP): ");

    double monthlyExpenses = getValidDouble(scanner);

    System.out.print("\t\t\tEnter the number of months you want to save for: ");
    int months = getValidInt(scanner);

    double requiredEmergencyFund = monthlyExpenses * months;

    System.out.printf("\n\t\t\tYou need a total of PHP %.2f saved for %d months of financial security.%n",
            requiredEmergencyFund, months);

    System.out.println("\t\t\t=============================================================");
    System.out.println("\t\t\tReturning to Emergency Fund Planner...");
}

public static int getValidInt(Scanner scanner) {
    while (true) {
        try {
            return scanner.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("\t\t\tInvalid input. Please enter a valid number.");
            scanner.next();
        }
    }
}

public static double getValidDouble(Scanner scanner) {
    while (true) {
        try {
            return scanner.nextDouble();
        } catch (InputMismatchException e) {
            System.out.println("\t\t\tInvalid input. Please enter a valid number.");
            scanner.next();
        }
    }
}

public static int getValidChoice(Scanner scanner) {
    while (true) {
        try {
            int choice = scanner.nextInt();
            if (choice >= 1 && choice <= 3) {
                return choice;
            } else {
                System.out.println("\t\t\tInvalid input. Please enter a valid choice (1, 2, or 3).");
            }
        } catch (InputMismatchException e) {
            System.out.println("\t\t\tInvalid input. Please enter a valid choice (1, 2, or 3).");
            scanner.next();
            }
        }
    }
}


//===================================================EMERGENCY CALCULATOR===================================================================
