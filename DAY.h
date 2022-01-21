#ifndef DAY_H
#define DAY_H

#include <iostream>

using namespace std;
struct NODE
{
    string data;
    NODE *next;
};

class DAY
{
private:
    NODE *head,*tail,*cur;
protected:
    int time;           //check time morning, afternoon, evening
    int day;            //Current Day
    int limit;          //Goal Day
    int quarantine;     //Day that need to stay at home
    string mae;         //keep "Morning","Afternoon","Evening"
public:
    DAY();
    void time_next();
    string time_show();
};

#endif // DAY_H
