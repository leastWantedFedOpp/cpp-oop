#include <iostream>
#include <map>
using namespace std;

//address structure
struct Address {
    string street;
    string city;
    string state;
    int zipCode;
};

//customer structure
struct Customer {
    string name;
    Address address;
};

void displayCustomer(Customer customer){
    cout << "Customer Info - - -" << endl;
    cout << customer.name << endl;
    cout << customer.address.street << endl;
    cout << customer.address.city << ", " << customer.address.state << " " << customer.address.zipCode << endl;
}

int main(int argc, const char * argv[]) {
    Customer customer;
    cout << "Name: ";
    getline(cin, customer.name);
    cout << "Street: ";
    getline(cin, customer.address.street);
    cout << "City: ";
    getline(cin, customer.address.city);
    cout << "State: ";
    getline(cin, customer.address.state);
    cout << "Zip: ";
    cin >> customer.address.zipCode;

    displayCustomer(customer);
    
    return 0;
}

/*
 create a structure for address:
 street
 city
 zipCode
 
 nested the address structure within customer
 create and initialize a customer object

 Note: user validation is a must
 */
