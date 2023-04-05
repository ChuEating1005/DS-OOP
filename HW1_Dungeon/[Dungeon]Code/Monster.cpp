#include "Monster.h"
Monster::Monster() : GameCharacter() {}
Monster::Monster(string name, int maxHealth, int maxMagic, int attack, int defense)
    : GameCharacter(name, "Monster", maxHealth, maxMagic, attack, defense)
{
}
bool Monster::triggerEvent(Object *object)
{
    cout << "\033[2J";
    if (getName() == "\033[1;36mBlue-Eyes White Dragon\033[m")
    {
        cout << "\033[1;36m                                                .:^.                                                                    \n";
        cout << "\033[1;36m                                             .:~7:                .:^          :^^::.                                   \n";
        cout << "\033[1;36m                                           .:.7J:             ..::^~^   ...     .^!7J?7^. .                             \n";
        cout << "\033[1;36m                                       ..::..?5:           ....:~!!75?!!~~^:       :^!JPP?:::.                          \n";
        cout << "\033[1;36m                                    .:^:.^.^YG7.        .::..:^~~~!PB5?!?J?!^^::     ^^:7J::^^:..                       \n";
        cout << "\033[1;36m                                ..^^^^.  :~~?!~:     .:::...::..:!7BJ7~!??!~~^^.     :7:^: ...:^^:.                     \n";
        cout << "\033[1;36m                             .:^^^:....   :!77^   :^^^^^:.   .:::J~!:~?JJ?JY!.        ~~~:  :~^ .::::.                  \n";
        cout << "\033[1;36m                          .:^::.     .~?!: .~!^ .~!~~^:. .:^!!7:^^.^!!!!?77!!~.       .!^.:Y#@&P7: ..:::.               \n";
        cout << "\033[1;36m                       .:::..     ^?P#@@@&G~.^^^!?77^: .!Y?7?Y!.~??7!!7!~!!^^~~.       !:.5@@##&@#5~  ..::.             \n";
        cout << "\033[1;36m                   ..::.      :!YB&@@@&&@@@G.:^!~~^:...7J7~~?~^?YY??JJ?!~^^^:.~~.      ^: 5&@BYYPG#&G!.  .::.           \n";
        cout << "\033[1;36m                 .::.      ^?P&@@#BGPPG&@@@@7.^:..^!~^^~::!7~!7!J?7!!7??7^:^~:.^^     .^. PBB#J?77J5G#G7.  .::          \n";
        cout << "\033[1;36m              .::.     .!YB&@#GY?7??JJB@&&&@#~.  :~^:::^~7J???!!!^^^:::!7!^.:~:.^.    ^:..P5?G?!?7!!7JP#B7   .^.        \n";
        cout << "\033[1;36m            :::.     ~Y#&&GY?!~~^^~7JG#GP5Y5BG^:^~~:..:^~^~?7!~^:.     :?!~^:^^.::   .^. ~P?~7?:~?!~~!!?5#G~   :^       \n";
        cout << "\033[1;36m          .^:::.  :?B&#PJ7~~^^^^^^^?PPY?77!7?PG! :^:  :..^!7!^~:      .~7!~^::^..:  .^. :GY?^:7^:~?!^^~~!?PBJ.  .^.     \n";
        cout << "\033[1;36m         .:.^!?!^?&&GJ7~~^::.....:~YY?77!!!!?J5BJ..:^.  :~!!^~:     .::!?!~^::^::: .^. ^PP77:.!~^.!?~:^^~~!JGG~  .^.    \n";
        cout << "\033[1;36m        .: :~!~!G&GJ!~^:..       :?J??7~~~^~???JGG~ .^. ^~~^~?~.   ::.:7?!!^::^:~:.^. !PY77~.:7~^:.?J~:^^^^~7YB?   ~:   \n";
        cout << "\033[1;36m       .^ :~~:?#GJ!~^:.         :JJ??7~^^^:!Y??7?5BY: .:^:......  ~: .777~^^:^~^7:: .?PJ?7!^ 7Y~^:.:YJ~.:::^~!?GY   ~.  \n";
        cout << "\033[1;36m      .: :^::P#Y7~^..          ^YJ??7~~!~^^75?!77?YG#7  .::... ::!!  !?!!!^^^^^7!..7PPJ?77~. PP7~^:.!P?~....:^~7GJ:^~!  \n";
        cout << "\033[1;36m     .^..:.!BP?~^..     .:.   :P5JJ?^7?!^~^~~~^!7?JJP@5^.. ..:!~?5^ .7777~^^^~?J^?BBPJ?77!: ~&G?~^:: 55?~   .:^~75^~~!. \n";
        cout << "\033[1;36m     ^..:.YBY!^:.     .~!^.  :GGYJJ~?&P.J&J:?#7^77?JYPBBPYY?~~7^7!^  ^!!~^::~??~#G?!~!777~. PPPY7!^:.^BYJ^   ..^~?~^^~: \n";
        cout << "\033[1;36m    ^...:5G?~:.     .^^..^  .P#PYJ7:PG:~G#~?#&J:?J7?YYYYJJ5GPY7 .:.:  :^:^^~!~:~!     .!~. ?7^JJ?7?7~ YB5?^   ..^!7.^~: \n";
        cout << "\033[1;36m   ::..:557^:.    :^:.  ::  Y#GPYJ~7J^^YJ~!GG5?7:!J7~:.    :^!JJ7..J!    :^~~^~!       :^ ~7^GBJPBYGP:^#G5?::. .:^7.:^: \n";
        cout << "\033[1;36m  .: .^5Y!:.    :^:     :. 7&BBG?^^^ ^7~:?BBP555Y:~J7:.....:~755~:?Y?~.    .~?!::       ^:~:^JPGYPGJPY.G#P7 .^. .:7:.~^ \n";
        cout << "\033[1;36m .^..:5J!:.   .^:       ^ ~&&G?: .:  ^:^!&#GY77JPP^:J! :^~?JJ!~::^?7:.:. .~YGP?J?.      ~~:~:.~G?^5?:5!7&G~  .^. :7: ^: \n";
        cout << "\033[1;36m :. .??~.   .^:        .:^##?.    .~J5J^P&BJ?J55Y5P:77^.J5^?~^^  !~~.  ^Y5B5YBY!~^.    :~^!^!J^JY:!J.!?:B#:   .^ .!. ~. \n";
        cout << "\033[1;36m.^  7?~.   ::.         .^G5:   .^:J5?!7JJ~~~^:^^!Y7~?Y5Y5P:~:^^::Y?^^..Y5?7!^:7?!::::^:7:!7J5?^~!.^7.^~:PB.    :::!..^  \n";
        cout << "\033[1;36m^. !?~.  .:.           ^J~     ~!?PY!:^^..     .?!.:!~7J?!~:^ ::!Y~:::~77J?:   .~7?5J7~!^J5J:  :^ .~ :: 5P      ^:! .:  \n";
        cout << "\033[1;36m^ ~?~. .:.             !.     :^~??J!:         ..  .~^~^^^^:^. ^~~^. :J5B5^      .~!~~:~^5~        .    ~7      :~~ ^   \n";
        cout << "\033[1;36m^:?~. ::                     :~^75Y!.            :~~:::^^~~^:::YY~::.JPJ77!:.   .^~!!^..:7^             ..      .!^::   \n";
        cout << "\033[1;36m:7!:.:.                      ^7!7!?!             ~~ .:::!JY~^:757:::^!~?5PYJ?~~~::.      .^                     .7.^    \n";
        cout << "\033[1;36m^7::^.                       :!7G^~?:         ..^^    :^~77!:!^!!   75BP?~~!77???77:.                           :!:.    \n";
        cout << "\033[1;36m!~^^                         .^7J!~7?~:~!^::^??7~7^   ::^~77!5?:^. 7P5Y77^  ..^:^~!!~^^:                        ~!.     \n";
        cout << "\033[1;36m!^:                          .:77~^::^7?77!~??7~7##J::~75P5GYY?!::~77?YBY~:    ^      ..                       .7:      \n";
        cout << "\033[1;36m!:                             .~55?!::^^^^~~^^^?P5PPPP5Y?PG7~:.:7JPGP@&GJ7!~: .:                              .:       \n";
        cout << "\033[1;36m^                                :7JY?J?7!~^::~^:~??J?JY5G@G:. .JPGP!7G&@#GYYY?^::                                      \n";
        cout << "\033[1;36m                                     .~?JJY5555!::JYY#&@@&GB^.7PPY?~75G?5BP   ^5!:                                      \n";
        cout << "\033[1;36m                                           .:!J?77#5JPB##&BY???7?J!Y5777~^^:::^~.                                       \n";
        cout << "\033[1;36m                                          .:!?!775P?^  ..:::.  :^!JJ!!?77!!77!?:                                        \n";
        cout << "\033[1;36m                                         .~??~^^~7!~7~.          .^?7JY5J7YJJPBGY7:                                     \n";
        cout << "\033[1;36m                                        .!P&PY7:?PJ7?Y~            .::~PY5GGG#BG5YY7:                                   \n";
        cout << "\033[1;36m                                       .^PB5Y5^ P&PJ5BJ~             .^7YPGBB5Y55?~^~~.                                 \n";
        cout << "\033[1;36m                                       .~P7~::..GY7~^J57.             ...:~7JY?:^~7^ ..                                 \n";
        cout << "\033[1;36m                                       .77^. ..^J~: .:J?.                   .:!^  .^:                                   \n";
        cout << "\033[1;36m                                       .~~.   :~!^   .~?                      .::                                       \n";
        cout << "\033[1;36m                                       .^.    .^^     ^^                                                                \n";
        cout << "\033[1;36m                                        .      :.                                                                       \033[m\n";
    }
    cout << fight ;
    Player *player = dynamic_cast<Player *>(object);
    while (!player->checkIsDead())
    {
        char option = 'A';
        map<char, char> decision;
        cout << "\n\033[1;33mWhat do you want to do?\033[m\n";
        cout << option << ". Normal Attack\n";
        decision[option] = 'N';
        decision[option + 32] = 'N';
        option++;
        for (int i = 0; i < 3; i++)
        {
            if (i == 2 && player->checkEnoughMagic(player->skill[i].getMP()))
            {
                cout << option << ". Use Ultimate Skill: " << player->skill[i].getSkillName() << endl;
                decision[option] = i + 1;
                decision[option + 32] = i + 1;
                option++;
            }
            else if (player->checkEnoughMagic(player->skill[i].getMP()))
            {
                cout << option << ". Use Skill " << i + 1 << ": " << player->skill[i].getSkillName() << endl;
                decision[option] = i + 1;
                decision[option + 32] = i + 1;
                option++;
            }
        }
        cout << option << ". Run Away\n";
        decision[option] = 'R';
        decision[option + 32] = 'R';
        option++;
        cout << "\nYour Choice: ";
        char input;
        cin >> input;
        int monster_dam = getAttack() - player->getDefense();
        int player_dam = player->getAttack() - getDefense();
        if (monster_dam < 0)
            monster_dam = 0;
        if (player_dam < 0)
            player_dam = 0;
        switch (decision[input])
        {
        case 'R':
            return false;
            break;
        case 'N':
            cout << "\n\nYour attack does " << player_dam << " damage.\n"
                 << this->getName() << "\'s attack does " << monster_dam << " damage\n\n";
            player->takeDamage(monster_dam);
            this->takeDamage(player_dam);
            cout << "\n------------------";
            player->showStatus();
            showStatus();
            if (this->checkIsDead())
                return true;
            else
                break;
        case 1:
        case 2:
        case 3:
            if(decision[input]==3) cout << "\033[2J";
            player->skill[decision[input] - 1].getScript();
            if (player->skill[decision[input] - 1].getType().first == "Demage")
            {
                this->takeDamage(player->skill[decision[input] - 1].getType().second + player_dam);
                this->showStatus();
            }
            else if (player->skill[decision[input] - 1].getType().first == "Heal")
            {
                player->healing(player->skill[decision[input] - 1].getType().second);
            }
            else if (player->skill[decision[input] - 1].getType().first == "ATKup")
            {
                player->setAttack(player->getAttack() + player->skill[decision[input] - 1].getType().second);
            }
            else if (player->skill[decision[input] - 1].getType().first == "DEFup")
            {
                player->setDefense(player->getDefense() + player->skill[decision[input] - 1].getType().second);
            }
            else if (player->skill[decision[input] - 1].getType().first == "MPup")
            {
                player->setCurrentMagic(player->getCurrentMagic() + player->skill[decision[input] - 1].getType().second);
            }
            player->useMaigc(player->skill[decision[input] - 1].getMP());
            cout << this->getName() << "\'s attack does " << monster_dam << " damage\n\n";
            player->takeDamage(monster_dam);
            cout << "\n------------------";
            player->showStatus();
            cout << "\n------------------\n";
            if (this->checkIsDead())
                return true;
            else
                break;
            break;
        default:
            break;
        }
    }
}
void Monster::showStatus()
{
    cout << "------------------\n\033[0;32;31mMonster Status:\033[m\n"
         << '[' << getName() << ']' << endl;
    cout << " > HP: " << getCurrentHealth() << '/' << getMaxHealth() << endl;
    cout << " > MP: " << getCurrentMagic() << '/' << getMaxMagic() << endl;
    cout << " > Attack:  " << getAttack() << endl;
    cout << " > Defense: " << getDefense() << "\n------------------\n";
    ;
}