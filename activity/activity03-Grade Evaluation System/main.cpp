//
//  main.cpp
//  02-GradeEvalSystem
//
//  Created by Chhiring D. Lama on 1/29/25.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    //grade evaluation system
    int studentGrade;
    cout << "Enter Student Grade: ";
    cin >> studentGrade;
    if(studentGrade < 60) {
        cout << "Fail" << endl;
    } else if ( studentGrade <= 69) {
        cout << "Pass" << endl;
    } else if (studentGrade <= 89) {
        cout << "Good" << endl;
    } else {
        cout << "Excellent" << endl;
    }
    return 0;
}
