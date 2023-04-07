#include "Object.h"

Object::Object() // defalut constructor
{
}

Object::Object(string name, string tag) // constructor
{
    this->name = name;
    this->tag = tag;
}

void Object::setName(string name)
{
    this->name = name;
}

void Object::setTag(string tag)
{
    this->tag = tag;
}

string Object::getName()
{
    if (name == "Empty")
        return "X";
    else
        return name;
}

string Object::getTag()
{
    return tag;
}