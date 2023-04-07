#include "Item.h"
#include "Player.h"

Item::Item() : Object() {}
Item::Item(string name, string type, int health, int magic, int attack, int defense)
    : Object(name, type)
{
    setHealth(health);
    setMagic(magic);
    setAttack(attack);
    setDefense(defense);
}

// virtual function: triggerEvent
bool Item::triggerEvent(Object *object)
{
    Player *player = dynamic_cast<Player*>(object);
    cout << "You pick up an \033[1;36m" << getTag() << "\033[m \"" << getName() << "\"" << endl;

    return true;
}

// set & get function
int Item::getHealth()
{
    return health;
}
int Item::getAttack()
{
    return attack;
}
int Item::getDefense()
{
    return defense;
}
int Item::getMagic()
{
    return magic;
}

void Item::setHealth(int health)
{
    this->health = health;
}
void Item::setAttack(int attack)
{
    this->attack = attack;
}
void Item::setDefense(int defense)
{
    this->defense = defense;
}
void Item::setMagic(int magic)
{
    this->magic = magic;
}