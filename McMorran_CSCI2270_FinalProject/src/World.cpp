#include "World.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

World::World()
{
    //ctor
    masterwin = 0;
    ifstream infile;
    infile.open("world.txt");
    if(!infile.good()){
        // FILE NOT FOUND
        return;
    }
    infile >> numlevels;
    levels = new Stage*[numlevels];

    string levelfile;
    for(int i=1; i<=numlevels; i++){
        infile >> levelfile;
        loadStage(levelfile, i);
    }
    currentLevel = levels[0];

}

World::~World()
{
    //dtor
    delete []levels;

}

/* PUBLIC FUNCTIONS */

void World::analyzeKeystroke(char input)
{
    string w = "w";
    string a = "a";
    string s = "s";
    string d = "d";
    string e = "e";
    string q = "q";
    bool good = 0;
    switch(input){
            case 'w':
                good = checkSpace(player->getx(), player->gety()-1);
                if(good){
                    player->moveUp();
                }
                else{
                    reportCollision(currentLevel->field[player->gety()-1][player->getx()]);
                }
                break;
            case 'a':
                good = checkSpace(player->getx()-1, player->gety());
                if(good){
                    player->moveLeft();
                }
                else{
                    reportCollision(currentLevel->field[player->gety()][player->getx()-1]);
                }
                break;
            case 's':
                good = checkSpace(player->getx(), player->gety()+1);
                if(good){
                    player->moveDown();
                }
                else{
                    reportCollision(currentLevel->field[player->gety()+1][player->getx()]);
                }
                break;
            case 'd':
                good = checkSpace(player->getx()+1, player->gety());
                if(good){
                    player->moveRight();
                }
                else{
                    reportCollision(currentLevel->field[player->gety()][player->getx()+1]);
                }
                break;
            case 'e':
                player->changeActive(1);
                break;
            case 'q':
                player->changeActive(-1);
                break;
            case 'f':
                cout << "space" << endl;
                player->useItem();
            default:
                cout << "invalid" << endl;
                break;
        }
        checkContact(player->getx(), player->gety());
        checkAdjancent(player->getx(), player->gety());
}

void World::printWorld()
{
    cout << "***PRINTING WORLD***" << endl;
    cout << "WORLD STATS" << endl;
    cout << "current level id: " << currentLevel->id << endl;
    cout << "number of levels: " << numlevels << endl;
    cout << endl;
    for(int i=0; i<numlevels; i++){
        cout << "LEVEL #" << levels[i]->id << endl;
        cout << "start x coordinate: " << levels[i]->startx << endl;
        cout << "start y coordinate: " << levels[i]->starty << endl;
        cout << "end x coordinate: " << levels[i]->endx << endl;
        cout << "end y coordinate: " << levels[i]->endy << endl;
        cout << "number of stage elements: " << levels[i]->numElements << endl;
        cout << "size of element storage: " << levels[i]->sizeElements << endl;
        cout << "elements: ";
        for(int j=0; j<levels[i]->sizeElements; j++){
            if(j<levels[i]->numElements){
                cout << levels[i]->elements[j].type << ", ";
            }
            else{
                cout << "empty, ";
            }
        }
        cout << endl;
        cout << endl;
    }

    cout << "***END WORLD STATS***" << endl;
}

void World::printStage()
{
    for(int i=0; i<100; i++){
        cout << endl;
    }
    for(int i=0; i<17; i++){
        if(player->gety() == i){
            for(int j=0; j<currentLevel->field[i].size(); j++){
                if(player->getx() == j){
                    cout << "&";
                }
                else{
                    cout << currentLevel->field[i][j];
                }
                if(j == currentLevel->field[i].size()-1){
                    cout << endl;
                }
            }
        }
        else{
            cout << currentLevel->field[i] << endl;
        }
    }
}

void World::printHUD()
{
    cout << "Player: " << player->getName() << "     Health: " << player->getHealth() << "     Level: " << currentLevel->id << endl;
    player->printInventory();
}

void World::initWorld()
{
    cout << "Please enter a character name:" << endl;
    string name;
    getline(cin, name);
    int initx = currentLevel->startx;
    int inity = currentLevel->starty;
    player = new Character(name, initx, inity);
    for(int i=0; i<100; i++){
        cout << endl;
    }
}

int World::checkConditions()
{
    if(player->getHealth() == 0){   // CONDITION: DEATH
        return -1;
    }
    if(player->getx() == currentLevel->endx && player->gety() == currentLevel->endy){
        if(currentLevel->id == numlevels){
            cout << "THE END!" << endl;
            cout << "YOU'VE MADE IT TO THE END! CONGRATULATIONS!" << endl;
            return 1;
        }
        else{
            changeLevel();
            return 0;
        }
    }

}

/* PRIVATE FUNCTIONS */

void World::loadStage(std::string filename, int n)
{
    ifstream infile;
    infile.open(filename);
    if(!infile.good()){
        // FILE NOT FOUND
        return;
    }
    int x1; int y1; int x2; int y2;
    infile >> x1 >> y1 >> x2 >> y2;
    Stage *newStage = new Stage(n, x1, y1, x2, y2);
    int gather;
    string sgather;
    infile >> gather;
    while(gather != -99){
        if(gather == -1){       // KEY
            Element newElement;
            infile >> gather;   // X coordinate
            newElement.x = gather;
            infile >> gather;   // Y coordinate
            newElement.y = gather;
            infile >> gather;   // Key
            newElement.key = gather;
            newElement.type = "Key";
            addElement(newElement, newStage);
        }
        else if(gather == -2){  // GENERIC ITEM
            Element newElement;
            infile >> gather;   // X coordinate
            newElement.x = gather;
            infile >> gather;   // Y coordinate
            newElement.y = gather;
            infile >> sgather;  // Type
            newElement.type = sgather;
            newElement.key = 0;
            addElement(newElement, newStage);
        }
        else if(gather == -3){  // DOOR
            Element newElement;
            infile >> gather;   // X coordinate
            newElement.x = gather;
            infile >> gather;   // Y coordinate
            newElement.y = gather;
            infile >> gather;  // Key
            newElement.key = gather;
            newElement.type = "Door";
            addElement(newElement, newStage);
        }
        infile >> gather;
    }
    for(int i=0; i<17; i++){
        infile >> newStage->field[i];
    }
    levels[n-1] = newStage;
}

void World::addElement(Element e, Stage *s)
{
    if(s->numElements == s->sizeElements){
        Element *newElements = new Element[s->sizeElements * 2];
        for(int i=0; i<s->sizeElements; i++){
            newElements[i] = s->elements[i];
        }
        s->sizeElements *= 2;
        delete s->elements;
        s->elements = newElements;
    }

    s->elements[s->numElements].type = e.type;
    s->elements[s->numElements].x = e.x;
    s->elements[s->numElements].y = e.y;
    s->elements[s->numElements].key = e.key;
    s->numElements++;

}

void World::removeElement(std::string t, int k, Stage *s)
{
    for(int i=0; i<s->numElements; i++){
        if(s->elements[i].type == t){
            if(s->elements[i].key == k){
                for(int j=i; j<s->numElements-1; j++){
                    s->elements[j] = s->elements[j+1];
                }
                s->numElements--;
                return;
            }
        }
    }
}

bool World::checkSpace(int x, int y)
{
    if(currentLevel->field[y][x] == '#'){
        return 0;
    }
    if(currentLevel->field[y][x] == '8'){
        return 0;
    }
    if(currentLevel->field[y][x] == '|' || currentLevel->field[y][x] == '_'){
        return 0;
    }
    else{
        return 1;
    }
}

void World::checkContact(int x, int y)
{
    if(currentLevel->field[y][x] == '%'){
        reportCollision('%');
    }
    if(currentLevel->field[y][x] == 'i'){
        reportCollision('i');
    }
    if(currentLevel->field[y][x] == 'm'){
        reportCollision('m');
        currentLevel->field[y][x] = '.';
    }
    if(currentLevel->field[y][x] == 'M'){
        reportCollision('M');
        currentLevel->field[y][x] = '.';
    }
}

void World::checkAdjancent(int x, int y)
{
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            if(currentLevel->field[y+1-j][x+1-i] == '|' || currentLevel->field[y+1-j][x+1-i] == '_'){
                if(player->activeItem){
                if(player->activeItem->type == "Key"){
                    for(int r=0; r<currentLevel->numElements; r++){
                        if(currentLevel->elements[r].x == x+1-i){
                            if(currentLevel->elements[r].y == y+1-j){
                                if(currentLevel->elements[r].key == player->activeItem->key){
                                    player->removeItem("Key", currentLevel->elements[r].key);
                                    currentLevel->field[y+1-j][x+1-i] = '.';
                                    currentLevel->elements[r].x = -1;
                                    currentLevel->elements[r].y = -1;
                                    break;
                                }
                            }
                        }
                    }
                }
                }
            }
        }
    }
}

void World::reportCollision(char symbol)
{
    if(symbol == '#'){
        player->decHealth(10);
    }
    if(symbol == '8'){
        player->decHealth(100);
    }
    if(symbol == 'm'){
        if(player->activeItem){
            if(player->activeItem->type == "Sword"){
                player->decHealth(30);
                return;
            }
        }
        player->decHealth(60);
    }
    if(symbol == 'M'){
        if(player->activeItem){
            if(player->activeItem->type == "Sword"){
                player->decHealth(50);
                return;
            }
        }
        player->decHealth(100);
    }
    if(symbol == '%'){
        int x = player->getx();
        int y = player->gety();
        for(int i=0; i<currentLevel->sizeElements; i++){
            if(currentLevel->elements[i].x == x){
                if(currentLevel->elements[i].y == y){
                    player->addItem(x, y, currentLevel->elements[i].type, currentLevel->elements[i].key);
                    currentLevel->field[y][x] = '.';
                    currentLevel->elements[i].x = -1;
                    currentLevel->elements[i].y = -1;
                    break;
                }
            }
        }
    }
    if(symbol == 'i'){
        int x = player->getx();
        int y = player->gety();
        for(int i=0; i<currentLevel->sizeElements; i++){
            if(currentLevel->elements[i].x == x){
                if(currentLevel->elements[i].y == y){
                    player->addItem(x, y, currentLevel->elements[i].type, currentLevel->elements[i].key);
                    currentLevel->field[y][x] = '.';
                    currentLevel->elements[i].x = -1;
                    currentLevel->elements[i].y = -1;
                    break;
                }
            }
        }
    }
    if(symbol == '|' || symbol == '_'){

    }
}

void World::changeLevel()
{
    for(int i=0; i<100; i++){
        cout << endl;
    }
    cout << "*******CONGRATULATIONS!*******" << endl;
    cout << " Level " << currentLevel->id << " complete." << endl;
    cout << endl;
        cout << "Press any key to continue..." << endl;
        string i;
        cin >> i;
        currentLevel = levels[currentLevel->id];
}
