//
//  main.cpp
//  week2 - activity 05 Calculator
//
//  Created by Chhiring D. Lama on 1/29/25.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {

//    Asks the user to choose an operation: +, -, *, or /.
//    Takes two numbers as inputs.
//    Uses a switch statement to perform the operation and display the result.
//    Include error handling for division by zero using the conditional operator.
    
    char userOperator;
    double x;
    double y;
    
    cout << "Choose an operator (+ , - , * , /) : ";
    cin >> userOperator;
    
    cout << "Choose your first number: ";
    cin >> x;
    cout << "Choose your second number: ";
    cin >> y;

    switch (userOperator) {
        case '+' :
            cout << x + y << endl;
            break;
        case '-' :
            cout << x - y << endl;
            break;
        case '*' :
            cout << x * y << endl;
            break;
        case '/' :
            if( x == 0 || y == 0) {
                cout << "Cant divide by 0" << endl;
            } else {
                cout << x / y << endl;
            }
            break;
        default:
            cout << "Try again" << endl;
            break;
    }
    return 0;
}
