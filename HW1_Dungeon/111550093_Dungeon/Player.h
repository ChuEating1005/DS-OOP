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
    Room *currentRoom;
    Room *previousRoom;
    map<string, Item> equipment;
    vector<Item> backpack;
public:
    Player();
    Player(string, string, int, int, int, int, int);
    Skill skill[3];
    void addItem(Item);
    void popItem(string);
    void equip();
    void changeEquipment(string, Item *);
    void changeWeapon(Item *);
    void increaseStates(int, int, int, int);
    void changeRoom(Room *);
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
    void setEquipment(map<string, Item>);
    void setBackpack(vector<Item>);
    void setOccupation(string);
    void setCoin(int);
    Room *getCurrentRoom();
    Room *getPreviousRoom();
    map<string, Item> getEquipment();
    vector<Item> getBackpack();
    string getOccupation();
    int getCoin();
    string getWeaponType();
    Item getWeapon();
};

#endif // PLAYER_H_INCLUDED
