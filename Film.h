#ifndef clip
#define clip
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
	void Read_file(ifstream &file);
    void Write_file(ofstream &file);
    void Read_console();
    void Write_console();
    string get_Genre();
    float get_IMDb();
    string get_Author();
    int get_Year();
    string get_Title();
    int comparison_Genre(string genre);

};
#endif
