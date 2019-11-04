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


/*
Для своего варианта задания реализуйте операторные функции:
 проверки двух объектов основного класса на эквивалентность (operator==),
 вывода информации в поток ostream (operator<<),
 ввода данных из потока istream (operator>>),
 записи в файловый поток ofstream (operator<<),
 чтения из файлового потока ifstream (operator>>),
 добавления нового элемента в класс-контейнер (operator+=).
*/

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
        shop film_store(NUMBER);
        for (int i = 0; i < NUMBER; i++)
            film_store.add_film("file", file);
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

        return 0;
    }
}

