#include "Tree.h"
#include "Branch.h"

Tree::Tree (){
    Tree::root_branch = Branch(3, 0, 0, 0);
}

Tree::Tree( Branch branch ){
    Tree::root_branch = branch;
}

Branch Tree::get_root_branch(){
    return Tree::root_branch;
}

void Tree::grow( int factor ){
    Tree::root_branch.set_height( Tree::root_branch.get_height() + factor);
}