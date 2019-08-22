#ifndef CANVAS_H
#define CANVAS_H

#include "Branch.h"
#include "Tree.h"

class Canvas {
    int width, height;
    std::vector<std::vector<char>> pixels;
public:
    Canvas(int, int);
    void draw_pixel(int, int, char);
    void draw_branch(int x, int y, float angle, Branch branch);
    void draw_tree(Tree tree);
    void clear();
    void print();
};

#endif
