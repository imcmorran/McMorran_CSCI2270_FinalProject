#include <iostream>

using namespace std;

/*  ************ASCII ROGUELIKE************
    -PLEASE VIEW THE README FIRST!-

    AUTHOR: Ian McMorran
    FILE CREATED: 15 Apr, 2016 @ 20:20 Mountain

    *************************************** */

// USER DEFINED INCLUDE SECTION
#include "Character.h"

// GLOBAL VARIABLES


// DEFINES


int main()
{
    cout << "***BEGIN UNIT TEST OF CHARACTER CLASS***" << endl << endl;

    Character player("Bob", 5, 5);
    cout << "STARTING CONDITIONS:" << endl;
    cout << "Location   |   expects 5, 5    | gets: " << player.getx() << ", " << player.gety() << endl;
    cout << "Name       |   expects Bob     | gets: " << player.getName() << endl;
    cout << "MODIFYING CONDITIONS:" << endl;
    player.moveUp();
    cout << "Moving UP  |   expects 5, 4    | gets: " << player.getx() << ", " << player.gety() << endl;
    player.moveLeft();
    cout << "Moving LEFT|   expects 4, 4    | gets: " << player.getx() << ", " << player.gety() << endl;
    player.moveDown();
    cout << "Moving DOWN|   expects 4, 5    | gets: " << player.getx() << ", " << player.gety() << endl;
    player.moveRight();
    cout << "Moving RIGH|   expects 5, 5    | gets: " << player.getx() << ", " << player.gety() << endl;
    player.teleport(10, 10);
    cout << "TELEPORTING|   expects 10, 10  | gets: " << player.getx() << ", " << player.getx() << endl;
    player.decHealth(50);
    cout << "Decreasing Health  |   expects 50  | gets: " << player.getHealth() << endl;
    player.incHealth(25);
    cout << "Increasing Health  |   expects 75  | gets: " << player.getHealth() << endl;
    player.incHealth(30);
    cout << "Maxing Health      |   expects 100 | gets: " << player.getHealth() << endl;
    player.decHealth(100);
    cout << "Minning Health     |   expects 0   | gets: " << player.getHealth() << endl;
    cout << "TESTING INVENTORY:" << endl;
    cout << "Printing: ";
    player.printInventory(); cout << endl;
    cout << "Adding: (Key)" << endl;
    Item newitem("Key", 5, 5, 100);
    Item item2("Sword", 6, 6);
    Item item3("Pizza", 7, 7);
    player.addItem(newitem);
    player.addItem(item2);
    player.addItem(item3);
    player.printInventory();

    cout << endl << "***END UNIT TEST OF CHARACTER CLASS***" << endl << endl;

    return 0;
}
