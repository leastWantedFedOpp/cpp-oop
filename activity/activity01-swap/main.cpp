#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
int x = 1;
int y = 2;
int temp = 0;


cout << "Before swap\n";
cout << x << endl;
cout << y << endl;

temp = y;
y = x;
x = temp;

cout << "After swap\n";
cout << x << endl;
cout << y << endl;
return 0;


}
