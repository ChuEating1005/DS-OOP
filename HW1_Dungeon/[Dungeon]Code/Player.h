#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <bits/stdc++.h>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
#include "Skill.h"
using namespace std;
class Item;
class Skill;

class Player : public GameCharacter
{
private:
    int coin;
    Item weapon;
    pair<string, string> occupation;
    Skill skills[3];
    Room *currentRoom;
    Room *previousRoom;
    map<string, Item> equipment;
    vector<Item> backpack;

public:
    Player();
    Player(string, string, int, int, int, int, int);
    void addItem(Item);
    void popItem(string);
    void equip();
    void changeEquipment(string, Item *);
    void changeWeapon(Item *);
    void changeRoom(Room *);
    void increaseStates(int, int, int, int);
    bool checkMap();
    void showStatus();
    void showEquipment();
    void showBackpack();
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object *);

    /* Set & Get function*/
    void setCurrentRoom(Room *);
    void setPreviousRoom(Room *);
    void setBackpack(vector<Item>);
    void setEquipment(string, Item);
    void setOccupation(string);
    void setWeapon(Item);
    void setCoin(int);
    void setSkill(Skill, int);
    
    Room *getCurrentRoom();
    Room *getPreviousRoom();
    vector<Item> getBackpack();
    map<string, Item> getEquipment();
    string getOccupation();
    Item getWeapon();
    string getWeaponType();
    int getCoin();
    Skill getSkill(int);
};

#endif // PLAYER_H_INCLUDED
