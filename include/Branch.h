#ifndef BRANCH_H
#define BRANCH_H

#include <vector>

class Branch {
    int height, z_index;
    float slope;
    float placement;
    std::vector<Branch> children;
public:
    Branch(int height, int z_index, float slope, float placement);
    int get_height();
    int get_z_index();
    float get_slope();
    float get_placement();
    void add_child(Branch);
    std::vector<Branch> get_children();
};

#endif
