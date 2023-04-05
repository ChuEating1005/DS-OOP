#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter : public Object
{
private:
    int maxHealth;
    int currentHealth;
    int maxMagic;
    int currentMagic;
    int attack;
    int defense;

public:
    GameCharacter();
    GameCharacter(string, string, int, int, int, int);
    bool checkIsDead();
    void takeDamage(int);
    void healing(int);
    bool checkEnoughMagic(int);
    int useMaigc(int);

    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setMaxMagic(int);
    void setCurrentMagic(int);
    void setAttack(int);
    void setDefense(int);
    int getMaxHealth();
    int getCurrentHealth();
    int getMaxMagic();
    int getCurrentMagic();
    int getAttack();
    int getDefense();
};
#endif // GAMECHARACTER_H_INCLUDED
