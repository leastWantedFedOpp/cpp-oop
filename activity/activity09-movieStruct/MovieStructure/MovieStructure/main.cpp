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

bool isLeapYear(int year){
    if ((year % 4 == 0 && year % 100 !=0) || year % 400 == 0){
        return true;
    }
    return false;
}

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

    /*
     if day has to be < 1 or > 31
     if month is april(04), june(06) ,september(09) , and novmeber(11) then day has to be <= 30
     if month == 2 and its a leap year then day has to be less than 29
     */
}

//movie function
Movie createMovie(){
    string name;
    int day, month, year;
    double rating;
    string director;
    int noOfDirector;
    vector<string> directorList;
//    bool validDate = false;
    
    cout << "Enter name of the movie: ";
    getline(cin, name);
    
    
    do {
        //ask user for input
        cout << "Release date (dd/mm/yyyy)" << endl;
        cout << "Day: "; //no number >= 0 or < 31?
        cin >> day;
        cout << "Month: "; //no number >= 0 or < 12
        cin >> month;
        cout << "Year: "; //no number > 0 and has to have length of 4
        //if year is leap year and month is 02 || 2 then allow user to input 29 as day else return error
        cin >> year;
        //check if input is valid, if not run loop again
        if(!checkInvalidDate(day, month, year)){
            cout << "Invalid date. Try again!" << endl;
        }
    } while(!checkInvalidDate(day, month, year));
    
    do {
        cout << "Current Rating (0/10): "; //no number > 0 or < 10
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

/*
 define a function that creates and returns a Movie object
 then display it using the overloaded stream insertion operator, while also ensuring
 user input validation. The Movie object will use a nested struct for additional movie details.
 
 make sure that your structs should include at least 3 different data type
 */
