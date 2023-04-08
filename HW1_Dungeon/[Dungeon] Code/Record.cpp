#include "Record.h"

Record::Record() {}
void Record::savePlayer(Player* player, ofstream& file)
{
    string part[6] = {"Helmet", "Necklace", "Armor", "Shield", "Pants", "Boots"};
    file << player->getName() << "\n" << player->getOccupation() << " " 
        << player->getMaxHealth() << " " << player->getMaxMagic() << " " << player->getAttack() << " " 
        << player->getDefense() << " " << player->getCoin() << endl;
    file << player->getCurrentRoom()->getIndex() << " " << player->getPreviousRoom()->getIndex() << endl;
    file << player->getCurrentHealth() << " " << player->getCurrentMagic() << endl;
    file << player->getWeapon().getName() << "\n" << player->getWeapon().getTag()
        << " " << player->getWeapon().getHealth() << " " << player->getWeapon().getMagic()
        << " " << player->getWeapon().getAttack() << " " << player->getWeapon().getDefense() << endl;
    for(int i = 0; i < 6; i++)
    {
        file << player->getEquipment()[part[i]].getName() << "\n" << player->getEquipment()[part[i]].getTag()
        << " " << player->getEquipment()[part[i]].getHealth() << " " << player->getEquipment()[part[i]].getMagic()
        << " " << player->getEquipment()[part[i]].getAttack() << " " << player->getEquipment()[part[i]].getDefense() << endl;
    }
    file << player->getBackpack().size() << endl;
    for(auto& item : player->getBackpack()) 
    {
        file << item.getName() << "\n" << item.getTag() << " " << item.getHealth() << " " 
            << item.getMagic() << " " << item.getAttack() << " " << item.getDefense() << endl;
    }
}

void Record::saveRooms(vector<Room>& rooms, ofstream& file)
{
    for(int i = 0; i < 16; i++)
    {
        file << rooms[i].getIndex() << " " << rooms[i].getIsExit() << endl;
        file << rooms[i].getObjects().size() << endl;
        if(!rooms[i].getObjects().empty())
            for(auto& object : rooms[i].getObjects()) 
            {
                file << object->getTag() << "\n";
                if(object->getTag() == "Monster")
                {
                    Monster* monster = dynamic_cast<Monster*>(object);
                    file << monster->getName() << "\n" << monster->getMaxHealth() << " " << monster->getMaxMagic()  << " " << monster->getAttack() << " " 
                        << monster->getDefense() <<  " " << monster->getCurrentHealth() << " " << monster->getCurrentMagic() << endl;
                    
                }
                else if(object->getTag() == "NPC")
                {
                    NPC* npc = dynamic_cast<NPC*>(object);
                    file << npc->getName() << "\n" << npc->getScript() << "\n" << npc->getCommodity().size() << endl;
                    for(auto& commodity : npc->getCommodity())
                    {
                        file << commodity.first << "\n"<< commodity.second.getName() << "\n" << commodity.second.getTag() << " " << commodity.second.getHealth() << " " 
                            << commodity.second.getMagic() << " " << commodity.second.getAttack() << " " << commodity.second.getDefense() << endl;
                    }
                }
                else
                {
                    Item* item = dynamic_cast<Item*>(object);
                    file << item->getName() << "\n" << item->getTag() << " " << item->getHealth() << " " 
                        << item->getMagic() << " " << item->getAttack() << " " << item->getDefense() << endl;
                }
            }
    }
}

void Record::loadPlayer(Player* player, ifstream& file, vector<Room>& rooms)
{
    string part[7] = {"Helmet", "Necklace", "Armor", "Shield", "Pants", "Boots"};

    string name , occupation;
    int maxHealth(0), maxMagic(0), attack(0), defense(0), coin(0);
    getline(file,name);
    file >> occupation >> maxHealth >> maxMagic >> attack >> defense >> coin;
    player->setName(name);
    player->setOccupation(occupation);
    player->setMaxHealth(maxHealth);
    player->setMaxMagic(maxMagic);
    player->setAttack(attack);
    player->setDefense(defense);
    player->setCoin(coin);
    player->initializeSkill(occupation);

    int currentRoomIndex, previousRoomIndex;
    file >> currentRoomIndex >> previousRoomIndex;
    player->setCurrentRoom( &rooms[currentRoomIndex]);
    player->setPreviousRoom( &rooms[previousRoomIndex]);
    
    int currentHealth, currentMagic;
    file >> currentHealth >> currentMagic;
    player->setCurrentHealth(currentHealth);
    player->setCurrentMagic(currentMagic);

    string tag;
    int health, magic;
    file.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(file,name);
    file >> tag >>  health >> magic >> attack >> defense;
    player->setWeapon(Item(name, tag, health, magic, attack, defense));
    for(int i = 0; i < 6; i++)
    {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(file,name);
        file >> tag >> health >> magic >> attack >> defense;
        if(name == "X") continue;
        player->setEquipment(tag, Item(name, tag, health, magic, attack, defense));
    }
    int backpackSize;
    file >> backpackSize;
    if(backpackSize > 0)
        for(int i = 0; i < backpackSize; i++)
        {
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(file,name);
            file >> tag >> health >> magic >> attack >> defense;
            player->addItem(Item(name, tag, health, magic, attack, defense));
        }
}

void Record::loadRooms(vector<Room>& rooms, ifstream& file)
{
    int index, objectsSize;
    bool isExit;
    string name, tag;
    rooms.reserve(15);
    for(int i = 0; i < 16; i++)
    {
        file >> index >> isExit >> objectsSize;
        vector<Object*> objects;
        if(objectsSize > 0)
        {
            for(int i = 0; i < objectsSize; i++)
            {
                file >> tag;
                file.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(file,name);
                if(tag == "Monster")
                {
                    int maxHealth, currentHealth, maxMagic, currentMagic, attack, defense;
                    file >> maxHealth >> maxMagic >> attack >> defense >> currentHealth >> currentMagic;
                    Monster* monster = new Monster(name, maxHealth, maxMagic, attack, defense);
                    monster->setCurrentHealth(currentHealth);
                    monster->setCurrentMagic(currentMagic);
                    objects.push_back(monster);
                }
                else if(tag == "NPC")
                {
                    string script, productName, productTag;
                    vector<pair<int,Item> >commodity;
                    int commoditySize, price;
                    int health, magic, attack, defense;
                    
                    getline(file,script);
                    file >> commoditySize;
                    if(commoditySize > 0)
                        for(int i = 0; i < commoditySize; i++)
                        {
                            file >> price;
                            file.ignore(numeric_limits<streamsize>::max(), '\n');
                            getline(file,productName);
                            file >> productTag >> health >> magic >> attack >> defense;
                            commodity.push_back(make_pair(price, Item(productName, productTag, health, magic, attack, defense)));
                        }
                    objects.push_back(new NPC(name, script, commodity));
                }
                else
                {
                    string itemTag;
                    int health, magic, attack, defense;
                    file >> itemTag >> health >> magic >> attack >> defense;
                    objects.push_back(new Item(name, itemTag, health, magic, attack, defense));
                }
            }
        }
        rooms.push_back(Room(isExit, index, objects));
    }
}

void Record::saveToFile(Player* player, vector<Room>& rooms)
{
    ofstream file1(path1,ios::trunc);
    ofstream file2(path2,ios::trunc);
    savePlayer(player, file1);
    saveRooms(rooms, file2);
    file1.close();
    file2.close();
}

void Record::loadFromFile(Player* player, vector<Room>& rooms)
{
    ifstream file1(path1);
    ifstream file2(path2);
    loadRooms(rooms, file2);
    loadPlayer(player, file1, rooms);
    file1.close();
    file2.close();
}