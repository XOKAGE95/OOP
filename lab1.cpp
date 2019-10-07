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
            getline (file, Title);
            getline (file, Author);
            getline (file, Genre);
            file >> Year;
            file >> Duration;
            file >> IMDb;
            file.get();
        };
        void Write()
        {
            cout << Title;
            cout << Author;
            cout << Genre;
            cout << Year;
            cout << Duration;
            cout << IMDb;
        };

    };

    void Search_good_film (Film *move, int NUMBER)
    {
        cout << "Enter genre: ";
        string genre;
        getline (cin, genre);
        cout << "Enter rating: ";
        float rating;
        cin >> rating;
        int film_count = 0;
        for (int i = 0; i < NUMBER; i++)
        {
            if ((move[i].Genre == genre) && (move[i].IMDb >= rating))
            {
                film_count++;
                move[i].Write();
            }
        }
        if (film_count == 0)
            cout << "This films didn't found" << endl;
    }


    void Search_latest_film_of_author (Film *move, int NUMBER)
    {
        cout << "Enter author: ";
        string author;
        getline (cin, author);
        int year = -1;
        int film_count = -1;
        for (int i = 0; i < NUMBER; i++)
        {
            if ((move[i].Author == author) && (move[i].Year >= year))
            {
                film_count = i;
                year = move[i].Year;
            }

        }
        if (film_count >= 0)
            move[film_count].Write();
        else
            cout << "Didn't found author" << endl;
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
            move[i].Read(file);
        file.close();
        Search_latest_film_of_author (move, NUMBER);
        Search_good_film (move, NUMBER);
        delete[] move;
        return 0;
    }
}

