#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>

#include "Serial.h"

Serial :: Serial(string TitleS, string AuthorS, string GenreS, int YearS, int DurationS, float IMDbS, int seriesS)
:Film(TitleS, AuthorS, GenreS, YearS, DurationS, IMDbS)
{
    Series = seriesS;
}

void Serial :: ReadFromFile(istream& file)
{
    Film :: ReadFromFile(file);
    file >> Series;
    file.ignore(255, '\n');
}

void Serial :: WriteInFile(ostream& file)
{
    Film :: WriteInFile(file);
    file << setw(10) << left << Series;
}

void Serial ::  WriteInFile(ofstream& file)
{
    Film :: WriteInFile(file);
    file << Series << endl;
}

void Serial :: Definition(ostream& file)
{
    Film :: Definition(file);
    file << setw(6) << left << "Series";
}


