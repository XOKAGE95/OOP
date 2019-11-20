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
using namespace std;
class shop
{
private:
    unsigned int max_film_number;
    unsigned int film_number;
    unsigned int serial_number;
    Film *movies;
    serial *series;
public:
    shop (unsigned int);
    ~shop ();
    void Search_good_film ();
    void Search_latest_film_of_author ();
    void add_film (istream&);
    void add_serial(istream&);
    void Display();
    void Definition();
    void delete_film(string);
    void operator+= (Film);
    void operator+= (serial);
};



#endif