#include <iostream>
#include "Canvas.h"
#include "Tree.h"
#include <math.h>
#include <vector>
#include <cmath>

int normalize_width(float slope, int width){
    float a = 2 / (1+std::exp(-std::abs(slope))) - 1;
    return int(std::round(width - ( width * 0.66 ) * a));
}

int normalize_height(float slope, int height){
    float a = 2 / (1+std::exp(-std::abs(slope))) - 1;
    return int(std::round(height + ( height ) * a));
}

char get_pixel(float slope) {
    if (std::abs( slope > 1)) return '.';
    else return ':';
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
    if (x < 0 || x >= Canvas::width) return;
    if (y < 0 || y >= Canvas::height) return;
    Canvas::pixels[y][x] = pixel;
}

void Canvas::draw_branch (int x, int y, float curr_angle, Branch branch){

    int deltaY_multiplier = 1;

    float angle = (branch.get_angle()+curr_angle);
    angle = std::fmod(angle, M_PI*2);

    if (angle > M_PI / 2 && angle < M_PI * 3 / 2){
        deltaY_multiplier = -1;
    }
    float slope = std::tan(angle);
    std::cout << angle << "->" << slope << std::endl;
    int width = normalize_width(slope, branch.get_width());
    int height = normalize_height(slope, branch.get_height());
    char pixel = get_pixel(slope);

    float currX = x;
    float currY = y;
    float deltaY = std::sqrt(1/(1+std::pow(slope, 2))) * deltaY_multiplier;
    float deltaX = slope * deltaY;

    for(int i = 0; i < height; i++){
        int leftX = int(std::round(currX-deltaY*width));
        int leftY = int(std::round(currY-deltaX*width));
        int rightX = int(std::round(currX+deltaY*width));
        int rightY = int(std::round(currY+deltaX*width));

        draw_pixel(leftX, leftY, pixel);
        draw_pixel(rightX, rightY, pixel);

        std::vector<Branch> branches_at_curr_height = branch.get_children_at_height(i);

        for(int k = 0; k < branches_at_curr_height.size(); k++){
            Branch child_branch = branches_at_curr_height[k];
            int childX, childY;
            if (i == height - 1){
                childX = currX;
                childY = currY;
            } else if (child_branch.get_angle() < 0){
                childX = leftX;
                childY = leftY;
            } else {
                childX = rightX;
                childY = rightY;
            }
            draw_branch(childX, childY, slope, child_branch);
        }
        currX += deltaX;
        currY -= deltaY;
    }
}

void Canvas::draw_tree(Tree tree){
    this->draw_branch(
        Canvas::width / 2, 
        Canvas::height - 1, 
        0,
        tree.get_root_branch()
    );
}

void Canvas::print () {
    for(int y = 0; y < Canvas::height; y++){
        for(int x = 0; x < Canvas::width; x++){
            std::cout << Canvas::pixels[y][x];
        }
        std::cout << std::endl;
    }
}
