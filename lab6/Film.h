#ifndef film_h
#define film_h
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Film
{
protected:
    string Title;
    string Author;
    string Genre;
    string *genres;
    int Year;
    int Duration;
    float IMDb;
public:
    Film(): Title(""), Author(""), Genre(""), Year(0), Duration(0), IMDb(0) {};
    Film (string, string, string, int, int, float);
    string get_Genre();
    float get_IMDb();
    string get_Author();
    int get_Year();
    string get_Title();
    bool comparison_Genre(string genre);
    friend istream& operator>> (istream&, Film&);
    friend ostream& operator<< (ostream&, Film);
    void Enter_file (ofstream&);
    friend bool operator== (Film, Film);
    friend bool operator!= (Film, Film);


};


#endif
