#include "Tree.h"
#include "Branch.h"
#include <vector>

Tree::Tree (){
    Tree::root_branch = Branch(0.5, 0.1, 0, 0);
}

Tree::Tree( Branch branch ){
    Tree::root_branch = branch;
}

Branch Tree::get_root_branch(){
    return Tree::root_branch;
}

void grow_branch_and_children( Branch* branch, float factor ){
    branch->grow(factor);
    std::vector<Branch*> branch_children = branch->get_children();
    for(int i = 0; i < branch_children.size(); i++){
        grow_branch_and_children(branch_children[i], factor);
    }

}

void Tree::grow(float factor){
    grow_branch_and_children(&( Tree::root_branch ), factor);
}
