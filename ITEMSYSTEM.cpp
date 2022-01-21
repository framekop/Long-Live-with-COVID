#include "ITEMSYSTEM.h"
#include <iostream>

ITEMSYSTEM :: ITEMSYSTEM()
{   ///1 NAME , 2 COST , 3 AMOUNT , 4 HP , 5 FOOD , 6 WATER , 7 STR , 8 MENTAL , 9 PROTECT
               //               1                    2    3    4    5    6    7    8    9
    //FOOD
    item[0][0] = {"Cup Noodle"                  ,   15,   1,   0,  15,   5, -10, -10,   0};
    item[0][1] = {"Rice Soup"                   ,   25,   0,   0,  20,  10,   0,   0,   0};
    item[0][2] = {"Salad"                       ,   35,   0,   0,  10,   0,  25,   0,   0};
    item[0][3] = {"Pancake"                     ,   45,   0,   0,  20,   0,   0,  25,   0};
    item[0][4] = {"Hot Dogs"                    ,   45,   0,   0,  20,   0,  25,   0,   0};
    item[0][5] = {"Bacon & Sausage"             ,   75,   0,   0,  50,   0, -30,  25,   0};
    item[0][6] = {"Cheeseburger"                ,   90,   0,   0,  60,   0,   0,   0,   0};
    item[0][7] = {"Ramen"                       ,  120,   0,   0,  50,  50,   0,   0,   0};
    item[0][8] = {"Steak"                       ,  150,   0,   0,  75,   0,  30,   0,   0};
    item[0][9] = {"Pizza"                       ,  250,   0,   0, 100,   0,  50,   0,   0};
    //WATER
    item[1][0] = {"Drinking Water"              ,   10,   1,   0,   0,  15,   0,   0,   0};
    item[1][1] = {"Coca-Cola"                   ,   15,   0,   0,   0,  20,  -5,   5,   0};
    item[1][2] = {"Hot Milk"                    ,   30,   0,   0,   0,  20,  20,   0,   0};
    item[1][3] = {"Italian Soda"                ,   30,   0,   0,   0,  20,   0,  20,   0};
    item[1][4] = {"Americano Coffee"            ,   40,   0,   0,   0,  30, -10,  15,   0};
    item[1][5] = {"Bubble Milk Tea"             ,   40,   0,   0,  10,  20, -10,  20,   0};
    item[1][6] = {"Chocolate Frappe"            ,   50,   0,   0,  15,  20,  20,  10,   0};
    item[1][7] = {"Whey Protein"                ,   60,   0,   0,  20,  10,  30, -10,   0};
    item[1][8] = {"Wine"                        ,  100,   0,   0,   0,  50, -30,  40,   0};
    item[1][9] = {"Vodka"                       ,  120,   0,   0,   0,  60, -30,  50,   0};
    //MEDICINE
    item[2][0] = {"Paracetamol"                 ,   50,   0,  10,   0,   0,   0,   0,   0};
    item[2][1] = {"Vitamin"                     ,   90,   0,  10,   0,   0,  10,   0,   0};
    item[2][2] = {"Zyrtec"                      ,  100,   0,  25,   0,   0,   0,   0,   0};
    item[2][3] = {"Amoxicillin"                 ,  150,   0,  45,   0,   0,   0,   0,   0};
    item[2][4] = {"Chinese Medicine"            ,  300,   0, 100,   0,   0,   0,   0,   0};
    item[2][5] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
    item[2][6] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
    item[2][7] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
    item[2][8] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
    item[2][9] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
    //PROTECT
    item[3][0] = {"Plastic Bag"                 ,    0,   1,   0,   0,   0,   0,   0,   1};
    item[3][1] = {"Face Shield"                 ,  100,   0,   0,   0,   0,   0,   0,  15};
    item[3][2] = {"Hygienic Mask"               ,  150,   0,   0,   0,   0,   0,   0,  25};
    item[3][3] = {"Protective Clothing"         ,  300,   0,   0,   0,   0,   0,   0,  50};
    item[3][4] = {"Gas Mask"                    ,  500,   0,   0,   0,   0,   0,   0,  99};
    item[3][5] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
    item[3][6] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
    item[3][7] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
    item[3][8] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
    item[3][9] = {"???"                         ,    0,   0,   0,   0,   0,   0,   0,   0};
}

void ITEMSYSTEM :: item_display(int x,int y)
{
    cout << item[x][y].call_name() << "\t Cost:" << item[x][y].call_cost() << "\t Amount:" << item[x][y].call_amount() << endl;
    cout << "HP:" << item[x][y].call_hp() << "\tFood:" << item[x][y].call_food() << "\t\tWater:" << item[x][y].call_water() << endl;
    cout << "STR:" << item[x][y].call_str() << "\tMental:" << item[x][y].call_mental() << "\tProtect:" << item[x][y].call_protect() << endl << endl;
}
