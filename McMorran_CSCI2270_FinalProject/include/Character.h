#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

struct Item
{
    Item(std::string t, int i, int j, int k)
    {
        type = t;
        x = i;
        y = j;
        key = k;
    }
    Item(std::string t, int i, int j)
    {
        type = t;
        x = i;
        y = j;
        key = 0;
    }

    std::string type;
    int x;
    int y;
    int key;
};


class Character
{
    public:
        Character(std::string name, int x, int y);
        ~Character();
        std::string getName();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void teleport(int x, int y);
        int getx();
        int gety();
        void incHealth(int);
        void decHealth(int);
        int getHealth();
        void addItem(int, int, std::string, int);
        void removeItem(std::string type, int key = 0);
        void printInventory();
        void changeActive(int); // 1 to move right, -1 to move left, all other numbers result in no change
        void useItem();
        Item *activeItem;
    protected:
    private:
        std::string name;
        int x;
        int y;
        int health;

        Item **inventory;
        int isize;


        void setName(std::string);
        void setx(int n);
        void sety(int n);

};

#endif // CHARACTER_H
