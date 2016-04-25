#ifndef WORLD_H
#define WORLD_H
#include <string>
#include "Character.h"

struct Element
{
    Element()
    {
        type = "unknown";
        x = 0;
        y = 0;
        key = 0;
    }
    std::string type;
    int x;
    int y;
    int key;
};

struct Stage
{
    Stage(int _id, int _startx, int _starty, int _endx, int _endy)
    {
        startx = _startx;
        starty = _starty;
        endx = _endx;
        endy = _endy;
        id = _id;
        numElements = 0;
        sizeElements = 10;
        elements = new Element[sizeElements];
    }
    ~Stage()
    {
        delete elements;
    }
    int id;
    std::string field[17];
    int startx;
    int starty;
    int endx;
    int endy;
    Element *elements;
    int sizeElements;
    int numElements;

};

class World
{
    public:
        World();
        ~World();
        void analyzeKeystroke(char input);
        void printWorld();
        void printStage();
        void initWorld();

    private:
        void loadStage(std::string filename, int n);
        void addElement(Element e, Stage *s);
        void removeElement(std::string t, int k, Stage *s);
        Stage **levels;
        Stage *currentLevel;
        int numlevels;

        Character *player;

};

#endif // WORLD_H
