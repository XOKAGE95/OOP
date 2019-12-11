#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include "Film.h"
#include "shop.h"
#include "serial.h"
using namespace std;


int main()
{
    int NUMBERF, NUMBERS;
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

        file_movie >> NUMBERF;
        file_movie.get();
        shop film_store(50);
        for (int i = 0; i < NUMBERF; i++)
            film_store.add_film(file_movie);
        file_movie.close();
        file_serial >> NUMBERS;
        file_serial.get();
        for (int i = 0; i < NUMBERS; i++)
            film_store.add_serial(file_serial);
        file_serial.close();
        film_store.Display();
        string ask;
        cout << "Want you add any film or serial?\n";
        getline(cin, ask);
        while (ask == "yes" || ask == "Yes")
        {
            cout << "What you want add, film or serial?\n";
            string name;
            getline(cin, name);
            if (name == "film" || name == "Film")
            {
                NUMBERF ++;
                Film clip;
                cout << "Write Title, Author, Genre, Year, Duration, IMDb\n";
                cin >> clip;
                film_store += clip;
            }
            else if (name == "serial" || name == "Serial")
            {
                NUMBERS++;
                Serial clip;
                cout << "Write Title, Author, Genre, Year, Duration, IMDb, Episodes\n";
                cin >> clip;
                film_store += clip;
            }
            else
            {
                ask == "yes";
                continue;
            }
            cout << "Want you add any film or serial?\n";
            getline(cin, ask);
        }


        cout << "Want you delete any film?\n";
        getline(cin, ask);
        while (ask == "yes" || ask == "Yes")
        {
            bool leg = false;
            cout << "What you want to delete, Film or serial?\n";
            string name;
            getline(cin, name);
            if (name == "Film" || name == "film")
            {
                cout << "Which film you want to delete?\n";
                string FilmName;
                getline (cin, FilmName);
                film_store.delete_film(FilmName, &leg);
                if (leg == true)
                    NUMBERF --;

            }
            else if (name == "Serial" || name == "serial")
            {
                cout << "Which serial you want to delete?\n";
                string SerialName;
                getline(cin, SerialName);
                film_store.delete_serial(SerialName, &leg);
                if (leg == true)
                    NUMBERS--;
            }
            else
            {
                ask = "yes";
                continue;
            }
            cout << "Want you delete any film?\n";
            getline (cin, ask);

        }
        film_store.Display();
        film_store.Search_latest_film_of_author ();
        film_store.Search_good_film ();
        film_store.make_file(NUMBERF, NUMBERS);
        return 0;
    }
}
