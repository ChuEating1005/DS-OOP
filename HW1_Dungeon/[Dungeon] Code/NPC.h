#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <bits/stdc++.h>
#include "GameCharacter.h"
#include "Item.h"

using namespace std;

class Item;

class NPC : public GameCharacter
{
private:
    string script;
    vector<pair<int, Item> > commodity;

public:
    NPC();
    NPC(string, string, vector<pair<int, Item> >);
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object *);

    /* Set & Get function*/
    void setScript(string);
    void setCommodity(vector<pair<int, Item> >);
    string getScript();
    vector<pair<int, Item> > getCommodity();
};

#endif // NPC_H_INCLUDED
