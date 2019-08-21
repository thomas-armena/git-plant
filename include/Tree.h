#ifndef TREE_H
#define TREE_H

#include "Branch.h"


class Tree {
    Branch root_branch;

public:
    Tree(Branch root_branch);
    Tree();
    Branch get_root_branch();
    void grow(float factor);
};

#endif
