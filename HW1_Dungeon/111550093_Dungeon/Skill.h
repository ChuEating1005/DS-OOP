#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class Skill
{
private:
    string skillName;
    pair<string, int> type;
    int MP;
    string script;

public:
    Skill();
    Skill(string, string, int, int, string);
    void setSkillName(string);
    void setScript(string);
    void setMP(int);
    void setType(string, int);
    string getSkillName();
    void getScript();
    int getMP();
    pair<string, int> getType();
};

#endif