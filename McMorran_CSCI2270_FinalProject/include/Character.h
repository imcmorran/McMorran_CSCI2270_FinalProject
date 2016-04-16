#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

struct Item
{
    public:
        std::string type;

};

struct Inventory
{
    public:
        Item *items;
        int size;
        int stored;

};

class Character
{
    public:
        Character();
        ~Character();
    protected:

    private:
        std::string _name;
        int _health;
        Inventory _inventory;
};

#endif // CHARACTER_H
