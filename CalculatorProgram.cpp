#include <iostream>

using namespace std;

// Function prototypes
/*
 ===================================Run Program================================================
sonu-lodhi@Kubuntu-Linux:~/DATA(D)/GCC Workspace$ g++ -o CalculatorProgram CalculatorProgram.cpp
sonu-lodhi@Kubuntu-Linux:~/DATA(D)/GCC Workspace$ ./CalculatorProgram

Simple Calculator
------------------
Operations:
+ : Addition
- : Subtraction
* : Multiplication
/ : Division
q : Quit
Enter an operation (+, -, *, /) or 'q' to quit: +
Enter first number: 10
Enter second number: 20
Result: 30

Simple Calculator
------------------
Operations:
+ : Addition
- : Subtraction
* : Multiplication
/ : Division
q : Quit
Enter an operation (+, -, *, /) or 'q' to quit:
*/

void showMenu();
void performOperation(char operation, double num1, double num2);

int main() {
    char operation;
    double num1, num2;

    while (true) {
        // Show menu
        showMenu();

        // Get user input
        cout << "Enter an operation (+, -, *, /) or 'q' to quit: ";
        cin >> operation;

        // Exit the program if user inputs 'q'
        if (operation == 'q') {
            cout << "Exiting the calculator." << endl;
            break;
        }

        // Get the two numbers
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        // Perform the selected operation
        performOperation(operation, num1, num2);
    }

    return 0;
}

// Function to show the menu
void showMenu() {
    cout << "\nSimple Calculator" << endl;
    cout << "------------------" << endl;
    cout << "Operations:" << endl;
    cout << "+ : Addition" << endl;
    cout << "- : Subtraction" << endl;
    cout << "* : Multiplication" << endl;
    cout << "/ : Division" << endl;
    cout << "q : Quit" << endl;
}

// Function to perform the operation
void performOperation(char operation, double num1, double num2) {
    switch (operation) {
        case '+':
            cout << "Result: " << (num1 + num2) << endl;
            break;
        case '-':
            cout << "Result: " << (num1 - num2) << endl;
            break;
        case '*':
            cout << "Result: " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << (num1 / num2) << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
    }
}
