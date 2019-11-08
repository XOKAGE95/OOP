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
private:
    string Title;
    string Author;
    string Genre;
    string *genres;
    int Year;
    int Duration;
    float IMDb;
public:
    string get_Genre();
    float get_IMDb();
    string get_Author();
    int get_Year();
    string get_Title();
    bool comparison_Genre(string genre);
    friend istream& operator>> (istream &file, Film &move);
    friend ostream& operator<< (ostream &file, Film move);
    bool operator== (Film move);
    bool operator!= (Film move);


};
#endif
