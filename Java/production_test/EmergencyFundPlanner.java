package production_test;

import java.util.InputMismatchException;
import java.util.Scanner;

public class EmergencyFundPlanner {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        runSavingsPlanner(scanner);
    }

    private static void runSavingsPlanner(Scanner scanner) {

        while (true) { // Loop to return to the menu after completing calculations
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
                case 1 -> calculateEmergencyFund(scanner); // After calculation, return to menu
                case 2 -> {
                    System.out.println("\t\t\tReturning to Home...");
                    return; // Exits the method, simulating "Back to Home"
                }
                case 3 -> {
                    System.out.println("\t\t\tExiting Program... Goodbye!");
                    System.exit(0); // Immediately exits the program
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
