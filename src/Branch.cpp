#include "Branch.h"
#include <vector>
#include <math.h>

Branch::Branch(float height_growth_rate, float width_growth_rate, float angle, float placement){
    Branch::height_growth_rate = height_growth_rate;
    Branch::width_growth_rate = width_growth_rate;
    Branch::growth_level = 0;
    Branch::angle = angle;
    Branch::placement = placement;
}

Branch::Branch(){
    Branch::height_growth_rate = 1;
    Branch::width_growth_rate = 0.2;
    Branch::growth_level = 0;
    Branch::angle = 0;
    Branch::placement = 0;
}

void Branch::add_child(Branch child_branch){
    Branch::children.push_back(child_branch);
}

std::vector<Branch> Branch::get_children_at_height(int height_ind){
    std::vector<Branch> branches;
    for(int k = 0; k < Branch::children.size(); k++){
        Branch child_branch = Branch::children[k];
        int curr_height_ind = int(std::round( Branch::get_height() * child_branch.get_placement() )) - 1;
        if (curr_height_ind == height_ind){
            branches.push_back(child_branch);
        }
    }
    return branches;
}

void Branch::set_angle( float angle ) {
    Branch::angle = angle;
}

void Branch::set_placement( float placement ) {
    Branch::placement = placement;
}

int Branch::get_height(){
    return Branch::height_growth_rate * Branch::growth_level; 
}

int Branch::get_width(){ 
    return Branch::width_growth_rate * Branch::growth_level; 
}

void Branch::grow(float factor){
    Branch::growth_level += factor;
}

float Branch::get_angle(){ return Branch::angle; }
float Branch::get_placement(){ return Branch::placement; }
std::vector<Branch> Branch::get_children(){ return Branch::children; }
