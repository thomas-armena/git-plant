#ifndef BRANCH_H
#define BRANCH_H

#include <vector>

class Branch {
    float height_growth_rate;
    float width_growth_rate;
    float growth_level;
    float angle;
    float placement;
    std::vector<Branch> children;
public:
    Branch(float height_growth_rate, float width_growth_rate, float angle, float placement);
    Branch();
    int get_height();
    int get_width();
    float get_angle();
    float get_placement();
    void set_angle(float angle);
    void set_placement(float placement);
    void add_child(Branch);
    void grow(float factor);
    std::vector<Branch> get_children();
    std::vector<Branch> get_children_at_height(int);
};

#endif
