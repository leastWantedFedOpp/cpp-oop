//
//  main.cpp
//  week2 - activity 04 AgeGroupClassifier
//
//  Created by Chhiring D. Lama on 1/29/25.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
//    Classify the age into categories:
//    “Child” (<12)
//    “Teen” (12-19)
//    “Adult” (20-64)
//    “Senior” (65+)
    int age;
    cout << "Enter your age: ";
    cin >> age;
    if ( age < 12 ){
        cout << "Child" << endl;
    } else if(age <= 19) {
        cout << "Teen" << endl;
    } else if(age <= 64) {
        cout << "Adult" << endl;
    } else {
        cout << "Senior" << endl;
    }
    return 0;
}
