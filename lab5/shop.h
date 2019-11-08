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
    Film *moves;
public:
    shop (unsigned int MAX);
    ~shop ();
    void Search_good_film ();
    void Search_latest_film_of_author ();
    void add_film (istream&);
    void Display();
    void Definition();
    void delete_film(string name);
    void operator+= (Film clip);
};



#endif
