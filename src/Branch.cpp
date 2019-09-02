#include "Branch.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <cmath>
#include <random>
#include <stdlib.h>

Branch::Branch(float height_growth_rate, float width_growth_rate, float angle, float placement){
    Branch::height_growth_rate = height_growth_rate;
    Branch::width_growth_rate = width_growth_rate;
    Branch::growth_level = 1;
    Branch::angle = angle;
    Branch::placement = placement;
    Branch::next_child_buffer = 15;
}

Branch::Branch(){
    Branch::height_growth_rate = 1;
    Branch::width_growth_rate = 0.2;
    Branch::growth_level = 0;
    Branch::angle = 0;
    Branch::placement = 0;
}

void Branch::add_child(Branch* child_branch){
    Branch::children.push_back(child_branch);
}

std::vector<Branch*> Branch::get_children_at_height(int height_ind){
    std::vector<Branch*> branches;
    for(int k = 0; k < Branch::children.size(); k++){
        Branch* child_branch = Branch::children[k];
        int curr_height_ind = int(std::round( Branch::get_height() * child_branch->get_placement() )) - 1;
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
    std::cout << "growth_level:" << Branch::growth_level << std::endl;

    for(int i = 0; i < Branch::children.size(); i++){
        children[i]->grow(factor);
    }

    Branch::next_child_buffer -= factor;
    if (Branch::next_child_buffer <= 0) {
        float remainder = -next_child_buffer;



        float a = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float c = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float d = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

        Branch * new_child  = new Branch( 
            Branch::height_growth_rate * a,
            Branch::width_growth_rate * b,
            M_PI * c - M_PI/2,
            d
        );
        this->add_child(new_child);
        Branch::next_child_buffer = 15;
    }

}

float Branch::get_angle(){ return Branch::angle; }
float Branch::get_placement(){ return Branch::placement; }
std::vector<Branch*> Branch::get_children(){ return Branch::children; }
