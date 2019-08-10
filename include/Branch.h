#ifndef BRANCH_H
#define BRANCH_H

#include <vector>

class Branch {
    int height, width;
    float slope;
    float placement;
    std::vector<Branch> children;
public:
    Branch(int height, int width, float slope, float placement);
    int get_height();
    int get_width();
    float get_slope();
    float get_placement();
    void add_child(Branch);
    std::vector<Branch> get_children();
};

#endif
