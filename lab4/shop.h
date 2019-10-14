#ifndef store
#define store
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
	void add_film (string mode, ifstream &file);
	void Display();
	void Definition();
    void Definition_file(ofstream &file);
};



#endif