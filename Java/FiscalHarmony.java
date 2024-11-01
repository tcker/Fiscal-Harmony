import java.util.*;

public class FiscalHarmony {
    private static final int INCOME_CATEGORIES = 5;
    private static final int EXPENSE_CATEGORIES = 5;
    
    private static LinkedList<Double> income = new LinkedList<>();
    private static LinkedList<Double> expense = new LinkedList<>();
    private static LinkedList<String> historyLog = new LinkedList<>();

    private static double totalIncome = 0;
    private static double totalExpenses = 0;
    private static double currentFunds = 0;
    private static double totalFunds = 0;
    
    public static void main(String[] args) {
        
        for (int i = 0; i < INCOME_CATEGORIES; i++) {
            income.add(0.0);
        }
        for (int i = 0; i < EXPENSE_CATEGORIES; i++) {
            expense.add(0.0);
        }   
        
    Scanner scanner = new Scanner(System.in);

//===================================================INSTRUCTIONS===================================================================        
        
        System.out.println("==============================================");
        System.out.println("         Welcome to Fiscal Harmony!");
        System.out.println("==============================================");
        System.out.println("             select an option:");
        System.out.println("[1]. Read Instructions for Income and Expenses Allocation,\nEmergency Fund Calculator, Tax Calculator, and Privacy Act");
        System.out.println("[2]. Exit");
        System.out.print("> ");

        int choice = scanner.nextInt();
        scanner.nextLine();

        if (choice == 1) {
            showCombinedInstructions();
            askIfDone(scanner);
        } else if (choice == 2) {
            System.out.println("Exiting the program. Thank you!");
        } else {
            System.out.println("Invalid choice. Please select a valid option.");
        }

        scanner.close();
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
            System.out.println("\n\n=============================================================");
            System.out.println("                 Welcome to Fiscal Harmony");
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

//===================================================HOME & FEATURES===================================================================

    private static void showFeaturesMenu(Scanner scanner, String userEmail) {
        boolean loggedIn = true;

        while (loggedIn) {
            System.out.println("================================================================");
            System.out.println("Welcome, " + userEmail + "! I hope you have a great time!");
            System.out.printf("Your Total funds left: PHP %.2f\n", currentFunds);
            System.out.println("================================================================");
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
                    break;
            }
        }
    }

//===================================================HOME & FEATURES===================================================================

//===================================================INCOME & EXPENSE ALLOCATION===================================================================

    private static void incomeExpensesAllocationModule() {
        String[] incomeCategories = {
                "Personal", "Business", "Gifts", "Loan", "Others"
        };

        String[] expenseCategories = {
                "Food & Drink", "Shopping & Groceries", "Transport", "Home", "Bills/Fees & others"
        };

        Scanner scanner = new Scanner(System.in);
        boolean goBackToFeature = true;

        while (goBackToFeature) {
            // Use global variables here
            totalIncome = calculateTotal(income);
            totalExpenses = calculateTotal(expense);
            currentFunds = totalIncome - totalExpenses;
            totalFunds += currentFunds;

            System.out.println("**************************************************");
            System.out.println("\tIncome and Expenses Allocation");
            System.out.println("**************************************************");
            System.out.printf("Total funds left: PHP %.2f\n", currentFunds);
            System.out.println("**************************************************");
            System.out.println("Kindly choose one of the following: ");
            System.out.println("[1]. Income [2]. Expenses [3]. History Log [4]. Home");
            System.out.print("> ");

            int userFeatureChoice = getValidChoice(scanner, 1, 4);

            switch (userFeatureChoice) {
                case 1:
                    handleIncome(scanner, income, incomeCategories);
                    break;
                case 2:
                    handleExpenses(scanner, expense, income, expenseCategories);
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

    private static void handleIncome(Scanner scanner, LinkedList<Double> income, String[] incomeCategories) {
        double userIncomeSum = 0;
        String userInputIE;

        do {
            System.out.println("_________________________________");
            System.out.println("\t\t\tIncome");
            System.out.println("_______________________________");
            System.out.print("Categories: ");
            for (int i = 0; i < incomeCategories.length; i++) {
                System.out.print((i + 1) + ". " + incomeCategories[i] + "  ");
            }
            System.out.println();
            System.out.print("Pick a category (1-" + incomeCategories.length + "): ");
            int categoryChoice = getValidChoice(scanner, 1, incomeCategories.length);

            System.out.print("Enter amount for " + incomeCategories[categoryChoice - 1] + ": PHP ");
            double userIncome = getValidAmount(scanner);
            income.set(categoryChoice - 1, income.get(categoryChoice - 1) + userIncome);

            historyLog.add("Income: " + userIncome + " from " + incomeCategories[categoryChoice - 1]);
            System.out.print("Do you want to enter another income (y/n): ");
            userInputIE = scanner.next();
        } while (userInputIE.equalsIgnoreCase("y"));

        System.out.println("_________________________________");
        userIncomeSum = calculateTotal(income);
        printIncomeSummary(userIncomeSum, income, incomeCategories);
    }

    private static void handleExpenses(Scanner scanner, LinkedList<Double> expense, LinkedList<Double> income, String[] expenseCategories) {
        double userExpenseSum = 0;
        String userInputIE;

        do {
            System.out.println("_________________________________");
            System.out.println("\t\t\tExpenses");
            System.out.println("_______________________________");
            System.out.print("Categories: ");
            for (int i = 0; i < expenseCategories.length; i++) {
                System.out.print((i + 1) + ". " + expenseCategories[i] + "  ");
            }
            System.out.println();
            System.out.print("Pick a category (1-" + expenseCategories.length + "): ");
            int categoryChoice = getValidChoice(scanner, 1, expenseCategories.length);

            System.out.print("Enter amount for " + expenseCategories[categoryChoice - 1] + ": PHP ");
            double userExpense = getValidAmount(scanner);
            double totalIncome = calculateTotal(income);

            if (userExpense > totalIncome) {
                System.out.println("*********************************");
                System.out.println("Insufficient funds! Please add more income.");
                System.out.println("*********************************");
                break;
            }

            expense.set(categoryChoice - 1, expense.get(categoryChoice - 1) + userExpense);
            historyLog.add("Expense: " + userExpense + " for " + expenseCategories[categoryChoice - 1]);

            System.out.print("Do you want to enter another expense? (y/n): ");
            userInputIE = scanner.next();
        } while (userInputIE.equalsIgnoreCase("y"));

        System.out.println("_________________________________");
        userExpenseSum = calculateTotal(expense);
        printExpenseSummary(userExpenseSum, calculateTotal(income), expense, expenseCategories);
    }

    private static int getValidChoice(Scanner scanner, int min, int max) {
        int choice;
        while (true) {
            choice = scanner.nextInt();
            if (choice >= min && choice <= max) {
                break;
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
                if (amount >= 0) {
                    break;
                }
            } else {
                scanner.next(); 
            }
            System.out.print("Invalid input. Please enter a valid numerical value: PHP ");
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

    private static void printIncomeSummary(double totalIncome, LinkedList<Double> income, String[] incomeCategories) {
        for (int i = 0; i < incomeCategories.length; i++) {
            double percentage = (totalIncome == 0) ? 0 : (income.get(i) / totalIncome) * 100;
            System.out.printf(" %.2f%% \t| %s Income: PHP %.2f\n", percentage, incomeCategories[i], income.get(i));
        }
        System.out.printf("_________________________________\nTotal Income: PHP %.2f\n", totalIncome);
    }

    private static void printExpenseSummary(double totalExpenses, double totalIncome, LinkedList<Double> expense, String[] expenseCategories) {
        for (int i = 0; i < expenseCategories.length; i++) {
            double percentage = (totalExpenses == 0) ? 0 : (expense.get(i) / totalExpenses) * 100;
            System.out.printf(" %.2f%% \t| %s Expense: PHP %.2f\n", percentage, expenseCategories[i], expense.get(i));
        }
        System.out.printf("_________________________________\nTotal Expenses: PHP %.2f\n", totalExpenses);
        System.out.printf("Total Funds: PHP %.2f\n", totalIncome - totalExpenses);
    }

    private static void showHistoryLog() {
        System.out.println("History Log:");
        for (String entry : historyLog) {
            System.out.println(entry);
        }
        System.out.println("_________________________________");
    }

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
