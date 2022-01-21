#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <fstream>
#define Listsize 30

using namespace std;

void scoreboard()
{
    string player[10]={"???"};
    int score[10]={0};
    int i;

    ifstream board;
    board.open("scoreboard.txt",ios::in);

    system("CLS");
    cout << "==================================================" << endl << endl;
    cout << "                    SCORE BOARD                   " << endl << endl;
    cout << "==================================================" << endl << endl;
    cout << "                      TOP 10                      " << endl << endl;
    for(i=0 ; i<10 ; i++)
    {
        board >> player[i] >> score[i];
        cout << setw(15) << i+1 << ".  " << left << setw(10) << player[i] << right << setw(8) << score[i] << endl;
    }
    cout << endl << "==================================================" << endl;

    getch();
    system("CLS");
}

#endif // SCOREBOARD_H
