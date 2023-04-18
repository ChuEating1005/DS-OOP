#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Character {
   private:
    string Name;
    int Hp;
    int Sp;

   public:
    void setName(string Name) { this->Name = Name; }
    void setHp(int Hp) { this->Hp = Hp; }
    void setSp(int Sp) { this->Sp = Sp; }

    void showStatus() {
        cout << "Name:" << this->Name << endl;
        cout << "HP:" << this->Hp << endl;
        cout << "SP:" << this->Sp << endl;
    }
};

class Player : public Character {
   private:
    int ATK;
    int DEF;

   public:
    Player(string Name, int Hp, int Sp) {
        
        setName(Name);
        setHp(Hp);
        setSp(Sp);
        ATK = 15;
        DEF = 10;
    }

    void showPlayerStatus() {
        showStatus();
        cout << "ATK:" << ATK << endl;
        cout << "DEF:" << DEF << endl;
    }
};

class Monster : public Character {
   private:
    int EXP;

   public:
    Monster(string Name, int Hp, int Sp, int EXP) {
        setName(Name);
        setHp(Hp);
        setSp(Sp);
        this->EXP = EXP;
    }

    void showMonsterStatus() {
        showStatus();
        cout << "EXP:" << EXP << endl;
    }
};

int main() {
    string n1, n2;
    int a, b, c, d, e;
    cin >> n1 >> a >> b;
    cin >> n2 >> c >> d >> e;

    Player P1(n1, a, b);
    P1.showPlayerStatus();

    Monster M1(n2, c, d, e);
    M1.showMonsterStatus();

    return 0;
}