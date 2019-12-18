#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include <typeinfo>

#include "shop.h"

using namespace std;

Shop :: Shop (unsigned int MAX) // Конструктор класса shop;
{
    MaxFilmNumber = MAX;                                  // Максимальное количество фильмов
    movies = new Film*[MaxFilmNumber];                   // Массив для хранения фильмов

    FilmNumber = 0;

}

Shop :: ~Shop ()                                            // Деструктор
{
    delete[] movies;
    MaxFilmNumber = 0;
    FilmNumber = 0;
}

void Shop :: ReadFile(istream& file)
{
    while (!file.eof())
        if (FilmNumber < MaxFilmNumber)
        {
            string mark;
            getline(file, mark);
            if (mark == "") return;
            if (mark.compare("Film") == 0)
            {
                movies[FilmNumber] = new Film(file);
            }
            else if (mark.compare("Serial") == 0)
            {
                movies[FilmNumber] = new Serial(file);
            }
            else if (mark.compare("TV") == 0)
            {
                movies[FilmNumber] = new TVSeries(file);
            }
            FilmNumber++;

        }
}

void Shop :: WriteFile(ostream& file)
{

    for(int i = 1; i < FilmNumber; i++)
    {
        /*movies[i] -> Definition(cout);
         cout << endl;*/
        movies[i] -> WriteInFile(cout);
        cout << endl;
    }
}

void Shop :: SearchLatestFilmOfAuthor()
{
    cout << "Enter author: ";
    string NAuthor;
    int CountYear = -1;
    int CountFilms = -1;
    getline(cin, NAuthor);
    for (int i = 0; i < FilmNumber; i++)
        if ((movies[i] -> GetAuthor() == NAuthor) && (movies[i] -> GetYear() >= CountYear))
        {
            CountYear = movies[i] -> GetYear();
            CountFilms = i;
        }
    if (CountYear == -1)
        cout << "No matches to " << NAuthor << endl;
    else
        movies[CountFilms] -> WriteInFile(cout);
    cout << endl;
}

void Shop :: SearchGoodFilm()
{
    cout << "Enter genre: ";
    string NGenre;
    getline(cin, NGenre);
    cout << "Enter rating: ";
    float NRating;
    cin >> NRating;
    cin.get();
    bool CountFilm = false;
    for (int i = 0; i < FilmNumber; i++)
        if (movies[i] -> ComparisonGenres(NGenre) == true && movies[i] -> GetIMDb() >= NRating)
        {
            movies[i] -> WriteInFile(cout);
            cout << endl;
            CountFilm = true;
        }
    if (CountFilm == false)
        cout << "No matches to genre " << NGenre << " and rating " << NRating;
    cout << endl;
}

void Shop :: DeleteFilm()
{
    cout << "Enter title: ";
    string Title;
    getline(cin, Title);
    bool CountFilm = false;
    int i = 0;
    for (i = 0; i < FilmNumber; i++)
        if(movies[i] -> GetTitle() == Title)
        {
            CountFilm = true;
            cout << "Want you delete this film:\n";
            movies[i] -> WriteInFile(cout);
            cout << endl;
            string ask;
            getline(cin, ask);
            if (ask == "Yes" || ask == "yes")
            {
                for (int o = i; o < FilmNumber - 1; o++)
                    movies[o] = movies[o + 1];
                FilmNumber--;
                cout << "Film was deleted\n";
            }
        }
    if(CountFilm == false)
        cout << "No matches\n";
}

void Shop :: AddFilm(string mode)
{
    cout << "Enter Title: ";
    string Title;
    getline(cin, Title);
    cout << "Enter Author: ";
    string Author;
    getline(cin, Author);
    cout << "Enter Genres: ";
    string Genres;
    getline(cin, Genres);
    cout << "Enter Year: ";
    int Year;
    cin >> Year;
    cin.get();
    cout << "Enter Duration: ";
    int Duration;
    cin >> Duration;
    cin.get();
    cout << "Enter IMDb: ";
    float IMDb;
    cin >> IMDb;
    cin.get();
    if (mode == "Film")
        movies[FilmNumber] = new Film(Title, Author, Genres, Year, Duration, IMDb);
    else if (mode == "Serial")
    {
        cout << "Enter Episodes: ";
        int Episodes;
        cin >> Episodes;
        cin.get();
        movies[FilmNumber] = new Serial(Title, Author, Genres, Year, Duration, IMDb, Episodes);
    }
    else if (mode == "TVSeries")
    {
        cout << "Enter Channel: ";
        string Channel;
        cin >> Channel;
        cout << "Enter StartTime: ";
        string StartTime;
        cin >> StartTime;
        movies[FilmNumber] = new TVSeries(Title, Author, Genres, Year, Duration, IMDb, Channel, StartTime);
    }

}

void Shop :: AddFilm()
{
    cout << "What you want to delete, Film, Serial or TVSeries: \n";
    int Definition;
    cout << "1) - Film\n2) - Serial\n3) - TVSeries\n";
    cin >> Definition;
    cin.get();
    switch (Definition)
    {
    case 1:
        Shop :: AddFilm("Film");
        movies[FilmNumber] -> WriteInFile(cout);
        FilmNumber++;
        cout << "\nWas added\n";
        break;
    case 2:
        Shop :: AddFilm("Serial");
        movies[FilmNumber] -> WriteInFile(cout);
        FilmNumber++;
        cout << "\nWas added\n";
        break;
    case 3:
        Shop :: AddFilm("TVSeries");
        movies[FilmNumber] -> WriteInFile(cout);
        FilmNumber++;
        cout << "\nWas added\n";
        break;
    default:
        cout << "Error\n";
        break;
    }
}

void Shop :: WriteFile()
{
    ofstream file;
    file.open("Film.txt");
    if(file)
    {
        for(int i = 1; i < FilmNumber; i++)
        {

            if(typeid(*(movies[i])) == typeid(Film))
                file << "Film" << endl;
            else if(typeid(*(movies[i])) == typeid(Serial))
                file << "Serial" << endl;
            else if(typeid(*(movies[i])) == typeid(TVSeries))
                file << "TV" << endl;
            movies[i] -> WriteInFile(file);
        }

    }
}
