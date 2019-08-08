#include <iostream>
#include "Canvas.h"
#include <math.h>
#include <vector>

float sigmoid(float x){
    return 1 / (1+std::exp(-x));
}

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

void Canvas::draw_branch (int x, int y, float curr_slope, Branch branch){
    float currX = x;
    float currY = y;
    float deltaX, deltaY;
    float slope = branch.get_slope()+curr_slope;
    deltaY = std::sqrt(1/(1+std::pow(slope, 2)));
    deltaX = slope * deltaY;

    float width = 3;
    width = width - ( width / 1.5 ) * sigmoid(std::abs(slope));

    for(int i = 0; i < branch.get_height(); i++){
        currX += deltaX;
        currY -= deltaY;
        Canvas::pixels[int(std::round(currY-deltaX*width))][int(std::round(currX-deltaY*width))] = 'x';
        Canvas::pixels[int(std::round(currY+deltaX*width))][int(std::round(currX+deltaY*width))] = 'x';
    }

    std::vector<Branch> branch_children = branch.get_children();
    for(int i = 0; i < branch_children.size(); i++){
        draw_branch(int(currX), int(currY), slope, branch_children[i]);
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
