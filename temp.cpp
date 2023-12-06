#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int userOption, userSignIn;
    int userFeatureChoice;
    string userRegisterEmail, userRegisterPassword, userEmail, userPassword;

    int userIncome, userExpense, categoryChoice;
    int userAllocationChoice;
    double userIncomeSum, userExpenseSum;
    userIncomeSum = 0;
    userExpenseSum = 0;
    double userIncomeSumPercentage, userExpenseSumPercentage;
    bool userFeatureChoiceBool = true;
    char userInputIE;

    const int INCOME_CATEGORIES = 5;
    double income[INCOME_CATEGORIES] = {0.0};

    string incomeCategories[INCOME_CATEGORIES] = {
        "Personal", "Business", "Gifts", "Loan", "Others"};

    const int EXPENSE_CATEGORIES = 5;
    double expense[EXPENSE_CATEGORIES] = {0.0};

    double emergencyFund = 0.0;

    string expenseCategories[EXPENSE_CATEGORIES] = {
        "Food & Drink", "Shopping & Groceries", "Transport", "Home", "Bills/Fees & others"};

    cout << "=============================================================" << endl;
    cout << "\t\tWelcome to Fiscal Harmony" << endl;
    cout << "=============================================================" << endl;
    cout << "Planning your future for a financially free life." << endl;
    cout << "[1]. Sign In [2]. Sign Up" << endl;
    cout << ">|";
    cin >> userOption;

    while (userOption != 1 && userOption != 2) {
        cout << "_________________________________" << endl;
        if (cin.fail() || (userOption != 1 && userOption != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number (1 or 2)." << endl;
            cout << ">|";
        }
        cin >> userOption;
    }

    switch (userOption) {
    case 1:
        cout << "_________________________________" << endl;
        cout << "You are now signing in..." << endl;
        cout << "Username: ";
        cin >> userEmail;
        cout << "Password: ";
        cin >> userPassword;
        cout << "_________________________________" << endl;

        if (userEmail != "admin" || userPassword != "password") {
            while (userEmail != "admin" || userPassword != "password") {
                cout << "Invalid password or username, please try again!" << endl;
                cout << "Username: ";
                cin >> userEmail;
                cout << "Password: ";
                cin >> userPassword;
                cout << "_________________________________" << endl;
            }
        }

        break;

    case 2:
        cout << "_________________________________" << endl;
        cout << "You are now creating an account" << endl;
        cout << "Username: ";
        cin >> userRegisterEmail;
        cout << "Password: ";
        cin >> userRegisterPassword;
        cout << "You have successfully created an account, would you like to sign in?" << endl;
        cout << "[1]. Yes [2]. No" << endl;
        cout << ">|";
        cin >> userSignIn;
        cout << "_________________________________" << endl;

        while (userSignIn != 1 && userSignIn != 2) {
            if (cin.fail() || (userSignIn != 1 && userSignIn != 2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number (1 or 2)." << endl;
                cout << ">|";
            }
            cin >> userSignIn;
            cout << "_________________________________" << endl;
        }

        if (userSignIn == 1) {
            cout << "Username: ";
            cin >> userEmail;
            cout << "Password: ";
            cin >> userPassword;
            cout << "_________________________________" << endl;
            if (userEmail != userRegisterEmail || userPassword != userRegisterPassword) {
                while (userEmail != userRegisterEmail || userPassword != userRegisterPassword) {
                    cout << endl;
                    cout << "You have entered the wrong username or password, please try again!" << endl;
                    cout << "Username: ";
                    cin >> userEmail;
                    cout << "Password: ";
                    cin >> userPassword;
                    cout << "_________________________________" << endl;
                }
            }
        } else if (userSignIn == 2) {
            cout << "Have a great day ahead!";
            exit(0);
        } else {
            cout << "Invalid input";
        }
    }

    do {
        cout << "Welcome, " << userEmail << " I hope you have a great time!" << endl;
        cout << "Here are our current available features, check them out!:" << endl;
        cout << "[1]. Income and Expense Allocation" << endl;
        cout << "[2]. Emergency Fund Calculator" << endl;
        cout << "[3]. Annual Income Taxed Calculator" << endl;
        cout << "[4]. Log out" << endl;

        cout << ">|";
        cin >> userFeatureChoice;

        userFeatureChoiceBool = true;

          while (userFeatureChoice != 1 && userFeatureChoice != 2 && userFeatureChoice != 3 && userFeatureChoice != 4) {
            cout << "Invalid input. Please enter a valid number (1, 2, 3, or 4)." << endl;
            cout << ">|";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> userFeatureChoice;
        }

        switch (userFeatureChoice) {
        case 1:
            cout << "=============================================================" << endl;
            cout << "\t\tIncome and Expenses Allocation" << endl;
            cout << "=============================================================" << endl;
            cout << "Kindly choose one of the following: " << endl;
            cout << "[1]. Income [2]. Expenses [3]. Exit" << endl;
            cout << "<|";
            cin >> userAllocationChoice;

            while (userAllocationChoice != 1 && userAllocationChoice != 2 && userAllocationChoice != 3) {
                cout << "_________________________________" << endl;
                if (cin.fail() || (userAllocationChoice != 1 && userAllocationChoice != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid number: " << endl;
                    cout << ">|";
                }
                cin >> userAllocationChoice;
            }

            switch (userAllocationChoice) {
            case 1:
                do {
                    userIncomeSum = 0;
                    userIncomeSumPercentage = 0;

                    cout << "_________________________________" << endl;
                    cout << "\t\t\tIncome" << endl;

                    cout << "___________________ __ __ __ _ _ _ _" << endl;
                    cout << "Categories: ";

                    for (int i = 0; i < INCOME_CATEGORIES; ++i) {
                        cout << i + 1 << ". " << incomeCategories[i] << "  ";
                    }

                    cout << endl;
                    cout << "Pick a category (1-" << INCOME_CATEGORIES << "): ";
                    cin >> categoryChoice;

                    if (categoryChoice < 1 || categoryChoice > INCOME_CATEGORIES) {
                        cout << "Invalid category choice. Please try again." << endl;
                        continue;
                    }

                    cout << "Enter amount for " << incomeCategories[categoryChoice - 1] << ": ₱";
                    cin >> userIncome;

                    if (categoryChoice == 0) {
                        userIncomeSum += userIncome;
                    } else {
                        income[categoryChoice - 1] += userIncome;
                    }

                    cout << "Do you want to enter another income (y/n): ";
                    cin >> userInputIE;
                } while (userInputIE == 'y' || userInputIE == 'Y');

                cout << "_________________________________" << endl;

                for (int i = 0; i < INCOME_CATEGORIES; ++i) {
                    userIncomeSum += income[i];
                }

                for (int i = 0; i < INCOME_CATEGORIES - 1; ++i) {
                    userIncomeSumPercentage = round(((income[i] / userIncomeSum) * 100));
                    cout << " " << userIncomeSumPercentage << "% "
                         << "\t| " << incomeCategories[i] << " Income: ₱" << income[i] << endl;
                }

                userIncomeSum += income[INCOME_CATEGORIES - 1];
                userIncomeSumPercentage = round(((income[INCOME_CATEGORIES - 1] / userIncomeSum) * 100));
                cout << " " << userIncomeSumPercentage << "% \t| "
                     << "Others Income: ₱" << income[INCOME_CATEGORIES - 1] << endl;
                cout << "_________________________________" << endl;
                cout << "Total Income: ₱" << userIncomeSum << endl;
                cout << "_________________________________" << endl;
                break;

            case 2:

                do {
                    userExpenseSum = 0;
                    userExpenseSumPercentage = 0;

                    cout << "_________________________________" << endl;
                    cout << "\t\t\tExpenses" << endl;

                    cout << "___________________ __ __ __ _ _ _" << endl;
                    cout << "Categories: ";

                    for (int i = 0; i < EXPENSE_CATEGORIES; ++i) {
                        cout << i + 1 << ". " << expenseCategories[i] << "  ";
                    }

                    cout << endl;
                    cout << "Pick a category (1-" << EXPENSE_CATEGORIES << "): ";
                    cin >> categoryChoice;

                    if (categoryChoice < 1 || categoryChoice > EXPENSE_CATEGORIES) {
                        cout << "Invalid category choice. Please try again." << endl;
                        continue;
                    }

                    cout << "Enter amount for " << expenseCategories[categoryChoice - 1] << ": ₱";
                    cin >> userExpense;

                    if (userExpense > userIncomeSum) {
                        cout << " " << endl;
                        cout << "*********************************" << endl;
                        cout << "Insufficient funds! Please add more income." << endl;
                        cout << "*********************************" << endl;
                        break;
                    }

                    if (categoryChoice == 0) {
                        userExpenseSum += userExpense;
                    } else {
                        expense[categoryChoice - 1] += userExpense;
                    }

                    cout << "Do you want to enter another expense? (y/n): ";
                    cin >> userInputIE;

                } while (userInputIE == 'y' || userInputIE == 'Y');

                cout << "_________________________________" << endl;

                for (int i = 0; i < EXPENSE_CATEGORIES; ++i) {
                    userExpenseSum += expense[i];
                }

                for (int i = 0; i < EXPENSE_CATEGORIES - 1; ++i) {

                    userExpenseSumPercentage = round(((expense[i] / userExpenseSum) * 100));
                    cout << " " << userExpenseSumPercentage << "% "
                         << "\t| " << expenseCategories[i] << " Expense: ₱" << expense[i] << endl;
                }

                userExpenseSum += expense[EXPENSE_CATEGORIES - 1];
                userExpenseSumPercentage = round(((expense[EXPENSE_CATEGORIES - 1] / userExpenseSum) * 100));

                cout << " " << userExpenseSumPercentage << "% \t| "
                     << "Bills/Fees & others: ₱" << expense[EXPENSE_CATEGORIES - 1] << endl;

                cout << "_________________________________" << endl;
                cout << "Total Expenses: ₱" << userExpenseSum << endl;
                cout << "Total Funds: ₱" << userIncomeSum - userExpenseSum << endl;
                cout << "_________________________________" << endl;
                break;

            case 3:
                userFeatureChoiceBool = false;
                cout << "_________________________________" << endl;
                break;
            }
        
            break;
        
            case 2:
    cout << "=============================================================" << endl;
    cout << "\t\tYour Trusty Emergency Fund Calculator" << endl;
    cout << "=============================================================" << endl;
    double totalExpensesPerMonth;
    int numberOfMonths;

    cout << "Enter your total monthly expenses: PHP ";
    cin >> totalExpensesPerMonth;

    cout << "Enter the number of months you want to cover: ";
    cin >> numberOfMonths;

    emergencyFund = totalExpensesPerMonth * numberOfMonths + 50;

    cout << "\nYour recommended emergency fund is: PHP " << emergencyFund << endl;

    char backOrLogOut3;
    cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
    cout << "> ";
    cin >> backOrLogOut3;

    if (backOrLogOut3 == '1') {
        continue;
    } else if (backOrLogOut3 == '2') {

        userFeatureChoiceBool = false;
    } else {
        cout << "Invalid input. Exiting." << endl;
        userFeatureChoiceBool = false;
    }
    break;

case 3:
            cout << "=============================================================" << endl;
            cout << "\t\tAnnual Income Taxed Calculator " << endl;
            cout << "=============================================================" << endl;
    double monthly_income;
    double annual;
    double final;
    double tax;
    double excess;
    double taxed_income;
    double addon;

    cout << "Do you want to compute your funds? " << endl;
    cout << "[1]. Yes [2]. No " << endl;
    cout << "> ";
    cin >> userOption;
    cout << "\n";

    while (userOption != 1 && userOption != 2) {
        cout << "_________________________________" << endl;
        if (cin.fail() || (userOption != 1 && userOption != 2)) {
            // Invalid input, clear the error state and discard the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // They need to input a valid number which is only 1 and 2, rather than 3 to ∞ or 0 to -∞, also invalid alphabetical letters
            cout << "Invalid input. Please enter a valid number (1, 2, or 3)." << endl;
            cout << "> ";
        }
        cin >> userOption;
        cout << "\n";
    }
        

    switch (userOption) {
        case 2:
            cout << "Signing out " << endl;
            exit(0);
        case 1:
    cout << "===========================" << endl;
    cout << "Enter your salary: ";
    cin >> monthly_income;
    cout << "===========================" << endl;
    cout << "\n";

    annual = monthly_income * 12;

    if (annual <= 250000) {
        final = annual / 12;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income did not exceed PHP250,000"<< endl; 
        cout << "\tand you are in the 0% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 0%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||No Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << final << endl;
        cout << "\t||TOTAL: " << final << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;

        char backOrLogOut2;
            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;

        while (backOrLogOut2 != '1' && backOrLogOut2 != '2') {
            cout << "Invalid input. Please enter either 1 or 2." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;
        }

        if (backOrLogOut2 == '1') {
            continue;
        } else if (backOrLogOut2 == '2') {
            userFeatureChoiceBool = false;
            exit(0);
        }
    } else {
        if (annual <= 400000) {
            tax = 0.15;
            excess = annual - 250000;
            final = (excess * tax) / 12;
            taxed_income = final / 12;
            addon = monthly_income - taxed_income;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income did not exceed PHP400,000"<< endl; 
        cout << "\tand you are in the 15% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 15%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << taxed_income << endl;
        cout << "\t||TOTAL: " << taxed_income << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
        char backOrLogOut2;
            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;

        while (backOrLogOut2 != '1' && backOrLogOut2 != '2') {
            cout << "Invalid input. Please enter either 1 or 2." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;
        }

        if (backOrLogOut2 == '1') {
            continue;
        } else if (backOrLogOut2 == '2') {
            userFeatureChoiceBool = false;
            exit(0);
        }
    } else if (annual <= 800000) {
            tax = 0.2;
            excess = annual - 400000;
            final = (excess * tax) + 22500;
            taxed_income = final / 12;
            addon = monthly_income - taxed_income;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income did not exceed PHP800,000"<< endl; 
        cout << "\tand you are in the 2% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 2%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << addon << endl;
        cout << "\t||TOTAL: " << addon << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
        char backOrLogOut2;
            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;

        while (backOrLogOut2 != '1' && backOrLogOut2 != '2') {
            cout << "Invalid input. Please enter either 1 or 2." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;
        }

        if (backOrLogOut2 == '1') {
            continue;
        } else if (backOrLogOut2 == '2') {
            userFeatureChoiceBool = false;
            exit(0);
        }
    } else if (annual <= 2000000) {
            tax = 0.25;
            excess = annual - 800000;
            final = (excess * tax) + 102500;
            taxed_income = final / 12;
            addon = monthly_income - taxed_income;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income did not exceed PHP2,000,000"<< endl; 
        cout << "\tand you are in the 25% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 25%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << addon << endl;
        cout << "\t||TOTAL: " << addon << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
        char backOrLogOut2;
            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;

        while (backOrLogOut2 != '1' && backOrLogOut2 != '2') {
            cout << "Invalid input. Please enter either 1 or 2." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;
        }

        if (backOrLogOut2 == '1') {
            continue;
        } else if (backOrLogOut2 == '2') {
            userFeatureChoiceBool = false;
            exit(0);
        }
    } else if (annual <= 8000000) {
            tax = 0.3;
            excess = annual - 2000000;
            final = (excess * tax) + 402500;
            taxed_income = final / 12;
            addon = monthly_income - taxed_income;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income did not exceed PHP8,000,000"<< endl; 
        cout << "\tand you are in the 3% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 3%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << addon << endl;
        cout << "\t||TOTAL: " << addon << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;

        char backOrLogOut2;
            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;

        while (backOrLogOut2 != '1' && backOrLogOut2 != '2') {
            cout << "Invalid input. Please enter either 1 or 2." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;
        }

        if (backOrLogOut2 == '1') {
            continue;
        } else if (backOrLogOut2 == '2') {
            userFeatureChoiceBool = false;
            exit(0);
        }
    } else {
            tax = 0.35;
            excess = annual - 8000000;  
            final = (excess * tax) + 2202500;
            taxed_income = final / 12;
            addon = monthly_income - taxed_income;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income exceed PHP8,000,000"<< endl; 
        cout << "\tand you are in the 35% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 35%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << addon << endl;
        cout << "\t||TOTAL: " << addon << endl;;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
        }
        char backOrLogOut2;
            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;

        while (backOrLogOut2 != '1' && backOrLogOut2 != '2') {
            cout << "Invalid input. Please enter either 1 or 2." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
            cout << "> ";
            cin >> backOrLogOut2;
        }

        if (backOrLogOut2 == '1') {
            continue;
        } else if (backOrLogOut2 == '2') {
            userFeatureChoiceBool = false;
            exit(0);
        }
            break;
        }
            }
    
break;
case 4:
    int userLogOut;

    cout << "*********************************" << endl;
    cout << "Do you want to log out?" << endl;
    cout << "[1]. Yes [2]. No" << endl;
    cout << ">| ";
    cin >> userLogOut;

    while (userLogOut != 1 && userLogOut != 2) {
        cout << "*********************************" << endl;
        if (cin.fail() || (userLogOut != 1 && userLogOut != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: " << endl;
            cout << ">|";
        }
        cin >> userLogOut;
    }

    if (userLogOut == 1) {
        // Log out the user and exit the loop
        cout << "Have a great day ahead! " << userEmail << endl;
        cout << "*********************************" << endl;
        return 0;
    }
        
    // User chose not to log out, continue to the next iteration of the loop
    break;
    }
        } while (userFeatureChoiceBool);

return 0;
} 
