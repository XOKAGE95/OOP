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
    moves = new Film[max_film_number];                      // Массив для хранения фильмов
    film_number = 0;                                        // это просто счетчик актуального фильма


}

shop :: ~shop ()                                            // Деструктор
{
    delete[] moves;
    film_number = 0;
    max_film_number = 0;
}

void shop :: add_film (string mode, ifstream &file)            // Добавление 1 фильма в магазин
{
    if ((film_number < max_film_number) && (mode == "file"))  // Проверка на свободное место
    {
        moves[film_number].Read_file(file);
        film_number ++;                                       // Счетчик актуального фильма
    }
    else if ((film_number < max_film_number)  && (mode == "console"))
    {
        moves[film_number].Read_console();
        film_number ++;
    }
    else cout << "Sorry, cant add films" << endl;

}

void shop :: Display()                                      // Показ всех фильмов
{
        Definition ();
    for (int i = 0; i < film_number; i++)
        moves[i].Write_console();                           // Показ i фильма
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
        if ((moves[i].get_Genre() == genre) && (moves[i].get_IMDb() >= rating))
        {
            film_count++;
            Definition();
            moves[i].Write_console();
        }
    }
    if (film_count == 0)
        cout << "This films didn't found" << endl;
}


void shop :: Search_latest_film_of_author ()
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
        Definition();
        moves[film_count].Write_console();
    }
    else
        cout << "Didn't found author" << endl;
}

void shop :: Definition()                   // Выводит поля в консоль
{
    cout << setw(20) << left << "Title";
    cout << "|";
    cout << setw(20) << left << "Author";
    cout << "|";
    cout << setw(15) << left << "Genre";
    cout << "|";
    cout << setw(10) << left << "Year";
    cout << "|";
    cout << setw(10) << left << "Duration";
    cout << "|";
    cout << setw(5) << left << "IMDb";
    cout << "|";
    cout << endl;
    for (int i = 0; i < 85; i++)
        cout << "-";
    cout << endl;
}

void shop :: Definition_file(ofstream &file)        // Выводит поля в файл
{
    file << setw(20) << left << "Title";
    file << setw(20) << left << "Author";
    file << setw(15) << left << "Genre";
    file << setw(10) << left << "Year";
    file << setw(6) << left << "Duration";
    file << setw(5) << left << "IMDb" << endl;
}
