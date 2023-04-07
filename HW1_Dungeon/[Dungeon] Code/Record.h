#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <bits/stdc++.h>
#include "Monster.h"
#include "NPC.h"
#include "Player.h"
#include "Item.h"
#define path1 "Save_Player.txt"
#define path2 "Save_Rooms.txt"

using namespace std;

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record
{
private:
    void savePlayer(Player*, ofstream&);
    void saveRooms(vector<Room>&, ofstream&);
    void loadPlayer(Player*, ifstream&, vector<Room>&);
    void loadRooms(vector<Room>&, ifstream&);

public:
    Record();
    void saveToFile(Player*, vector<Room>&);
    void loadFromFile(Player*, vector<Room>&);

};

#endif // RECORD_H_INCLUDED
