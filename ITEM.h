#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class ITEM
{
private:
    string name;
    int cost;
    int amount;

    int hp;
    int food;
    int water;
    int str;
    int mental;

    int protect;
public:
    ITEM(string="???", int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0);
    string call_name();
    int call_cost();
    int call_amount();
    int call_hp();
    int call_food();
    int call_water();
    int call_str();
    int call_mental();
    int call_protect();

    void operator++();
    void operator--();
};

#endif // ITEM_H
