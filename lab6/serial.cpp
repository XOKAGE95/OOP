#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "serial.h"

Serial :: Serial(string TitleS, string AuthorS, string GenreS, int YearS, int DurationS, float IMDbS, int seriesS)
{
    Film(TitleS, AuthorS, GenreS, YearS, DurationS, IMDbS);
    series = seriesS;
}
ostream& operator<< (ostream &file, Serial sitcom)
{
    file << static_cast<Film>(sitcom);
    file << sitcom.series;
    return file;
}
void Serial :: Enter_file(ofstream &file)
{
    file << Title << endl;
    file << Author << endl;
    file << Genre << endl;
    file << Year << endl;
    file << Duration << endl;
    file << IMDb << endl;
    file << series << endl;
}
istream& operator>> (istream &file, Serial &sitcom)
{
    file >> static_cast<Film&>(sitcom);
    file >> sitcom.series;
    file.ignore(255, '\n');
    return file;
}
bool operator== (Serial sitcom1, Serial sitcom2)
{
    return ((operator==(static_cast<const Film>(sitcom1), static_cast<const Film>(sitcom2))) && sitcom1.series == sitcom2.series);
}

bool operator!= (Serial sitcom1, Serial sitcom2)
{
    return !(operator== (sitcom1, sitcom2));
}

