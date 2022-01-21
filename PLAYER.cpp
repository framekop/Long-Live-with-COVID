#include "PLAYER.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <fstream>
#include "color.h"
#include <windows.h>

PLAYER :: PLAYER(string x)
{
    name            = x;
    netflix_access  = 0;
    hp              = 100;
    food            = 100;
    water           = 100;
    strength        = 100;
    mental          = 100;
    money           = 100;

    immunity        = 0;
    score           = 0;

    cout << endl << setw(25-((name.length())/2)) << "Hi! ";
    textcolor(DARKGREEN,BLACK);
    cout<< name << endl;
    resetcolor();
    cout << "       Welcome to \"Long Live with COVID-19\"     " << endl << endl;
    cout << "   At present the Coronavirus is widespread around" << endl;
    cout << "   the world. You have to stay at home 14 days for" << endl;
    cout << "   avoiding the virus.                            " << endl << endl;
    cout << "   In a hopeless world, you have to choose between" << endl << endl;
    textcolor(DARKYELLOW,BLACK);
    cout << "                DEATH or SURVIVAL.                " << endl << endl;
    textcolor(DARKRED,BLACK);
    cout << "==================================================" << endl;
    resetcolor();
    getch();
    system("CLS");
    cout << "==================================================" << endl << endl;
    textcolor(BLUE,BLACK);
    cout << "                  How to survive?                 " << endl;
    resetcolor();
    cout << "  You should do activities and eat food to control" << endl;
    cout << "  your emotional and physical condition.          " << endl;
    cout << "        Keep extremely calm and stay happy.       " << endl << endl;
    cout << "    Let's find the strongest survivor with us...  " << endl << endl;
    textcolor(DARKRED,BLACK);
    cout << "                   !!!Caution!!!                  " << endl;
    resetcolor();
    cout << "  You can go outside but it has risk to infection." << endl;
    cout << "  If you infected COVID-19, you have to quarantine" << endl;
    cout << "  and stay at home for MORE 14 days!!             " << endl << endl;
    cout << "==================================================" << endl;
    getch();
    system("CLS");
    cout << "==================================================" << endl << endl;
    textcolor(BLUE,BLACK);
    cout << "                    Controller                    " << endl << endl;
    resetcolor();
    cout << "                 Up Arrow  =  Up                  " << endl;
    cout << "               Down Arrow  =  Down                " << endl;
    cout << "               Left Arrow  =  Left                " << endl;
    cout << "              Right Arrow  =  Right               " << endl;
    cout << "                    Enter  =  Select              " << endl;
    cout << "                Backspace  =  Back                " << endl << endl;
    cout << "==================================================" << endl;
    getch();
    system("CLS");

}
//////////////////////////////////////////////////
PLAYER :: ~PLAYER()
{
   textcolor(BLACK,YELLOW); cout << "            ...USER HAS BEEN DELETED...           " << endl; resetcolor();
}
//////////////////////////////////////////////////MENU
int  PLAYER :: menu()
{

    int ch=1, cl;
    while(cl != 13)
    {
        if(cl == 72)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = 4;
            }
        }
        if(cl == 80)
        {
            ch += 1;
            if(ch > 4)
            {
                ch = 1;
            }
        }
        if(ch == 1)
        {
            stat_display();
            textcolor(DARKYELLOW,BLACK);
            cout << "                >> Go shopping" << endl;
            resetcolor();
            cout << "                   Daily life" << endl;
            cout << "                   Open fridge" << endl;
            cout << "                   Do nothing" << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 2)
        {
            stat_display();
            cout << "                   Go shopping" << endl;
            textcolor(DARKYELLOW,BLACK);
            cout << "                >> Daily life" << endl;
            resetcolor();
            cout << "                   Open fridge" << endl;
            cout << "                   Do nothing" << endl << endl;
            resetcolor();
            cout << "==================================================" << endl;
        }
        if(ch == 3)
        {
            stat_display();
            cout << "                   Go shopping" << endl;
            cout << "                   Daily life" << endl;
            textcolor(DARKYELLOW,BLACK);
            cout << "                >> Open fridge" << endl;
            resetcolor();
            cout << "                   Do nothing" << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 4)
        {
            stat_display();
            cout << "                   Go shopping" << endl;
            cout << "                   Daily life" << endl;
            cout << "                   Open fridge" << endl;
            textcolor(DARKYELLOW,BLACK);
            cout << "                >> Do nothing" << endl << endl;
            resetcolor();
            cout << "==================================================" << endl;
        }
        resetcolor();
        cl = getch();
        system("CLS");
    }

    if(ch == 1)
    {
        return 1;
    }
    else if(ch == 2)
    {
        return 2;
    }
    else if(ch == 3)
    {
        return 3;
    }
    else if(ch == 4)
    {
        return 4;
    }
}
//////////////////////////////////////////////////MENU GO SHOPPING
int  PLAYER :: menu_goshopping()
{
    int ch=1, cl=0;
    while( cl != 13 )
    {
        if(cl == 72)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = 2;
            }
        }
        if(cl == 80)
        {
            ch += 1;
            if(ch > 2)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            return 0;
        }

        if(ch == 1)
        {
            stat_display();
            textcolor(DARKGREEN,BLACK);
            cout << "                >> Go by myself                   " << endl;
            resetcolor();
            cout << "                   Call GRAB                      " << endl << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 2)
        {
            stat_display();
            cout << "                   Go by myself                   " << endl;
            textcolor(DARKGREEN,BLACK);
            cout << "                >> Call GRAB                      " << endl << endl;
            resetcolor();
            cout << "        (GRAB has a shipping cost of 50$)         " << endl;
            cout << "==================================================" << endl;
        }
        cl = getch();
        system("CLS");
    }

    if(ch == 1)
    {
        if( quarantine > 0 )
        {
            stat_display();
            cout << "           You are infected COVID-19!!!           " << endl;
            cout << "        You must stay at home for " << quarantine << " days." << endl << endl;
            cout << "==================================================" << endl;
            getch();
        }
        else    goout_ornot();
    }
    else if(ch == 2)
    {
        shop_grab();
    }
}
/////////////////////////
int  PLAYER :: goout_ornot()
{
    int i, pro;
    int ch=1, cl=0;
    while( cl != 13 )
    {
        if(cl == 75)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = 2;
            }
        }
        if(cl == 77)
        {
            ch += 1;
            if(ch > 2)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            return 0;
        }

        if(ch == 1)
        {
            stat_display();
            cout << "            Do you want to go outside?            " << endl;
            cout << "        There are high risks of infection.        " << endl;
            cout << "  (Can be reduced by using protective equipment.) " << endl << endl;
            cout << "==================================================" << endl << endl;
            cout << "              >> Yes           No                 " << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 2)
        {
            stat_display();
            cout << "            Do you want to go outside?            " << endl;
            cout << "        There are high risks of infection.        " << endl;
            cout << "  (Can be reduced by using protective equipment.) " << endl << endl;
            cout << "==================================================" << endl << endl;
            cout << "                 Yes        >> No                 " << endl << endl;
            cout << "==================================================" << endl;
        }
        cl = getch();
        system("CLS");
    }

    if(ch == 1)
    {
        for(i=0,pro=0 ; i<10 ; i++)
        {
            if( item[3][i].call_amount() > 0 )      pro++;
        }

        if( pro > 0 )   protector_using();
        else            shop_myself();
    }
    else if(ch == 2)
    {
        return 1;
    }
}
/////////////////////////
int  PLAYER :: shop_myself()
{
    int i,j, n, all, pro, itemsize=10;   //COUT SYSTEM VAL
    int ch=1, cl, x=0, y=0;   //SELECT SYSTEM VALUE

    while(cl != 13)
    {
        for(i=0,all=0 ; i < 3 ; i++)
        {
            for(j=0 ; j < itemsize ; j++)
            {
                if( item[i][j].call_cost() > 0 )
                {
                    all++;
                }
            }
        }
        for(i=3,pro=0 ; i == 3 ; i++)
        {
            for(j=0 ; j < 5 ; j++)
            {
                if( item[i][j].call_amount() == 0 )
                {
                    all++;  pro++;
                }
            }
        }

        if(cl == 72)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = all;
            }
        }
        if(cl == 80)
        {
            ch += 1;
            if(ch > all)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            infection();
            goout_tired();
            return 0;
        }

        stat_display();
        for(i=0,n=0 ; i < 4 ; i++)
        {
            //cout << "\tch = " << ch << "\tn = " << n << "\tall = " << all << endl;      //VALUE CHECK LINE
            if(i==0)
            {
                cout << "                       SHOP                       " << endl;
                cout << "  Food" << endl;
            }
            if(i==1)
            {
                cout << "  Drink" << endl;
            }
            if(i==2)
            {
                cout << "  Medicine" << endl;
            }
            if(pro > 0 && i==3)
            {
                cout << "  Protector" << endl;
            }

            for(j=0 ; j < itemsize ; j++)
            {
                if( i != 3)
                {
                    if( item[i][j].call_cost() > 0 )
                    {
                        n++;
                        if(ch == n)
                        {
                            cout << setfill(' ') << setw(10) << ">> " << setfill('_') << left << setw(20) << item[i][j].call_name() << right << setw(12) << item[i][j].call_cost() << "$" << endl;
                            x = i;
                            y = j;
                        }
                        else
                        {
                            cout << setfill(' ') << setw(10) << "   " << setfill('_') << left << setw(20) << item[i][j].call_name() << right << setw(12) << item[i][j].call_cost() << "$" << endl;
                        }
                    }
                }
                else
                {
                    if( item[i][j].call_amount() == 0 && item[i][j].call_cost() > 0 )
                    {
                        n++;
                        if(ch == n)
                        {
                            cout << setfill(' ') << setw(10) << ">> " << setfill('_') << left << setw(20) << item[i][j].call_name() << right << setw(12) << item[i][j].call_cost() << "$" << endl;
                            x = i;
                            y = j;
                        }
                        else
                        {
                            cout << setfill(' ') << setw(10) << "   " << setfill('_') << left << setw(20) << item[i][j].call_name() << right << setw(12) << item[i][j].call_cost() << "$" << endl;
                        }
                    }
                }
            }
        }
        cout << endl << "==================================================" << endl;
        cl = getch();
        system("CLS");

        if( cl == 13 )
        {
            cl = 0;
            shop_myself(x,y);
        }
    }
}
/////////////////////////
int  PLAYER :: shop_myself(int x, int y)
{
    int ch=1, cl=0;
    int namelength;

    namelength = ( item[x][y].call_name().length() )/2;

    while( cl != 13 )
    {
        if(cl == 75)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = 2;
            }
        }
        if(cl == 77)
        {
            ch += 1;
            if(ch > 2)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            return 0;
        }

        if(ch == 1)
        {
            stat_display();
            cout << "               Do you want to buy...              " << endl;
            cout << setfill(' ') << setw(25-namelength) << "\"" << item[x][y].call_name() << "\"" << endl << endl;

            if(item[x][y].call_hp() > 0)            cout << setw(28) << "HP +" << item[x][y].call_hp() << endl;
            else if(item[x][y].call_hp() < 0)       cout << setw(27) << "HP " << item[x][y].call_hp() << endl;

            if(item[x][y].call_food() > 0)          cout << setw(28) << "FOOD +" << item[x][y].call_food() << endl;
            else if(item[x][y].call_food() < 0)     cout << setw(27) << "FOOD " << item[x][y].call_food() << endl;

            if(item[x][y].call_water() > 0)         cout << setw(28) << "WATER +" << item[x][y].call_water() << endl;
            else if(item[x][y].call_water() < 0)    cout << setw(27) << "WATER " << item[x][y].call_water() << endl;

            if(item[x][y].call_str() > 0)           cout << setw(28) << "STRENGTH +" << item[x][y].call_str() << endl;
            else if(item[x][y].call_str() < 0)      cout << setw(27) << "STRENGTH " << item[x][y].call_str() << endl;

            if(item[x][y].call_mental() > 0)        cout << setw(28) << "MENTAL +" << item[x][y].call_mental() << endl;
            else if(item[x][y].call_mental() < 0)   cout << setw(27) << "MENTAL " << item[x][y].call_mental() << endl;

            if(item[x][y].call_protect() > 0)       cout << setw(28) << "PROTECT " << item[x][y].call_protect() << "%" << endl;

            cout << endl << setw(27) << item[x][y].call_cost() << "$" << endl << endl;
            cout << "==================================================" << endl << endl;
            cout << "              >> Yes           No                 " << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 2)
        {
            stat_display();
            cout << "               Do you want to buy...              " << endl;
            cout << setfill(' ') << setw(25-namelength) << "\"" << item[x][y].call_name() << "\"" << endl << endl;

            if(item[x][y].call_hp() > 0)            cout << setw(28) << "HP +" << item[x][y].call_hp() << endl;
            else if(item[x][y].call_hp() < 0)       cout << setw(27) << "HP " << item[x][y].call_hp() << endl;

            if(item[x][y].call_food() > 0)          cout << setw(28) << "FOOD +" << item[x][y].call_food() << endl;
            else if(item[x][y].call_food() < 0)     cout << setw(27) << "FOOD " << item[x][y].call_food() << endl;

            if(item[x][y].call_water() > 0)         cout << setw(28) << "WATER +" << item[x][y].call_water() << endl;
            else if(item[x][y].call_water() < 0)    cout << setw(27) << "WATER " << item[x][y].call_water() << endl;

            if(item[x][y].call_str() > 0)           cout << setw(28) << "STRENGTH +" << item[x][y].call_str() << endl;
            else if(item[x][y].call_str() < 0)      cout << setw(27) << "STRENGTH " << item[x][y].call_str() << endl;

            if(item[x][y].call_mental() > 0)        cout << setw(28) << "MENTAL +" << item[x][y].call_mental() << endl;
            else if(item[x][y].call_mental() < 0)   cout << setw(27) << "MENTAL " << item[x][y].call_mental() << endl;

            if(item[x][y].call_protect() > 0)       cout << setw(28) << "PROTECT " << item[x][y].call_protect() << "%" << endl;

            cout << endl << setw(27) << item[x][y].call_cost() << "$" << endl << endl;
            cout << "==================================================" << endl << endl;
            cout << "                 Yes        >> No                 " << endl << endl;
            cout << "==================================================" << endl;
        }
        cl = getch();
        system("CLS");
    }

    if(ch == 1)
    {
        if( shop_payment(item[x][y].call_cost()) )
        {
            ++item[x][y];
        }
    }
    else if(ch == 2)
    {
        return 0;
    }
}
/////////////////////////
int  PLAYER :: shop_grab()
{
    int i,j, n, all, itemsize=10;   //COUT SYSTEM VAL
    int ch=1, cl, x=0, y=0;   //SELECT SYSTEM VALUE

    while(cl != 13)
    {
        for(i=0,all=0 ; i < 2 ; i++)
        {
            for(j=0 ; j < itemsize ; j++)
            {
                if( item[i][j].call_cost() > 0 )
                {
                    all++;
                }
            }
        }

        if(cl == 72)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = all;
            }
        }
        if(cl == 80)
        {
            ch += 1;
            if(ch > all)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            return 0;
        }

        stat_display();
        for(i=0,n=0 ; i < 2 ; i++)
        {
            //cout << "\tch = " << ch << "\tn = " << n << "\tall = " << all << endl;      //VALUE CHECK LINE
            if(i==0)
            {
                cout << "                       GRAB                       " << endl;
                cout << "  Food" << endl;
            }
            if(i==1)
            {
                cout << "  Drink" << endl;
            }

            for(j=0 ; j < itemsize ; j++)
            {
                if( item[i][j].call_cost() > 0 )
                {
                    n++;
                    if(ch == n)
                    {
                        cout << setfill(' ') << setw(10) << ">> " << setfill('_') << left << setw(20) << item[i][j].call_name() << right << setw(12) << item[i][j].call_cost() << "$" << endl;
                        x = i;
                        y = j;
                    }
                    else
                    {
                        cout << setfill(' ') << setw(10) << "   " << setfill('_') << left << setw(20) << item[i][j].call_name() << right << setw(12) << item[i][j].call_cost() << "$" << endl;
                    }
                }
            }
        }
        cout << endl << "==================================================" << endl;
        cl = getch();
        system("CLS");

        if( cl == 13 )
        {
            cl = 0;
            shop_grab(x,y);
        }
    }
}
/////////////////////////
int  PLAYER :: shop_grab(int x, int y)
{
    int ch=1, cl=0;
    int namelength;

    namelength = ( item[x][y].call_name().length() )/2;

    while( cl != 13 )
    {
        if(cl == 75)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = 2;
            }
        }
        if(cl == 77)
        {
            ch += 1;
            if(ch > 2)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            return 0;
        }

        if(ch == 1)
        {
            stat_display();
            cout << "               Do you want to buy...              " << endl;
            cout << setfill(' ') << setw(25-namelength) << "\"" << item[x][y].call_name() << "\"" << endl << endl;

            if(item[x][y].call_hp() > 0)            cout << setw(28) << "HP +" << item[x][y].call_hp() << endl;
            else if(item[x][y].call_hp() < 0)       cout << setw(27) << "HP " << item[x][y].call_hp() << endl;

            if(item[x][y].call_food() > 0)          cout << setw(28) << "FOOD +" << item[x][y].call_food() << endl;
            else if(item[x][y].call_food() < 0)     cout << setw(27) << "FOOD " << item[x][y].call_food() << endl;

            if(item[x][y].call_water() > 0)         cout << setw(28) << "WATER +" << item[x][y].call_water() << endl;
            else if(item[x][y].call_water() < 0)    cout << setw(27) << "WATER " << item[x][y].call_water() << endl;

            if(item[x][y].call_str() > 0)           cout << setw(28) << "STRENGTH +" << item[x][y].call_str() << endl;
            else if(item[x][y].call_str() < 0)      cout << setw(27) << "STRENGTH " << item[x][y].call_str() << endl;

            if(item[x][y].call_mental() > 0)        cout << setw(28) << "MENTAL +" << item[x][y].call_mental() << endl;
            else if(item[x][y].call_mental() < 0)   cout << setw(27) << "MENTAL " << item[x][y].call_mental() << endl;

            cout << endl << setw(21) << item[x][y].call_cost() << " + 50 = " << item[x][y].call_cost()+50 << "$" << endl << endl;
            cout << "==================================================" << endl << endl;
            cout << "             >> Yes           No                 " << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 2)
        {
            stat_display();
            cout << "               Do you want to buy...              " << endl;
            cout << setfill(' ') << setw(25-namelength) << "\"" << item[x][y].call_name() << "\"" << endl << endl;

            if(item[x][y].call_hp() > 0)            cout << setw(28) << "HP +" << item[x][y].call_hp() << endl;
            else if(item[x][y].call_hp() < 0)       cout << setw(27) << "HP " << item[x][y].call_hp() << endl;

            if(item[x][y].call_food() > 0)          cout << setw(28) << "FOOD +" << item[x][y].call_food() << endl;
            else if(item[x][y].call_food() < 0)     cout << setw(27) << "FOOD " << item[x][y].call_food() << endl;

            if(item[x][y].call_water() > 0)         cout << setw(28) << "WATER +" << item[x][y].call_water() << endl;
            else if(item[x][y].call_water() < 0)    cout << setw(27) << "WATER " << item[x][y].call_water() << endl;

            if(item[x][y].call_str() > 0)           cout << setw(28) << "STRENGTH +" << item[x][y].call_str() << endl;
            else if(item[x][y].call_str() < 0)      cout << setw(27) << "STRENGTH " << item[x][y].call_str() << endl;

            if(item[x][y].call_mental() > 0)        cout << setw(28) << "MENTAL +" << item[x][y].call_mental() << endl;
            else if(item[x][y].call_mental() < 0)   cout << setw(27) << "MENTAL " << item[x][y].call_mental() << endl;

            cout << endl << setw(21) << item[x][y].call_cost() << " + 50 = " << item[x][y].call_cost()+50 << "$" << endl << endl;
            cout << "==================================================" << endl << endl;
            cout << "                Yes        >> No                 " << endl << endl;
            cout << "==================================================" << endl;
        }
        cl = getch();
        system("CLS");
    }

    if(ch == 1)
    {
        if( shop_payment(item[x][y].call_cost()+50) )
        {
            ++item[x][y];
        }
    }
    else if(ch == 2)
    {
        return 0;
    }
}
/////////////////////////
bool PLAYER :: shop_payment(int price)
{
    if( money >= price)
    {
        money -= price;
        return 1;
    }
    else
    {
        stat_display();
        cout << "                Not enough money.                 " << endl << endl;
        cout << "==================================================" << endl;
        getch();
        system("CLS");
        return 0;
    }
}
/////////////////////////
void PLAYER :: goout_tired()
{
    if( (food -= 10) < 0 )
    {
        food = 0;
        hp -= 10;
        gameover();
    }
    if( (water -= 10) < 0 )
    {
        water = 0;
        hp -= 10;
        gameover();
    }
    time_next();
}
//////////////////////////////////////////////////MENU DAILY LIFE
int  PLAYER :: menu_daily()
{
    int ch=1, cl;
    while(cl != 13)
    {
        if(cl == 72)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = 4;
            }
        }
        if(cl == 80)
        {
            ch += 1;
            if(ch > 4)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            return 0;
        }

        if(ch == 1)
        {
            stat_display();
            cout << "                >> Coding" << endl;
            cout << "                   Work out" << endl;
            cout << "                   Play games" << endl;
            cout << "                   Watch Netflix" << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 2)
        {
            stat_display();
            cout << "                   Coding" << endl;
            cout << "                >> Work out" << endl;
            cout << "                   Play games" << endl;
            cout << "                   Watch Netflix" << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 3)
        {
            stat_display();
            cout << "                   Coding" << endl;
            cout << "                   Work out" << endl;
            cout << "                >> Play games" << endl;
            cout << "                   Watch Netflix" << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 4)
        {
            stat_display();
            cout << "                   Coding" << endl;
            cout << "                   Work out" << endl;
            cout << "                   Play games" << endl;
            cout << "                >> Watch Netflix" << endl << endl;
            cout << "==================================================" << endl;
        }
        cl = getch();
        system("CLS");
    }

    if(ch == 1)
    {
        daily_code();
    }
    else if(ch == 2)
    {
        daily_workout();
    }
    else if(ch == 3)
    {
        daily_game();
    }
    else if(ch == 4)
    {
        daily_netflix();
    }
}
/////////////////////////
void PLAYER :: daily_code()
{
    if( (food -= 10) < 0 )
    {
        food = 0;
        hp -= 10;
        gameover();
    }
    if( (water -= 10) < 0 )
    {
        water = 0;
        hp -= 10;
        gameover();
    }
    if( (strength -= 10) < 0 )
    {
        strength = 0;
        hp -= 10;
        gameover();
    }
    if( (mental -= 20) < 0 )
    {
        mental = 0;
        hp -= 20;
        gameover();
    }
    money += 50;
    time_next();
}
/////////////////////////
void PLAYER :: daily_workout()
{
    if( (food -= 20) < 0 )
    {
        food = 0;
        hp -= 20;
        gameover();
    }
    if( (water -= 20) < 0 )
    {
        water = 0;
        hp -= 20;
        gameover();
    }
    if( (strength += 20) > 100 )
    {
        strength = 100;
    }
    time_next();
}
/////////////////////////
void PLAYER :: daily_game()
{
    if( (food -= 10) < 0 )
    {
        food = 0;
        hp -= 10;
        gameover();
    }
    if( (water -= 10) < 0 )
    {
        water = 0;
        hp -= 10;
        gameover();
    }
    if( (strength -= 10) < 0 )
    {
        strength = 0;
        hp -= 10;
        gameover();
    }
    if( (mental += 10) > 100 )
    {
        mental = 100;
    }
    time_next();
}
/////////////////////////
int  PLAYER :: daily_netflix()
{
    if(netflix_access == 1)
    {
        if( (food -= 10) < 0 )
        {
            food = 0;
            hp -= 10;
            gameover();
        }
        if( (water -= 10) < 0 )
        {
            water = 0;
            hp -= 10;
            gameover();
        }
        if( (mental += 20) > 100 )
        {
            mental = 100;
        }
        time_next();
    }
    else
    {
        int ch=1, cl=0;
        while( cl != 13 )
        {
            if(cl == 75)
            {
                ch -= 1;
                if(ch < 1)
                {
                    ch = 2;
                }
            }
            if(cl == 77)
            {
                ch += 1;
                if(ch > 2)
                {
                    ch = 1;
                }
            }
            if(cl == 8)
            {
                return 0;
            }

            if(ch == 1)
            {
                stat_display();
                cout << "            You don't have a Netflix ID           " << endl;
                cout << "            Want to register now?(150$)           " << endl << endl;
                cout << "==================================================" << endl << endl;
                cout << "              >> Yes           No                 " << endl << endl;
                cout << "==================================================" << endl;
            }
            if(ch == 2)
            {
                stat_display();
                cout << "            You don't have a Netflix ID           " << endl;
                cout << "            Want to register now?(150$)           " << endl << endl;
                cout << "==================================================" << endl << endl;
                cout << "                 Yes        >> No                 " << endl << endl;
                cout << "==================================================" << endl;
            }
            cl = getch();
            system("CLS");
        }

        if(ch == 1)
        {
            if(money >= 150)
            {
                money -= 150;
                netflix_access = 1;
                stat_display();
                cout << "              Purchased a Netflix ID.             " << endl << endl;
                cout << "==================================================" << endl;
                getch();
                system("CLS");
            }
            else
            {
                stat_display();
                cout << "                 Not enough money.                " << endl << endl;
                cout << "==================================================" << endl;
                getch();
                system("CLS");
            }
        }
        else if(ch == 2)
        {
            return 1;
        }
    }
}
//////////////////////////////////////////////////MENU INVENTORY
int  PLAYER :: menu_inventory()
{
    int i,j, n, check, all, itemsize=10;   //COUT SYSTEM VAL
    int ch=1, cl, x=0, y=0;   //SELECT SYSTEM VALUE

    while(cl != 13)
    {
        for(i=0,all=0 ; i < 3 ; i++)    //Check how many item you have now(Use for count how many time can press UP or DOWN)
        {
            for(j=0 ; j < itemsize ; j++)
            {
                if( item[i][j].call_amount() > 0 )
                {
                    all++;
                }
            }
        }

        if(cl == 72)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = all;
            }
        }
        if(cl == 80)
        {
            ch += 1;
            if(ch > all)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            return 0;
        }

        stat_display();
        for(i=0,n=0 ; i < 3 ; i++)  //'n' is the number that every item-perline has for themself to check with 'ch'
        {
            check = 0 ;
            //cout << "\tch = " << ch << "\tn = " << n << "\tall = " << all << "\t check = " << check << endl;      //VALUE CHECK LINE
            if(i==0) {cout << "  Food" << endl;     }
            if(i==1) {cout << "  Drink" << endl;    }
            if(i==2) {cout << "  Medicine" << endl; }

            for(j=0 ; j < itemsize ; j++)
            {
                if( item[i][j].call_amount() > 0 )
                {
                    n++;    check++;
                    if(ch == n)
                    {
                        cout << setfill(' ') << setw(10) << ">> " << setfill('_') << left << setw(20) << item[i][j].call_name() << right << setw(12) << "x" << item[i][j].call_amount() << endl;
                        x = i;
                        y = j;
                    }
                    else
                    {
                        cout << setfill(' ') << setw(10) << "   " << setfill('_') << left << setw(20) << item[i][j].call_name() << right << setw(12) << "x" << item[i][j].call_amount() << endl;
                    }
                }
            }
            if(check == 0)
            {
                cout << setfill(' ') << setw(30) << "...Nothing..." << endl;
            }
            cout << endl;
        }

        cout << "  Protector" << endl;
        for(i=3,j=0,check=0 ; j<itemsize ; j++)
        {
            if( item[i][j].call_amount() > 0 )
            {
                check++;
                cout << setfill(' ') << setw(10) << "   " << setfill('_') << left << setw(20) << item[i][j].call_name() << right << setw(12) << "x" << item[i][j].call_amount() << endl;
            }
        }
        if(check == 0)
            {
                cout << setfill(' ') << setw(30) << "...Nothing..." << endl;
            }
        cout << endl << "==================================================" << endl;
        cl = getch();
        system("CLS");
    }

    if(all > 0)
    {
        inventory_using(x,y);
    }
    else
    {
        stat_display();
        cout << "               ...Nothing to use...               " << endl << endl;
        cout << "==================================================" << endl;
        getch();
        system("CLS");
    }
}
/////////////////////////
void PLAYER :: inventory_using(int x,int y)
{
    int namelength;
    stat_display();

    namelength = ( item[x][y].call_name().length() )/2;
    cout << setfill(' ') << setw(27) << "Using" << endl;
    cout << setw(24-namelength) << "\"" << item[x][y].call_name() << "\"" << endl << endl;

    --item[x][y];

    hp += item[x][y].call_hp();             if(hp > 100)        hp = 100;
    if(item[x][y].call_hp() > 0)            cout << setw(27) << "HP +" << item[x][y].call_hp() << endl;
    else if(item[x][y].call_hp() < 0)       cout << setw(26) << "HP " << item[x][y].call_hp() << endl;

    food += item[x][y].call_food();         if(food > 100)      food = 100;
    if(item[x][y].call_food() > 0)          cout << setw(27) << "FOOD +" << item[x][y].call_food() << endl;
    else if(item[x][y].call_food() < 0)     cout << setw(26) << "FOOD " << item[x][y].call_food() << endl;

    water += item[x][y].call_water();       if(water > 100)     water = 100;
    if(item[x][y].call_water() > 0)         cout << setw(27) << "WATER +" << item[x][y].call_water() << endl;
    else if(item[x][y].call_water() < 0)    cout << setw(26) << "WATER " << item[x][y].call_water() << endl;

    strength += item[x][y].call_str();      if(strength > 100)  strength = 100;
    if(item[x][y].call_str() > 0)           cout << setw(27) << "STRENGTH +" << item[x][y].call_str() << endl;
    else if(item[x][y].call_str() < 0)      cout << setw(26) << "STRENGTH " << item[x][y].call_str() << endl;

    mental += item[x][y].call_mental();     if(mental > 100)    mental = 100;
    if(item[x][y].call_mental() > 0)        cout << setw(27) << "MENTAL +" << item[x][y].call_mental() << endl;
    else if(item[x][y].call_mental() < 0)   cout << setw(26) << "MENTAL " << item[x][y].call_mental() << endl;

    cout << endl << "==================================================" << endl;
    getch();
    gameover();
}
//////////////////////////////////////////////////MENU NOTHING
void PLAYER :: menu_nothing()
{
    if( (food -= 5) < 0 )
    {
        food = 0;
        hp -= 5;
        gameover();
    }
    if( (water -= 5) < 0 )
    {
        water = 0;
        hp -= 5;
        gameover();
    }
    time_next();
}
//////////////////////////////////////////////////STAT DISPLAY
void PLAYER :: stat_display()
{
    int i;
    cout << "==================================================" << endl;
    textcolor(DARKBLUE,BLACK);
    cout << "     DAY : " << right << setfill('0') << setw(2) << day << "/" << setw(2) << limit << setfill(' ') << "\t";
    textcolor(DARKRED,BLACK);
    cout << "     TIME : " << time_show() << endl;
    resetcolor();
    cout << "==================================================" << endl;

    cout << right << setw(12) << "      HP [";      for(i=0 ; i<(hp+5)/10       ; i++)  cout << "+";  for(i=0 ; i<10-((hp+5)/10)       ; i++)  cout << " ";  cout << "]" << "\t";
    cout << right << setw(12) << "   MONEY =";      cout << setw(5) << money << " $" << endl;
    cout << right << setw(12) << "    FOOD [";      for(i=0 ; i<(food+5)/10     ; i++)  cout << "+";  for(i=0 ; i<10-((food+5)/10)     ; i++)  cout << " ";  cout << "]" << "\t";
    cout << right << setw(12) << "   WATER [";      for(i=0 ; i<(water+5)/10    ; i++)  cout << "+";  for(i=0 ; i<10-((water+5)/10)    ; i++)  cout << " ";  cout << "]" << endl;
    cout << right << setw(12) << "STRENGTH [";      for(i=0 ; i<(strength+5)/10 ; i++)  cout << "+";  for(i=0 ; i<10-((strength+5)/10) ; i++)  cout << " ";  cout << "]" << "\t";
    cout << right << setw(12) << "  MENTAL [";      for(i=0 ; i<(mental+5)/10   ; i++)  cout << "+";  for(i=0 ; i<10-((mental+5)/10)   ; i++)  cout << " ";  cout << "]" << endl;

    cout << "==================================================" << endl << endl;
}
//////////////////////////////////////////////////GAME OVER CHECKER
int  PLAYER :: gameover()
{
    if(hp <= 0)
    {
        system("CLS");
        cout << "==================================================" << endl << endl;
        cout << "                    GAME  OVER                    " << endl << endl;
        cout << "==================================================" << endl;
        getch();
        score_calculate();
        scoreboard(name,score);
        exit(EXIT_SUCCESS);
    }

    else if(day >= limit)
    {
        system("CLS");
        cout << "==================================================" << endl << endl;
        cout << "                  YOU SURVIVE!!!                  " << endl << endl;
        cout << "==================================================" << endl;
        getch();
        score_calculate();
        scoreboard(name,score);
        return 0;
    }
}
//////////////////////////////////////////////////INFECTION SYSTEM
int  PLAYER :: protector_using()
{
    int i, all=0, n, x;
    int ch=1, cl;
    for(i=0 ; i<10 ; i++)
    {
        if( item[3][i].call_amount() > 0 )      all++;
    }

    while(cl != 13)
    {
        if(cl == 72)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = n;
            }
        }
        if(cl == 80)
        {
            ch += 1;
            if(ch > n)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            return 0;
        }

        stat_display();
        for(i=0,n=0 ; i < 10 ; i++)  //'n' is the number that every item-perline has for themself to check with 'ch'
        {
            if(i==0)
            {
                cout << "                  USING PROTECTOR                 " << endl << endl;
            }

            if( item[3][i].call_amount() > 0 )
            {
                n++;
                if(ch == n)
                {
                    cout << setfill(' ') << right << setw(18) << ">> " << left << setw(20) << item[3][i].call_name() << endl;
                    x = i;
                }
                else
                {
                    cout << setfill(' ') << right << setw(18) << "   " << left << setw(20) << item[3][i].call_name() << endl;
                }
            }
        }
        cout << endl << "==================================================" << endl;
        cl = getch();
        system("CLS");
    }

    ch=1;   cl=0;
    while( cl != 13 )
    {
        if(cl == 75)
        {
            ch -= 1;
            if(ch < 1)
            {
                ch = 2;
            }
        }
        if(cl == 77)
        {
            ch += 1;
            if(ch > 2)
            {
                ch = 1;
            }
        }
        if(cl == 8)
        {
            return 0;
        }

        if(ch == 1)
        {
            stat_display();
            cout << "               Do you want to use...              " << endl;
            cout << setfill(' ') << setw(25-((item[3][x].call_name().length())/2)) << "\"" << item[3][x].call_name() << "\"" << endl << endl;

            cout << setw(28) << "PROTECT " << setw(2) << item[3][x].call_protect() << "%" << endl;

            cout << "==================================================" << endl << endl;
            cout << "              >> Yes           No                 " << endl << endl;
            cout << "==================================================" << endl;
        }
        if(ch == 2)
        {
            stat_display();
            cout << "               Do you want to use...              " << endl;
            cout << setfill(' ') << setw(25-((item[3][x].call_name().length())/2)) << "\"" << item[3][x].call_name() << "\"" << endl << endl;

            cout << setw(28) << "PROTECT " << setw(2) << item[3][x].call_protect() << "%" << endl;

            cout << "==================================================" << endl << endl;
            cout << "                 Yes        >> No                 " << endl << endl;
            cout << "==================================================" << endl;
        }
        cl = getch();
        system("CLS");
    }

    if(ch == 1)
    {
        immunity += item[3][x].call_protect();
        shop_myself();
    }
    else if(ch == 2)
    {
        return 0;
    }
}
/////////////////////////
void PLAYER :: infection()
{
    int risk=100;

    immunity += strength/2;
    if( immunity > 100 )    immunity = 100;

    risk -= immunity;

    if( (rand()%100)+1 <= risk )
    {
        DAY::limit += 14;
        DAY::quarantine += 14;

        stat_display();
        cout << "           You are infected COVID-19!!!           " << endl;
        cout << "        You must stay at home for 14 days.        " << endl << endl;
        cout << "==================================================" << endl;

        getch();
    }
    immunity = 0;
}
//////////////////////////////////////////////////SCORE SYSTEM
void PLAYER :: score_calculate()
{
    int namelength=name.length();

    score = ( (hp*10)+(food*10)+(water*10)+(strength*10)+(mental*10)+(money*10) ) / ( ((day-1)/14)+1 );

    system("CLS");
    cout << "==================================================" << endl << endl;
    cout << "                    YOUR SCORE                    " << endl << endl;
    cout << "==================================================" << endl << endl;
    cout << setw(25+(name.length()/2)) << name << endl << endl;
    cout << setw(27) << "HP : +" << hp*10 << endl;
    cout << setw(27) << "FOOD : +" << food*10 << endl;
    cout << setw(27) << "WATER : +" << water*10 << endl;
    cout << setw(27) << "STRENGTH : +" << strength*10 << endl;
    cout << setw(27) << "MENTAL : +" << mental*10 << endl;
    cout << setw(27) << "MONEY : +" << money*10 << endl;
    cout << setw(19) << day << " DAY : -" << ( (hp*10)+(food*10)+(water*10)+(strength*10)+(mental*10)+(money*10) ) - score << endl << endl;
    cout << setw(26) << "TOTAL : " << score << endl << endl;
    cout << "==================================================" << endl;

    getch();
    system("CLS");
}
/////////////////////////
void PLAYER :: scoreboard(string username, int userpoint)
{
    const int Listsize=30;
    string player[Listsize],temp;
    int score[Listsize], t;
    int n=1,i,j;

    fstream myscore;
    myscore.open("scoreboard.txt",ios::in);

    player[0] = username;
    score[0]  = userpoint;

    while(myscore >> player[n] >> score[n])
    {
        //cout<<player[n]<< ' ' <<score[n]<<endl;
        n++;
    }

    myscore.close();

    for(i=0 ; i<n ; i++)
    {
        for(j=i+1 ; j<n ; j++)
        {
            if( score[i] < score[j] )
            {
                temp = player[i];
                player[i] = player[j];
                player[j] = temp;

                t=score[i];
                score[i]=score[j];
                score[j]=t;
            }
        }
    }

    myscore.open("scoreboard.txt",ios::out);
    for(i=0 ; i<n ; i++)
    {
        myscore << player[i] << "\t\t" << score[i] << endl;
    }
    myscore.close();
}

