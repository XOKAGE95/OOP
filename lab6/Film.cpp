#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "Film.h"
using namespace std;

Film :: Film(string TitleF, string AuthorF, string GenreF,int YearF, int DurationF, float IMDbF)
{
    Title = TitleF;
    Author = AuthorF;
    Genre = GenreF;
    Year = YearF;
    Duration = DurationF;
    IMDb = IMDbF;
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
string Film :: get_Title()
{
    return Title;
}
bool Film :: comparison_Genre(string genre)
{
    return
        (       ((genres[0] == genre) && (genres[0] != "\0"))
         || 	((genres[1] == genre) && (genres[1] != "\0"))
         || 	((genres[2] == genre) && (genres[2] != "\0"))
        );
}
istream& operator>> (istream &file, Film &movie)
{
    getline(file, movie.Title);
    getline (file, movie.Author);
    getline (file, movie.Genre);
    file >> movie.Year;
    file.ignore(255, '\n');
    file >> movie.Duration;
    file.ignore(255, '\n');
    file >> movie.IMDb;
    file.ignore(255, '\n');
    int o = 0;
    movie.genres = new string[3];
    for (unsigned int i = 0; i < movie.Genre.length(); i++)
    {
        if (movie.Genre[i] == ' ')
        {
            o++;
            continue;
        }
        else
            movie.genres[o] += movie.Genre[i];
    }
    return file;
}
ostream& operator<< (ostream &file, Film movie)
{
    file << setw(30) << left << movie.Title;
    file << setw(20) << left << movie.Author;
    file << setw(10) << left << movie.genres[0];
    file << setw(10) << left << movie.genres[1];
    file << setw(10) << left << movie.genres[2];
    file << setw(10) << left << movie.Year;
    file << setw(10) << left << movie.Duration;
    file << setw(5) << left << movie.IMDb;
    return file;
}
void Film :: Enter_file(ofstream &file)
{
    file << Title << endl;
    file << Author << endl;
    file << Genre << endl;
    file << Year << endl;
    file << Duration << endl;
    file << IMDb << endl;
}
bool operator== (Film movie1, Film movie2)
{
    return
        ((movie1.Title == movie2.Title)
         && (movie1.Author == movie2.Author)
         && (movie1.genres[0] == movie2.genres[0])
         && (movie1.genres[1] == movie2.genres[1])
         && (movie1.genres[2] == movie2.genres[2])
         && (movie1.Year == movie2.Year)
         && (movie1.Duration== movie2.Duration)
         && (movie1.IMDb == movie2.IMDb));
}

bool operator!= (Film movie1, Film movie2)
{
    return !(operator== (movie1, movie2));
}

