#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "Film.h"
using namespace std;

void Film :: Read_file(ifstream &file)
{
    getline(file, Title);
    getline (file, Author);
    file >> Genre;
    file.ignore(255, '\n');
    file >> Year;
    file.ignore(255, '\n');
    file >> Duration;
    file.ignore(255, '\n');
    file >> IMDb;
    file.ignore(255, '\n');
}

void Film :: Read_console()
{
    getline(cin, Title);
    getline (cin, Author);
    cin >> Genre;
    cin.ignore(255, '\n');
    cin >> Year;
    cin.ignore(255, '\n');
    cin >> Duration;
    cin.ignore(255, '\n');
    cin >> IMDb;
    cin.ignore(255, '\n');
}

void Film :: Write_file(ofstream &file)
{
    file << setw(20) << left << Title;
    file << setw(20) << left << Author;
    file << setw(15) << left << Genre;
    file << setw(10) << left << Year;
    file << setw(10) << left << Duration;
    file << setw(5) << left << IMDb << endl;
}

void Film :: Write_console()
{
    cout << setw(20) << left << Title;
    cout << "|";
    cout << setw(20) << left <<  Author;
    cout << "|";
    cout << setw(15) << left << Genre;
    cout << "|";
    cout << setw(10) << left << Year;
    cout << "|";
    cout << setw(10) << left << Duration;
    cout << "|";
    cout << setw(5) << left << IMDb;
    cout << "|";
    cout << endl;
    for (int i = 0; i < 85; i++)
    cout << "-";
    cout << endl;
}

string Film :: get_Genre()
{
    return Genre;
}

float Film :: get_IMDb()
{
    return IMDb;
}

string Film :: get_Author()
{
    return Author;
}

int Film :: get_Year()
{
    return Year;
}