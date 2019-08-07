#include "Branch.h"

Branch::Branch(int height, int z_index, float slope){
    Branch::height = height;
    Branch::z_index = z_index;
    Branch::slope = slope;
}

int Branch::get_height(){ return Branch::height; }
int Branch::get_z_index(){ return Branch::z_index; }
float Branch::get_slope(){ return Branch::slope; }