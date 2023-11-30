//arial 12
//1.5 spacing
//statement of the problem
//15mins presentation

//Inclusions of the Program
//Computation of overall salary for certain months
//Computation for Emergency Fund
//Receipt Implementation

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
int main(){
    int userOption, userSignIn;
    string userRegisterEmail, userRegisterPassword, userEmail, userPassword;
   
    cout << "=============================================================" << endl;
    cout << "\t\t|Welcome to Fiscal Harmony|" << endl;
    cout << "=============================================================" << endl;
    cout << "Planning your future for a financial free life." << endl;
    cout << "[1]. Sign In [2]. Sign Up" << endl;
    cout << "> ";
    cin >> userOption;


    while (userOption != 1 && userOption != 2) {
        cout << "__________________________________________________________________" << endl;
        if (cin.fail() || (userOption != 1 && userOption != 2)) {
            // Invalid input, clear the error state and discard the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // They need to input a valid number which is only 1 and 2, rather than 3 to ∞ or 0 to -∞, also invalid alphabetical letters
            cout << "Invalid input. Please enter a valid number (1 or 2)." << endl;
            cout << "> ";
        }
        cin >> userOption;
    }
   
    switch(userOption)
    {
   
    case 1:
        cout << "__________________________________________________________________" << endl;
        cout << "You are now signing in..." << endl;
        cout << "Username: "; cin >> userEmail;
        cout << "Password: "; cin >> userPassword;
        cout << "__________________________________________________________________" << endl;
        cout << "\n";


        if(userEmail != "admin" || userPassword != "password"){
            while(userEmail != "admin" || userPassword != "password"){
                cout << "Invalid password or username, please try again!" << endl;
                cout << "Username: "; cin >> userEmail;
                cout << "Password: "; cin >> userPassword;
                cout << "__________________________________________________________________" << endl;
                cout << "\n";
               
            }
        }
       
        break;
   
    case 2:
        cout << "__________________________________________________________________" << endl;
        cout << "You are now creating an account" << endl;
        cout << "Username: "; cin >> userRegisterEmail;
        cout << "Password: "; cin >> userRegisterPassword;
        cout << "You have succesfully created an account, would you like to sign in?" << endl;
        cout << "[1]. Yes [2]. No" << endl;
        cout << ">|"; cin >> userSignIn;
        cout << "__________________________________________________________________" << endl;
        cout << "\n";
       
        while (userSignIn != 1 && userSignIn != 2) {
        cout << "__________________________________________________________________" << endl;
        if (cin.fail() || (userSignIn != 1 && userSignIn != 2)) {
            // Invalid input, clear the error state and discard the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // They need to input a valid number which is only 1 and 2, rather than 3 to ∞ or 0 to -∞, also invalid alphabetical letters
            cout << "Invalid input. Please enter a valid number (1 or 2)." << endl;
            cout << ">|";
        }
            cin >> userSignIn;
        }
       
        if (userSignIn == 1){
            cout << "Username: "; cin >> userEmail;
            cout << "Password: "; cin >> userPassword;
            cout << "__________________________________________________________________" << endl;
            cout << "\n";
            if(userEmail != userRegisterEmail || userPassword != userRegisterPassword){
                while(userEmail != userRegisterEmail || userPassword != userRegisterPassword){
                    cout << endl;
                    cout << "You have entered the wrong username or password, please try again!" << endl;
                    cout << "Username: "; cin >> userEmail;
                    cout << "Password: "; cin >> userPassword;
                    cout << "__________________________________________________________________";
                    cout << "\n";
                }
            }
        } else if (userSignIn == 2){
            cout << "Have a great day ahead!";
            exit(0);
        } else {
            cout << "Invalid input";
            cout << "\n";
        }
    }
    cout << "Welcome, " << userEmail << " I hope you have a great time!" << endl;

// MONTHLY INCOME TAX DEDUCTOR PROGRAM

    double monthly_income;
    double annual;
    double final;
    double tax;
    double excess;
    double taxed_income;
    double addon;

    cout << "Do you want to compute your funds? " << endl;
    cout << "Type: [1]. Yes Type: [2]. No Type [3]. Double Pay Option " << endl;
    cout << "> ";
    cin >> userOption;
    cout << "\n";

    while (userOption != 1 && userOption != 2 && userOption != 3) {
        cout << "_________________________________" << endl;
        if (cin.fail() || (userOption != 1 && userOption != 2 && userOption != 3)) {
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
        case 3:
            cout << "Do you want to compute your funds with double pay? " << endl;
            cout << "Type: [1]. Yes Type: [2]. No" << endl;
            cout << "> ";
            cin >> userOption;
            cout << "||SERVICE IS NOT WORKING, I'M SORRY HAVE A GREAT TIME||" << endl;
            break;
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
        cout << "\t||No Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << final << endl;
        cout << "\t||TOTAL: " << final << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
    } else {
        if (annual <= 400000) {
            tax = 0.15;
            excess = annual - 250000;
            final = (excess * tax) / 12;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income did not exceed PHP400,000"<< endl; 
        cout << "\tand you are in the 15% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 15%" << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << final << endl;
        cout << "\t||TOTAL: " << final << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
        } else if (annual <= 800000) {
            tax = 0.2;
            excess = annual - 400000;
            final = (excess * tax) + 22500;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income did not exceed PHP800,000"<< endl; 
        cout << "\tand you are in the 2% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 2%" << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << final << endl;
        cout << "\t||TOTAL: " << final << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
        } else if (annual <= 2000000) {
            tax = 0.25;
            excess = annual - 800000;
            final = (excess * tax) + 102500;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income did not exceed PHP2,000,000"<< endl; 
        cout << "\tand you are in the 25% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 25%" << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << final << endl;
        cout << "\t||TOTAL: " << final << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
        } else if (annual <= 8000000) {
            tax = 0.3;
            excess = annual - 2000000;
            final = (excess * tax) + 402500;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income did not exceed PHP8,000,000"<< endl; 
        cout << "\tand you are in the 3% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 3%" << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << final << endl;
        cout << "\t||TOTAL: " << final << endl;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
        } else {
            tax = 0.35;
            excess = annual - 8000000;  
            final = (excess * tax) + 2202500;
        cout << "\t\tRECEIPT" << endl;
        cout << "\t=======================" << endl;
        cout << "\tYour monthly income exceed PHP8,000,000"<< endl; 
        cout << "\tand you are in the 35% tax bracket." << endl;
        cout << "\t=======================" << endl;
        cout << "\t||Tax Bracket: 35%" << endl;
        cout << "\t||Tax Deduction: " << final << endl;
        cout << "\t||Your salary with tax deducted is: " << final << endl;
        cout << "\t||TOTAL: " << final << endl;;
        cout << "\t=======================" << endl;

        cout << "\n";
        cout << "\tFor more information kindly visit this link " << endl;
        cout << "\thttps://www.taxumo.com/tax-computation-philippines/ \n\n";
        cout << "\t<><> Fiscal Harmony Enterprises <><>" << endl;
        }
        taxed_income = final / 12;
        addon = monthly_income - taxed_income;

        }
        break;

    default:
        cout << "Invalid option" << endl;
        break;
    }
}

// Program ni Emerson

//   cout << "Do you want to compute your funds? " << endl;
//    cout << "Type: [1]. Yes Type: [2]. No Type [3]. Double Pay Option " << endl;
//    cout << "> ";
//    cin >> userOption;

//    if (userOption == 3)
//    {
//        cout << "Do you want to compute your funds with double pay? " << endl;
//        cout << "Type: [1]. Yes Type: [2]. No" << endl;
//        cout << "> ";
//        cin >> userOption;
//    }
//    else if (userOption == 2)
//    {
//        cout << "Signing out " << endl;
//    }  

//    if (userOption == 1)
//    {
//        cout << "Enter your salary: ";
//        cin >> monthly_income;
//
//
//        annual = monthly_income * 12;
//        if (annual <= 250000)
//        {

//            final = annual / 12;
//            cout << "Your salary with tax deducted is: " << taxed_income << endl;
//        }
//    }
//    else if (annual <= 400000)
//    {
//        tax = 0.15;
//        excess = annual - 250000;
//        final = (excess * tax) / 12;
//        taxed_income = monthly_income - final;
//        cout << "Your salary with tax deducted is: " << taxed_income << endl;
//    }
//    else if (annual <= 800000)
//    {
//        tax = 0.2;
//        excess = annual - 400000;
//        final = (excess * tax) + 22500;
//        taxed_income = final / 12;
//        addon = monthly_income - taxed_income;

//       cout << "Your salary with tax deducted is: " << addon << endl;
//    }

//    else if (annual <= 2000000)
//    {
//        tax = 0.25;
//        excess = annual - 800000;
//        final = (excess * tax) + 102500;
//        taxed_income = final / 12;
//        addon = monthly_income - taxed_income;

//        cout << "Your salary with tax deducted is: " << addon << endl;
//    }

//    else if (annual <= 800000)
//    {
//        tax = 0.3;
//        excess = annual - 2000000;  
//        final = (excess * tax) + 402500;
//        taxed_income = final / 12;
//        addon = monthly_income - taxed_income;

//        cout << "Your salary with tax deducted is: " << addon << endl;
//    }
//    else
//    {
//        tax = 0.35;
//        excess = annual - 8000000;
//        final = (excess * tax) + 2202500;
//        taxed_income = final / 12;
//        addon = monthly_income - taxed_income;

//        cout << "Your salary with tax deducted is: " << addon << endl;
//    }
//}
