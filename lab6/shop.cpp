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

shop :: shop (unsigned int MAX) // Конструктор класса shop;
{
    max_film_number = MAX;                                  // Максимальное количество фильмов
    movies = new Film[max_film_number];                      // Массив для хранения фильмов
    serial_number = 0;
    film_number = 0;                                        // это просто счетчик актуального фильма
    series = new serial[max_film_number];

}

shop :: ~shop ()                                            // Деструктор
{
    delete[] movies;
    film_number = 0;
    max_film_number = 0;
    serial_number = 0;
}


void shop :: Display()                                      // Показ всех фильмов
{
    cout << "MOVIES:" << endl;
    cout << setw(30) << left << "Title";
    cout << setw(20) << left << "Author";
    cout << setw(30) << left << "Genre";
    cout << setw(10) << left << "Year";
    cout << setw(10) << left << "Duration";
    cout << setw(5) << left << "IMDb" << endl << endl;
    for (int i = 0; i < film_number; i++)
        cout << movies[i] << endl;                           // Показ i фильмов

    cout << "SITCOMES:" << endl;
    cout << setw(30) << left << "Title";
    cout << setw(20) << left << "Author";
    cout << setw(30) << left << "Genre";
    cout << setw(10) << left << "Year";
    cout << setw(10) << left << "Duration";
    cout << setw(5)  << left << "IMDb";
    cout << setw(9)  << left << "Episodes" << endl << endl;
    for (int i = 0; i < serial_number; i++)
        cout << series[i] << endl;

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
    for (int i = 0; i < serial_number; i++)
    {
        if
        (
            (series[i].comparison_Genre(genre))
            && (series[i].get_IMDb() >= rating)
        )
        {
            film_count++;
            cout << series[i] << endl;
        }
    }
    for (int i = 0; i < film_number; i++)
    {
        if
        (
            (movies[i].comparison_Genre(genre))
            && (movies[i].get_IMDb() >= rating)
        )
        {
            film_count++;
            cout << movies[i] << endl;
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
        if
        (
            (movies[i].get_Author() == author)
            && (movies[i].get_Year() >= year)
        )
        {
            film_count = i;
            year = movies[i].get_Year();
        }

    }
    if (film_count >= 0)
        cout << movies[film_count] << endl;
    else
        cout << "Didn't find author" << endl;
}

void shop :: delete_film(string name) // Удаление фильма
{
    int count_i = -1;
    for (int i = 0; i < film_number && count_i == -1; i++)
    {
        if (movies[i].get_Title() == name)
        {
            count_i = i;
        }
    }
    if (count_i != -1)
    {
        cout << "This film was delete:\n";
        cout << movies[count_i];
        for (int i= count_i; i < (film_number - 1); i++)
            movies[i] = movies[i+1];
        film_number --;
    }

    else
        cout << "Didn't find this film\n";
}

void shop :: add_film(istream &file)
{
    Film clip;
	file >> clip;
	operator+= (clip);
}

void shop :: add_serial(istream &file)
{
    serial sitcom;
	file >> sitcom;
	operator+= (sitcom);
}

void shop :: operator+=(Film clip) //Добавление фильма
{
    if ((film_number + serial_number) < max_film_number)
    {
        movies[film_number] = clip;
        film_number ++;
    }
    else cout << "Sorry, can't add film";

}

void shop :: operator+=(serial sitcom) //Добавление сериала
{
    if ((film_number + serial_number) < max_film_number)
    {
        series[serial_number] = sitcom;
        serial_number ++;
    }
    else cout << "Sorry, can't add serial" << endl;

}
