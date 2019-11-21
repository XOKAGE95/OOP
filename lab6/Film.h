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
    friend istream& operator>> (istream &file, Film &movie);
    friend ostream& operator<< (ostream &file, Film movie);
    friend bool operator== (Film movie1, Film movie2);
    friend bool operator!= (Film movie1, Film movie2);


};

class serial : public Film
{
private:
	int series;
public:
	serial(): Title(""), Author(""), Genre(""), Year(0), Duration(0), IMDb(0), series(0) {};
	serial(string, string, string, int, int, float, int);
	friend istream& operator>> (istream &file, serial &sitcom);
    friend ostream& operator<< (ostream &file, serial sitcom);
    friend bool operator== (serial sitcom1, serial sitcom2);
    friend bool operator!= (serial sitcom1, serial sitcom2);
};
#endif
