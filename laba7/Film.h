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
    string genres[3];
    int Year;
    int Duration;
    float IMDb;
public:
    Film(): Title(""), Author(""), Genre(""), Year(0), Duration(0), IMDb(0) {};
    Film(istream & file) {ReadFromFile(file);}
    Film (string, string, string, int, int, float);

    virtual string GetGenre(){return Genre;}
    virtual string GetAuthor(){return Author;}
    virtual string GetTitle(){return Title;}
    virtual float GetIMDb(){return IMDb;}
    virtual int GetYear(){return Year;}
    virtual void EnterGenres() {cout << genres[0] << "." << endl;}


    virtual void ReadFromFile(istream&);
    virtual void WriteInFile(ostream&);
    virtual void WriteInFile(ofstream&);

    virtual void Definition(ostream&);
    virtual bool ComparisonGenres(string);

};

#endif

