#include "Tree.h"
#include "Branch.h"

Tree::Tree (){
    Tree::root_branch = Branch(3, 0, 0, 0);
}

Tree::Tree( Branch branch ){
    Tree::root_branch = branch;
}

void Tree::grow( int factor ){

}