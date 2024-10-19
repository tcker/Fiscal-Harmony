import java.util.*;

public class IncomeExpensesAllocation {
    private static final int INCOME_CATEGORIES = 5;
    private static final int EXPENSE_CATEGORIES = 5;
    
    private static String[] incomeCategories = {
        "Personal", "Business", "Gifts", "Loan", "Others"
    };
    
    private static String[] expenseCategories = {
        "Food & Drink", "Shopping & Groceries", "Transport", "Home", "Bills/Fees & others"
    };
    
    private static double[] income = new double[INCOME_CATEGORIES];
    private static double[] expense = new double[EXPENSE_CATEGORIES];
    private static ArrayList<String> historyLog = new ArrayList<>();
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean goBackToFeature = true;
        
        while (goBackToFeature) {
            System.out.println("**************************************************");
            System.out.println("\tIncome and Expenses Allocation");
            System.out.println("**************************************************");
            System.out.println("Kindly choose one of the following: ");
            System.out.println("[1]. Income [2]. Expenses [3]. History Log [4]. Main Menu");
            System.out.print("> ");
            
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
                    goBackToFeature = false;
                    break;
            }
        }
        
        scanner.close();
    }
    
    private static void handleIncome(Scanner scanner) {
        double userIncomeSum = 0;
        String userInputIE;

        do {
            System.out.println("_________________________________");
            System.out.println("\t\t\tIncome");
            System.out.println("_______________________________");
            System.out.print("Categories: ");
            for (int i = 0; i < INCOME_CATEGORIES; i++) {
                System.out.print((i + 1) + ". " + incomeCategories[i] + "  ");
            }
            System.out.println();
            System.out.print("Pick a category (1-" + INCOME_CATEGORIES + "): ");
            int categoryChoice = getValidChoice(scanner, 1, INCOME_CATEGORIES);

            System.out.print("Enter amount for " + incomeCategories[categoryChoice - 1] + ": PHP ");
            double userIncome = getValidAmount(scanner);
            income[categoryChoice - 1] += userIncome;

            historyLog.add("Income: " + userIncome + " from " + incomeCategories[categoryChoice - 1]);
            System.out.print("Do you want to enter another income (y/n): ");
            userInputIE = scanner.next();
        } while (userInputIE.equalsIgnoreCase("y"));

        System.out.println("_________________________________");
        userIncomeSum = calculateTotal(income);
        printIncomeSummary(userIncomeSum);
    }
    
    private static void handleExpenses(Scanner scanner) {
        double userExpenseSum = 0;
        String userInputIE;

        do {
            System.out.println("_________________________________");
            System.out.println("\t\t\tExpenses");
            System.out.println("_______________________________");
            System.out.print("Categories: ");
            for (int i = 0; i < EXPENSE_CATEGORIES; i++) {
                System.out.print((i + 1) + ". " + expenseCategories[i] + "  ");
            }
            System.out.println();
            System.out.print("Pick a category (1-" + EXPENSE_CATEGORIES + "): ");
            int categoryChoice = getValidChoice(scanner, 1, EXPENSE_CATEGORIES);

            System.out.print("Enter amount for " + expenseCategories[categoryChoice - 1] + ": PHP ");
            double userExpense = getValidAmount(scanner);
            double totalIncome = calculateTotal(income);

            if (userExpense > totalIncome) {
                System.out.println("*********************************");
                System.out.println("Insufficient funds! Please add more income.");
                System.out.println("*********************************");
                break;
            }

            expense[categoryChoice - 1] += userExpense;
            historyLog.add("Expense: " + userExpense + " for " + expenseCategories[categoryChoice - 1]);

            System.out.print("Do you want to enter another expense? (y/n): ");
            userInputIE = scanner.next();
        } while (userInputIE.equalsIgnoreCase("y"));

        System.out.println("_________________________________");
        userExpenseSum = calculateTotal(expense);
        printExpenseSummary(userExpenseSum, calculateTotal(income));
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
                scanner.next(); // Clear invalid input
            }
            System.out.print("Invalid input. Please enter a valid numerical value: PHP ");
        }
        return amount;
    }

    private static double calculateTotal(double[] array) {
        double total = 0;
        for (double value : array) {
            total += value;
        }
        return total;
    }

    private static void printIncomeSummary(double totalIncome) {
        for (int i = 0; i < INCOME_CATEGORIES; i++) {
            double percentage = (income[i] / totalIncome) * 100;
            System.out.printf(" %.2f%% \t| %s Income: PHP %.2f\n", percentage, incomeCategories[i], income[i]);
        }
        System.out.printf("_________________________________\nTotal Income: PHP %.2f\n", totalIncome);
    }

    private static void printExpenseSummary(double totalExpenses, double totalIncome) {
        for (int i = 0; i < EXPENSE_CATEGORIES; i++) {
            double percentage = (expense[i] / totalExpenses) * 100;
            System.out.printf(" %.2f%% \t| %s Expense: PHP %.2f\n", percentage, expenseCategories[i], expense[i]);
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
}
