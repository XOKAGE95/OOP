#ifndef serial_H
#define serial_H

#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>

#include "Film.h"

class Serial : public Film
{
private:
    int Series;
public:
    Serial(): Film(), Series(0) {};
    Serial(string, string, string, int, int, float, int);
    Serial(istream& file) {ReadFromFile(file);}

    virtual void ReadFromFile(istream&);
    virtual void WriteInFile(ostream&);
    virtual void WriteInFile(ofstream&);

    virtual void Definition(ostream&);
};

#endif
