#include "Branch.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <cmath>
#include <random>
#include <stdlib.h>

float get_random_float(){
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

Branch::Branch(float height_growth_rate, float width_growth_rate, float angle, float placement){
    Branch::height_growth_rate = height_growth_rate;
    Branch::width_growth_rate = width_growth_rate;
    Branch::growth_level = 1;
    Branch::angle = angle;
    Branch::placement = placement;
    Branch::next_child_buffer = 15;
}

Branch::Branch(){
    Branch::height_growth_rate = 0.25;
    Branch::width_growth_rate = 0.05;
    Branch::growth_level = 0;
    Branch::angle = (get_random_float()-0.5) / 2;
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

    for(int i = 0; i < Branch::children.size(); i++){
        children[i]->grow(factor);
    }

    Branch::next_child_buffer -= factor;
    if (Branch::next_child_buffer <= 0) {
        float remainder = -next_child_buffer;

        float a = get_random_float();
        float b = get_random_float();
        float c = get_random_float();
        float d = get_random_float();

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
