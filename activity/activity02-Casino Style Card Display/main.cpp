//
//  card.cpp
//  01
//
//  Created by Chhiring D. Lama on 1/27/25.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(){
    
    srand((unsigned)time(nullptr));
    int randSuit = rand() % 4;
    int randRank = rand() % 13;
    
    string suit[] = {"Spade", "Hearts", "Diamonds", "Clubs"};
    string rank[] = {"Ace", "King" , "Queen", "Jack", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two"};
        
    cout << setfill('*') << setw(40) << "" << endl;
    cout << "*" <<  setfill(' ') << setw(39) << "*" << endl;
    
    cout << "*" << left << "Casino Card" << setfill('-') << setw(15) << right << rank[randRank] << " of " << suit[randSuit] << right << "*" << endl;
    
    cout << "*" <<  setfill(' ') << setw(39) << "*" << endl;
    cout << setfill('*') << setw(40) << "" << endl;

    return 0 ;
}
