#ifndef CANVAS_H
#define CANVAS_H

#include "Branch.h"

class Canvas {
    int width, height;
    std::vector<std::vector<char>> pixels;
public:
    Canvas(int, int);
    void draw_pixel(int, int, char);
    void draw_branch(int, int, Branch);
    void print();
};

#endif