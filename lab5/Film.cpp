#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "Film.h"
using namespace std;

/*void Film :: Read_file(ifstream &file)
{
    getline(file, Title);
    getline (file, Author);
    getline (file, Genre);
    file >> Year;
    file.ignore(255, '\n');
    file >> Duration;
    file.ignore(255, '\n');
    file >> IMDb;
    file.ignore(255, '\n');
    int o = 0;
    genres = new string[3];
    for (int i = 0; i < Genre.length(); i++)
    {
        if (Genre[i] == ' ')
        {
            o++;
            continue;
        }
        else genres[o] += Genre[i];
    }

}

void Film :: Read_console()
{
    getline(cin, Title);
    getline (cin, Author);
    getline (cin, Genre);
    cin >> Year;
    cin.ignore(255, '\n');
    cin >> Duration;
    cin.ignore(255, '\n');
    cin >> IMDb;
    cin.ignore(255, '\n');
    int o = 0;
    genres = new string[3];
    for (int i = 0; i < Genre.length(); i++)
    {
        if (Genre[i] == ' ')
        {
            o++;
            continue;
        }
        else genres[o] += Genre[i];
    }
}

void Film :: Write_file(ofstream &file)
{
    file << setw(30) << left << Title;
    file << setw(20) << left << Author;
    file << setw(10) << left << genres[0];
    file << setw(10) << left << genres[1];
    file << setw(10) << left << genres[2];
    file << setw(10) << left << Year;
    file << setw(10) << left << Duration;
    file << setw(5) << left << IMDb << endl;
}

void Film :: Write_console()
{
    cout << setw(30) << left << Title;
    cout << setw(20) << left <<  Author;
    cout << setw(10) << left << genres[0] << " ";
    cout << setw(10) << left << genres[1] << " ";
    cout << setw(10) << left << genres[2] << " ";
    cout << setw(10) << left << Year;
    cout << setw(10) << left << Duration;
    cout << setw(5) << left << IMDb;
    cout << endl;
    cout << endl;
}*/

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
string Film :: get_Title()
{
    return Title;
}
int Film :: comparison_Genre(string genre)
{
    if ((genres[0] == genre) || (genres[1] == genre) || (genres[2] == genre))
        return 1;
    else return 0;
}

istream& operator>> (istream &file, Film &move)
{
    getline(file, move.Title);
    getline (file, move.Author);
    getline (file, move.Genre);
   	file >> move.Year;
    file.ignore(255, '\n');
    file >> move.Duration;
    file.ignore(255, '\n');
    file >> move.IMDb;
    file.ignore(255, '\n');
    int o = 0;
    move.genres = new string[3];
    for (int i = 0; i < move.Genre.length(); i++)
    {
        if (move.Genre[i] == ' ')
        {
            o++;
            continue;
        }
        else move.genres[o] += move.Genre[i];
    }
    return file;
}
ostream& operator<< (ostream &file, Film move)
{
    file << setw(30) << left << move.Title;
    file << setw(20) << left << move.Author;
    file << setw(10) << left << move.genres[0];
    file << setw(10) << left << move.genres[1];
    file << setw(10) << left << move.genres[2];
    file << setw(10) << left << move.Year;
    file << setw(10) << left << move.Duration;
    file << setw(5) << left << move.IMDb << endl << endl;


}

bool Film :: operator== (const Film move)
{
        return (Title == move.Title) && (Author == move.Author) && (genres[0] == move.genres[0]) && (genres[1] == move.genres[1]) && (genres[2] == move.genres[2]) && (Year == move.Year) && (Duration== move.Duration) && (IMDb == move.IMDb);
}

bool Film :: operator!= (const Film move)
{
        return !((Title == move.Title) && (Author == move.Author) && (genres[0] == move.genres[0]) && (genres[1] == move.genres[1]) && (genres[2] == move.genres[2]) && (Year == move.Year) && (Duration== move.Duration) && (IMDb == move.IMDb));
}
