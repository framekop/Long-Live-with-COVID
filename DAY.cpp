#include "DAY.h"

DAY :: DAY()
{
    head  = NULL;
    tail  = NULL;
    cur   = NULL;
    time  = 0;    //Start at Morning (show as morning but it change time as another)
    day   = 1;    //Start at Day ...
    limit = 14;   //Day Limit
    quarantine = 0;
/////MORNING
    NODE *tmp = new NODE;
    cur = tmp;
    tmp->data = "Morning";
    tmp->next = NULL;
        head = tmp;
        tail = tmp;
/////AFTERNOON
    tmp = new NODE;
    tmp->data = "Afternoon";
    tail->next = tmp;   //MAKE M->A
    tail = tail->next;
/////EVENING
    tmp = new NODE;
    tmp->data = "Evening";
    tail->next = tmp;   //MAKE A->E
    tail = tail->next;
    tail->next=head;    //MAKE E->M

    mae = cur->data;    //SET mae = Morning
}

void DAY :: time_next()
{
    time++;
    if(time > 2)   time=0;

    if(time == 1)
    {
        cur = cur->next;
        mae = cur->data;
    }
    else if(time == 2)
    {
        cur = cur->next;
        mae = cur->data;
    }
    else if(time == 0)
    {
        cur = cur->next;
        mae = cur->data;
        day++;
        quarantine--;
        if(quarantine < 0)  quarantine=0;
    }
}

string DAY :: time_show()
{
    return mae;
}
