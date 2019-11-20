#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "Film.h"
#include "shop.h"
#include "Film.cpp"
#include "shop.cpp"

using namespace std;

int main()
{
    int NUMBER;
    ifstream file_movie;
    ifstream file_serial;
    file_movie.open("Film.txt");
    file_serial.open("Serial.txt");
    if (!file_movie && !file_serial)
    {
        cout << "This file didn't found" << endl;
        return 1;
    }
    else
    {

        file_movie >> NUMBER;
        file_movie.get();
        shop film_store(50);
        for (int i = 0; i < NUMBER; i++)
            film_store.add_film(file_movie);
        NUMBER = 0;
        file_serial >> NUMBER;
        file_serial.get();
        for (int i = 0; i < NUMBER; i++)
            film_store.add_serial(file_serial);
        film_store.Display();
        film_store.Search_latest_film_of_author ();
        film_store.Search_good_film ();
        cout << "Want you delete any film?\n";
        string ask;
        getline(cin, ask);
        while (ask == "yes")
        {
            cout << "Which film you want to delete?\n";
            string name;
            getline(cin, name);
            film_store.delete_film(name);
            cout << "Want you delete any film?\n";
            cin >> ask;

        }

        film_store.Display();
        file_movie.close();
        file_serial.close();
        return 0;
    }
}

