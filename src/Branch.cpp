#include "Branch.h"
#include <vector>
#include <math.h>

Branch::Branch(int height, int width, float slope, float placement){
    Branch::height = height;
    Branch::width = width;
    Branch::slope = slope;
    Branch::placement = placement;
}

void Branch::add_child(Branch child_branch){
    Branch::children.push_back(child_branch);
}

std::vector<Branch> Branch::get_children_at_height(int height_ind){
    std::vector<Branch> branches;
    for(int k = 0; k < Branch::children.size(); k++){
        Branch child_branch = Branch::children[k];
        int curr_height_ind = int(std::round( Branch::height * child_branch.get_placement() )) - 1;
        if (curr_height_ind == height_ind){
            branches.push_back(child_branch);
        }
    }
    return branches;
}


int Branch::get_height(){ return Branch::height; }
int Branch::get_width(){ return Branch::width; }
float Branch::get_slope(){ return Branch::slope; }
float Branch::get_placement(){ return Branch::placement; }
std::vector<Branch> Branch::get_children(){ return Branch::children; }
