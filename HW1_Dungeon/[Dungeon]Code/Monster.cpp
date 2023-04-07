#include "Monster.h"
Monster::Monster() : GameCharacter() {}
Monster::Monster(string name, int maxHealth, int maxMagic, int attack, int defense)
    : GameCharacter(name, "Monster", maxHealth, maxMagic, attack, defense)
{
}
bool Monster::triggerEvent(Object *object)
{
    Player *player = dynamic_cast<Player *>(object);
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
    else if (getName() == "\033[0;32;31mThe Baphomet\033[m")
    {
        cout << "\033[0;32;31m                                                                                           .    ..~.      .:. . ...:    \n";
        cout << "\033[0;32;31m                                                                                       .:.::. :!7!!^^~^..^7?7^::!       \n";
        cout << "\033[0;32;31m                                                                              .~!!!7^..:~!^:. ^!7~!7?JJ!!?7!~!~^.       \n";
        cout << "\033[0;32;31m                                                                             .^!~~~~!7?!^~!JJ~~~!77!!?J?J!              \n";
        cout << "\033[0;32;31m                                                         .:^^:::.          .~~^:.::~!!!!7???7!!7??7!77?J~               \n";
        cout << "\033[0;32;31m                                                      :~7JYYY55YJ?!~:      :~^...^~^:.:^~~~~~7?7: :~~~^.                \n";
        cout << "\033[0;32;31m                                                   :!J5PPGGGGGBGPPYJJ7:     ^!^..:.. .^^^~7??5Y.                        \n";
        cout << "\033[0;32;31m                                                .~?PGGGBBGGGPGGBBGP55YJ7:    .:7~.  .~!~?JJJJ5Y       .                 \n";
        cout << "\033[0;32;31m                       .~^:                   :75GGBGGG5J!^:..:!JPGGGP5YJ^     .?5?7YGGYYPYJJGG7::^~7?!.                \n";
        cout << "\033[0;32;31m                        .~7JJ7~:.       ..^!?5G##BGPY7^.         :?PGGP55Y~      JP55PJ.:J??5GBBGP5Y!:                  \n";
        cout << "\033[0;32;31m                           .!JPGPP5YYYY5PG####BGPJ!:               7PGGPYJ?:     :YY5? .JYJYGP7!!^.                     \n";
        cout << "\033[0;32;31m                               :~7JY55555P5J?!^:.           .:::^^^~YGBGP55?     .J5P7~JY?JPGJ                          \n";
        cout << "\033[0;32;31m                                                        .^7YPGB#######BBGP5Y^   .!Y5B#PYY5GG5:                          \n";
        cout << "\033[0;32;31m                                                     :!YG##&&&&&&&@@@&#BGP55?   ~GY5B5JJP#BY:                           \n";
        cout << "\033[0;32;31m                                                 .^?PB&&&###&&&&@&57~!PBBGP55~^^:JYPB5PBBGG?                            \n";
        cout << "\033[0;32;31m                                              .~JG#########&&&@&5^.^^~7GBGP555GGY5YP&GB#BG#B7                           \n";
        cout << "\033[0;32;31m                                           .^JPBBBBB#####&&&@&5^ .~J5PBBBBBGPGBGPP5G&#BB#&##B~                          \n";
        cout << "\033[0;32;31m                                         :7YGGGGPGBB##&&&&&@B! .:!YG#&&&&####BBBGGPB###&&##BBP^                         \n";
        cout << "\033[0;32;31m                                       .75PGGPPGBBBB##&&&&&5: .^J#&&@@@&&&&#####BBB##&@@&&&###P.                        \n";
        cout << "\033[0;32;31m                                      :J5PGGPPGBBGB##&&&@@#. ~5B#&&&&&@@&&@&BG#&####&&@@@@@@&&#P:                       \n";
        cout << "\033[0;32;31m                                     ~YPPGPPGBBGB##&&&@@@@&7 ^5G#BBB#&@@@@&G&&G##&###&&&&&###BBG^                       \n";
        cout << "\033[0;32;31m                                   .75PGPPPGBGGB##&&&@@@@@@&?JG#&&@&&@&@@@&##&&##B#&@&@&#&#B##BB5.                      \n";
        cout << "\033[0;32;31m                                  :?5GGPPGBBGG###&&&&@@@@&&@@&&&&@&#&#&#&@&&####GGB@@@@&###B##BGG~                      \n";
        cout << "\033[0;32;31m                                 ^YPGBPPGBBGB####&&&@@@@@&#&&&&&&&#&#&&#@@&####BBB&@@@@&##&B#&BGBJ                      \n";
        cout << "\033[0;32;31m                                ~5GGGGGB#BBB######&&@@@@@@&&&#&&@&#&#&#&&@&&##&BBB&@@@&&&#&####BBP:                     \n";
        cout << "\033[0;32;31m                               7PPPGGBB##B#######&&&&&&&&@&&&&&&&&&@####&&&&###GGG#@@&&&&&&&###BBB!                     \n";
        cout << "\033[0;32;31m                             .?5PPGBBBB####&####&&&&&&&&&&&&&#B&&&&@&#&#&#&&&####&@@&#&&&&&&&##BBGY                     \n";
        cout << "\033[0;32;31m                            :?Y5PGBGGB########&#&&##&&&&&&&&#GB#&&@@@@&#&#&&&@&@@@@@&&&&&&&####GGGP:                    \n";
        cout << "\033[0;32;31m                           :?J5PPGGGGBBB#####&######&#&&&&&&GB##&&@@@@@&&&&#&&&@@@@&&&&&&&&####BGGG7                    \n";
        cout << "\033[0;32;31m                          ^?J5PPPPGBBGB####B#####B####&#&&&&#&&&&&&BBG#@@@&#&&@@@@@&&#&&&&&#####GGGY                    \n";
        cout << "\033[0;32;31m                         ^JJ5PPPPGGBGB###B!:GB##B#######&&&#&&&&@@@#B5G@@@@&&&@@@G&@&&&&&&&&#B##BGGP:                   \n";
        cout << "\033[0;32;31m                        ^JJ5PPPPGGGGB###G~  5BBGB##B##B#&&#PB#&&@@@@@@&&@@@&&&@@&@@@@&B#&&&&#B###GGG7                   \n";
        cout << "\033[0;32;31m                       ~JJYPP55GGGGB###5:  .PBGB##B##B####GPB#&@@@&&&&&@@@@@&&@G7P#@&&BG#&&&&BB##BGGY                   \n";
        cout << "\033[0;32;31m                      ~JJY5P55PGGGB##BJ.   .PGB##BB#BB###BPG##&@@@&&&@@@#5YY5#@P!?P&GYPGG#&&&#B###GGP^                  \n";
        cout << "\033[0;32;31m                     ~JJY5P55PGGPB#BG7      :?GBGB#BGB###BG##&@&@@@@@@@B7!7?YB&P!77G&B55G###&#BB##BGG7                  \n";
        cout << "\033[0;32;31m                    !JJY5P55PPPPB#B5^         .7YGBBG###BBB#&&B^5@@@&G77JJJ5P##Y~?J7JBGY5BGGGBBBB#BGGY.                 \n";
        cout << "\033[0;32;31m                   !JJY5P555PPGBGY~              .^!77YGGG###&7 ^&&B7 .!5Y5PPBB!:JJ~~7?YB##BBGGPPPGGGP~                 \n";
        cout << "\033[0;32;31m                  !JJ555555PPP5!.                  .~J5GB##&&5 ^JBBJ^!77?JJYJJ?~^???JJ:~PGB####BBGGPPP57^.              \n";
        cout << "\033[0;32;31m                .!JJ555YY5PPJ^                   ^?5PPG###BP7.^55YYJJY55P5YJJ5??JJY5J5J::^!7JGBB####G5PPP55^            \n";
        cout << "\033[0;32;31m               .7JJ555YY55J^                    :5PGPPPBPY?7??JJJY5PP55PPYYJP5^:?55PGP5YJJYYYYJJJJYYGPPBBGG5~.          \n";
        cout << "\033[0;32;31m              .7JJ555YY5J^                     .?PP#&##PGPYJJJJJJJY5PPPPPP5Y5?77JGGPP555PP5YYJJJJJYPGBGBBBB#GY.         \n";
        cout << "\033[0;32;31m             .7JJ555YYY!.                     :5#BB#GGBB###G555555P5PPPPGGGPYY555GGGGGGPP5555555PB#GPPGGBBB#BB~         \n";
        cout << "\033[0;32;31m            .7JJ555YY!.                       !B&&##GGGBBBB##P55PPPGGGGGGGBPPGBGGBBBGGPP555YYY5GGGPGGBBB&&&&#B^         \n";
        cout << "\033[0;32;31m           .7JJY55Y!:                         ^G&&&&&#####BB##BBGGGGBBBBBGPPBBBBGBBGGPPPPPP55PPPPPPGB&&@&##G7:          \n";
        cout << "\033[0;32;31m          .7JJY5Y!.                            !5PB##&&&&##BGPPGGGGGGPPPPPPGBGGGPGBGGGGPPPPPPPPGGGB&@&##BY^.            \n";
        cout << "\033[0;32;31m         .7JJYJ!.                                 ^P##&&&##BBGPPPPPGGGGPPPGGPPGPPPGGBB###BBB####&&@&#J^JG5              \n";
        cout << "\033[0;32;31m        .?JJ?~.                                    .^Y&&&&&&&#BGGGGBBBBP5YJ!^~7J5G####&#&&&&&@@&#BP!:   7G~             \n";
        cout << "\033[0;32;31m       .?J?~.                                         !5#&&&&&@&&##&&&&#BY!7JJ5G#&&&&&&&@@@&&B57^.       ~J.            \n";
        cout << "\033[0;32;31m      .??!.                                            .^JPG##&&&&&&&&&&###&@@@@@@@&##G5Y?7~~:            ^:            \n";
        cout << "\033[0;32;31m     .7!:                                                 .::~7YG#####&&&&&&&&&&&##P?^                                  \n";
        cout << "\033[0;32;31m    .!:                                                         .:~5##&&&&&&&&&&&##BGY^                                 \n";
        cout << "\033[0;32;31m    :                                                           .!P##&&&&&#BGB#@@@&&#BGJ^.                              \n";
        cout << "\033[0;32;31m                                                            .~?5G#&&&#G5?!~. .^?5B&&####BP?~^.                          \n";
        cout << "\033[0;32;31m                                                            ?#&&&&#P?^           .!YGBB####BBG5~                        \n";
        cout << "\033[0;32;31m                                                            .^~!!!:                 .:^~!?YPP5J:                        \033[m\n";
    }
    else if (player->getCurrentRoom()->getIndex() == 14)
    {
        cout << "\n\n\033[1;31mYou've fallen into a trap, and you eccounter a monster. \nDefeat it or you'll die....\033[0m\n\n";
    }
    if(getName() != "\033[0;32;31mThe Baphomet\033[m" ) cout << fight;
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
            if (i == 2 && player->checkEnoughMagic(player->getSkill(i).getMP()))
            {
                cout << option << ". Use Ultimate Skill: " << player->getSkill(i).getSkillName() << endl;
                decision[option] = i + 1;
                decision[option + 32] = i + 1;
                option++;
            }
            else if (player->checkEnoughMagic(player->getSkill(i).getMP()))
            {
                cout << option << ". Use Skill " << i + 1 << ": " << player->getSkill(i).getSkillName() << endl;
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
            if (decision[input] == 3)
                cout << "\033[2J";
            player->getSkill(decision[input] - 1).getScript();
            if (player->getSkill(decision[input] - 1).getType().first == "Demage")
            {
                this->takeDamage(player->getSkill(decision[input] - 1).getType().second + player_dam);
                this->showStatus();
            }
            else if (player->getSkill(decision[input] - 1).getType().first == "Heal")
            {
                player->healing(player->getSkill(decision[input] - 1).getType().second);
            }
            else if (player->getSkill(decision[input] - 1).getType().first == "ATKup")
            {
                player->setAttack(player->getAttack() + player->getSkill(decision[input] - 1).getType().second);
            }
            else if (player->getSkill(decision[input] - 1).getType().first == "DEFup")
            {
                player->setDefense(player->getDefense() + player->getSkill(decision[input] - 1).getType().second);
            }
            else if (player->getSkill(decision[input] - 1).getType().first == "MPup")
            {
                player->setCurrentMagic(player->getCurrentMagic() + player->getSkill(decision[input] - 1).getType().second);
            }
            player->useMaigc(player->getSkill(decision[input] - 1).getMP());
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