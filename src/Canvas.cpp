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

    std::vector<Branch> branch_children = branch.get_children();
    std::cout << branch_children.size() << std::endl;
    std::vector<std::vector<Branch>> branchesAtHeight;
    for (int i = 0; i < branch.get_height(); i++){
        std::vector<Branch> branches;
        for(int k = 0; k < branch_children.size(); k++){
            Branch child_branch = branch_children[k];
            int height_ind = int(std::round( branch.get_height() * child_branch.get_placement() )) - 1;
            std::cout << "height ind "<< height_ind << std::endl;
            if (height_ind == i){
                branches.push_back(child_branch);
            }
        }
        branchesAtHeight.push_back(branches);
    }

    float currX = x;
    float currY = y;
    float deltaX, deltaY;
    float slope = branch.get_slope()+curr_slope;
    deltaY = std::sqrt(1/(1+std::pow(slope, 2)));
    deltaX = slope * deltaY;

    float width = 3;
    width = width - ( width / 1.5 ) * sigmoid(std::abs(slope));

    for(int i = 0; i < branch.get_height(); i++){
        float leftX = int(std::round(currY-deltaX*width));
        float leftY = int(std::round(currX-deltaY*width));
        float rightX = int(std::round(currY+deltaX*width));
        float rightY = int(std::round(currX+deltaY*width));

        Canvas::pixels[leftX][leftY] = 'x';
        Canvas::pixels[rightX][rightY] = 'x';

        for(int k = 0; k < branchesAtHeight[i].size(); k++){
            draw_branch(int(currX), int(currY), slope, branchesAtHeight[i][k]);
        }
        currX += deltaX;
        currY -= deltaY;
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
