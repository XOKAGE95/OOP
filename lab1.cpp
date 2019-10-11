#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "Film.h"
#include "Film.cpp"

using namespace std;



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
        if ((move[i].get_Genre() == genre) && (move[i].get_IMDb() >= rating))
        {
            film_count++;
            move[i].Write_console();
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
        if ((move[i].get_Author() == author) && (move[i].get_Year() >= year))
        {
            film_count = i;
            year = move[i].get_Year();
        }

    }
    if (film_count >= 0)
        move[film_count].Write_console();
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
            move[i].Read_file(file);
        file.close();
        Definition();
        for (int i = 0; i < NUMBER; i++)
            move[i].Write_console();
        Search_latest_film_of_author (move, NUMBER);
        Search_good_film (move, NUMBER);
        ofstream file;
        file.open("FilmOUT.txt");
        Definition_file(file);
        for (int i = 0; i < NUMBER; i++)
            move[i].Write_file(file);
        file.close();
        delete[] move;
        return 0;
    }
}

