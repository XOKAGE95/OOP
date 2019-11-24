#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "shop.h"
using namespace std;

shop :: shop (unsigned int MAX) // Конструктор класса shop;
{
    max_film_number = MAX;                                  // Максимальное количество фильмов
    movies = new Film[max_film_number];                      // Массив для хранения фильмов
    serial_number = 0;
    film_number = 0;                                        // это просто счетчик актуального фильма
    series = new Serial[max_film_number];

}

shop :: ~shop ()                                            // Деструктор
{
    delete[] movies;
    delete[] series;
    film_number = 0;
    max_film_number = 0;
    serial_number = 0;

}


void shop :: Display()                                      // Показ всех фильмов
{
    cout << "MOVIES:" << endl << endl;
    Definition();
    cout << endl << endl;
    for (unsigned int i = 0; i < film_number; i++)
        cout << movies[i] << endl;                           // Показ i фильмов
    cout << endl;
    cout << "SITCOMES:" << endl << endl;
    Definition();
    cout << setw(9)  << left << "Episodes" << endl << endl;
    for (unsigned int i = 0; i < serial_number; i++)
        cout << series[i] << endl;
    cout << endl;

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
    for (unsigned int i = 0; i < serial_number; i++)
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
    for (unsigned int i = 0; i < film_number; i++)
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
    for (unsigned int i = 0; i < film_number; i++)
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

void shop :: delete_film(string name) // Удаление Фильма
{
    int count_i = -1;
    for (unsigned int i = 0; i < film_number && count_i == -1; i++)
    {
        if (movies[i].get_Title() == name)
        {
            count_i = i;
        }
    }
    if (count_i != -1)
    {
        cout << "Are you sure want delete this film:\n";
        cout << movies[count_i] << endl;
        string ask;
        getline(cin, ask);
        if (ask == "Yes" || ask == "yes")
        {
            for (unsigned int i= count_i; i < (film_number - 1); i++)
                movies[i] = movies[i+1];
            film_number --;
        }
        else
            return;
    }

    else
        cout << "Didn't find this film\n";
}
void shop :: delete_serial(string name) // Удаление Сериала
{
    int count_i = -1;
    for (unsigned int i = 0; i < serial_number && count_i == -1; i++)
    {
        if (series[i].get_Title() == name)
        {
            count_i = i;
        }
    }
    if (count_i != -1)
    {
        cout << "Are you sure want delete this serial:\n";
        cout << series[count_i] << endl;
        string ask;
        getline(cin, ask);
        if (ask == "Yes" || ask == "yes")
        {
            for (unsigned int i= count_i; i < (serial_number - 1); i++)
                series[i] = series[i+1];
            serial_number --;
        }
        else
            return;
    }

    else
        cout << "Didn't find this serial\n";
}
void shop :: add_film(istream &file)
{
    Film clip;
    file >> clip;
    operator+= (clip);
}

void shop :: add_serial(istream &file)
{
    Serial sitcom;
    file >> sitcom;
    operator+= (sitcom);
}

void shop :: operator+=(Film clip) //Добавление фильма
{
    if (film_number < max_film_number)
    {
        movies[film_number] = clip;
        film_number ++;
    }
    else
        cout << "Sorry, can't add film";

}

void shop :: operator+=(Serial sitcom) //Добавление сериала
{
    if (serial_number < max_film_number)
    {
        series[serial_number] = sitcom;
        serial_number ++;
    }
    else
        cout << "Sorry, can't add serial" << endl;

}

void shop :: make_file(int NUMBERF, int NUMBERS)
{
    ofstream file;
    file.open("Film.txt");
    file << NUMBERF << endl;
    for(int i = 0; i < NUMBERF; i++)
        movies[i].Enter_file(file);
    file.close();
    file.open("Serial.txt");
    file << NUMBERS << endl;
    for(int i = 0; i < NUMBERS; i++)
        series[i].Enter_file(file);
    file.close();
}
void shop :: Definition()
{
    cout << setw(30) << left << "Title";
    cout << setw(20) << left << "Author";
    cout << setw(30) << left << "Genre";
    cout << setw(10) << left << "Year";
    cout << setw(10) << left << "Duration";
    cout << setw(5)  << left << "IMDb";
}

