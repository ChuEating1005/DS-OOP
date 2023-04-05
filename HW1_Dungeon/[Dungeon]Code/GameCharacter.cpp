#include "GameCharacter.h"

// constructor
GameCharacter::GameCharacter() : Object() {}
GameCharacter::GameCharacter(string name, string tag, int health, int magic, int attack, int defense)
    : Object(name, tag)
{
    setMaxHealth(health);
    setCurrentHealth(getMaxHealth()); // intializing the character's hp
    setMaxMagic(magic);
    setCurrentMagic(getMaxMagic()); // intializing the character's mp
    setAttack(attack);
    setDefense(defense);
}

// basic function
bool GameCharacter::checkIsDead()
{
    if (getCurrentHealth() == 0)
        return true;
    else
        return false;
}
void GameCharacter::takeDamage(int demage)
{
    setCurrentHealth(getCurrentHealth() - demage);
}
void GameCharacter::healing(int heal)
{
    setCurrentHealth(getCurrentHealth() + heal);
}
bool GameCharacter::checkEnoughMagic(int MP)
{
    if (getCurrentMagic() >= MP)
        return true;
    else
        return false;
}
int GameCharacter::useMaigc(int mp)
{
    setCurrentMagic(getCurrentMagic() - mp);
    cout << "Current MP: " << getCurrentMagic() << endl;
}

/* Set & Get function*/
void GameCharacter::setMaxHealth(int health)
{
    if (health < 0)
        this->maxHealth = 0;
    else
        this->maxHealth = health;
}
void GameCharacter::setCurrentHealth(int health)
{
    if (health < 0)
        this->currentHealth = 0;
    else
        this->currentHealth = health;
}
void GameCharacter::setMaxMagic(int magic)
{
    if (magic < 0)
        this->maxMagic = 0;
    else
        this->maxMagic = magic;
}
void GameCharacter::setCurrentMagic(int magic)
{
    if (magic < 0)
        this->currentMagic = 0;
    else
        this->currentMagic = magic;
}
void GameCharacter::setAttack(int attack)
{
    if (attack < 0)
        this->attack = 0;
    else
        this->attack = attack;
}
void GameCharacter::setDefense(int defense)
{
    if (defense < 0)
        this->defense = 0;
    else
        this->defense = defense;
}
int GameCharacter::getMaxHealth()
{
    return maxHealth;
}
int GameCharacter::getCurrentHealth()
{
    return currentHealth;
}
int GameCharacter::getMaxMagic()
{
    return maxMagic;
}
int GameCharacter::getCurrentMagic()
{
    return currentMagic;
}
int GameCharacter::getAttack()
{
    return attack;
}
int GameCharacter::getDefense()
{
    return defense;
}