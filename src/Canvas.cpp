#include <iostream>
#include "Canvas.h"
#include <math.h>
#include <vector>

int normalize_width(float slope, int width){
    float a = 2 / (1+std::exp(-std::abs(slope))) - 1;
    return int(std::round(width - ( width * 0.66 ) * a));
}

int normalize_height(float slope, int height){
    float a = 2 / (1+std::exp(-std::abs(slope))) - 1;
    return int(std::round(height + ( height * 1.33 ) * a));
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
    float slope = branch.get_slope()+curr_slope;
    int width = normalize_width(slope, branch.get_width());
    int height = normalize_height(slope, branch.get_height());

    std::vector<Branch> branch_children = branch.get_children();
    std::vector<std::vector<Branch>> branchesAtHeight;
    for (int i = 0; i < height; i++){
        std::vector<Branch> branches;
        for(int k = 0; k < branch_children.size(); k++){
            Branch child_branch = branch_children[k];
            int height_ind = int(std::round( height * child_branch.get_placement() )) - 1;
            if (height_ind == i){
                branches.push_back(child_branch);
            }
        }
        branchesAtHeight.push_back(branches);
    }

    float currX = x;
    float currY = y;
    float deltaX, deltaY;
    deltaY = std::sqrt(1/(1+std::pow(slope, 2)));
    deltaX = slope * deltaY;

    char pixel;
    if (std::abs( slope > 1)) pixel = '.';
    else pixel = ':';

    for(int i = 0; i < height; i++){
        int leftX = int(std::round(currX-deltaY*width));
        int leftY = int(std::round(currY-deltaX*width));
        int rightX = int(std::round(currX+deltaY*width));
        int rightY = int(std::round(currY+deltaX*width));

        Canvas::pixels[leftY][leftX] = pixel;
        Canvas::pixels[rightY][rightX] = pixel;

        for(int k = 0; k < branchesAtHeight[i].size(); k++){
            Branch child_branch = branchesAtHeight[i][k];
            int childX, childY;
            if (i == height - 1){
                childX = int(currX);
                childY = int(currY);
            } else if (child_branch.get_slope() < 0){
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
        if (currX <= 0 || currX >= Canvas::width) break;
        if (currY <= 0 || currY >= Canvas::height) break;
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
