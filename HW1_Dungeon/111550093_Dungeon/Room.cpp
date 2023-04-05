#include "Room.h"

Room::Room() {}
Room::Room(bool exit, int index, vector<Object *> objects)
{
    setUpRoom(NULL);
    setDownRoom(NULL);
    setLeftRoom(NULL);
    setRightRoom(NULL);
    setIsExit(exit);
    setIndex(index);
    setObjects(objects);
}
bool Room::popObject(Object *object)
{
    for(int i =0; i < objects.size(); i++)
    {
        if ( objects[i] == object)
        {
            objects.erase( objects.begin()+i);
            return true;
        }
    }
    return false;
}
/* Set & Get function*/
void Room::setUpRoom(Room *u)
{
    this->upRoom = u;
}
void Room::setDownRoom(Room *d)
{
    this->downRoom = d;
}
void Room::setLeftRoom(Room *l)
{
    this->leftRoom = l;
}
void Room::setRightRoom(Room *r)
{
    this->rightRoom = r;
}
void Room::setIsExit(bool exit)
{
    this->isExit = exit;
}
void Room::setIndex(int index)
{
    this->index = index;
}
void Room::setObjects(vector<Object *> objects)
{
    this->objects = objects;
}
bool Room::getIsExit()
{
    return isExit;
}
int Room::getIndex()
{
    return index;
}
vector<Object *> Room::getObjects()
{
    return objects;
}
Room *Room::getUpRoom()
{
    return upRoom;
}
Room *Room::getDownRoom()
{
    return downRoom;
}
Room *Room::getLeftRoom()
{
    return leftRoom;
}
Room *Room::getRightRoom()
{
    return rightRoom;
}