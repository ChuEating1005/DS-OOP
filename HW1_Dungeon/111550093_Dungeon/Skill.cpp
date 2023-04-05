#include "Skill.h"
Skill::Skill(){};
Skill::Skill(string skillName, string type, int val, int MP, string script)
{
    setSkillName(skillName);
    setType(type, val);
    setMP(MP);
    setScript(script);
}
void Skill::setSkillName(string name)
{
    this->skillName = name;
}
void Skill::setScript(string script)
{
    this->script = script;
}
void Skill::setMP(int MP)
{
    this->MP = MP;
}
void Skill::setType(string type, int val)
{
    this->type = make_pair(type, val);
}
string Skill::getSkillName()
{
    return skillName;
}
void Skill::getScript()
{
    cout << script;
    if (getSkillName() == "Excalibur")
    {
        cout << "\n\n\n\n\n\n\n\n";
        cout << "\t\t\033[1;33m                     ..                                                                            \n";
        cout << "\t\t                    :77~^.                                 .......                                  \n";
        cout << "\t\t                   .~^:^~~^:::::.       :.  .          ....:^^^^^^^^.                       .:^~:   \n";
        cout << "\t\t                        ......:^::    .^^:..:~~.    ..:..:. ...:::^~~~^.                  :~7~:.    \n";
        cout << "\t\t                      .!!~::^^^::.::....::::.:7^ .::^:. .^^:       .:^^~^.       ...   ..:^:.       \n";
        cout << "\t\t                     ^YYYY?7~^^:^^::::. .:777!~^::.::::^~~^^^^^^^^^^^^~~~~^...:^~!!~::^^:.        ^~\n";
        cout << "\t\t                    ~J?7?JY?~7!^!!!~~~::..^~^:.^:.....:::::::^^~^^^^^^^~^::^^^~!7!~^^~~!???!^.  .JJ.\n";
        cout << "\t\t                   :GBGPPP7^?YP?!?Y57~^::::.::.:~.           :^~~^:   .:^^~~^~^^::...:.:~!^::. :JJ. \n";
        cout << "\t\t                   :?PP5Y5!.?PP7:^?J!~~^~^      :~:            :^~~~!!!777!!!~^~~.       ^~..~7?~   \n";
        cout << "\t\t                     :JGPP5YYPYJ7!!^~7!:^7?~..   .^^:..         .:!JYYJ?7!~:.  .^~~^::....~??7^.    \n";
        cout << "\t\t                     .~YB##GGPP555Y57?5^::~~~~~~!.  .:^~~~~!!77?JJ??7~^:.         .:^^~~~~~:.       \n";
        cout << "\t\t                       ~J!~PGPPGGPPPP55^. :^::~?!      ..::^^^^:...                                 \n";
        cout << "\t\t                        .:^JYP#BB##BGBY                                                             \n";
        cout << "\t\t                       .~!7?!Y###&####B~                                                            \n";
        cout << "\t\t                       ^7J?!JPPPBB###BP:                                                            \n";
        cout << "\t\t                       ~?J5YPGPJ77YPP?.                                                             \n";
        cout << "\t\t                       !!77Y5Y~?5GP?:                                                               \n";
        cout << "\t\t                      !55PPG5J^JG?:                                                                 \n";
        cout << "\t\t                    .JBGGB#GJ!~~~!77~:                                                              \n";
        cout << "\t\t                   :?BBPPBPJ^. .:::^~!7~:.                                                          \n";
        cout << "\t\t                  ^7PP555PP?!:       .^!?J?!:                                                       \n";
        cout << "\t\t                :??5P55PPPB57~:.   :^~77?JY55!^~~~~~~~^^:.                                          \n";
        cout << "\t\t           :^!?JJ#GY5PPPPPGPPP?!!!!^:::...::^~7J5PGGPP5555J?~:.                                     \n";
        cout << "\t\t        ^!?JY5J7Y5Y55PPPP5GYG&#GP7:.        .~J55YYYJJJJJYPGBBG5?~.                                 \n";
        cout << "\t\t      ~?JJ?JJ!7Y?JJPP5PP5YP?5YB&P?7!^:..  .!55?~^^^^^^^~YB########GY7^                              \n";
        cout << "\t\t    .7J7!!?Y??J^!JJ5G5P5JY57PG?5#B5?JJ7~^7GB7:.:::..::!5GBBB##GPPGGPGG57.                           \n";
        cout << "\t\t    .^^77!~^:^^^?J?YPGYPJJY7!77!?5GGB&#GP#B7^:.....::YBGGPP555555Y555PPG7                           \n";
        cout << "\t\t       ..   .:.:JYJY5GPP5?J7:..:^!?YPGB##BPJ?7!!!777P&##BGPPG##&#BGPGGGG7                           \n";
        cout << "\t\t     .!!^...:..!Y?YJYYP5?JY!:....:^!7JY5PGGGGP5PBBGB&#GG5J5G####BBPYJPPG!                           \n";
        cout << "\t\t   ^JGBY!^^:...?5?J5PPP5PGP!::..   .:^!7JY555PPGBBBB#BP?~~~~~~^!^^!~^:!J^ .                         \n";
        cout << "\t\t.~5B#GJ!77!!:^~J5PBBBBBBGGG7^^^^::~!^^^^^~!7JJYYYYY55?~^~^^~!:~7777!~^^:. ..                        \n";
        cout << "\t\t:!?7~: ^!?J!:^?PB##BP55PGGG?7!7Y55P55YY?!!~!~777!!77~^~!!::?J???77!!!~^^....                        \n";
        cout << "\t\t       .!JJ~!5B#BPJ?J7J5GBY^!~.:~^!YJ?JYJ???7J?!!!?!!!7J5Y?^~JJ?7!!!~~^^...                         \n";
        cout << "\t\t        :^~75PJ7~~!5#JJPGG5~~^     .. :~. .: ^!!JP5!!~.7?5BBJ^^7??7!!~^^:.                          \n";
        cout << "\t\t    ...::^:7GPYJYPGGPPPGBPJ^^!:                 :YY5PJ755!~7PG?..^!!!!!~^.                          \n";
        cout << "\t\t   ......  .J#GBB5PGBGGGGB#5^                      ^7J5BBGY^.~YP^   ..:^:.                          \n";
        cout << "\t\t             :::.  :!JPB##B##P?!!^.                    ^YGBG?. !P^                                  \n";
        cout << "\t\t                       :!YG##BBBGGGY^                    ^JGB5! :Y^                                 \n";
        cout << "\t\t                          .!GBPJ77P&Y                      :JGGJ:.?~                                \n";
        cout << "\t\t                            :PG5J5BB:                        :JGP! !7.                              \n";
        cout << "\t\t                             .YGY75B^                          ^YGJ.:7~.                            \n";
        cout << "\t\t                              !GY^:Y:                            !P5^ ^7~^.                         \n";
        cout << "\t\t                              :?J:.~                              :YG?..7???!.                      \n";
        cout << "\t\t                              .7Y::                                .YB5~^ ?G5:                      \n";
        cout << "\t\t                               ..                                   :557^~!?7                       \n";
        cout << "\t\t                                                                     .!P?: .~                       \n";
        cout << "\t\t                                                                       JGY~ :                       \n";
        cout << "\t\t                                                                       :J5J:.                       \n";
        cout << "\t\t                                                                        J57.                        \n";
        cout << "\t\t                                                                        ..                          \033[m\n";
        cout << "\n\n\n\n\n\n\n\n";
    }
    else if (getSkillName() == "Enuma Elish")
    {
        cout << "\n\n\n\n\n\n\n\n";
        cout << "\t\t\033[1;33m                                                       .                              .:.                                \n";
        cout << "\t\t                                                  ....                       .      ^~.                                 \n";
        cout << "\t\t                                                 .:..        ... .... .  ....     .7~                                   \n";
        cout << "\t\t                                                :^..     ...::^^:^~^~~!.^...     ~?:                                    \n";
        cout << "\t\t                                               .~:..    .^~^::...::::~~7!..    :J?.                                     \n";
        cout << "\t\t                                               .!..  .^^~~^::::::::^:::7J7.   75~                .                      \n";
        cout << "\t\t                                               .!:..  ~^:...:^^^::^^~~^?5!  ^55.             .:!J!.                     \n";
        cout << "\t\t                                                :!..  :77!~~~^::^:..:^!J7..?B?            .^JG#B!                       \n";
        cout << "\t\t                                                 :~:.  !?!7!^..!J!~:.^!Y:^5P^ .         .!?#@B?.                        \n";
        cout << "\t\t                                                  .:^:.:!?7~........~Y!!PBY.          :?B#JY!.                          \n";
        cout << "\t\t                                            .:::....::^!~7~?!...::.:7!:YY~!J: ...   :^5&G?~                             \n";
        cout << "\t\t                          .^^..:.         :~?JJJJ??7!~^~!!777~~:..^!^!P?    .:~!. ^5#Y7~.                               \n";
        cout << "\t\t                        ^^7P7~Y5!.       .?J55YYYYYYYJJ?77?JJ?!~~?G5YP~^~~~~7~.?5^5Y~.                                  \n";
        cout << "\t\t                        !YGY5BPY7!~      .YYYYJJJJJJJJJJJJJJ5PJ~:^JB&#GG###&#GY5PJY^                                    \n";
        cout << "\t\t                         !P?YG!Y5JJ~:     75JJ?77?????JJJYYY5PPJ^::^7P?^P&&P?J5JYJ?~                                    \n";
        cout << "\t\t                          !YGYYBJ~JY^     :?J!^^^~!7???JJJY55PP55^^^^~!~~5BY!777JYPY.                                   \n";
        cout << "\t\t                           ^YGGGGP#7      :J?~~!7???7?JJJJY55P55BY~!777?77PY777?JY5B!                                   \n";
        cout << "\t\t                            :?BGGBB5J^  :7J?~^^^~7??JYYYYYY55P5P#G!!7?JYGB#GJ??JY5PG^           ..                      \n";
        cout << "\t\t                             .YBBBPGBP7^!P####GPYJ??JJYPP5BGBBB###5?JJJJJ5&BPYYPPGG!          ...                       \n";
        cout << "\t\t                              :YGGGGGBP5JPBG?YB&&&&&G5PPP#&&&#GGBB57?????5##PBGGGGY..     .....                         \n";
        cout << "\t\t                               ^5B#BBPGGPGG&P7?G@&G5^^G#B##BG5PGGGGYJYYY5BGG5#&###?                                     \n";
        cout << "\t\t           .                    ~GBBBGPGB#B&&PPP57.   !BBPPPPPGGGGGP55PGBPJG5#@&#GP^                                    \n";
        cout << "\t\t           .:::.                 ~PBB#BB##&&&BG5:      !BBGPPPGGGGGGGB#BY!~G5#G5~^^:    .~??.                           \n";
        cout << "\t\t              .^~~^.              .7B&&#&&&#BGY^        ~PG5555PPPGBBGY7~~~7#GJ5P57. .!JY?~.                            \n";
        cout << "\t\t                 :~77~:             :?P##BPY?!.          JBPYYY5P55P5!::^~~~JY?YPB#PJ5?~.  ..                           \n";
        cout << "\t\t                    :!JJ!:            :7PPJ~.           ^PGY7~^~!!7?5BY7~^~?5G?JPBB#Y      ...                          \n";
        cout << "\t\t         .::.     ..   :7YY?: .!.       .:             ^557^::^^~~7?YG&BP?7?5#YJPBBB!        ..                         \n";
        cout << "\t\t         .!?JJ?7!~^.      :7?J5!               .      ^5Y~::::^^~!7JY5##G5!~PBJJYB#P.         ..                        \n";
        cout << "\t\t            .:^!JJJJJ?7~:.  !7^!?7^.          .J7    ^Y?^:^!???7~~!?Y5G#G5~!#G5JJY7.           .                        \n";
        cout << "\t\t              .~.  .:~!?JYYYY7~::!??!~         :G7..^?!^~YB#BB##5!7?YPP#P^~5BY55?              .                        \n";
        cout << "\t\t              :~ .  .     .^~7J5GBG55P^.     .^!5&P5?7?5B#BGGG##G~!7J5PGB!?#PY5JYJ~           ..                        \n";
        cout << "\t\t              ^~ .  .          .~~!7?YJP~~7^YGBGP5B5PB##BGGGB##G!^~!7J5Y55G5P5P?75#Y.        ..                         \n";
        cout << "\t\t              .!:.   .        .: .:^7!!GGP5~!J:  :G###BGGGGGGB#GGBBG5GGPPG?7?5P?!75&B~     ...                          \n";
        cout << "\t\t               :~:.         :^J?^YPP57:^.    7Y~!G#B#BGGGGBJ^!JP5##YYG###?^?Y5GYPBB55?~:.....                           \n";
        cout << "\t\t                .::.  .^!?~^555?^:::        :J###BYGBGGGGGY^~~!?J?J7JPB#P^!55PPJPJB? ~GY.   :7^                         \n";
        cout << "\t\t                .:!?J:?YJ7^...!.:. ..    :7PJJYP57PBGGGGGP~^~!!YP~~7JG##Y^^~7YPJBYYJ  .~J7  ^GB:                        \n";
        cout << "\t\t          .:~7?JYJ?!^..      .^~..  . .~!P#P7:~?!GBGGGGGP777~!?5G!~75#GBP~^~J5PJGPJY^   :Y5!P#B7.                       \n";
        cout << "\t\t          ~?7!^.               ^^.  :?G#J7^  :77GBGBGGGP!^~7JY5GG!~J#B5BG7^^7YPJPPJ5BPYJYP#?5!^~.                       \n";
        cout << "\t\t                                 ^7Y7P5!:   .!7GBGBGGGP!^~~!?J5GG!7BG5PBBJ^^?BGYGGYYG#####5^7J^.                        \n";
        cout << "\t\t                               ^?G#G7^.    .!7GBBGGGGG7:^~!7JYPGG7GB5PGBB5~^~YPYGGYJJ5###B:  7B!^                       \n";
        cout << "\t\t                            :75#BY~.       ~7GBGGGGGG?^^~!7?YPGGGG#BBBBBGG7^~JP5GGGGP!75B#7   ~7P!                      \n";
        cout << "\t\t                         .~JB#P?:         ~?GBGGGGGBY^^~!7?YPGPGBBBBBBBGGBY^~?55GBBBBG5^:!?~    ^?~                     \n";
        cout << "\t\t                       :75BGJ~        .  ^?PGPPPGGG5~^~!7?YPGPGBBGGGGGPPGBG!^75PGBBPPGBG:         .                     \n";
        cout << "\t\t                    .~JGB5!.            :?GGPGP5GBG!^~!7?Y5GPPGGGGGPPPPPGGG5Y5PGGGGPPPPG?                               \n";
        cout << "\t\t                  :7PBGJ^             :~JGGGP5YJGBY~~!7JYPGGPBGPPPBPPPPPGGGGGGGGGGGGPPPP5!^.                            \n";
        cout << "\t\t                 :PGY!.           :~J5PGPPP?::!?YYJ77??JYYYYY55Y!^YP55PGGPP5PPPPPPPP5YYYY5Y?~.                          \n";
        cout << "\t\t                 .::             .:^^^^::::. .~YGBPJ?JJY5PGBGGB?^..::::::::::::::::::.........                          \n";
        cout << "\t\t                                              .7Y5YJJJJJJJYYYJ?:                                                        \n";
        cout << "\t\t                                               .:::::::::::::..                                                         \033[m\n";
        cout << "\n\n\n\n\n\n\n\n";
    }
    else if (getSkillName() == "Gae Bulg")
    {
        cout << "\n\n\n\n\n\n\n\n";
        cout << "\t\t\033[0;32;34m                                 YP55:                                                               \n";
        cout << "\t\t                               .^P5P!                                                                \n";
        cout << "\t\t                             .~!!JYP5?!~^:.                                                          \n";
        cout << "\t\t                            ^!!!?YB######5JY7~^:.                                                    \n";
        cout << "\t\t                            ~!!!7JG#&##&PP##55PP5YJ?!~^:.               ...:.                        \n";
        cout << "\t\t                           .!!!!!7?5G#&P5&#YP####BBBGGPP5Y?!^:.            .^!7~.                    \n";
        cout << "\t\t                            ~?JYYJ7?J55?5GPY&&&&&&&&######BBBPY?7^.           .!Y?:                  \n";
        cout << "\t\t                             ~PPPGJ?7:    .^!?PB&&&#####&&&###B5YPPY:           .YG7                 \n";
        cout << "\t\t                             ~G5P?..           .~JG######BBBBGPJBBPG5      ...:^. 5BJ                \n";
        cout << "\t\t                             5G5P:               ~Y5YJJ?77?JPBYG##&PY          :?:~BG!               \n";
        cout << "\t\t                            :B#BJ              ~5GBGP55YY??5YYYB&#&&P.          :Y!BGY               \n";
        cout << "\t\t                            ?BBB^             ?GBGBBB#######&########G~ .       :PPGG?               \n";
        cout << "\t\t                           .PBBJ             ?BGGBB##################&#J?       5BGG5:               \n";
        cout << "\t\t                           7BBB^            ~GGGG######################&P     :5BGGJ:                \n";
        cout << "\t\t                           P#G5             YGGGG######BB#########B#BG##B!  .?BBGY~                  \n";
        cout << "\t\t                          ~BBB!            :PGBGGB#BBBBBGGGGGGB##GGGGBBBB.:JB#GJ^                    \n";
        cout << "\t\t                          Y#BP             ~GBGGGB##BBGGBBBGGGPBBGGBBGGBGY##P7:                      \n";
        cout << "\t\t                         ^BBB7             ~GBGGGG##B#GY??YGGGBBBGGJ7YPBBGJ^                         \n";
        cout << "\t\t                         J#BG:             :PGPBGGPB#BG?~:J!^!7J7~Y!^J55?:                           \n";
        cout << "\t\t                        :GBBY               JGPGGP7J5YY??PP~:~^:^~PPPJ7?!.                           \n";
        cout << "\t\t                        5BBG^               .?5P5P5JJ??^^GBGY!~^~5575!!?Y.                           \n";
        cout << "\t\t                       .GB#5                  :?YGB5GY!!^^~!7!~^!!~::^J^J5~                          \n";
        cout << "\t\t                       ?#BB7                   ?##G5BBJ!!^::^!!~^:::~J?~?G#7                         \n";
        cout << "\t\t                      :GBBP                   J&&B55P#GY?!^^^~!!~:^?Y?!7!!PB!                        \n";
        cout << "\t\t                      7#BB7                  ~&###&BJG#GYY?~^^~^~7YJ7!77:^!5#!                       \n";
        cout << "\t\t                      5#BG.                  5&####&GJ#BYBBG5JYYJYJ??JY7!!!7PB:                      \n";
        cout << "\t\t                     ^BGGJ                   G&###&&BJYY5P55GGBB555YYJJYJ777!?7^                     \n";
        cout << "\t\t                     Y#BB~                   5&####&#PP555P5JJ5PPJ??JYYYJJ?77!!77^                   \n";
        cout << "\t\t                    :GBBG.                   ~&####&&###BBBBBP5J?J??JJJJJY5?77!^~77:                 \n";
        cout << "\t\t                    J#GB~                     ?&##&#########B5YYYJ7!7?JJYYJJ?7!~:~?J^                \n";
        cout << "\t\t                   .G#BP                       ?#&&##########P55J7!!77???JJJ??7~. .!?^               \n";
        cout << "\t\t                   7#BB?                        G&&#######&&#55YJJ?!~^~7??JJJYYYJ!^7?7.              \n";
        cout << "\t\t                  .PBBG.                        ?#&####&&##&#G555J!~^^~7J5PGGGGBBBGGGY^              \n";
        cout << "\t\t                  7BBB?                         .P&&&&&##&#G5B5YYJ?77?YPGGGGGGGGGGGGP?.              \n";
        cout << "\t\t                  PBBB:                         .Y#&&##&#G5P#&GYYJY5PGGGGGGGGGGGGGG5!                \n";
        cout << "\t\t                 ~BBBP                           5#&&&#P5P#####P5PPPPPPPGGGGGGGGGP7.                 \n";
        cout << "\t\t                 Y#GG!                          ~&#BGPY5BBBBBBB#G5PPPPPPPPPPPPPY?!                   \n";
        cout << "\t\t                ^B#BP.                         ~YPPP?JBBBBBBBBB##B555PPGGGGG5?!!~.                   \n";
        cout << "\t\t                J#BB7                      .:!JB##&PY#BBBB######&&B5GPYYY5Y?!~~^                     \n";
        cout << "\t\t               :G#BP:                  :!YPB###GPP575PPPGB########BJ5GP5YY55Y!.                      \n";
        cout << "\t\t               ?#BBJ                :?P#######5JGGGGGGGPJB&&&##&&BJGGBBBBBGP7.                       \n";
        cout << "\t\t              .P#BB~              ^Y#&##BB#B#PJBBBBBB##GP######GPJJP555555G?                         \n";
        cout << "\t\t              ?BBGP             .J#&##BBBBGPP5BB###BGGBGGGG5???!!PBGGGBBBBG:                         \n";
        cout << "\t\t             :G#BB~           .7B###BBBP55PGBBB###GGBPPB##BPYJ7!7BBBBBBBBBY:                         \n";
        cout << "\t\t             !##GG:        .^P#&##BGP55PGBBBBBB##P#&&&B5JY555Y7G#B####BBP57                          \n";
        cout << "\t\t             YBBB!      :!?5PGPGP55PGBBBB###P5B#&BP&&##BYGGBBB?5&###BP5Y5#^                          \n";
        cout << "\t\t            ~BBBP     ~7YGGBBGGPGBBBBB####&PJB&#&GP&&##BBBBB##J7YYYYY5GB#B^                          \n";
        cout << "\t\t            J#BGJ:~??P##BGPY5BBBBB#######&G?5##&#YB#&&#BBB####J?GBBBBBB#B5^                          \n";
        cout << "\t\t           :BP!~~~^~JP#BBBBB5J##G########BJ5G55GJP&##G########JJ#BBBBBGPPJ                           \n";
        cout << "\t\t           7J^:^^^^^?YBBBB###JY!!#######&5J###BJ?##&55&#######75##BG5Y5G#~                           \n";
        cout << "\t\t         :!~~7J~^^^!?G###G5J~:  J&#####&B7P#####YY&#B&###BB##G!5PYJYPB##5                            \n";
        cout << "\t\t        .7!?G#5^~^~?Y#P?^.      5&###&&#J7####BB#YG&&###&#GPY7!J5PBBB###^                            \n";
        cout << "\t\t        ^7YBBP~^!7~!7~         .B&&##G5Y?75B#BBB#BY&###G5YY55!5BBBBB###J                             \n";
        cout << "\t\t         7B#G!:!7!^.           ~##G55GB##B5?YGBB#&B#&#5YPB&B?5BBBBB###Y                              \n";
        cout << "\t\t         YBG7^!7~.            .JY5P#&&####BB5J5B##&&BYG&&&B?YBBBBBB##5                               \n";
        cout << "\t\t        ^BB7!?7^               !B#&######BBBBBYYPG&GYB&##B?JBBBBBB##P.                               \n";
        cout << "\t\t       .5#5!7~                .G&#&######BBBBB#BG&GJB&#BB?JBBBBBB##P.                                \n";
        cout << "\t\t       !B#BP~                  J&#&######BBBB##&&BJG&##B?YBBBBBB##P.                                 \n";
        cout << "\t\t       YBBP5.                  !&#&######BB######YP#G5J7YBBBBB###P.                                  \n";
        cout << "\t\t      7B#BBY                   ^G#&&#####B#&##BPYJ555?~5BBBBB###P.                                   \n";
        cout << "\t\t      Y##GB^                    !YB&&####B&&#GPPGB##57PBBBBB###5.                                    \n";
        cout << "\t\t     .PBGGJ                      .7YG#####BP5G#&&##Y7PBBBBB###Y                                      \n";
        cout << "\t\t     ?BBGG^                        :J555555B#&##B#Y7GBBBB###B7                                       \n";
        cout << "\t\t    :GGPP5                          .JPPPPB&###B#J7GBBBB###P^                                        \n";
        cout << "\t\t    ?GP5P!                            .::7&##BB#J?BBBBB##B?                                          \n";
        cout << "\t\t   .5G5P5.                              ^B&##BBJJBBBB###P^                                           \n";
        cout << "\t\t   ~GP5P!                              7##BP55?7BBBB##B?                                             \n";
        cout << "\t\t   ?G5P5.                             ~YP5PGBBB?Y#B##P:                                              \n";
        cout << "\t\t  .PG5G!                             .5B###BBB#B7B##B:                                               \n";
        cout << "\t\t  !GPPP.                             P&&#BBBBB#&5Y#G~                                                \n";
        cout << "\t\t  YG5P?                            ^?&#&#BBBBB###P?:                                                 \n";
        cout << "\t\t ~GP5P:                           :JP&&&BBBB#####Y                                                   \n";
        cout << "\t\t 5G5PY                           .55Y#&#B##&&#BG7                                                    \n";
        cout << "\t\t GGPG7                          :G&B?P&##&#BPY5!                                                     \n";
        cout << "\t\t P5PG7                         :G&#&P75BPYJJ5B5                                                      \n";
        cout << "\t\t 555PY                        .G&###&Y!J5PB##B:                                                      \n";
        cout << "\t\t GGGY^                        J&###&P7P#BB##B~                                                       \n";
        cout << "\t\t BPP7.                       .B####G7PBBB###!                                                        \n";
        cout << "\t\t BPP7                        7&###B75BBB##G~                                                         \n";
        cout << "\t\t PP?^                        G&##B?YBBB##Y.                                                          \n";
        cout << "\t\t PP5~                       !&##B?JBB##B7                                                            \n";
        cout << "\t\t PPJ                       .B&#B?JBB##P^                                                             \n";
        cout << "\t\t P5:                       Y&##J?B###5.                                                              \033[m\n";
        cout << "\n\n\n\n\n\n\n\n";
    }
}
int Skill::getMP()
{
    return MP;
}
pair<string, int> Skill::getType()
{
    return type;
}
