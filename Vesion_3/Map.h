#ifndef MAP_H
#define MAP_H
#include "ObjectList.h"
#include <string>

class Map {
    private:
        int width;
        int height;
        ObjectList** rows;
        ObjectList** columns;
        // Part 2
        ObjectList* lights;
    public:
        Map(int w, int h);
        void add(Object* obj);
        std::string print();
        ~Map();
        // Part 2
        void addLight(Object* light);
        Object* getAt(int x, int y);
        void resetEnvironment();
        void updateEnvironment();
};
#endif