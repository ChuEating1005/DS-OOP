#include <vector>
#include <iostream>
using namespace std;

class Object
{
public:
    virtual void response() = 0;

    virtual ~Object() = default;
};

class IceMonster : public Object
{
public:
    // add constructor or functions if you need
    void response()
    {
        cout << "fire attack\n";
    }
    IceMonster() = default;
    ~IceMonster() = default;
};

class FireMonster : public Object
{
public:
    // add constructor or functions if you need
    void response()
    {
        cout << "ice attack\n";
    }
    FireMonster() = default;
    ~FireMonster() = default;
};

class Treasure : public Object
{
public:
    // add constructor or functions if you need
    void response()
    {
        cout << "ya\n";
    }
    Treasure() = default;
    ~Treasure() = default;
};

class Room
{
public:
    // add anything if you need

    Room *up_room;
    Room *down_room;
    Room *left_room;
    Room *right_room;
    int index;
    Object *o;
    // add constructor or functions if you need
    Room()
    {
    }
    Room(int Index, char c)
    {
        index = Index;
        switch (c)
        {
        case 'i':
            o = new IceMonster;
            break;
        case 't':
            o = new Treasure;
            break;
        case 'f':
            o = new FireMonster;
            break;
        default:
            o = NULL;
            break;
        }
    }
    void emptyRoom()
    {
        o = NULL;
    }
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n;
    cin >> m >> n;
    Room *roomList = new Room[m];
    char c;
    int u, d, l, r;
    for (int i = 0; i < m; i++)
    {
        cin >> c >> u >> d >> l >> r;
        roomList[i] = Room(i, c);

        if (u != -1)
            roomList[i].up_room = &roomList[u];
        else
            roomList[i].up_room = NULL;

        if (d != -1)
            roomList[i].down_room = &roomList[d];
        else
            roomList[i].down_room = NULL;

        if (l != -1)
            roomList[i].left_room = &roomList[l];
        else
            roomList[i].left_room = NULL;

        if (r != -1)
            roomList[i].right_room = &roomList[r];
        else
            roomList[i].right_room = NULL;
    }
    cout << "0" << endl;
    Room *now = &roomList[0];
    if (now->o != NULL)
        now->o->response();
    char cc;
    for (int i = 0; i < n; i++)
    {
        cin >> cc;
        switch (cc)
        {
        case 'u':
            if (now->up_room == NULL)
            {
                cout << "-1\n";
            }
            else
            {
                now = now->up_room;
                cout << (now->index) << " ";
                if (now->o != NULL)
                {
                    now->o->response();
                    now->emptyRoom();
                }
                else
                    cout << endl;
            }
            break;
        case 'd':
            if (now->down_room == NULL)
            {
                cout << "-1\n";
            }
            else
            {
                now = now->down_room;
                cout << (now->index) << " ";
                if (now->o != NULL)
                {
                    now->o->response();
                    now->emptyRoom();
                }
                else
                    cout << endl;
            }
            break;
        case 'l':
            if (now->left_room == NULL)
            {
                cout << "-1" << endl;
            }
            else
            {
                now = now->left_room;
                cout << now->index << " ";
                if (now->o != NULL)
                {
                    now->o->response();
                    now->emptyRoom();
                }
                else
                    cout << endl;
            }
            break;
        case 'r':
            if (now->right_room == NULL)
            {
                cout << "-1\n";
            }
            else
            {
                now = now->right_room;
                cout << (now->index) << " ";
                if (now->o != NULL)
                {
                    now->o->response();
                    now->emptyRoom();
                }
                else
                    cout << endl;
            }
            break;
        default:
            cout << cc << "error\n";
            break;
        }
    }
    return 0;
}