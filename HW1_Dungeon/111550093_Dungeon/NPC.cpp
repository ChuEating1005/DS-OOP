#include "NPC.h"
#include "Player.h"

NPC::NPC()
    : GameCharacter("", "NPC", 0, 0, 0, 0)
{
}
NPC::NPC(string name, string script, vector<pair<int, Item> > items)
    : GameCharacter(name, "NPC", 10000, 0, 0, 0)
{
    setScript(script);
    setCommodity(items);
}

/* virtual function */
bool NPC::triggerEvent(Object *object)
{
    Player *player = dynamic_cast<Player *>(object);
    if ((getName() == "Gilles de Rais" && player->getOccupation() != "Saber") || (getName() == "The Great Warrior" && commodity.size() != 6) || commodity.empty())
    {
        cout << "\nSorry, I have nothing to help you.\n";
        return false;
    }
    else
    {
        cout << "\n\" " << getScript() << " \"\n\n";
        char option = 'A';
        for (auto& it : commodity)
        {
            cout << " > " << option << ". " << setw(15) << left << it.second.getName()
                 << " (" << setw(10) << left << it.second.getTag() << ", HP: +" << setw(3) << right << it.second.getHealth() << ", MP: +" 
                 << setw(3) << right << it.second.getMagic() << ", ATK: +" << setw(3) << right << it.second.getAttack() << ", DEF: +" 
                 << setw(3) << right << it.second.getDefense() << ")\t" << it.first << " coins\n";
            option++;
        }
        cout << " > " << option << ". Exit.\n";
        char sel;
        cin >> sel;
        if( sel >= 'a') sel -= 32;
        sel -= 'A';
        if(sel == commodity.size()) return false;
        else
        {
            if (player->getCoin() >= commodity[sel].first)
            {
                player->setCoin(player->getCoin() - commodity[sel].first);
                player->addItem(commodity[sel].second);
                commodity.erase(commodity.begin() + sel );
                return true;
            }
            else
            {
                cout << "Sorry, You don't have enough money.\n";
                return false;
            }
        }
    }
}

/* Set & Get function*/
void NPC::setScript(string script)
{
    this->script = script;
}
void NPC::setCommodity(vector<pair<int, Item> > commodity)
{
    this->commodity = commodity;
}
string NPC::getScript()
{
    return this->script;
}
vector<pair<int, Item> > NPC::getCommodity()
{
    return this->commodity;
}