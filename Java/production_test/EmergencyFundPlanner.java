package production_test;

import java.util.InputMismatchException;
import java.util.Scanner;

public class EmergencyFundPlanner {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        runSavingsPlanner(scanner);
    }

    public static void runSavingsPlanner(Scanner scanner) {
        double currentFunds = 1000.00; 

        while (true) {
            System.out.println("\t\t\t+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+");
            System.out.println("\t\t\t                 Emergency Fund Planner");
            System.out.println("\t\t\t+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+");
            System.out.println("\t\t\t        Current Savings today: PHP " + currentFunds);
                System.out.println("\t\t\t+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+");

            double recommendedMonths = 6;
            double emergencyFundGoal = currentFunds * recommendedMonths;

            System.out.printf("\n\t\t\tYou must have a total of PHP %.2f \n\t\t\tsaved in the next few months to ensure financial security.%n",
                    emergencyFundGoal);

            double waterBill = emergencyFundGoal * 0.1; 
            double electricityBill = emergencyFundGoal * 0.2; 
            double foodExpenses = emergencyFundGoal * 0.4; 
            double otherExpenses = emergencyFundGoal * 0.3; 
        
            System.out.println("\n\t\t\tSuggested Segmentation:");
            System.out.printf("\t\t\tWater Bill: PHP %.2f%n", waterBill);
            System.out.printf("\t\t\tElectricity Bill: PHP %.2f%n", electricityBill);
            System.out.printf("\t\t\tFood Expenses: PHP %.2f%n", foodExpenses);
            System.out.printf("\t\t\tOther Expenses: PHP %.2f%n", otherExpenses);

            System.out.println("\t\t\t=============================================================");
            System.out.println("\t\t\t[1] How much emergency fund do I need?");
            System.out.println("\t\t\t[2] Back to Home");
            System.out.println("\t\t\t[3] Exit Savings Fund");
            System.out.print("\t\t\tChoose an option: ");

            int userChoice = getValidChoice(scanner);

            switch (userChoice) {
                case 1 -> calculateEmergencyFundWithSuggestions(scanner);
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

    public static void calculateEmergencyFundWithSuggestions(Scanner scanner) {
        System.out.println("\t\t\t=============================================================");
        System.out.print("\t\t\tEnter your average monthly expenses (PHP): ");
        double monthlyExpenses = getValidDouble(scanner);

        System.out.print("\t\t\tEnter the number of months you want to save for: ");
        int months = getValidInt(scanner);

        double totalEmergencyFund = monthlyExpenses * months;

        System.out.printf("\n\t\t\tYou need a total of PHP %.2f saved for %d months of financial security.%n",
                totalEmergencyFund, months);


        double waterBill = monthlyExpenses * 0.1; 
        double electricityBill = monthlyExpenses * 0.2; 
        double foodExpenses = monthlyExpenses * 0.4; 
        double otherExpenses = monthlyExpenses * 0.3; 

        System.out.println("\n\t\t\tSuggested Segmentation:");
        System.out.printf("\t\t\tWater Bill: PHP %.2f%n", waterBill * months);
        System.out.printf("\t\t\tElectricity Bill: PHP %.2f%n", electricityBill * months);
        System.out.printf("\t\t\tFood Expenses: PHP %.2f%n", foodExpenses * months);
        System.out.printf("\t\t\tOther Expenses: PHP %.2f%n", otherExpenses * months);

        System.out.println("\t\t\t=============================================================");
        System.out.println("\t\t\tReturning to Emergency Fund Planner...");
    }

    private static int getValidChoice(Scanner scanner) {
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

    private static double getValidDouble(Scanner scanner) {
        while (true) {
            try {
                return scanner.nextDouble();
            } catch (InputMismatchException e) {
                System.out.println("\t\t\tInvalid input. Please enter a valid number.");
                scanner.next(); 
            }
        }
    }

    private static int getValidInt(Scanner scanner) {
        while (true) {
            try {
                return scanner.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("\t\t\tInvalid input. Please enter a valid number.");
                scanner.next(); 
            }
        }
    }
}
