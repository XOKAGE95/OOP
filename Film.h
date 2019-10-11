#ifndef func
#define func
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
    void Definition();
    void Definition_file(ofstream &file);
};
#endif
