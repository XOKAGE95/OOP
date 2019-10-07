#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>


// #include <>
/*
	Название
	Автор
	Жанр
	Длительность
	Год
	Рейтинг

*/

using namespace std;

    class Film
    {   public:
        string Title;
        string Author;
        string Genre;
        int Year;
        int Duration;
        float IMDb;
        void Read(ifstream &file)
        {
            getline (file, Film.Title);
            file.ignore(255, \n);
            getline (file, Film.Author);
            file.ignore(255, \n);
            getline (file, Film.Genre);
            file.ignore(255, \n);
            file >> Film.Year;
            file.ignore(255, \n);
            file >> Film.Duration;
            file.ignore(255, \n);
            file >> Film.IMDb;
            file.ignore(255, \n);
        };
        void Write()
        {
            cout << setw(15) << left << Film.Title;
            cout << setw(15) << left << Film.Author;
            cout << setw(10) << left << Film.Genre;
            cout << setw(6) << left << Film.Year;
            cout << setw(5) << left << Film.Duration;
            cout << setw(5) << left << Film.IMDb;
        };

    };

    void Search_good_film (Film *move, int NUMBER)
    {
        cout << "Enter genre: ";
        string genre;
        cin >> genre;
        cout << "Enter rating: ";
        float rating;
        cin >> rating;
        film_count = 0;
        for (int i = 0; i < NUMBER; i++)
        {
            if ((move[i].Genre == genre) && (move[i].IMDb >= rating))
            {
                film_count++;
                move[i].Write();
            }
        }
        if (film_count == 0)
            cout << "This films didn't found"
    }


    void Search_latest_film_of_author (Film *move, int NUMBER)
    {
        cout << "Enter author: ";
        string author;
        cin >> author;
        int year
        for (int i = 0; i < NUMBER; i++)
        {
            if
        }
    }



int main()
{
    int NUMBER;
    ifstream file;
    file.open("Film.txt");
    if (!file)
    {
        cout << "This file didn't found" << endl;
        return 1;
    }
    else
    {

        file >> NUMBER;
        Film *move = new Film[NUMBER];
        for (int i = 0; i < NUMBER; i++)
            move[i].Read();
        file.close();
        Search_latest_film_of_author (move, NUMBER);
        Search_good_film (move, NUMBER);
        delete Film[];
        return 0;
    }
}

