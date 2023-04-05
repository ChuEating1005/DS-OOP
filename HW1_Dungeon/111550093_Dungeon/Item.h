#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;


class Item : public Object
{
private:
    int health, magic, attack, defense;
    string type;

public:
    Item();
    Item(string, string, int, int, int, int);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object *);

    /* Set & Get function*/
    int getHealth();
    int getMagic();
    int getAttack();
    int getDefense();
    string getType();
    void setHealth(int);
    void setMagic(int);
    void setAttack(int);
    void setDefense(int);
    void setType(string);
};

#endif // ITEM_H_INCLUDED
