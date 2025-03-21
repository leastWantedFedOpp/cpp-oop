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

//movie function
Movie createMovie(){
    string name;
    int day = 0, month = 0, year = 0;
    double rating = 0;
    string director;
    int noOfDirector = 0;
    vector<string> directorList;
    bool validDate = false;
    
    cout << "Enter name of the movie: ";
    getline(cin, name);
    do {
        //ask user for input
        cout << "Release date (00/00/0000)" << endl;
        cout << "Day: "; //no number >= 0 or < 31?
        cin >> day;
        cout << "Month: "; //no number >= 0 or < 12
        cin >> month;
        cout << "Year: "; //no number > 0 and has to have length of 4
        //if year is leap year and month is 02 || 2 then allow user to input 29 as day else return error
        cin >> year;
        //check if input is valid, if not run loop again
    } while (!validDate);

    cout << "Current Rating (0/10): "; //no number > 0 or < 10
    cin >> rating;
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
