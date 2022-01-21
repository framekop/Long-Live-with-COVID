#ifndef ITEMSYSTEM_H
#define ITEMSYSTEM_H

#include "ITEM.h"

class ITEMSYSTEM
{
protected:
    ITEM item[4][10];

public:
    ITEMSYSTEM();
    void item_display(int,int);
};

#endif // ITEMSYSTEM_H
