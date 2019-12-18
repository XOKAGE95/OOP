#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>

#include "TVSeries.h"

TVSeries :: TVSeries(string TitleS, string AuthorS, string GenreS, int YearS, int DurationS, float IMDbS, string ChannelS, string TimeStartS)
:Film(TitleS, AuthorS, GenreS, YearS, DurationS, IMDbS)
{
    Channel = ChannelS;
    TimeStart = TimeStartS;
}

void TVSeries :: ReadFromFile(istream& file)
{
    Film :: ReadFromFile(file);
    getline(file, Channel);
    getline(file, TimeStart);
}

void TVSeries :: WriteInFile(ostream& file)
{
    Film :: WriteInFile(file);
    file << setw(10) << left << Channel;
    file << setw(6) << left << TimeStart;
}

void TVSeries ::  WriteInFile(ofstream& file)
{
    Film :: WriteInFile(file);
    file << Channel << endl;
    file << TimeStart << endl;
}

void TVSeries :: Definition(ostream& file)
{
    Film :: Definition(file);
    file << setw(10) << left << "Channel";
    file << setw(10) << left << "Time";
}


