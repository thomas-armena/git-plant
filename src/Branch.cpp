#include "Branch.h"
#include <vector>

Branch::Branch(int height, int z_index, float slope){
    Branch::height = height;
    Branch::z_index = z_index;
    Branch::slope = slope;
}

void Branch::add_child(Branch child_branch){
    Branch::children.push_back(child_branch);
}

int Branch::get_height(){ return Branch::height; }
int Branch::get_z_index(){ return Branch::z_index; }
float Branch::get_slope(){ return Branch::slope; }
std::vector<Branch> Branch::get_children(){ return Branch::children; }
