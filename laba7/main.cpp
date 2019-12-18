#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>

#include "shop.h"

using namespace std;

enum
{
    Help,
    Delete,
    Add,
    Finish,
    Quest,
    Error,
    Show,
} Task;

enum Color
{
    Black         = 0,
    Blue          = 1,
    Green         = 2,
    Cyan          = 3,
    Red           = 4,
    Magenta       = 5,
    Brown         = 6,
    LightGray     = 7,
    DarkGray      = 8,
    LightBlue     = 9,
    LightGreen    = 10,
    LightCyan     = 11,
    LightRed      = 12,
    LightMagenta  = 13,
    Yellow        = 14,
    White         = 15
};

void SetColor(Color text, Color background)
{
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void WriteCommand(string name)
{
    SetColor(LightRed , Black);
    cout << name;
}

void WriteText(string name)
{
    SetColor(LightGray , Black);
    cout << name;
}


void Commands()
{
    WriteCommand("Help");
    WriteText(" or ");
    WriteCommand("help");
    WriteText(" to display commands.\n");

    WriteCommand("Add");
    WriteText(" or ");
    WriteCommand("add");
    WriteText(" to add film.\n");

    WriteCommand ("Delete");
    WriteText(" or ");
    WriteCommand(" delete ");
    WriteText(" to delete film\n");

    WriteCommand("Task");
    WriteText(" or ");
    WriteCommand("task");
    WriteText(" to doing tasks\n");

    WriteCommand("Show");
    WriteText(" or ");
    WriteCommand("show");
    WriteText(" to showing all films\n");

    WriteCommand("Finish");
    WriteText(" or ");
    WriteCommand("finish");
    WriteText(" to exit from program.\n");
}

int main ()
{
    ifstream file;
    file.open("Film.txt");

    if (!file)
    {
        cout << "This file didn't found" << endl;
        return 1;
    }
    else
    {
        Shop FilmStore(50);
        FilmStore.ReadFile(file);
        file.close();
        FilmStore.WriteFile(cout);
        cout << "Write help to display a list of commands\n";
        while(true)
        {
            string Command;
            getline(cin, Command);
            if (Command == "Help" || Command == "help")
                Task = Help;
            else if (Command == "Add" || Command == "add")
                Task = Add;
            else if (Command == "Delete" || Command == "delete")
                Task = Delete;
            else if (Command == "Finish" || Command == "finish")
                Task = Finish;
            else if (Command == "Task" || Command == "task")
                Task = Quest;
            else if (Command == "Show" || Command == "show")
                Task = Show;
            else Task = Error;

            switch(Task)
            {
            case Help:
                Commands();
                break;
            case Add:
                FilmStore.AddFilm();
                break;
            case Delete:
                FilmStore.DeleteFilm();
                break;
            case Finish:
                FilmStore.WriteFile(cout);
                FilmStore.WriteFile();
                return 0;
            case Quest:
                FilmStore.SearchLatestFilmOfAuthor();
                FilmStore.SearchGoodFilm();
                break;
            case Error:
                cout << "The command does not exist" << endl;
                break;
            case Show:
                FilmStore.WriteFile(cout);
            }
        }
    }
}
