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
    int series;
public:
    Serial(): Film(), series(0) {};
    Serial(string, string, string, int, int, float, int);
    friend istream& operator>> (istream&, Serial&);
    friend ostream& operator<< (ostream&, Serial);
    void Enter_file (ofstream&);
    friend bool operator== (Serial, Serial);
    friend bool operator!= (Serial, Serial);

};
#endif
