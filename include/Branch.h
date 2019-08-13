#ifndef BRANCH_H
#define BRANCH_H

#include <vector>

class Branch {
    int height, width;
    float angle;
    float placement;
    std::vector<Branch> children;
public:
    Branch(int height, int width, float angle, float placement);
    Branch();
    int get_height();
    int get_width();
    float get_angle();
    float get_placement();
    void set_height(int height);
    void set_width(int width);
    void set_angle(float angle);
    void set_placement(float placement);
    void add_child(Branch);
    std::vector<Branch> get_children();
    std::vector<Branch> get_children_at_height(int);
};

#endif
