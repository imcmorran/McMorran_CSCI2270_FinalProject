#include "Character.h"
#include <string>

Character::Character()
{
    //ctor
    x = -1;
    y = -1;
    _name = "Player";
    _health = 100;
    _itemsStored = 0;
    for(int i=0; i<10; i++){
        _inventory[i] = NULL;
    }
}

Character::~Character()
{
    //dtor
    for(int i=0; i<10; i++){
        if(_inventory[i]){
            delete _inventory[i];
        }
    }
}

int Character::moveUp()              // Will update the character's location (Returns Y coordinate for vertical movement, X coordinate for horizontal movement, -1 for error)
{
    if(x<0 || y<0) return -1;

    return --y;
}

int Character::moveDown()            // ''
{
    if(x<0 || y>0) return -1;

    return ++y;
}

int Character::moveLeft()            // ''
{
    if(x<0 || y<0) return -1;

    return --x;
}

int Character::moveRight()           // ''
{
    if(x<0 || y<0) return -1;

    return ++x;
}

int Character::addItem(Item i)         // Adds an item to the inventory array
{
    Item * newItem = new Item;
    newItem->damage = i.damage;
    newItem->key    = i.key;
    newItem->type   = i.type;

    for(int i=0; i<10; i++){
        if(!_inventory[i]){
            _inventory[i] = newItem;
            return 0;
        }
    }
    return 101;                           // ERROR CODE 101: Inventory Full
}

int Character::removeItem(Item i)      // Removes an item to the inventory array
{
    for(int i=0; i<10; i++){
        if(_inventory[i]){
        if(_inventory[i]->type == i.type){
            if(_inventory[i]->key == i.key){
                delete _inventory[i];
                _inventory[i] = NULL;
                return 0;
            }
        }
        }
    }
    return 102;                         // ERROR CODE 102: iTEM NOT FOUND
}

void Character::changeActiveLeft()    // Moves the pointer to the left
{

}

void Character::changeActiveRight()   // Moves the pointer to the right
{

}

void Character::updateHealth(int)     // updates health positively
{

}

void Character::updateDamage(int)     // updates health negatively
{

}
