#ifndef BRANCH_H
#define BRANCH_H

#include <vector>

class Branch {
    int height, z_index;
    float slope;
    std::vector<Branch> children;
public:
    Branch(int height, int z_index, float slope);
    int get_height();
    int get_z_index();
    float get_slope();
    void add_child(Branch);
    std::vector<Branch> get_children();
};

#endif
