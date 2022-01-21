#include "ITEM.h"

ITEM :: ITEM(string input_name, int input_cost, int input_amount, int input_hp, int input_food, int input_water, int input_str, int input_mental, int input_protect)
{
    name    = input_name;
    cost    = input_cost;
    amount  = input_amount;

    hp      = input_hp;
    food    = input_food;
    water   = input_water;
    str     = input_str;
    mental  = input_mental;

    protect = input_protect;
}

string ITEM :: call_name()
{
    return name;
}

int ITEM :: call_cost()
{
    return cost;
}
int ITEM :: call_amount()
{
    return amount;
}
int ITEM :: call_hp()
{
    return hp;
}
int ITEM :: call_food()
{
    return food;
}
int ITEM :: call_water()
{
    return water;
}
int ITEM :: call_str()
{
    return str;
}
int ITEM :: call_mental()
{
    return mental;
}
int ITEM :: call_protect()
{
    return protect;
}

void ITEM :: operator++()
{
    amount++;
}
void ITEM :: operator--()
{
    amount--;
}
