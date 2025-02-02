//
//  main.cpp
//  formatted-report
//
//  Created by Chhiring D. Lama on 2/1/25.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //initalizing array for id, name, and balance
    int id[3] = {1,2,3};
    string name[3] = {"Alice","Bob","Charlie"};
    double balance[3]={1000.00,530.25,2040.50};
    
    //column header
    cout << setw(6) << left << "Id";
    cout << setw(10) << left << "Name";
    cout << right << "Daily Report Balance"<< endl;
    
    cout << setfill('-') << setw(6) << " ";
    cout << setfill('-') << setw(10) << " ";
    cout << setfill('-') << setw(21) << " " << endl;

    for(int i = 0;  i < 3 ; i++){
        cout << setprecision(2) << fixed; //to display only the first two decimal
        cout << setfill('0') << setw(5) << id[i] << " " << setfill(' ') << setw(10) << left << name[i] << setw(0) << right << '$' << balance[i] << endl;

    }
    
    return 0;
}
