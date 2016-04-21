#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>


class Character
{
    public:
        struct Item
        {
            std::string type;
            int key;
            int damage;
        };

        Character();
        ~Character();
        int moveUp();              // Will update the character's location
        int moveDown();            // ''
        int moveLeft();            // ''
        int moveRight();           // ''
        int addItem(Item);         // Adds an item to the inventory array
        int removeItem(Item);      // Removes an item to the inventory array
        void changeActiveLeft();    // Moves the pointer to the left
        void changeActiveRight();   // Moves the pointer to the right
        void updateHealth(int);     // updates health positively
        void updateDamage(int);     // updates health negatively

    protected:

    private:
        // Player Specs
        std::string _name;
        int _health;
        int x;
        int y;

        // Inventory
        Item * _inventory[10];
        int _itemsStored;

};

#endif // CHARACTER_H
