#ifndef PLAYER_H
#define PLAYER_H

#include "DAY.h"
#include "ITEMSYSTEM.h"
#include <iostream>

using namespace std;

class PLAYER : public DAY, public ITEMSYSTEM
{
    private:
        string name;
        int netflix_access;
        int hp;
        int food;
        int water;
        int strength;
        int mental;
        int money;

        int immunity;
        int score;

    protected:
        int  goout_ornot();
        int  shop_myself();
        int  shop_myself(int,int);
        int  shop_grab();
        int  shop_grab(int,int);
        bool shop_payment(int);
        void goout_tired();
        void daily_code();
        void daily_workout();
        void daily_game();
        int  daily_netflix();
        void inventory_using(int,int);

        int  protector_using();
        void infection();

        void score_calculate();
        void scoreboard(string,int);

    public:
        PLAYER(string="???");
        ~PLAYER();
        int  menu();
        int  menu_goshopping();
        int  menu_daily();
        int  menu_inventory();
        void menu_nothing();
        void stat_display();
        int  gameover();

};

#endif // PLAYER_H
