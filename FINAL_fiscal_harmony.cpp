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

    int signInAttempts = 0;
    bool goBackToSignUp = true;

// =================== LOGIN TERMINAL ================================

    while (goBackToSignUp) {
        cout << "=============================================================" << endl;
        cout << "\t\tWelcome to Fiscal Harmony" << endl;
        cout << "=============================================================" << endl;
        cout << "Planning your future for a financially free life." << endl;
        cout << "[1]. Sign In [2]. Sign Up" << endl;
        cout << "> ";
        cin >> userOption;
        

        while (userOption != 1 && userOption != 2) {
            cout << "_________________________________" << endl;
            if (cin.fail() || (userOption != 1 && userOption != 2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number (1 or 2)." << endl;
                cout << "> ";
            }
            cin >> userOption;
        }

        switch (userOption) {
            case 1:
                cout << "_________________________________" << endl;
                cout << "You are now signing in..." << endl;

                do {
                    cout << "Username: ";
                    cin >> userEmail;
                    cout << "Password: ";
                    cin >> userPassword;
                    cout << "_________________________________" << endl;

                    if (userEmail != "admin" || userPassword != "password") {
                        signInAttempts++;
                        cout << "Invalid password or username, please try again!" << endl;
                    }
                } while ((userEmail != "admin" || userPassword != "password") && signInAttempts < 2);

                if (signInAttempts == 2) {
                    cout << "You have reached the maximum number of sign-in attempts." << endl;
                    cout << "=======================================================" << endl;
                    cout << "[1]. Go back to Sign-up Terminal [2]. Exit" << endl;
                    cout << "> ";
                    cin >> userOption;

                    while (userOption != 1 && userOption != 2) {
                    cout << "_________________________________" << endl;
                    if (cin.fail() || (userOption != 1 && userOption != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid number (1 or 2)." << endl;
                    cout << "> ";
                        }
                    cin >> userOption;
                    }

                    if (userOption == 1) {
                        signInAttempts = 0;
                        goBackToSignUp = true;
                        continue;
                    } else {
                        cout << "Have a great day ahead!";
                        exit(0);
                    }
                } else {
                    goBackToSignUp = false;
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
        cout << "> ";
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

// ============================= MAIN MENU | FEATURES TERMINAL ==============================

    do {
        cout << "================================================================" << endl;
        cout << "Welcome, " << userEmail << " I hope you have a great time!" << endl;
        cout << "Here are our current available features, check them out!:" << endl;
        cout << "[1]. Income and Expense Allocation" << endl;
        cout << "[2]. Emergency Fund Calculator" << endl;
        cout << "[3]. Salary Calculator" << endl;
        cout << "[4]. Log out" << endl;
        cout << "================================================================" << endl;
        cout << "> ";
        cin >> userFeatureChoice;
        cout << "\n";

        userFeatureChoiceBool = true;   

          while (userFeatureChoice != 1 && userFeatureChoice != 2 && userFeatureChoice != 3 && userFeatureChoice != 4) {
            cout << "Invalid input. Please enter a valid number (1, 2, 3, or 4)." << endl;
            cout << ">|";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> userFeatureChoice;
        }

// =============================[1] INCOME AND EXPENSES ALLOCATION ==============================

        switch (userFeatureChoice) {
        case 1:
            cout << "**************************************************" << endl;
            cout << "\tIncome and Expenses Allocation" << endl;
            cout << "**************************************************" << endl;
            cout << "Kindly choose one of the following: " << endl;
            cout << "[1]. Income [2]. Expenses [3]. Exit" << endl;
            cout << "> ";
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

                    while (cin.fail() || categoryChoice < 1 || categoryChoice > INCOME_CATEGORIES) {
                    cout << "Invalid input. Please enter a valid number (1-" << INCOME_CATEGORIES << "): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> categoryChoice;
                    }

                    cout << "Enter amount for " << incomeCategories[categoryChoice - 1] << ": PHP ";

                    while (!(cin >> userIncome) || userIncome < 0) {
                    cout << "Invalid input. Please enter a valid numerical value: PHP ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

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
                         << "\t| " << incomeCategories[i] << " Income: PHP " << fixed << setprecision(2) << income[i] << endl;
                }

                userIncomeSum += income[INCOME_CATEGORIES - 1];
                userIncomeSumPercentage = round(((income[INCOME_CATEGORIES - 1] / userIncomeSum) * 100));
                cout << fixed << setprecision(2) << " " << userIncomeSumPercentage << "% \t| "
                     << "Others Income: PHP " << income[INCOME_CATEGORIES - 1] << endl;
                cout << "_________________________________" << endl;
                cout << fixed << setprecision(2) << "Total Income: PHP " << userIncomeSum << endl;
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

                    while (cin.fail() || categoryChoice < 1 || categoryChoice > EXPENSE_CATEGORIES) {
                    cout << "Invalid input. Please enter a valid number (1-" << EXPENSE_CATEGORIES << "): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> categoryChoice;
                    }

                    cout << "Enter amount for " << expenseCategories[categoryChoice - 1] << ": PHP ";
                    

                    while (!(cin >> userExpense) || userExpense < 0) {
                    cout << "Invalid input. Please enter a valid numerical value: PHP ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

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
                    cout << fixed << setprecision(2) << " " << userExpenseSumPercentage << "% "
                         << "\t| " << expenseCategories[i] << " Expense: PHP " << fixed << setprecision(2) << expense[i] << endl;
                }

                userExpenseSum += expense[EXPENSE_CATEGORIES - 1];
                userExpenseSumPercentage = round(((expense[EXPENSE_CATEGORIES - 1] / userExpenseSum) * 100));

                cout << " " << userExpenseSumPercentage << "% \t| "
                     << "Bills/Fees & others: PHP " << expense[EXPENSE_CATEGORIES - 1] << endl;

                cout << "_________________________________" << endl;
                cout << fixed << setprecision(2) << "Total Expenses: PHP " << userExpenseSum << endl;
                cout << fixed << setprecision(2) << "Total Funds: PHP " << userIncomeSum - userExpenseSum << endl;
                cout << "_________________________________" << endl;
                break;

            case 3:
                cout << "_________________________________" << endl;
                break;
            }
        
            break;
            
// ============================= [2] EMERGENCY FUND CALCULATOR  ==============================

    case 2:
    cout << "+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+" << endl;
    cout << "\tYour Trusty Emergency Fund Calculator" << endl;
    cout << "\t\tNon negative Values only" << endl;
    cout << "+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+-x=+" << endl;
    double totalExpensesPerMonth;
    int numberOfMonths;

    cout << "Enter your total monthly expenses: PHP ";

    while (!(cin >> totalExpensesPerMonth)) {
    cout << "Invalid input. Please enter a numerical value: PHP ";
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    cout << "Enter the number of months you want to cover: ";

    while (!(cin >> numberOfMonths)) {
    cout << "Invalid input. Please enter a numerical value: ";
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    cout << "You entered: " << numberOfMonths << " months \n";

    emergencyFund = totalExpensesPerMonth * numberOfMonths + 50;

    cout << fixed << setprecision(2) << "\nYour recommended emergency fund is: PHP " << emergencyFund << endl;

    char backOrLogOut3;
    cout << "=============================================================" << endl;
    cout << "Do you want to go back to the main menu (1) or log out (2)? " << endl;
    cout << "> ";

    while (!(cin >> backOrLogOut3) || (backOrLogOut3 != '1' && backOrLogOut3 != '2')) {
    cout << "Invalid input. Please enter 1 or 2: ";
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    if (backOrLogOut3 == '1') {
        continue;
    } else if (backOrLogOut3 == '2') {
        userFeatureChoiceBool = false;
    } 
    break;
    
// ============================= [3] SALARY CALCULATOR  =================================

case 3:
    cout << "=========tX==========sSs=================gSis============pHealth==========" << endl;
    cout << "\t\t\tSALARY CALCULATOR " << endl;
    cout << "=========tX==========sSs=================gSis============pHealth==========" << endl;
    cout << "MUST READ! - You must finish the feature first before you go back" << endl;
    cout << "\t\tTo the main Menu after you click [1] YES" << endl;
    cout << "=========tX==========sSs=================gSis============pHealth==========" << endl;

// ===============================   TAX DEDUCTOR   =================================

    double monthly_income;
    double annual;
    double final;
    double tax;
    double excess;
    double taxed_income;
    double addon;
    int userOption;

    cout << "Do you want to compute your funds? " << endl;
    cout << "[1]. YES, [2]. MAIN MENU " << endl;
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
            cout << "Invalid input. Please enter a valid number (1, 2)." << endl;
            cout << "> ";
        }
        cin >> userOption;
        cout << "\n";
    }
        

    switch (userOption) {
        case 2:
            break;
        case 1:
    while (true) {
        cout << "===========================" << endl;
        cout << "Enter your salary: ";

  
        if (cin >> monthly_income) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a numeric value." << endl;
        }
    }
    cout << "\nYou entered: " << monthly_income << endl;
    cout << "===========================\n" << endl;


annual = monthly_income * 12;
if (annual<=250000){
	
	final = annual / 12;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tTAX\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\tYour monthly income did not exceed PHP250,000"<< endl; 
        cout << "\tand you are in the 0% tax bracket." << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||Tax Bracket: 0%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||No Tax Deduction: " << final << endl;
        cout << fixed << setprecision(2) << "\t||Your salary with tax deducted is: " << final << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: "  << final << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
}
else if (annual<=400000){
	tax = 0.15;
	excess = annual - 250000;
	 final = (excess * tax)/12;
	taxed_income= monthly_income - final;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tTAX\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\tYour monthly income did not exceed PHP400,000"<< endl; 
        cout << "\tand you are in the 15% tax bracket." << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||Tax Bracket: 15%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << fixed << setprecision(2) << "\t||Your salary with tax deducted is: " << taxed_income << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << taxed_income << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
}
else if (annual<=800000){
	tax = 0.2;
	excess = annual - 400000;
	 final = (excess *tax)+ 22500;
	 taxed_income = final / 12;
	 addon = monthly_income - taxed_income;

        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tTAX\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\tYour monthly income did not exceed PHP800,000"<< endl; 
        cout << "\tand you are in the 20% tax bracket." << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||Tax Bracket: 2%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << fixed << setprecision(2) << "\t||Your salary with tax deducted is: " << addon << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << addon << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
}

else if (annual<=2000000){
	tax = 0.25;
	excess = annual - 800000;
 final = (excess *tax)+ 102500;
	 taxed_income = final / 12;
	addon = monthly_income - taxed_income;

        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tTAX\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\tYour monthly income did not exceed PHP800,000"<< endl; 
        cout << "\tand you are in the 25% tax bracket." << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||Tax Bracket: 2%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << fixed << setprecision(2) << "\t||Your salary with tax deducted is: " << addon << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << addon << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
}

else if (annual<=800000){
	tax = 0.3;
	excess = annual - 2000000;
 final = (excess *tax)+ 402500;
	 taxed_income = final / 12;
	addon = monthly_income - taxed_income;

        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tTAX\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\tYour monthly income did not exceed PHP800,000"<< endl; 
        cout << "\tand you are in the 30% tax bracket." << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||Tax Bracket: 2%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << fixed << setprecision(2) << "\t||Your salary with tax deducted is: " << addon << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << addon << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
}
else{
	tax = 0.35;
	excess = annual - 8000000;
 final = (excess *tax)+ 2202500;
	 taxed_income = final / 12;
	 addon = monthly_income - taxed_income;

        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tTAX\t\t\t\t||" << endl;
        cout << "\t==================================================" << endl;
        cout << "\tYour monthly income did not exceed PHP800,000"<< endl; 
        cout << "\tand you are in the 35% tax bracket." << endl;
        cout << "\t==================================================" << endl;
        cout << "\t||Tax Bracket: 2%" << endl;
        cout << fixed << setprecision(2) << "\t||Your annual income is; " << annual << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << fixed << setprecision(2) << "\t||Your salary with tax deducted is: " << addon << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << addon << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
}

// ===============================   SSS CONTRIBUTIONS   =================================

int sss;
int member;
double msc;
double mpf;
double ec;
double cr = 0.14;
double tmc;
double final_sss;

    cout << "=============================================================" << endl;
    cout << "\t\t| SSS CONTRIBUTIONS| " << endl;
    cout << "=============================================================" << endl;
    cout << "Do you want to compute your SSS contribution? [1] YES, [2] NO" << endl;
    cout << "> ";

    // Input validation loop for sss choice
    do {
        cin >> sss;
        cout << "\n";
        // Check if input is not an integer or is not 1 or 2
        if (cin.fail() || (sss != 1 && sss != 2)) {
            cin.clear();                                           // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter [1] for YES or [2] for NO: ";
        }
    } while (sss != 1 && sss != 2);

    cout << "_______________________________________________" << endl;

    if (sss == 1) {
        cout << "What kind of member are you? [1] HOUSEHOLD, [2] EMPLOYEE " << endl;
        cout << "> ";

        // Input validation loop for member choice
        do {
            cin >> member;
            cout << "\n";

            // Check if input is not an integer or is not 1 or 2
            if (cin.fail() || (member != 1 && member != 2)) {
                cin.clear();                                           // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid input. Please enter [1] for HOUSEHOLD or [2] for EMPLOYEE: ";
            }
        } while (member != 1 && member != 2);

// ===============================   IF HOUSEHOLD SSS   =================================

	if(member == 1){
        if(monthly_income<=5000){
            cout << "==============================" << endl;
            cout << "This was paid by your employer." << endl;
            cout << "==============================" << endl;
        }
            
else if (monthly_income <=5249.99){
            msc = 5000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t===============================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        } else if (monthly_income <=5749.99){
            msc = 5500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=6249.99){
            msc = 6000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=6749.99){
            msc = 6500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=7249.99){
            msc = 7000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=7749.99){
            msc = 7500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=8249.99){
            msc = 8000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=8749.99){
            msc = 8500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=9249.99){
            msc = 9000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final- tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=9749.99){
            msc = 9500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=10249.99){
            msc = 10000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=10749.99){
            msc = 10500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=11249.99){
            msc = 11000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=11749.99){
            msc = 11500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=12249.99){
            msc = 12000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=12749.99){
            msc = 12500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }

         else if (monthly_income <=13249.99){
            msc = 13000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=13749.99){
            msc = 13500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=14249.99){
            msc = 14000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=14749.99){
            msc = 14500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=15249.99){
            msc = 15000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=15749.99){
            msc = 15500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=16249.99){
            msc = 16000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=16749.99){
            msc = 16500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=17249.99){
            msc = 17000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=17749.99){
            msc = 17500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=18249.99){
            msc = 18000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=18749.99){
            msc = 18500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=19249.99){
            msc = 19000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=19749.99){
            msc = 19500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=20249.99){
            msc = 20000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=20749.99){
            msc = 20000;
            ec = 30;
            mpf = 500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=21249.99){  //breaking point
            msc = 20000;
            ec = 30;
            mpf = 1000;
          tmc = (msc * cr)+ec +(mpf * cr);
            if (monthly_income <=20833.33){
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
          }
          else
          {

              final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
          }
        }
         else if (monthly_income <=21749.99){
            msc = 20000;
            ec = 30;
            mpf = 1500;
           tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=22249.99){
            msc = 20000;
            ec = 30;
            mpf = 2000;
          tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=22749.99){
            msc = 20000;
            ec = 30;
            mpf = 2500;
         tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=23249.99){
            msc = 20000;
            ec = 30;
            mpf = 3000;
          tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=23749.99){
            msc = 20000;
            ec = 30;
            mpf = 3500;
          tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=24249.99){
            msc = 20000;
            ec = 30;
            mpf = 4000;
       tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=24749.99){
            msc = 20000;
            ec = 30;
            mpf= 4500;
          tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=25249.99){
            msc = 20000;
            ec = 30;
            mpf = 5000;
           tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=25749.99){
            msc = 20000;
            ec = 30;
            mpf = 5500;
           tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=26249.99){
            msc = 20000;
            ec = 30;
            mpf = 6000;
        tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=26749.99){
            msc = 20000;
            ec = 30;
            mpf = 6500;
        tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=27249.99){
            msc = 20000;
            ec = 30;
            mpf = 7000;
         tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=27749.99){
            msc = 20000;
            ec = 30;
            mpf = 7500;
         tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=28249.99){
            msc = 20000;
            ec = 30;
            mpf = 8000;
           tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income- tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
 else if (monthly_income <=28749.99){
            msc = 20000;
            ec = 30;
            mpf = 8500;
          tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=29249.99){
            msc = 20000;
            ec = 30;
            mpf = 9000;
          tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=29749.99){
            msc = 20000;
            ec = 30;
            mpf = 9500;
          tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else{  //breaking point
            msc = 20000;
            ec = 30;
            mpf = 10000;
          tmc = (msc * cr)+ec +(mpf * cr);
          if (monthly_income <=33333.33){
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
          }
          else
          {

              final_sss = addon - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
          }
        }



// ===============================   IF EMPLOYEE SSS   =================================

    }
    else if (member == 2){
         if (monthly_income <=4250){
            msc = 4000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=4749){
            msc = 4500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=5249.99){
            msc = 5000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=5749.99){
            msc = 5500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=6249.99){
            msc = 6000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=6749.99){
            msc = 6500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=7249.99){
            msc = 7000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=7749.99){
            msc = 7500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=8249.99){
            msc = 8000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=8749.99){
            msc = 8500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=9249.99){
            msc = 9000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final- tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=9749.99){
            msc = 9500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=10249.99){
            msc = 10000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=10749.99){
            msc = 10500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=11249.99){
            msc = 11000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=11749.99){
            msc = 11500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=12249.99){
            msc = 12000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=12749.99){
            msc = 12500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }

         else if (monthly_income <=13249.99){
            msc = 13000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=13749.99){
            msc = 13500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=14249.99){
            msc = 14000;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=14749.99){
            msc = 14500;
            ec = 10;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=15249.99){
            msc = 15000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=15749.99){
            msc = 15500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=16249.99){
            msc = 16000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=16749.99){
            msc = 16500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=17249.99){
            msc = 17000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=17749.99){
            msc = 17500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=18249.99){
            msc = 18000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=18749.99){
            msc = 18500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=19249.99){
            msc = 19000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=19749.99){
            msc = 19500;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=20249.99){
            msc = 20000;
            ec = 30;
            tmc = (msc * cr)+ ec;
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=20749.99){
            msc = 20000;
            ec = 30;
            mpf = 500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=21249.99){  //breaking point
            msc = 20000;
            ec = 30;
            mpf = 1000;
            tmc = (msc * cr)+ec +(mpf * cr);
            if (monthly_income <=20833.33){
            final_sss = final - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
          }
          else
          {

              final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
          }
        }
         else if (monthly_income <=21749.99){
            msc = 20000;
            ec = 30;
            mpf = 1500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=22249.99){
            msc = 20000;
            ec = 30;
            mpf = 2000;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=22749.99){
            msc = 20000;
            ec = 30;
            mpf = 2500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=23249.99){
            msc = 20000;
            ec = 30;
            mpf = 3000;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=23749.99){
            msc = 20000;
            ec = 30;
            mpf = 3500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=24249.99){
            msc = 20000;
            ec = 30;
            mpf = 4000;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=24749.99){
            msc = 20000;
            ec = 30;
            mpf= 4500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=25249.99){
            msc = 20000;
            ec = 30;
            mpf = 5000;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=25749.99){
            msc = 20000;
            ec = 30;
            mpf = 5500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=26249.99){
            msc = 20000;
            ec = 30;
            mpf = 6000;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=26749.99){
            msc = 20000;
            ec = 30;
            mpf = 6500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=27249.99){
            msc = 20000;
            ec = 30;
            mpf = 7000;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=27749.99){
            msc = 20000;
            ec = 30;
            mpf = 7500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=28249.99){
            msc = 20000;
            ec = 30;
            mpf = 8000;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income- tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
        else if (monthly_income <=28749.99){
            msc = 20000;
            ec = 30;
            mpf = 8500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=29249.99){
            msc = 20000;
            ec = 30;
            mpf = 9000;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else if (monthly_income <=29749.99){
            msc = 20000;
            ec = 30;
            mpf = 9500;
            tmc = (msc * cr)+ec +(mpf * cr);
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
        }
         else{//breaking point
            msc = 20000;
            ec = 30;
            mpf = 10000;
            tmc = (msc * cr)+ec +(mpf * cr);
          if (monthly_income <=33333.33){
            final_sss = taxed_income - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
          }
          else
          {

            final_sss = addon - tmc;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
        cout << "\t==================================================" << endl;
        cout << "\t||\t\t SSS \t\t\t\t||"<< endl; 
        cout << "\t==================================================" << endl;
        cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << tmc << endl;
        cout << "\t||Your remaining balance with tax " << endl;
        cout << fixed << setprecision(2) << "\t||and SSS deduction is: " << final_sss << endl;
        cout << fixed << setprecision(2) << "\t||TOTAL: " << final_sss << endl;
        cout << "\t==================================================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://avenuegh.com/sss-contribution-table-2023/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
            }
          }
        }
    } else if (sss == 2); {

// ===============================   GSIS CONTRIBUTIONS   =================================

double gsis_contri = 0.09;
double final_gsis;
double total_gsis;
double gsis;

cout << "=============================================================" << endl;
cout << "\t\t| GSIS CONTRIBUTIONS| " << endl;
cout << "=============================================================" << endl;

cout << "Do you want to compute your GSIS contribution? " << endl;
cout << "[1]. YES, [2]. NO " << endl;
cout << "> ";
cin >> gsis;
cout << "\n";

   while (gsis != 1 && gsis != 2) {
        cout << "_________________________________" << endl;
        if (cin.fail() || (gsis != 1 && gsis != 2)) {
            // Invalid input, clear the error state and discard the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // They need to input a valid number which is only 1 and 2, rather than 3 to ∞ or 0 to -∞, also invalid alphabetical letters
            cout << "Invalid input. Please enter a valid number (1, 2)." << endl;
            cout << "> ";
        }
        cin >> gsis;
        cout << "\n";
    }

if (gsis == 1){
if(annual <= 250000){
    total_gsis = monthly_income * gsis_contri;
    final_gsis = final - total_gsis;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tGSIS \t\t\t\t||"<< endl; 
    cout << "\t==================================================" << endl;
    cout << "\t||GSIS Contribution Percentage: " << "9%" << endl;
    cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << total_gsis << endl;
    cout << fixed << setprecision(2) << "\t||Your remaining balance with tax, GSIS: " << final_gsis << endl;
    cout << fixed << setprecision(2) << "\t||TOTAL: " << final_gsis << endl;
    cout << "\t==================================================" << endl;

    cout << "\n";
    cout << "\tFor more information kindly visit this link " << endl;
    cout << "\thttps://www.gsis.gov.ph/active-members/contributions/ \n\n";
    cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
    }
    else if( annual<= 400000){
    total_gsis = monthly_income * gsis_contri;
    final_gsis = taxed_income - total_gsis;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tGSIS \t\t\t\t||"<< endl; 
    cout << "\t==================================================" << endl;
    cout << "\t||GSIS Contribution Percentage: " << "9%" << endl;
    cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << total_gsis << endl;
    cout << fixed << setprecision(2) << "\t||Your remaining balance with tax, GSIS: " << final_gsis << endl;
    cout << fixed << setprecision(2) << "\t||TOTAL: " << final_gsis << endl;
    cout << "\t==================================================" << endl;

    cout << "\n";
    cout << "\tFor more information kindly visit this link " << endl;
    cout << "\thttps://www.gsis.gov.ph/active-members/contributions/ \n\n";
    cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
    }
    else {
    total_gsis = monthly_income * gsis_contri;
    final_gsis = addon - total_gsis;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tGSIS \t\t\t\t||"<< endl; 
    cout << "\t==================================================" << endl;
    cout << "\t||GSIS Contribution Percentage: " << "9%" << endl;
    cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << total_gsis << endl;
    cout << fixed << setprecision(2) << "\t||Your remaining balance with tax, GSIS: " << final_gsis << endl;
    cout << fixed << setprecision(2) << "\t||TOTAL: " << final_gsis << endl;
    cout << "\t==================================================" << endl;

    cout << "\n";
    cout << "\tFor more information kindly visit this link " << endl;
    cout << "\thttps://www.gsis.gov.ph/active-members/contributions/ \n\n";
    cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
    }
}
else 

// ===============================   PhilHealth CONTRIBUTIONS   =================================

cout << "=============================================================" << endl;
cout << "=============================================================" << endl;
cout << "\t\t| PhilHealth CONTRIBUTIONS| " << endl;
cout << "=============================================================" << endl;

double ph;
double ph_total;
double ph_final;

cout << "Do you want to compute your Philhealth contribution? " << endl;
cout << "[1]. YES, [2]. NO " << endl;
cout << "> ";
cin >> ph;
cout << "\n";

   while (ph != 1 && ph != 2) {
        cout << "_________________________________" << endl;
        if (cin.fail() || (ph != 1 && ph != 2)) {
            // Invalid input, clear the error state and discard the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // They need to input a valid number which is only 1 and 2, rather than 3 to ∞ or 0 to -∞, also invalid alphabetical letters
            cout << "Invalid input. Please enter a valid number (1, 2)." << endl;
            cout << "> ";
        }
        cin >> ph;
        cout << "\n";
    }

if(ph == 1){
    if (annual <= 250000){
    ph_total = monthly_income * 0.04;
    ph_final = final - ph_total;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tPhilhealth\t\t\t||"<< endl; 
    cout << "\t==================================================" << endl;
    cout << "\t||Philhealth Contribution Percentage: " << "4%" << endl;
    cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << ph_total << endl;
    cout << fixed << setprecision(2) << "\t||Your remaining balance with tax, Philhealth: " << ph_final << endl;
    cout << fixed << setprecision(2) << "\t||TOTAL: " << ph_final << endl;
    cout << "\t==================================================" << endl;

    cout << "\n";
    cout << "\tFor more information kindly visit this link " << endl;
    cout << "\thttps://sprout.ph/blog/philhealth-new-contribution-rates/ \n\n";
    cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
    }
    else if(annual <=400000){
           ph_total = monthly_income * 0.04;
    ph_final = taxed_income - ph_total;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tPhilhealth\t\t\t||"<< endl; 
    cout << "\t==================================================" << endl;
    cout << "\t||Philhealth Contribution Percentage: " << "4%" << endl;
    cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << ph_total << endl;
    cout << fixed << setprecision(2) << "\t||Your remaining balance with tax, Philhealth: " << ph_final << endl;
    cout << fixed << setprecision(2) << "\t||TOTAL: " << ph_final << endl;
    cout << "\t==================================================" << endl;

    cout << "\n";
    cout << "\tFor more information kindly visit this link " << endl;
    cout << "\thttps://sprout.ph/blog/philhealth-new-contribution-rates/ \n\n";
    cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
    }
    else{
    ph_total = monthly_income * 0.04;
    ph_final = addon - ph_total;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tRECEIPT \t\t\t||"<< endl;
    cout << "\t==================================================" << endl;
    cout << "\t||\t\tPhilhealth\t\t\t||"<< endl; 
    cout << "\t==================================================" << endl;
    cout << "\t||Philhealth Contribution Percentage: " << "4%" << endl;
    cout << fixed << setprecision(2) << "\t||Your total monthly contribution is: " << ph_total << endl;
    cout << fixed << setprecision(2) << "\t||Your remaining balance with tax, Philhealth: " << ph_final << endl;
    cout << fixed << setprecision(2) << "\t||TOTAL: " << ph_final << endl;
    cout << "\t==================================================" << endl;

    cout << "\n";
    cout << "\tFor more information kindly visit this link " << endl;
    cout << "\thttps://sprout.ph/blog/philhealth-new-contribution-rates/ \n\n";
    cout << "\t<><> Fiscal Harmony Enterprises <><>\n" << endl;
    }
}

            break;
        }
            }
    
break;

// =============================== [4] EXIT/LOG OUT MAIN MENU | FEATURES   =================================

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
            cout << "> ";
        }
        cin >> userLogOut;
    }

    if (userLogOut == 1) {
        // Log out the user and exit the loop
        cout << "Have a great day ahead! " << userEmail << endl;
        cout << "*********************************" << endl;
        return 0;
    }
        
    // User chose not to log out, breaks the loop and continue to the MAIN MENU | FEATURES
    break;
    }
        } while (userFeatureChoiceBool);

return 0;
    } 
}
