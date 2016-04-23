#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(std::string name, int x, int y)
{
    //ctor
    setName(name);
    setx(x);
    sety(y);

    health = 100;

    activeItem = NULL;
    isize = 10;
    inventory = new Item*[isize];
    for(int i=0; i<isize; i++){
        inventory[i] = NULL;
    }


}

Character::~Character()
{
    //dtor
}

std::string Character::getName()
{
    return name;
}

void Character::setx(int n)
{
    x = n;
}

void Character::sety(int n)
{
    y = n;
}

void Character::moveUp()
{
    y--;
}

void Character::moveDown()
{
    y++;
}

void Character::moveLeft()
{
    x--;
}

void Character::moveRight()
{
    x++;
}

void Character::teleport(int x, int y)
{
    setx(x);
    sety(y);
}

int Character::getx()
{
    return x;
}

int Character::gety()
{
    return y;
}

void Character::incHealth(int n)
{
    health += n;
    if(health > 100) health = 100;
}

void Character::decHealth(int n)
{
    health -= n;
    if(health < 0) health = 0;
}

int Character::getHealth()
{
    return health;
}

void Character::setName(std::string n)
{
    name = n;
}

void Character::addItem(Item j)
{
    Item *newItem = new Item(j.type, j.x, j.y, j.key);

    for(int i=0; i<isize; i++){
        if(!inventory[i]){
            inventory[i] = newItem;
            if(!activeItem){
                activeItem = newItem;
            }
            return;
        }
    }
}

void Character::removeItem(std::string type, int key)
{
    for(int i=0; i<isize; i++){
        if(inventory[i]){
        if(inventory[i]->type == type){
            if(inventory[i]->key == key){
                Item *tmp = inventory[i];
                if(activeItem == tmp){
                    activeItem = NULL;
                    for(int j=0; j<isize-1; j++){
                        if(inventory[(i+j+1) % isize]){
                            activeItem = inventory[(i+j+1) % isize];
                            break;
                        }
                    }
                }
                delete tmp;
                inventory[i] = NULL;
                return;
            }
        }
        }
    }
}

void Character::printInventory()
{
    bool c = 0;
    cout << "Inventory: |";
    for(int i=0; i<isize; i++){
        if(inventory[i]){
            cout << " ";
            if(inventory[i] == activeItem){
                cout << "[";
            }
            cout << inventory[i]->type;
            if(inventory[i] == activeItem){
                cout << "]";
            }
            cout << " |";
            c = 1;
        }
    }
    if(!c){
        cout << " empty |";
    }
    cout << endl;
}

void Character::changeActive(int n)
{
    if(n>1 || n<-1) return;

    for(int i=0; i<isize; i++){
        if(inventory[i] == activeItem){
            i += n;
            if(i >= isize) i = 0;
            if(i < 0) i = isize-1;
            while(!inventory[i]){
                i += n;
                if(i >= isize) i = 0;
                if(i < 0) i = isize-1;
            }
            break;
        }
    }
}
