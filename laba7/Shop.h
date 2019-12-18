#ifndef shop_h
#define shop_h
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>

#include "Film.h"
#include "serial.h"
#include "TVSeries.h"

using namespace std;

class Shop
{
private:

    int MaxFilmNumber;
    int FilmNumber;
    int nubmerF;
    int numberS;
    Film **movies;
public:

    Shop (unsigned int);
    ~Shop ();

    void SearchGoodFilm ();
    void SearchLatestFilmOfAuthor ();

    void ReadFile(istream&);
    void WriteFile(ostream&);
    void WriteFile();

    void AddFilm();
    void AddFilm(string);
    void DeleteFilm();

    void operator+=(Film);
    void operator+=(Serial);
};
#endif
