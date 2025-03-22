#include <iostream>
#include <vector>

using namespace std;

struct Date {
    int month;
    int day;
    int year;
};

struct Movie {
    string name;
    Date date;
    double rating;
    vector<string> directors;
};

//overloaded stream insertion operator
ostream& operator << (ostream& stream, const Movie& movie){
    stream << "- - -" << endl;
    stream << "Name: " << movie.name << endl;
    stream << "Release date: " << movie.date.month << "/"  << movie.date.day << "/" << movie.date.year << endl;
    stream << "Rating: " << movie.rating << "/10" << endl;
    stream << "Directors: " << endl;
    for (auto const& director: movie.directors) {
        stream << "- " << director << endl;
    }
    return stream ;
}

//for user input validation
bool isLeapYear(int year){
    if ((year % 4 == 0 && year % 100 !=0) || year % 400 == 0){
        return true;
    }
    return false;
}

//check if date is valid or not
bool checkInvalidDate(int day, int month, int year){
    bool dayInValid = false, monthInValid = false, yearInValid = false;
    
    //invalid
    if(year < 999 || year > 10000){
        yearInValid = true;
    }
    if(month <= 0 || month > 12){
        monthInValid = true;
    }
    if((day <= 0 || day > 31) || ((month == 4 || month == 6 || month == 9 || month == 11 ) && day > 30) || ((month == 2 && isLeapYear(year)) && day > 29) || (month == 2 && !isLeapYear(year) && day > 28)){
        dayInValid = true;
    }

    if (!yearInValid && !monthInValid && !dayInValid) {
        return true;
    } else {
        return false;
    }
}

//createMovie function
Movie createMovie(){
    string name;
    int day, month, year;
    double rating;
    string director;
    int noOfDirector;
    vector<string> directorList;
    
    cout << "Enter name of the movie: ";
    getline(cin, name);
    
    do {
        cout << "Release date (d/m/yyyy)" << endl;
        cout << "Day: ";
        cin >> day;
        cout << "Month: ";
        cin >> month;
        cout << "Year: ";
        cin >> year;
        if(!checkInvalidDate(day, month, year)){
            cout << "Invalid date. Try again!" << endl;
        }
    } while(!checkInvalidDate(day, month, year));
    
    do {
        cout << "Current Rating (0/10): ";
        cin >> rating;
        if(rating < 0 || rating > 10){
            cout << "Invalid rating. Try again!" << endl;
        }
    } while (rating < 0 || rating > 10);

    cout << "Director(s)" << endl;
    cout << "Please enter the number of directors involved in this movie: ";
    cin >> noOfDirector;
    cin.ignore();
    for (int i = 0; i < noOfDirector; i++) {
        cout << "Director " << i + 1 << ": ";
        getline(cin, director);
        directorList.push_back(director);
    }
    
    Movie movie {
        name, {month, day, year}, rating, directorList
    };
    
    return movie;
}

int main(int argc, const char * argv[]) {
    Movie mymovie = createMovie();
    cout << mymovie;
    
    return 0;
}
