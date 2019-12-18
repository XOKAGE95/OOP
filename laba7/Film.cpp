#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "Film.h"

using namespace std;

Film :: Film(string TitleF, string AuthorF, string GenreF,int YearF, int DurationF, float IMDbF) //Êîíñòðóêòîð.
{
    Title = TitleF;
    Author = AuthorF;
    Genre = GenreF;
    Year = YearF;
    Duration = DurationF;
    IMDb = IMDbF;
    for (int i = 0; i < 3; i++)
    {
        int number = Genre.find(" ", 0);
        if (number == -1)
        {
            number = Genre.find('\0', 0);
            genres[i].assign(Genre, 0, number);
            Genre.erase(0, number);
        }
        else
        {
            genres[i].assign(Genre, 0, number);
            Genre.erase(0, number+1);
        }


    }
}

void Film :: ReadFromFile(istream& file)
{
    getline(file, Title);
    getline (file, Author);
    getline (file, Genre);
    file >> Year;
    file.ignore(255, '\n');
    file >> Duration;
    file.ignore(255, '\n');
    file >> IMDb;
    file.get();
    for (int i = 0; i < 3; i++)
    {
        int number = Genre.find(" ", 0);
        if (number == -1)
        {
            number = Genre.find('\0', 0);
            genres[i].assign(Genre, 0, number);
            Genre.erase(0, number);
        }
        else
        {
            genres[i].assign(Genre, 0, number);
            Genre.erase(0, number+1);
        }


    }
}

void Film :: WriteInFile(ostream& file)
{
    file << setw(30) << left << Title;
    file << setw(20) << left << Author;
    file << setw(10) << left << genres[0];
    file << setw(10) << left << genres[1];
    file << setw(10) << left << genres[2];
    file << setw(10) << left << Year;
    file << setw(10) << left << Duration;
    file << setw(5) << left << IMDb;
}

void Film ::  WriteInFile(ofstream& file)
{
    file << Title << endl;
    file << Author << endl;
    file << genres[0] << " " << genres[1] << " " << genres[2] << endl;
    file << Year << endl;
    file << Duration << endl;
    file << IMDb << endl;
}

void Film :: Definition(ostream& file)
{
    file << setw(30) << left << "Title";
    file << setw(20) << left << "Author";
    file << setw(30) << left << "Genres";
    file << setw(10) << left << "Year";
    file << setw(10) << left << "Duration";
    file << setw(5) << left << "IMDb";
}

bool Film :: ComparisonGenres(string genre)
{
    return
        (       ((genres[0] == genre) && (genres[0] != "\0"))
                || 	((genres[1] == genre) && (genres[1] != "\0"))
                || 	((genres[2] == genre) && (genres[2] != "\0"))
        );
}
