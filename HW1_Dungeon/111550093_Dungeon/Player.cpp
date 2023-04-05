#include "Player.h"

// constructor
Player::Player()
    : GameCharacter("", "Player", 0, 0, 0, 0), coin(0), currentRoom(NULL), previousRoom(NULL)
{
    setOccupation("Empty");
    occupation = make_pair("Empty","Empty");
    weapon = Item("Empty","Empty",0,0,0,0);
    equipment["Helmet"] = Item("Empty", "Helmet", 0, 0, 0, 0);
    equipment["Necklace"] = Item("Empty", "Necklace", 0, 0, 0, 0);
    equipment["Armor"] = Item("Empty", "Armor", 0, 0, 0, 0);
    equipment["Shield"] = Item("Empty", "Shield", 0, 0, 0, 0);
    equipment["Pants"] = Item("Empty", "Pants", 0, 0, 0, 0);
    equipment["Boots"] = Item("Empty", "Boots", 0, 0, 0, 0);
}
Player::Player(string name, string occupation, int maxHealth, int maxMagic, int attack, int defense, int money)
    : GameCharacter(name, "Player", maxHealth, maxMagic, attack, defense), coin(money)
{
    backpack.clear();
    currentRoom = NULL;
    previousRoom = NULL;
    setOccupation(occupation);
    if (occupation == "Saber")
    {
        this->occupation = make_pair("Saber","Sword");
        this->weapon = Item("Empty", "Sword", 0, 0, 0, 0);
        this->skill[0] = Skill("Karisuma", "ATKup", 10, 10, "Attack UP!\n");
        this->skill[1] = Skill("Kagayakeru Michi", "MPup", 10, 0, "MP up up!!\n");
        this->skill[2] = Skill("Excalibur", "Demage", 100, 40, "\n\033[1;33m「───束ねるは星の息吹、輝ける命の奔流。受けるが良い!『約束された勝利の剣 (エクスカリバー) 』ーーー！！」\033[m");
    }
    else if (occupation == "Archer")
    {
        this->occupation = make_pair("Archer","Bow");
        this->weapon = Item("Empty", "Bow", 0, 0, 0, 0);
        this->skill[0] = Skill("Shinig", "Heal", 30, 5, "Heal\n");
        this->skill[1] = Skill("Gate of Babylon", "MPup", 20, 0, "MP up up!!\n");
        this->skill[2] = Skill("Enuma Elish", "Demage", 150, 40, "\033[1;33m\n「───裁きの時だ。世界を割くは我が乖離剣。受けよ! 『天地乖離す開闢の星(エヌマ・エリシュ)』ーーー！！」\033[m\n");
    }
    else if (occupation == "Lancer")
    {
        this->occupation = make_pair("Lancer","Lance");
        this->weapon = Item("Empty", "Lance", 0, 0, 0, 0);
        this->skill[0] = Skill("Karisuma", "ATKup", 10, 5, "Attack UP!\n");
        this->skill[1] = Skill("Kagayakeru Michi", "MPup", 5, 0, "MP up up!!");
        this->skill[2] = Skill("Gae Bulg", "Demage", 150, 40, "\033[1;33m\n「───刺し穿ち……突き穿つ! 『貫き穿つ死翔の槍 (ゲイ･ボルク･オルタナティブ)』ーーー! ! 」\033[m\n");
    }
    else if (occupation == "Caster")
    {
        this->occupation = make_pair("Caster","Staff");
        this->weapon = Item("Empty", "Staff", 0, 0, 0, 0);
        this->skill[0] = Skill("Eiyuu Sakusei", "DEFup", 30, 30, "DEF UP!\n");
        this->skill[1] = Skill("Bless of Avalon", "MPup", 30, 0, "MP up up!!");
        this->skill[2] = Skill("Garden of Avalon", "ATKup", 50, 50, "....");
    }
    else if (occupation == "Assassin")
    {
        this->occupation = make_pair("Assassin","Dragger");
        this->weapon = Item("Empty", "Dragger", 0, 0, 0, 0);
        this->skill[0] = Skill("maryoku souten", "ATKup", 10, 5, "Attack UP!\n");
        this->skill[1] = Skill("Kagayakeru Michi", "MPup", 5, 0, "MP up up!!");
        this->skill[2] = Skill("Tubame Gaesi", "Demage", 50, 10, "Tubame Gaesi");
    }
    else if (occupation == "Rider")
    {
        this->occupation = make_pair("Rider","Whip");
        this->weapon = Item("Empty", "Whip", 0, 0, 0, 0);
        this->skill[0] = Skill("Karisuma", "ATKup", 10, 5, "Attack UP!\n");
        this->skill[1] = Skill("Kagayakeru Michi", "MPup", 5, 0, "MP up up!!");
        this->skill[2] = Skill("Excalibur", "Demage", 50, 10, "Ex.......caliburrrrrr!!!!!!!!!\n");
    }
    else if (occupation == "Berserker")
    {
        this->occupation = make_pair("Berserker","Axe");
        this->weapon = Item("Empty", "Axe", 0, 0, 0, 0);
        this->skill[0] = Skill("Karisuma", "ATKup", 10, 5, "Attack UP!\n");
        this->skill[1] = Skill("Kagayakeru Michi", "MPup", 5, 0, "MP up up!!");
        this->skill[2] = Skill("Excalibur", "Demage", 50, 10, "Ex.......caliburrrrrr!!!!!!!!!\n");
    }
    equipment["Helmet"] = Item("Empty", "Helmet", 0, 0, 0, 0);
    equipment["Necklace"] = Item("Empty", "Necklace", 0, 0, 0, 0);
    equipment["Armor"] = Item("Empty", "Armor", 0, 0, 0, 0);
    equipment["Shield"] = Item("Empty", "Shield", 0, 0, 0, 0);
    equipment["Pants"] = Item("Empty", "Pants", 0, 0, 0, 0);
    equipment["Boots"] = Item("Empty", "Boots", 0, 0, 0, 0);
}

// basic function
void Player::addItem(Item item)
{
    backpack.push_back(item);
}
void Player::popItem(string name)
{
    for (auto i = backpack.begin(); i != backpack.end(); i++)
    {
        if (i->getName() == name)
        {
            backpack.erase(i);
            break;
        }
    }
}
void Player::equip()
{
    /* check whether player already equip this equipment */
    /* if already equip, then put it in backpack */
    char option = 'A', sel;
    map<char, string> part;
    part['a'] = part['A'] = "Weapon";
    part['b'] = part['B'] = "Helmet";
    part['c'] = part['C'] = "Necklace";
    part['d'] = part['D'] = "Armor";
    part['e'] = part['E'] = "Shield";
    part['f'] = part['F'] = "Pants";
    part['g'] = part['G'] = "Boots";

    cout << "\n\033[1;33mChoose which part do you want to equip?\033[m\n";
    cout << " > A. Weapon\n"
         << " > B. Helmet\n"
         << " > C. Necklace\n"
         << " > D. Armor\n"
         << " > E. Shield\n"
         << " > F. Pants\n"
         << " > G. Boots\n";
    cout << "\nYour Choice: ";
    cin >> sel;
    map<char, int> det;
    char s = 'A';
    int index = 0;
    switch (sel)
    {
    case 'a':
    case 'A':
        cout << "\n\033[1;33m\nChoose the weapon you want to wear?\033[m\n";
        for (int i = 0 ; i < backpack.size() ; i++)
        {
            if (backpack[i].getTag() == occupation.second)
            {
                cout << " > " << s << ". " << backpack[i].getName() << endl;
                det[s] = index;
                det[s+32] = index;
                s++;
            }
            index++;
        }
        if (s == 'A')
        {
            cout << "Sorry, You don't have any corresponding weapon.\n";
            cout << "\033[1;33mDo you want to wear other equipment? (Y/N)\033[m\nYes or No: ";
            char ss;
            cin >> ss;
            switch (ss)
            {
            case 'y':
            case 'Y':
                equip();
                return;
            default:
                return;
            }
        }
        else
        {
            cout << "\nYour Choice: ";
            char ss;
            cin >> ss;
            changeWeapon(&backpack[det[ss]]);
            popItem(backpack[det[ss]].getName());
        }
        break;
    default:
        cout << "\033[1;33m\nWhich one do you want to wear?\033[m\n";
        for (int i = 0 ; i < backpack.size() ; i++)
        {
            if (backpack[i].getTag() == part[sel])
            {
                cout << " > " << s << ". " << backpack[i].getName() << endl;
                det[s] = index;
                det[s+32] = index;
                s++;
            }
            index++;
        }
        if (s == 'A')
        {
            cout << "\nSorry, You don't have any corresponding equipment.\n";
            cout << "\n\033[1;33mDo you want to wear other equipment? (Y/N)\033[m\n\nYes or No: ";
            char ss;
            cin >> ss;
            switch (ss)
            {
            case 'y':
            case 'Y':
                equip();
                return;
            default:
                return;
            }
        }
        else
        {
            cout << "\nYour Choice: ";
            char ss;
            cin >> ss;
            changeEquipment(part[sel], &backpack[det[ss]]);
            popItem(backpack[det[ss]].getName());
            break;
        }
    }
}
void Player::changeEquipment(string part, Item *item)
{
    if (equipment[part].getName() != "X")
    {
        increaseStates(equipment[part].getHealth() * (-1), equipment[part].getMagic() * (-1), equipment[part].getAttack() * (-1), equipment[part].getDefense() * (-1));
        addItem(equipment[part]);
    }
    equipment[part] = *item;
    increaseStates(item->getHealth(), item->getMagic(), item->getAttack(), item->getDefense());
}
void Player::changeWeapon(Item *item)
{
    if (weapon.getName() != "X")
    {
        increaseStates(weapon.getHealth() * (-1), weapon.getMagic() * (-1), weapon.getAttack() * (-1), weapon.getDefense() * (-1));
        addItem(weapon);
    }
    weapon = *item;
    increaseStates(item->getHealth(), item->getMagic(), item->getAttack(), item->getDefense());
}
void Player::increaseStates(int health, int magic, int attack, int defense)
{
    setMaxHealth(getMaxHealth() + health);
    setCurrentHealth(getCurrentHealth() + health);
    setCurrentMagic(getCurrentMagic() +  magic);
    setMaxMagic(getMaxMagic() + magic);
    setAttack(getAttack() + attack);
    setDefense(getDefense() + defense);
}
void Player::changeRoom(Room *next)
{
    setPreviousRoom(getCurrentRoom());
    setCurrentRoom(next);
}
void Player::showStatus()
{
    cout << "\n\033[0;32;32mPlayer Status:\033[m\n"
         << '[' << getName() << ']' << endl;
    cout << " > \033[1;37mClass: \033[m" << getOccupation() << endl;
    cout << " > \033[1;33mCoin: \033[m" << getCoin() << endl;
    cout << " > \033[1;36mHP: \033[m" << getCurrentHealth() << '/' << getMaxHealth() << endl;
    cout << " > \033[1;35mMP: \033[m" << getCurrentMagic() << '/' << getMaxMagic() << endl;
    cout << " > \033[1;31mAttack:  \033[m" << getAttack() << endl;
    cout << " > \033[0;32;32mDefense: \033[m" << getDefense() << endl;
}
void Player::showEquipment()
{
    cout << "\033[1;33mEquipment:\033[m  " << endl;
    cout <<" > Weapon (" << getWeaponType() << setw(9-getWeaponType().length()) << left << "): " ;
    cout << setw(15) << left << weapon.getName() ;
    cout << " (HP +"  << setw(3) << right << weapon.getHealth()
         << ", MP +"  << setw(3) << right << weapon.getMagic() 
         << ", ATK +" << setw(3) << right <<weapon.getAttack()
         << ", DEF +" << setw(3) << right <<weapon.getDefense() << ")" << endl;
    cout << setw(20) << left << " > Helmet: ";
    cout << setw(15) << left << equipment["Helmet"].getName();
    cout << " (HP +"  << setw(3) << right << equipment["Helmet"].getHealth()
         << ", MP +"  << setw(3) << right << equipment["Helmet"].getMagic() 
         << ", ATK +" << setw(3) << right <<equipment["Helmet"].getAttack()
         << ", DEF +" << setw(3) << right << equipment["Helmet"].getDefense() << ")" << endl;
    cout << setw(20) << left << " > Necklace: ";
    cout << setw(15) << left << equipment["Necklace"].getName() ;
    cout << " (HP +"  << setw(3) << right << equipment["Necklace"].getHealth()
         << ", MP +"  << setw(3) << right << equipment["Necklace"].getMagic() 
         << ", ATK +" << setw(3) << right << equipment["Necklace"].getAttack()
         << ", DEF +" << setw(3) << right << equipment["Necklace"].getDefense() << ")" << endl;
    cout << setw(20) << left << " > Armor: ";
    cout << setw(15) << left << equipment["Armor"].getName();
    cout << " (HP +"  << setw(3) << right << equipment["Armor"].getHealth()
         << ", MP +"  << setw(3) << right << equipment["Armor"].getMagic() 
         << ", ATK +" << setw(3) << right << equipment["Armor"].getAttack()
         << ", DEF +" << setw(3) << right << equipment["Armor"].getDefense() << ")" << endl;
    cout << setw(20) << left << " > Shield: ";
    cout << setw(15) << left << equipment["Shield"].getName();
    cout << " (HP +"  << setw(3) << right << equipment["Shield"].getHealth()
         << ", MP +"  << setw(3) << right << equipment["Shield"].getMagic() 
         << ", ATK +" << setw(3) << right << equipment["Shield"].getAttack()
         << ", DEF +" << setw(3) << right << equipment["Shield"].getDefense() << ")" <<  endl;
    cout << setw(20) << left << " > Pants: ";
    cout << setw(15) << left << equipment["Pants"].getName();
    cout << " (HP +"  << setw(3) << right << equipment["Pants"].getHealth()
         << ", MP +"  << setw(3) << right << equipment["Pants"].getMagic() 
         << ", ATK +" << setw(3) << right << equipment["Pants"].getAttack()
         << ", DEF +" << setw(3) << right << equipment["Pants"].getDefense() << ")" << endl;
    cout << setw(20) << left << " > Boots: ";
    cout << setw(15) << left << equipment["Boots"].getName();
    cout << " (HP +"  << setw(3) << right << equipment["Boots"].getHealth()
         << ", MP +"  << setw(3) << right << equipment["Boots"].getMagic() 
         << ", ATK +" << setw(3) << right << equipment["Boots"].getAttack()
         << ", DEF +" << setw(3) << right << equipment["Boots"].getDefense() << ")" <<  endl;
}
void Player::showBackpack()
{
    cout << "\033[1;33mBackpack:\033[m  " << endl;
    if (!(getBackpack().empty()))
    {
        for (auto &i : backpack)
        {
            if(i.getName() == "X") continue;
            cout <<  " > " << setw(15) << left << i.getName() ;
            cout << " (" << setw(10) << left << i.getTag() << ", HP: +" << setw(3) << right << i.getHealth() << ", MP: +" 
                 << setw(3) << right << i.getMagic() << ", ATK: +" << setw(3) << right << i.getAttack() << ", DEF: +" 
                 << setw(3) << right << i.getDefense() << ")" << endl;
        }
    }
    else
        cout << " (no items)" << endl;
}


/* Virtual function that you need to complete   */
/* In Player, this function should show the     */
/* status of player.                            */
bool Player::triggerEvent(Object *object)
{
    cout << "\n------------------------------------------------";
    showStatus();
    showEquipment();
    showBackpack();
    cout << "------------------------------------------------\n";
    return true;
}

/* Set & Get function*/
void Player::setCurrentRoom(Room *cur)
{
    this->currentRoom = cur;
}
void Player::setPreviousRoom(Room *prev)
{
    this->previousRoom = prev;
}
void Player::setEquipment(map<string, Item> equipment)
{
    this->equipment = equipment;
}
void Player::setBackpack(vector<Item> backpack)
{
    this->backpack = backpack;
}
void Player::setOccupation(string name)
{
    this->occupation.first = name;
}
void Player::setCoin(int money)
{
    this->coin = money;
}
Room *Player::getCurrentRoom()
{
    return currentRoom;
}
Room *Player::getPreviousRoom()
{
    return previousRoom;
}
map<string, Item> Player::getEquipment()
{
    return equipment;
}
vector<Item> Player::getBackpack()
{
    return backpack;
}
string Player::getOccupation()
{
    return occupation.first;
}
int Player::getCoin()
{
    return coin;
}
string Player::getWeaponType()
{
    return occupation.second;
}
Item Player::getWeapon()
{
    return weapon;
}

