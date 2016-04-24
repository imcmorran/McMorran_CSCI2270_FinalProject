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
    cout << numlevels << endl;

    levels = new Stage*[numlevels];

    string levelfile;
    for(int i=1; i<=numlevels; i++){
        infile >> levelfile;
        cout << "Loading stage #" << i << " " << levelfile << endl;
        loadStage(levelfile, i);
    }

}

World::~World()
{
    //dtor

}

/* PUBLIC FUNCTIONS */

void World::analyzeKeystroke(std::string input)
{

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
    cout << gather << endl;
    while(gather != -99){
        if(gather == -1){       // KEY
            infile >> gather;   // X coordinate
            infile >> gather;   // Y coordinate
            infile >> gather;   // Key
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
        cout << gather << endl;
    }
    for(int i=0; i<17; i++){
        infile >> newStage->field[i];
        cout << newStage->field[i] << endl;
    }
}
