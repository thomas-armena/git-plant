#include "Branch.h"
#include <vector>

Branch::Branch(int height, int width, float slope, float placement){
    Branch::height = height;
    Branch::width = width;
    Branch::slope = slope;
    Branch::placement = placement;
}

void Branch::add_child(Branch child_branch){
    Branch::children.push_back(child_branch);
}

int Branch::get_height(){ return Branch::height; }
int Branch::get_width(){ return Branch::width; }
float Branch::get_slope(){ return Branch::slope; }
float Branch::get_placement(){ return Branch::placement; }
std::vector<Branch> Branch::get_children(){ return Branch::children; }
