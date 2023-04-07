#include "Dungeon.h"

Dungeon::Dungeon()
{
}
/* Create a new player, and give him/her basic status */
void Dungeon::createPlayer()
{
    string name;
    char sel;
    map<char, string> occupation;
    occupation['A'] = occupation['a'] = "Saber";
    occupation['B'] = occupation['b'] = "Archer";
    occupation['C'] = occupation['c'] = "Lancer";
    occupation['D'] = occupation['d'] = "Caster";
    occupation['E'] = occupation['e'] = "Assassin";
    occupation['F'] = occupation['f'] = "Rider";
    occupation['G'] = occupation['g'] = "Berserker";
    map<char, vector<int> > statistic;
    vector<int> v1;
    v1.push_back(50);
    v1.push_back(10);
    v1.push_back(30);
    v1.push_back(20);
    vector<int> v2;
    v2.push_back(30);
    v2.push_back(20);
    v2.push_back(50);
    v2.push_back(10);
    vector<int> v3;
    v3.push_back(30);
    v3.push_back(10);
    v3.push_back(50);
    v3.push_back(20);
    vector<int> v4;
    v4.push_back(30);
    v4.push_back(30);
    v4.push_back(40);
    v4.push_back(20);
    vector<int> v5;
    v5.push_back(40);
    v5.push_back(10);
    v5.push_back(50);
    v5.push_back(10);
    vector<int> v6;
    v6.push_back(40);
    v6.push_back(20);
    v6.push_back(40);
    v6.push_back(10);
    vector<int> v7;
    v7.push_back(50);
    v7.push_back(0);
    v7.push_back(50);
    v7.push_back(30);
    statistic['A'] = statistic['a'] = v1;
    statistic['B'] = statistic['b'] = v2;
    statistic['C'] = statistic['c'] = v3;
    statistic['D'] = statistic['d'] = v4;
    statistic['E'] = statistic['e'] = v5;
    statistic['F'] = statistic['f'] = v6;
    statistic['G'] = statistic['g'] = v7;
    cout << "\n\033[1;33mType your name:\033[m ";
    cin >> name;
    cout << "\n\033[1;33mChoose your character's class:\033[m \n";
    cout << "A. Saber     (HP: 70, MP: 10, ATK: 30, DEF: 20)\n"
         << "B. Archer    (HP: 50, MP: 20, ATK: 50, DEF: 10)\n"
         << "C. Lancer    (HP: 50, MP: 10, ATK: 50, DEF: 20)\n"
         << "D. Caster    (HP: 50, MP: 30, ATK: 40, DEF: 20)\n"
         << "E. Assassin  (HP: 60, MP: 10, ATK: 50, DEF: 10)\n"
         << "F. Rider     (HP: 60, MP: 20, ATK: 40, DEF: 10)\n"
         << "G. Berserker (HP: 70, MP:  0, ATK: 50, DEF: 30)\n"
         << endl;
    cout << "\nYour Choice: ";
    cin >> sel;
    player = Player(name, occupation[sel], statistic[sel][0], statistic[sel][1], statistic[sel][2], statistic[sel][3], 20);
    player.showStatus();
}

/* Create a map, which include several different rooms */
void Dungeon::createMap()
{
    // Creating Map
    srand(time(NULL));
    //* basic weapon for each class
    map<string, Item *> weapon;
    weapon["Saber"] = new Item("Bronze Sword", "Sword", 10, 0, 10, 10);
    weapon["Archer"] = new Item("Wood Bow", "Bow", 10, 5, 15, 0);
    weapon["Lancer"] = new Item("Bronze Lance", "Lance", 5, 5, 20, 0);
    weapon["Caster"] = new Item("Magic Book", "Staff", 0, 20, 10, 0);
    weapon["Assassin"] = new Item("Bronze Dagger", "Dagger", 0, 0, 30, 0);
    weapon["Rider"] = new Item("Leather Whip", "Whip", 5, 0, 15, 10);
    weapon["Berserker"] = new Item("Bronze Battle Axe", "Axe", 0, 0, 15, 15);
    //* treasure room weapon
    map<string, Item *> treasure;
    treasure["Saber"] = new Item("Frie Sword", "Sword", 20, 0, 30, 30);
    treasure["Archer"] = new Item("Frie Bow", "Bow", 30, 15, 45, 0);
    treasure["Lancer"] = new Item("Frie Lance", "Lance", 15, 15, 60, 10);
    treasure["Caster"] = new Item("Fire Ball!", "Staff", 0, 60, 30, 0);
    treasure["Assassin"] = new Item("Fire Dagger", "Dagger", 0, 0, 90, 0);
    treasure["Rider"] = new Item("Fire Whip", "Whip", 15, 0, 45, 30);
    treasure["Berserker"] = new Item("Fire Battle Axe", "Axe", 0, 0, 45, 45);
    //* legendary weapon dropped when defeat the Warrior
    map<string, Item *> artifact;
    artifact["Saber"] = new Item("\033[0;32;31mExcalibur\033[m", "Sword", 100, 50, 200, 50);
    artifact["Archer"] = new Item("\033[0;32;31mEa\033[m", "Bow", 120, 60, 180, 0);
    artifact["Lancer"] = new Item("\033[0;32;31mGae Bolg\033[m", "Lance", 60, 60, 240, 40);
    artifact["Caster"] = new Item("\033[0;32;31mThunderstorm Glaive\033[m", "Staff", 0, 240, 120, 0);
    artifact["Assassin"] = new Item("\033[0;32;31mTwilight\033[m", "Dagger", 0, 0, 400, 0);
    artifact["Rider"] = new Item("\033[0;32;31mMassive Wire\033[m", "Whip", 60, 0, 180, 120);
    artifact["Berserker"] = new Item("\033[0;32;31mDawn of Echoes\033[m", "Axe", 50, 0, 300, 50);
    vector<pair<int, Item> > products[6];

    //* Merchant's
    products[0].push_back(make_pair(40, Item("XenoBlade", "Sword", 20, 0, 30, 20)));
    products[0].push_back(make_pair(40, Item("Truestrike", "Bow", 15, 5, 50, 0)));
    products[0].push_back(make_pair(40, Item("Gae Bolg", "Lance", 10, 0, 50, 10)));
    products[0].push_back(make_pair(40, Item("Avada Kedavra", "Staff", 0, 20, 10, 0)));
    products[0].push_back(make_pair(40, Item("Sacrifice", "Dagger", 0, 0, 70, 0)));
    products[0].push_back(make_pair(40, Item("Eternal Rest", "Whip", 30, 0, 40, 0)));
    products[0].push_back(make_pair(10, Item("Dungeon Map", "Map", 0, 0, 0, 0)));
    products[0].push_back(make_pair(20, Item("Apocalypse", "Shield", 20, 0, 0, 40)));
    products[0].push_back(make_pair(25, Item("Crystal Heart", "Necklace", 0, 40, 0, 0)));
    products[0].push_back(make_pair(30, Item("King's Brand", "Helmet", 20, 20, 10, 0)));

    //* The Priest's
    products[1].push_back(make_pair(0, Item("Cross", "Item", 0, 0, 0, 0)));
    products[1].push_back(make_pair(0, Item("Holy Grail", "Item", 0, 0, 0, 0)));
    
    //* Gilles de Rais's
    products[2].push_back(make_pair(0, Item("Elegant Key", "Key", 0, 0, 0, 0)));

    //* Warrior's
    products[3].push_back(make_pair(0, Item("\033[1;36mAbyss Shriek\033[m", "Helmet", 30, 30, 70, 40)));
    products[3].push_back(make_pair(0, Item("\033[1;36mMothwing Cloak\033[m", "Armor", 50, 20, 30, 50)));
    products[3].push_back(make_pair(0, Item("\033[1;36mShade Cloak\033[m", "Pants", 30, 100, 30, 0)));
    products[3].push_back(make_pair(0, Item("\033[1;36mIsma's Tear\033[m", "Necklace", 30, 100, 30, 0)));
    products[3].push_back(make_pair(0, Item("\033[1;36mMonarch Wings\033[m", "Boots", 30, 100, 30, 0)));
    products[3].push_back(make_pair(0, Item("\033[1;36mDreamshield\033[m", "Shield", 40, 0, 0, 100)));
    
    //* Jeanne d'Arc
    products[4].push_back(make_pair(0, Item("\033[1;36mLuminosite Eternelle\033[m", "Armor", 500, 500, 500, 500)));

    //* creating objects for each room
    vector<Object *> objects[16];
    // room 0 (start point)
    objects[0].push_back(weapon[player.getOccupation()]);
    // room 1 (normal monster)
    objects[1].push_back(new Monster("Blue Slime", 40, 0, 40, 5));
    objects[1].push_back(new Item("Cross Bow", "Bow", 0, 20, 40, 0));
    // room 2 (normal monster)
    objects[2].push_back(new Monster("Red Slime", 50, 0, 40, 10));
    objects[2].push_back(new Item("Shadow Belle", "Necklace", 0, 0, 15, 0));
    // room 3 (NPC: merchant)
    objects[3].push_back(new Monster("Annoying Friend", 150, 0, 5, 0));
    objects[3].push_back(new NPC("Your Friend's Steve", "\033[1;36mDododo~ do~ dodo~ do~ Steveeeee!\033[0m", products[0]));
    objects[3].push_back(new Item("Iron Boots", "Boots", 0, 0, 15, 0));
    // room 5 (NPC: priest)
    objects[5].push_back(new Monster("Women's Right General", 100, 0, 40, 10));
    objects[5].push_back(new NPC("The Priest", "\033[1;36mYorokobe syounen. Kimi no moti nozomi wa youyaku kanou.......\033[0m", products[1]));
    objects[5].push_back(new Item("Iron Shield", "Shield", 0, 0, 0, 20));
    // room 6 (Little Boss: Dragon)
    objects[6].push_back(new Monster("\033[1;36mBlue-Eyes White Dragon\033[m", 200, 0, 60, 20));
    switch (rand() % 6)
    {
    case 0:
        objects[6].push_back(new Item("\033[1;36mAbyss Shriek\033[m", "Helmet", 30, 30, 70, 40));
        break;
    case 1:
        objects[6].push_back(new Item("\033[1;36mMothwing Cloak\033[m", "Armor", 50, 20, 30, 50));
        break;
    case 2:
        objects[6].push_back(new Item("\033[1;36mShade Cloak\033[m", "Pants", 30, 100, 30, 0));
        break;
    case 3:
        objects[6].push_back(new Item("\033[1;36mIsma's Tear\033[m", "Necklace", 30, 100, 30, 0));
        break;
    case 4:
        objects[6].push_back(new Item("\033[1;36mMonarch Wings\033[m", "Boots", 30, 100, 30, 0));
        break;
    case 5:
        objects[6].push_back(new Item("\033[1;36mDreamshield\033[m", "Shield", 40, 0, 0, 100));
        break;
    default:
        break;
    }
    // room 7 (Treasure Room & Gilles de Rais Easter Egg)
    objects[7].push_back(new Monster("Goblin", 60, 0, 20, 15));
    objects[7].push_back(new NPC("Gilles de Rais", "\033[1;36mI am Gilles de Rais, and I have come to you at your invitation. From here on, I shall be at your command.\033[0m", products[2]));
    objects[7].push_back(treasure[player.getOccupation()]);
    // room 8 (normal monster)
    objects[8].push_back(new Monster("Ghost", 40, 0, 20, 20));
    objects[8].push_back(new Item("Iron Sword", "Sword", 15, 0, 30, 15));
    // room 9 (the Altar)
    objects[9].push_back(new Item("Altar", "Altar", 0, 0, 0, 0));
    // room 10 (normal monster)
    objects[10].push_back(new Monster("Alien", 100, 0, 30, 0));
    // room 11 (NPC: the Wariior)
    objects[11].push_back(new NPC("The Great Warrior", "\033[1;36mChoose one quipment and defeat the BOSS!!!!\033[0m", products[3]));
    // room 12 (normal monster)
    objects[12].push_back(new Monster("Goblin", 60, 0, 20, 15));
    objects[12].push_back(new Item("Iron Axe", "Axe", 0, 0, 30, 20));
    // room 13 (secret room)
    objects[13].push_back(new Item("Lock", "Lock", 0, 0, 0, 0));
    objects[13].push_back(new NPC("\033[1;33mJeanne d'Arc\033[0m", "\033[1;36mHello! Hahaha, someone must mistake you for me.\033[0m", products[4]));
    objects[13].push_back(artifact[player.getOccupation()]);
    // room 14 (trap)
    objects[14].push_back(new Item("Trap", "Trap", 0, 0, 0, 0));
    objects[14].push_back(new Monster("\033[0;32;31mThe Abyss\033[m", 200, 0, 50, 15));
    // room 15 (Boss: )
    objects[15].push_back(new Monster("\033[0;32;31mThe Baphomet\033[m", 500, 0, 70, 15));
    for (int i = 0; i < 16; i++)
    {
        Room r(0, i, objects[i]);
        rooms.push_back(r);
    }
    player.setCurrentRoom(&rooms[0]);
    // set room 0
    rooms[0].setUpRoom(&rooms[3]);
    rooms[0].setLeftRoom(&rooms[1]);
    // set room 1
    rooms[1].setUpRoom(&rooms[2]);
    rooms[1].setRightRoom(&rooms[0]);
    // set room 2
    rooms[2].setDownRoom(&rooms[1]);
    rooms[2].setLeftRoom(&rooms[5]);
    rooms[2].setRightRoom(&rooms[3]);
    // set room 3
    rooms[3].setLeftRoom(&rooms[2]);
    rooms[3].setUpRoom(&rooms[8]);
    rooms[3].setDownRoom(&rooms[0]);
    // set room 5
    rooms[5].setRightRoom(&rooms[2]);
    rooms[5].setUpRoom(&rooms[6]);
    // set room 6
    rooms[6].setDownRoom(&rooms[5]);
    rooms[6].setLeftRoom(&rooms[7]);
    rooms[6].setUpRoom(&rooms[10]);
    // set room 7
    rooms[7].setRightRoom(&rooms[6]);
    // set room 8
    rooms[8].setRightRoom(&rooms[9]);
    rooms[8].setUpRoom(&rooms[12]);
    rooms[8].setDownRoom(&rooms[3]);
    // set room 9
    rooms[9].setLeftRoom(&rooms[8]);
    // set room 10
    rooms[10].setRightRoom(&rooms[15]);
    rooms[10].setUpRoom(&rooms[11]);
    rooms[10].setDownRoom(&rooms[6]);
    // set room 11
    rooms[11].setDownRoom(&rooms[10]);
    // set room 12
    rooms[12].setDownRoom(&rooms[8]);
    rooms[12].setUpRoom(&rooms[14]);
    rooms[12].setLeftRoom(&rooms[15]);
    rooms[12].setRightRoom(&rooms[13]);
    // set room 13
    rooms[13].setLeftRoom(&rooms[12]);
    // set room 14
    rooms[14].setDownRoom(&rooms[12]);
    // set room 15
    rooms[15].setLeftRoom(&rooms[10]);
    rooms[15].setRightRoom(&rooms[12]);
}

/* Deal with player's moveing action */
void Dungeon::handleMovement()
{
    char option = 'A', input;
    map<char, char> decision;
    cout << "\n\033[1;33mWhere do you want to go?\033[m\n";
    if (player.getCurrentRoom()->getUpRoom() != NULL)
    {
        cout << option << ". Move Up.\n";
        decision[option] = 'u'; // stand for up
        decision[option + 32] = 'u';
        option++;
    }
    if (player.getCurrentRoom()->getDownRoom() != NULL)
    {
        cout << option << ". Move Down.\n";
        decision[option] = 'd'; // stand for down
        decision[option + 32] = 'd';
        option++;
    }
    if (player.getCurrentRoom()->getLeftRoom() != NULL)
    {
        cout << option << ". Move Left.\n";
        decision[option] = 'l'; // stand for left
        decision[option + 32] = 'l';
        option++;
    }
    if (player.getCurrentRoom()->getRightRoom() != NULL)
    {
        cout << option << ". Move Right.\n";
        decision[option] = 'r'; // stand for right
        decision[option + 32] = 'r';
        option++;
    }
    cout << "Your choice: ";
    cin >> input;
    switch (decision[input])
    {
    case 'u':
        player.changeRoom(player.getCurrentRoom()->getUpRoom());
        break;
    case 'd':
        player.changeRoom(player.getCurrentRoom()->getDownRoom());
        break;
    case 'l':
        player.changeRoom(player.getCurrentRoom()->getLeftRoom());
        break;
    case 'r':
        player.changeRoom(player.getCurrentRoom()->getRightRoom());
        break;
    default:
        break;
    }
}

/* Deal with player's iteraction with objects in that room */
void Dungeon::handleEvent(Object *object)
{
    if (object->getTag() == "Monster")
    {

        if (object->triggerEvent(&player)) // if monster is dead
        {
            if (object->getName() == "\033[1;36mBlue-Eyes White Dragon\033[m")
            {
                player.setCoin(player.getCoin() + 30);
                cout << "\033[1;33m(Something special things was dropped from the dragon)\033[m\n";
                cout << "\n\033[1;33mCongratulaitons!! Dragon is dead!!\033[m\nYou get 30 coins.\n";
            }
            else if (object->getName() == "\033[0;32;31mThe Baphomet\033[m")
            {
                cout << "\033[2J";
                cout << "\n\033[1;33mCongratulaitons!! The boss is dead!!\nYou can get out of the dungeon now!\033[m\n";
                player.getCurrentRoom()->setIsExit(1);
            }
            else
            {
                player.setCoin(player.getCoin() + 10);
                cout << "\n\033[1;33mCongratulaitons!! This monster is dead!!\033[m\nYou get 10 coins\n";
            }
            player.getCurrentRoom()->popObject(object);
        }
        else
        {
            cout << "\n\033[0;32;31mMonster " << object->getName() << " is still alive.......\033[m\n";
        }
    }
    else if (object->getTag() == "NPC")
    {
        if (object->triggerEvent(&player))
        {
            cout << "\nTrading Successful!!\n";
        }
    }
    else if (object->getTag() == "Player")
    {
        if (object->triggerEvent(&player))
        {
            return;
        }
    }
    else
    {
        if (object->triggerEvent(&player))
        {
            Item* item = dynamic_cast<Item*>(object);
            map<string,string> tran;
            tran["Sword"] = tran["Bow"] = tran["Lance"] = tran["Staff"] = tran["Dagger"] = tran["Whip"] = tran["Axe"] = "Weapon";
            tran["Pants"] = tran["Armor"] = tran["Helmat"] = tran["Boots"] = tran["Necklace"] = tran["Shield"] = "Equipment";
            char sel1;
            if( item->getTag() != "Key" || item->getTag() != "Item")
            {
                cout << "\033[1;33m\nDo you want to wear this item? (Y/N)\033[m\nYes or No: ";
                char sel2;
                cin >> sel2;
                while (sel2 != 'Y' && sel2 != 'y' && sel2 != 'N' && sel2 != 'n')
                {
                    cout << "\n\033[0;32;31mINVALID INPUT!!!\033[m\n\033[1;33mLet's try again. \nDo you want to wear this item? (Y/N)\033[m\nYes or No: ";
                    cin >> sel2;
                }
                if (sel2 == 'Y' || sel2 == 'y')
                {
                    if(tran[item->getTag()] == "Equipment" )
                    {
                        player.changeEquipment(object->getTag(),item);
                        player.getCurrentRoom()->popObject(item);
                        return;
                    }
                    else if(tran[item->getTag()] == "Weapon" && item->getTag() == player.getWeaponType())
                    {
                        player.changeWeapon(item);
                        player.getCurrentRoom()->popObject(item);
                        return;
                    }
                    else
                    {
                        cout << "\nSorry, you can't wear this item....\n"; 
                    }
                }
            }
            player.addItem(*item);
            player.getCurrentRoom()->popObject(item);
        }
    }
}
void Dungeon::handleMap()
{
    switch(player.getCurrentRoom()->getIndex())
    {
        case 0:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|   \033[1;33mX\033[m   |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 1:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |   \033[1;33mX\033[m   |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 2:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|   \033[1;33mX\033[m   |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 3:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|   \033[1;33mX\033[m   |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 5:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |   \033[1;33mX\033[m   |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 6:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|   \033[1;33mX\033[m   |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 7:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |   \033[1;33mX\033[m   |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 8:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |   \033[1;33mX\033[m   |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 9:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|   \033[1;33mX\033[m   |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 10:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |   \033[1;33mX\033[m   |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 11:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |   \033[1;33mX\033[m   |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 12:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|   \033[1;33mX\033[m   |*****|       |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        case 13:
            cout << " _________________________________________________________________________________________________ \n";
            cout << "|                                                                                                 |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                              |       |                   |       |                              |\n";
            cout << "|                               -------                     -------                               |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |*****|   \033[1;33mX\033[m   |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                  *           Boss            *           Secret                 |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                |       |*****|       |                   |       |*****|       |                |\n";
            cout << "|                |       |     |       |                   |       |     |       |                |\n";
            cout << "|                 -------       -------                     -------       -------                 |\n";
            cout << "|                                  *                           *           Altar                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                                  *                           *                                  |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                              |       |*****|       |*****|       |     |  ???  |                |\n";
            cout << "|                              |       |     |       |     |       |     |       |                |\n";
            cout << "|                               -------       -------       -------       -------                 |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                                *             *                                  |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                            |       |*****|       |                              |\n";
            cout << "|                                            |       |     |       |                              |\n";
            cout << "|                                             -------       -------                               |\n";
            cout << "|                                                            Start         X : Player's Position  |\n";
            cout << " _________________________________________________________________________________________________ \n";
            break;
        default:
            break;
    }
}


/* Deal with all game initial setting       */
/* Including create player, create map etc  */
void Dungeon::startGame()
{

    char sel;
    cout << "\033[2J";
    cout << "\033[1;33mDo you want to enter the Dungeon? (Y/N)\033[m\n"
         << "\nYour Choice: ";
    cin >> sel;
    while (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n')
    {
        cout << "\n\033[0;32;31mINVALID INPUT!!!\033[m\nLet's try again. Do you want to enter the Dungeon? Ans(Y or N): ";
        cin >> sel;
    }
    if (sel == 'N' || sel == 'n')
    {
        cout << "Ok, fine. Bye...\n";
        return;
    }
    createPlayer();
    createMap();
    cout << "\n\033[1;33mFriendly Remind :\033[m \n"
    << " > Beat a Monster can earn 10 coins.\n"
    << " > You can use money to trade with NPC.\n"
    << " > You can't use weapons that don't correspond to your class.\n"
    << " > There's some SECRETs within the whole dungeon. Try to find all of it if you can.\n\n\033[1;33mGood Luck!!!\033[m\n\n---------------------------------------------------------\n\n";
}

/* Deal with the player's action     */
/* including showing the action list */
/* that player can do at that room   */
/* and dealing with player's input   */
void Dungeon::chooseAction(vector<Object *> things)
{
    char option = 'A', input;
    map<char, char> decision;
    map<char, int> item;
    if (things.size() > 0 && things[0]->getTag() == "Monster")
    {
        if (player.getCurrentRoom()->getIndex() == 15)
        {
            cout << "\n\033[0;32;31mWARNING!!! You will go into the boss room. Do you insist to go in? Ans(Y/N)\033[m\n";
            cout << "\nYour Choice: ";
            char sel;
            cin >> sel;
            while (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n')
            {
                cout << "\n\033[0;32;31mINVALID INPUT!!!\033[m\nLet's try again.  Do you want to go in the boss room?? Ans(Y or N) \n";
                cout << "\nYour Choice: ";
                cin >> sel;
            }
            if (sel == 'N' || sel == 'n')
            {
                cout << "\n\033[1;33mOk, fine. Get prepared if you want to defeat the boss.\033[m\n";
                player.changeRoom(player.getPreviousRoom());
                return;
            }
            else
            {
                cout << "\n\033[1;33mOk, Be careful! Hoping that you can defeat the boss.\033[m\n";
                handleEvent(things[0]);
                return;
            }
        }
        else
        {
            cout << "\n\033[1;33mYou encounter a monster. What do you want to do?\033[m\n";
            cout << option << ". Fight with " << things[0]->getName() << endl;
            decision[option] = 'f'; // stand for fight
            decision[option + 32] = 'f';
            item[option] = 0;
            item[option + 32] = 0;
            option++;
        }
        if (player.getPreviousRoom() != NULL)
        {
            cout << option << ". Retreat(back to previous room)" << endl;
            decision[option] = 'r'; // stand for retreat
            decision[option + 32] = 'r';
            option++;
        }
    }
    else if (things.size() > 0 && things[0]->getTag() == "Altar") // Special Event: Altar
    {
        int check = 0;
        for (auto it : player.getBackpack())
        {
            if (it.getName() == "Cross" || it.getName() == "Holy Grail")
                check++;
        }
        if (check == 2)
        {
            cout << "\n\033[1;36mMay the God bless you.\033[0m\n";
            player.setCurrentHealth(player.getMaxHealth());
            player.setCurrentMagic(player.getMaxMagic());
            player.setAttack(player.getAttack() + 20);
            player.setDefense(player.getDefense() + 20);
            cout << "\n\033[1;36mYou've accept God's blessing, you are feeling very good now.\033[0m\n";
            player.getCurrentRoom()->popObject(things[0]);
            return;
        }
        else
        {
            cout << "\n\033[1;36mYou are not religious enough. Go back.\033[0m\n";
            player.changeRoom(player.getPreviousRoom());
            return;
        }
    }
    else if (player.getCurrentRoom()->getIndex() == 4) // Special Event: Gachpon
    {
        cout << "\n\n\033[1;33mYou've enter a mysterious place. And there is a machine in front of you.\033[m\n"
             << "\nDo you want to use it? (Y/N)\n"
             << "Yes/No :";
        char sel, sel2;
        cin >> sel;
        while (sel != 'Y' && sel != 'y' && sel != 'N' && sel != 'n')
        {
            cout << "\n\033[0;32;31mINVALID INPUT!!!\033[m\nLet's try again. Do you want to enter the Dungeon? Ans(Y or N): ";
            cin >> sel;
        }
        switch (sel)
        {
        case 'Y':
        case 'y':
            cout << "\n\n\033[1;36mIt's a gachapon machine. Little prize: 10%, Big prize: 90%\033[m\n"
                 << "Put in 10 coins to get a gachapon. Yes or No?\n"
                 << "\nYour Choice: ";
            cin >> sel2;
            while (sel2 == 'y' || sel2 == 'Y')
            {
                if (player.getCoin() >= 10)
                {
                    player.setCoin(player.getCoin() - 10);
                    switch (rand() % 20)
                    {
                    case 0:
                        cout << "\n\033[1;33mCongratulaitons!! You got the BIG PRIZE!!\033[m\n";
                        player.addItem(Item("HaHaHa", "Helmet", 1000, 1000, 1000, 1000));
                        break;
                    case 1:
                    case 2:
                    case 3:
                        cout << "\nNot Bad!! You got 10 coins back!! Keep trying.\n";
                        break;
                    default:
                        cout << "Sorry...You got nothing. Keep trying.\n";
                        break;
                    }
                    cout << "Put in 10 coins to get a gachapon. Yes or No?\n"
                         << "Your Choice: ";
                    cin >> sel2;
                    if (sel2 == 'Y' || sel2 == 'y')
                        continue;
                    else
                        break;
                }
                else
                {
                    cout << "You don't have enough money, bye!!\n";
                    break;
                }
            }
            player.changeRoom(&rooms[3]);
            player.setPreviousRoom(NULL);
            return;
        default:
            player.changeRoom(&rooms[3]);
            player.setPreviousRoom(NULL);
            return;
        }
    }
    else if (things.size() > 0 && things[0]->getTag() == "Trap") // Special Event: Trap
    {
        if (things[1]->triggerEvent(&player) != true)
        {
            player.setCurrentHealth(0);
            return;
        }
        else
        {
            player.setCoin(player.getCoin() + 10);
            cout << "\nCongratulaitons!! This monster is dead!!\nYou get 10 coins\n";
            player.changeRoom(&rooms[4]);
            return;
        }
    }
    else if (things.size() > 0 && things[0]->getTag() == "Lock") // Special Event: Secret Room
    {
        cout << "\n\n\033[0;36mYou've enter a secret chamber.\033[0m\n";
        bool check = 0;
        for (auto it : player.getBackpack())
        {
            if (it.getTag() == "Key")
            {
                check = 1;
                break;
            }
        }
        if (check)
        {
            cout << "\033[0;36mYou have the key. Welcome!\033[0m\n";
            player.getCurrentRoom()->popObject(things[0]);
            return;
        }
        else
        {
            cout << "\033[0;36mYou don't have the key. Go to find it.\n(Hint: Maybe it's not your falut. You're born not to have the key.)\033[0m\n";
            player.changeRoom(player.getPreviousRoom());
            return;
        }
    }
    else
    {
        cout << "\n\033[1;33mWhat do you want to do?\033[m\n";
        cout << option << ". Move" << endl;
        decision[option] = 'm'; // stand for move
        decision[option + 32] = 'm';
        option++;
        int index = 0;
        for (auto i : things)
        {
            if (i->getTag() == "NPC")
            {
                cout << option << ". Talk to " << i->getName() << endl;
                decision[option] = 't'; // stand for talk
                decision[option + 32] = 't';
                item[option] = index;
                item[option + 32] = index;
            }
            else
            {
                cout << option << ". Pick up " << i->getName() << endl;
                decision[option] = 'p'; // stand for pick up
                decision[option + 32] = 'p';
                item[option] = index;
                item[option + 32] = index;
            }
            index++;
            option++;
        }
    }
    if(player.checkMap())
    {
        cout << option << ". Show Map\n";
        decision[option] = 'M'; // stand for MAp
        decision[option + 32] = 'M';
        option++;
    }
    cout << option << ". Show Status\n";
    decision[option] = 's'; // stand for status
    decision[option + 32] = 's';
    option++;
    cout << option << ". Wear equipment or weapon\n";
    decision[option] = 'w'; // stand for status
    decision[option + 32] = 'w';
    option++;

    cout << "\nYour choice: ";
    cin >> input;
    switch (decision[input])
    {
    case 'f':
    case 'p':
    case 't':
        handleEvent(things[item[input]]);
        break;
    case 's':
        handleEvent(&player);
        break;
    case 'r':
        player.changeRoom(player.getPreviousRoom());
        cout << "\033[2J";
        break;
    case 'w':
        player.equip();
        break;
    case 'm':
        handleMovement();
        cout << "\033[2J";
        break;
    case 'M':
        handleMap();
        break;
    default:
        break;
    }
    // if ecounter a monster, whether beat it or you can't do anything but retreat
}

/* Check whether the game should end or not */
/* Including player victory, or he/she dead */
bool Dungeon::checkGameLogic()
{
    if (!player.checkIsDead())
        return player.getCurrentRoom()->getIsExit();
    return player.checkIsDead();
}
/* Deal with the whole game process */
void Dungeon::runDungeon()
{
    startGame();
    while (!checkGameLogic())
        chooseAction(player.getCurrentRoom()->getObjects());
    if (player.checkIsDead())
    {
        cout << "\033[2J";
        cout << "\n___________________________________________________________________________";
        cout << "\n|                                                                          |";
        cout << "\n|             \033[31m@@@@@   @@@@@@      @      @@@@@       \\     |     /\033[0m         |";
        cout << "\n|             \033[31m@    @  @          @ @     @    @       \\    |    /\033[0m          |";
        cout << "\n|             \033[31m@    @  @@@@@     @   @    @    @        \\   |   /\033[0m           |";
        cout << "\n|             \033[31m@    @  @        @@@@@@@   @    @         \\  |  /\033[0m            |";
        cout << "\n|             \033[31m@@@@@   @@@@@@  @       @  @@@@@           \\ | /\033[0m             |";
        cout << "\n|                                                                          |";
        cout << "\n|                                                                          |";
        cout << "\n| \033[31m@@@@@@     @     @       @  @@@@@@     @@@@@@  @       @  @@@@@@  @@@@@\033[0m  |";
        cout << "\n| \033[31m@         @ @    @@     @@  @          @    @   @     @   @       @    @\033[0m |";
        cout << "\n| \033[31m@   @@   @   @   @ @   @ @  @@@@@      @    @    @   @    @@@@@   @@@@@\033[0m  |";
        cout << "\n| \033[31m@    @  @@@@@@@  @  @ @  @  @          @    @     @ @     @       @  @\033[0m   |";
        cout << "\n| \033[31m@@@@@@ @       @ @   @   @  @@@@@@     @@@@@@      @      @@@@@@  @   @\033[0m  |";
        cout << "\n|__________________________________________________________________________|\n";
    }
    else
    {

        cout << "\n____________________________________________________________________________________";
        cout << "\n|                                                                                   |";
        cout << "\n|                                                                                   |";
        cout << "\n|  \033[1;34m@@@@@@@@@  @@@@@@@@@    @       @   @@@@@@@@@   @@@@@@@@@   @       @     @ @ @\033[0m  |";
        cout << "\n|  \033[1;34m@              @        @@      @       @       @           @       @     @ @ @\033[0m  |";
        cout << "\n|  \033[1;34m@              @        @ @     @       @       @           @       @     @ @ @\033[0m  |";
        cout << "\n|  \033[1;34m@              @        @  @    @       @       @           @       @     @ @ @\033[0m  |";
        cout << "\n|  \033[1;34m@@@@@@@        @        @   @   @       @       @@@@@@@@@   @@@@@@@@@     @ @ @\033[0m  |";
        cout << "\n|  \033[1;34m@              @        @    @  @       @               @   @       @     @ @ @\033[0m  |";
        cout << "\n|  \033[1;34m@              @        @     @ @       @               @   @       @     @ @ @\033[0m  |";
        cout << "\n|  \033[1;34m@              @        @      @@       @               @   @       @\033[0m            |";
        cout << "\n|  \033[1;34m@          @@@@@@@@@    @       @   @@@@@@@@@   @@@@@@@@@   @       @     @ @ @\033[0m  |";
        cout << "\n|                                                                                   |";
        cout << "\n|___________________________________________________________________________________|\n";
    }
}