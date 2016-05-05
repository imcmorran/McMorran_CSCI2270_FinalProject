#include <iostream>
#include <cstdlib>

using namespace std;

/*  ************ASCII ROGUELIKE************
    -PLEASE VIEW THE README FIRST!-

    AUTHOR: Ian McMorran
    FILE CREATED: 15 Apr, 2016 @ 20:20 Mountain

    *************************************** */

// USER DEFINED INCLUDE SECTION
#include "Character.h"
#include "World.h"

// GLOBAL VARIABLES and Function definitions
void CharacterUnitTest();
int playGame();
void printMenu();
void clearScreen();

// DEFINES


int main()
{
    char in;
    while(1){
        printMenu();
        cin >> in;
        if(in == '1'){
            cin.get();
            playGame();
            cin.get();
        }
        else if(in == '2'){
            cout << "Please view the README for game instructions and more" << endl;
        }
        else if(in == '3'){
            cout << "Goodbye!" << endl;
            break;
        }
        else{
            cout << "DID NOT RECOGNIZE COMMAND... TRY AGAIN" << endl << endl;
        }
    }


    return 0;
}

void printMenu()
{
    cout << "------------------------------------" << endl;
    cout << "-             WELCOME!             -" << endl;
    cout << "- Select an option below:          -" << endl;
    cout << "-  1. Play Game!                   -" << endl;
    cout << "-  2. Rules                        -" << endl;
    cout << "-  3. Quit                         -" << endl;
    cout << "------------------------------------" << endl;
}

int playGame()
{
    cin.clear();
    World game;
    game.initWorld();
    int res;
    char input;
    while(1){
        game.printStage();
        game.printHUD();
        cin >> input;
        game.analyzeKeystroke(input);
        res = game.checkConditions();
        if(res == -1){
            clearScreen();
            cout << "YOU DIED... TRY AGAIN!" << endl << endl;
            cout << "press any character to continue...";
            cin.get(input);
            return res;
        }
        if(res == 1){
            return res;
        }
    }
}

void clearScreen()
{
    for(int i=0; i<100; i++){
        cout << endl;
    }
}

void CharacterUnitTest()
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
    /*player.addItem(newitem);
    cout << "Adding: (Sword)" << endl;
    player.addItem(item2);
    cout << "Adding: (Pizza)" << endl;
    player.addItem(item3);
    cout << "Printing: ";
    player.printInventory();
    cout << "Removing: (Key, 100)" << endl;
    player.removeItem("Key", 100);
    cout << "Printing: ";
    player.printInventory();
    cout << "Removing: (Sword)" << endl;
    player.removeItem("Sword");
    cout << "Removing: (Pizza, 0)" << endl;
    player.removeItem("Pizza", 0);
    cout << "Printing: ";
    player.printInventory();
    cout << "Filling Inventory: (Taco, Chicken, Pie, Caserole, Pasta, Beans, Burger, Pizza, Oatmeal, Toast)" << endl;
    Item item10("Taco", 0, 0);
    Item item11("Chicken", 0, 0);
    Item item12("Pie", 0, 0);
    Item item13("Caserole", 0, 0);
    Item item14("Pasta", 0, 0);
    Item item15("Beans", 0, 0);
    Item item16("Burger", 0, 0);
    Item item17("Pizza", 0, 0);
    Item item18("Oatmeal", 0, 0);
    Item item19("Toast", 0, 0);
    player.addItem(item10);
    player.addItem(item11);
    player.addItem(item12);
    player.addItem(item13);
    player.addItem(item14);
    player.addItem(item15);
    player.addItem(item16);
    player.addItem(item17);
    player.addItem(item18);
    player.addItem(item19);*/
    cout << "Printing: ";
    player.printInventory();
    cout << "Moving active:" << endl;
    for(int i=0; i<11; i++){
        player.changeActive(1);
        player.printInventory();
    }
    cout << "Moving back active:" << endl;
    for(int i=0; i<5; i++){
        player.changeActive(-1);
        player.printInventory();
    }
    cout << "Final Inventory test:" << endl;
    player.removeItem("Oatmeal");
    player.removeItem("Burger");
    player.removeItem("Beans");
    player.removeItem("Chicken");
    player.removeItem("Pasta");
    player.printInventory();
    player.removeItem("Pizza");
    player.printInventory();
    //player.addItem(item18);
    player.printInventory();

    cout << endl << "***END UNIT TEST OF CHARACTER CLASS***" << endl << endl;
    return;
}
