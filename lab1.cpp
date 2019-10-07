#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>


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
            getline(file, Title);
            //file >> Title;
            //file.ignore(255, '\n');
            getline (file, Author);
            file >> Genre;
            //getline (file, Genre);
            file.ignore(255, '\n');
            file >> Year;
            file.ignore(255, '\n');
            file >> Duration;
            file.ignore(255, '\n');
            file >> IMDb;
            file.ignore(255, '\n');
        };
        void Write()
        {
            cout << setw(20) << left << Title;
            cout << setw(20) << left << Author;
            cout << setw(15) << left << Genre;
            cout << setw(10) << left << Year;
            cout << setw(6) << left << Duration;
            cout << setw(5) << left << IMDb << endl;
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
        file.get();
        Film *move = new Film[NUMBER];
        for (int i = 0; i < NUMBER; i++)
            move[i].Read(file);
        file.close();
        for (int i = 0; i < NUMBER; i++)
            move[i].Write();
        Search_latest_film_of_author (move, NUMBER);
        Search_good_film (move, NUMBER);
        delete[] move;
        return 0;
    }
}

