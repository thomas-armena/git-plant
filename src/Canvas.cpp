#include <iostream>
#include "Canvas.h"
#include <math.h>

Canvas::Canvas(int width, int height) {
    Canvas::width = width;
    Canvas::height = height;
    for(int y = 0; y < Canvas::height; y++) {
        std::vector<char> newRow;
        for(int x = 0; x < width; x++) {
            newRow.push_back(' ');
        }
        Canvas::pixels.push_back(newRow);
    }
}

void Canvas::draw_pixel (int x, int y, char pixel) {
    Canvas::pixels[y][x] = pixel;
}

void Canvas::draw_branch (int x, int y, Branch branch){
    float currX = x;
    float currY = y;
    float deltaX, deltaY;
    deltaY = std::sqrt(1/(1+std::pow(branch.get_slope(), 2)));
    deltaX = branch.get_slope() * deltaY;
    for(int i = 0; i < branch.get_height(); i++){
        currX += deltaX;
        currY -= deltaY;
        Canvas::pixels[int(currY)][int(currX)] = 'x';
    }
}

void Canvas::print () {
    for(int y = 0; y < Canvas::height; y++){
        for(int x = 0; x < Canvas::width; x++){
            std::cout << Canvas::pixels[y][x];
        }
        std::cout << std::endl;
    }
}