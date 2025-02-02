//
//  main.cpp
//  week 2 - activity 07 LeapYear
//
//  Created by Chhiring D. Lama on 1/29/25.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int year;
    cout << "Enter a year to check if its a leap year: ";
    cin >> year;
    if ((year % 4 == 0 && year % 100 !=0) || year % 400 == 0){
        cout << "Leap Year" << endl;
    } else {
        cout << "Not Leap Year" << endl;
    }
    
    return 0;
}

// year % 4 == 0 leap year :)
// year % 4 == 0 && year % 100 == 0 not leap year :(
// year % 4 == 0 && year % 100 != 0 leap year :)
// year % 400 == 0 leap year :)
