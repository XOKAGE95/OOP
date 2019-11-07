#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "Film.h"
#include "shop.h"
using namespace std;

void shop :: Definition()
{
    cout << setw(30) << left << "Title";
    cout << setw(20) << left << "Author";
    cout << setw(30) << left << "Genre";
    cout << setw(10) << left << "Year";
    cout << setw(10) << left << "Duration";
    cout << setw(5) << left << "IMDb" << endl << endl << endl;
}

shop :: shop (unsigned int MAX) // Конструктор класса shop;
{
    max_film_number = MAX;                                  // Максимальное количество фильмов
    moves = new Film[max_film_number];                      // Массив для хранения фильмов
    film_number = 0;                                        // это просто счетчик актуального фильма


}

shop :: ~shop ()                                            // Деструктор
{
    delete[] moves;
    film_number = 0;
    max_film_number = 0;
}


void shop :: Display()                                      // Показ всех фильмов
{
    Definition ();
    for (int i = 0; i < film_number; i++)
        cout << moves[i];                           // Показ i фильмов
}

void shop :: Search_good_film ()                           // Задание 1
{
    cout << "Enter genre: ";
    string genre;
    getline (cin, genre);
    cout << "Enter rating: ";
    float rating;
    cin >> rating;
    cin.get();
    int film_count = 0;
    for (int i = 0; i < film_number; i++)
    {
        if ((moves[i].comparison_Genre(genre) != 0) && (moves[i].get_IMDb() >= rating))
        {
            film_count++;
            cout << moves[i];
        }
    }
    if (film_count == 0)
        cout << "This films didn't find" << endl;
}


void shop :: Search_latest_film_of_author () // Задание 2
{
    cout << "Enter author: ";
    string author;
    getline (cin, author);
    int year = -1;
    int film_count = -1;
    for (int i = 0; i < film_number; i++)
    {
        if ((moves[i].get_Author() == author) && (moves[i].get_Year() >= year))
        {
            film_count = i;
            year = moves[i].get_Year();
        }

    }
    if (film_count >= 0)
    {
        cout << moves[film_count];
    }
    else
        cout << "Didn't find author" << endl;
}

void shop :: delete_film(string name) // Удаление фильма
{
    int count_i = -1;
    for (int i = 0; i < film_number && count_i == -1; i++)
    {
        if (moves[i].get_Title() == name)
        {
            count_i = i;
        }
    }
    if (count_i != -1)
    {
        cout << "This film was delete:\n";
        cout << moves[count_i];
        for (int i= count_i; i < (film_number - 1); i++)
        {
            moves[i] = moves[i+1];
        }
        film_number --;



    }

    else
        cout << "Didn't find this film\n";
}

void shop :: operator+=(Film clip) //Добавление фильма
{
    if (film_number < max_film_number)
    {
        moves[film_number] = clip;
        film_number ++;
    }
    else cout << "Sorry, can't add film";

}
