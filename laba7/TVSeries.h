#ifndef TVSeries_H
#define TVSeries_H

#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>

#include "Film.h"

class TVSeries : public Film
{
private:
    string Channel;
    string TimeStart;
public:
    TVSeries(): Film(), Channel(""), TimeStart("0:0") {};
    TVSeries(string, string, string, int, int, float, string, string);
    TVSeries(istream& file){ReadFromFile(file);}

    virtual void ReadFromFile(istream&);
    virtual void WriteInFile(ostream&);
    virtual void WriteInFile(ofstream&);

    virtual void Definition(ostream&);

};
#endif
