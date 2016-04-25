#include "World.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

World::World()
{
    //ctor
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
    switch(input){
            case 'w':
                player->moveUp();
                break;
            case 'a':
                player->moveLeft();
                break;
            case 's':
                player->moveDown();
                break;
            case 'd':
                player->moveRight();
                break;
            case 'e':
                break;
            case 'q':
                break;
            default:
                cout << "invalid" << endl;
                break;
        }
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
                    cout << "@";
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
            infile >> gather;   // X coordinate
            infile >> gather;   // Y coordinate
            infile >> sgather;  // Type
        }
        else if(gather == -3){  // DOOR
            infile >> gather;   // X coordinate
            infile >> gather;   // Y coordinate
            infile >> gather;  // Key
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
