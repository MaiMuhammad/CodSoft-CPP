#include <bits/stdc++.h>
#define ll long long
#define MaI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endL "\n"
using namespace std;

void solution() {
    char operation;
    double num1, num2, result;

    cout << "Welcome to Simple Calculator Program!" << endL;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << endL;
            break;
        case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << endL;
            break;
        case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << endL;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << num1 << " / " << num2 << " = " << result << endL;
            }
            else
                cout << "INVALID! Division by zero." << endL;
            break;
        default:
            cout << "Invalid operation! Please choose from (+, -, *, /)." << endL;
            break;
    }
}

int main() {
    solution();
    return 0;
}




