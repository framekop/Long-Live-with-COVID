#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <exception>
#include <windows.h>
#include "PLAYER.h"
#include "ERROR_CHECK.h"
#include "SCOREBOARD.h"
#include "COLOR.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int mainmenu=1, newgame=1, run=1;
    string input_name;
    srand((unsigned)time(0));

    while(mainmenu)
    {
        int ch=1, cl=0;
        while( cl != 13 )       //13 = ENTER
        {
            if(cl == 72)        //72 = UP
            {
                ch -= 1;
                if(ch < 1)
                {
                    ch = 3;
                }
            }
            if(cl == 80)        //80 = DOWN
            {
                ch += 1;
                if(ch > 3)
                {
                    ch = 1;
                }
            }
            if(ch == 1)
            {
                resetcolor();
                cout << "==================================================" << endl;
                textcolor(BLACK,DARKYELLOW);
                gotoxy(13,2);
                cout << "Long Live with COVID-19" << endl << endl;
                resetcolor();
                cout << "==================================================" << endl << endl;
                textcolor(DARKYELLOW,BLACK);
                cout << "                >> New Game" << endl;
                resetcolor();
                cout << "                   Score Board" << endl;
                cout << "                   Exit" << endl << endl;
                cout << "==================================================" << endl;
            }
            if(ch == 2)
            {
                cout << "==================================================" << endl;
                textcolor(BLACK,DARKYELLOW);
                gotoxy(13,2);
                cout << "Long Live with COVID-19" << endl << endl;
                resetcolor();
                cout << "==================================================" << endl << endl;
                cout << "                   New Game" << endl;
                textcolor(DARKYELLOW,BLACK);
                cout << "                >> Score Board" << endl;
                resetcolor();
                cout << "                   Exit" << endl << endl;
                cout << "==================================================" << endl;
            }
            if(ch == 3)
            {
                cout << "==================================================" << endl;
                textcolor(BLACK,DARKYELLOW);
                gotoxy(13,2);
                cout << "Long Live with COVID-19" << endl << endl;
                resetcolor();
                cout << "==================================================" << endl << endl;
                cout << "                   New Game" << endl;
                cout << "                   Score Board" << endl;
                textcolor(DARKYELLOW,BLACK);
                cout << "                >> Exit" << endl << endl;
                resetcolor();
                cout << "==================================================" << endl;
            }
            cl = getch();
            system("CLS");
        }

        if(ch == 1)
        {
            mainmenu=0;
            while(newgame)
            {
                try
                {
                    system("CLS");
                    textcolor(DARKBLUE,BLACK);
                    cout << "==================================================" << endl;
                    textcolor(DARKRED,BLACK);
                    cout << endl << setw(27) << "Your name : ";
                    textcolor(BLACK,DARKGREEN);
                    cin >> input_name;        newgame = 0;
                    textcolor(DARKBLUE,BLACK);
                    cout <<endl<< "==================================================" << endl;
                    resetcolor();
                    if(cin.fail())  { throw "...Please insert your name..."; }
                }
                catch(const char* name_err)
                {
                    cerr << endl << name_err << endl;
                    cin.clear();
                    cin.ignore(15,'\n');
                    newgame = 1;
                }
            }
        }
        else if(ch == 2)
        {
            scoreboard();
        }
        else if(ch == 3)
        {
            exit(EXIT_SUCCESS);
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////

    PLAYER user(input_name);
    ERROR_CHECK err;

    while(run)
    {
        try
        {
            switch(user.menu())
            {
                case 1 : user.menu_goshopping();
                         system("CLS");
                         break;
                case 2 : system("CLS");
                         user.menu_daily();
                         system("CLS");
                         break;
                case 3 : user.menu_inventory();
                         system("CLS");
                         break;
                case 4 : user.menu_nothing();
                         system("CLS");
                         break;
                default: throw err;
                         break;
            }
            run = user.gameover();///RETURN = 1||0
        }

        catch(ERROR_CHECK &error)
        {
            cerr << endl << error.what() << endl << endl;
            run = 1;
        }
    }

    cout << endl << endl << "                ....END PROGRAM....               " << endl << endl;
    resetcolor();
    getch();
}
