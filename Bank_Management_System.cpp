#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
============================================Start-Bank_Management_System Application====================================
sonu-lodhi@Kubuntu-Linux:~/DATA(D)/GCC Workspace$ g++ -o Bank_Management_System Bank_Management_System.cpp
sonu-lodhi@Kubuntu-Linux:~/DATA(D)/GCC Workspace$ ./Bank_Management_System

--- Bank Management System ---
1. Create Account
2. Display Account Details
3. Deposit Money
4. Withdraw Money
5. Check Balance
6. Exit
Enter your choice: 1
Enter Account Number: 2010512
Enter Account Holder Name: Sonu Lodhi
Enter Initial Balance: 10000
Account created successfully!

--- Bank Management System ---
1. Create Account
2. Display Account Details
3. Deposit Money
4. Withdraw Money
5. Check Balance
6. Exit
Enter your choice: 2
Enter Account Number: 2010512
Account Number: 2010512
Account Holder Name: Sonu Lodhi
Account Balance: 10000

--- Bank Management System ---
1. Create Account
2. Display Account Details
3. Deposit Money
4. Withdraw Money
5. Check Balance
6. Exit
Enter your choice: 3
Enter Account Number: 2010512
Enter Amount to Deposit: 5500
Amount Deposited: 5500

--- Bank Management System ---
1. Create Account
2. Display Account Details
3. Deposit Money
4. Withdraw Money
5. Check Balance
6. Exit
Enter your choice: 4
Enter Account Number: 2010512
Enter Amount to Withdraw: 500
Amount Withdrawn: 500

--- Bank Management System ---
1. Create Account
2. Display Account Details
3. Deposit Money
4. Withdraw Money
5. Check Balance
6. Exit
Enter your choice: 5
Enter Account Number: 2010512
Current Balance: 15000

--- Bank Management System ---
1. Create Account
2. Display Account Details
3. Deposit Money
4. Withdraw Money
5. Check Balance
6. Exit
Enter your choice:
=====================================Ended Application=================================================
*/


class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    Account(string accNo, string accName, double initialBalance) {
        accountNumber = accNo;
        accountHolderName = accName;
        balance = initialBalance;
    }

    // Function to display account details
    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Balance: " << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    // Function to check account balance
    double checkBalance() {
        return balance;
    }

    // Function to get the account number
    string getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    vector<Account> accounts;
    int choice;
    string accNo, accName;
    double initialBalance, amount;

    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Display Account Details\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Check Balance\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, accName);
                cout << "Enter Initial Balance: ";
                cin >> initialBalance;
                accounts.push_back(Account(accNo, accName, initialBalance));
                cout << "Account created successfully!\n";
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accNo;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNo) {
                        acc.displayAccountDetails();
                    }
                }
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNo) {
                        acc.deposit(amount);
                    }
                }
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNo) {
                        acc.withdraw(amount);
                    }
                }
                break;

            case 5:
                cout << "Enter Account Number: ";
                cin >> accNo;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNo) {
                        cout << "Current Balance: " << acc.checkBalance() << endl;
                    }
                }
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
