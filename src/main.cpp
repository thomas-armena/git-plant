#include <iostream>
#include "Tree.h"
#include "Branch.h"
#include "Canvas.h"
#include <cmath>
#include <ctime>
#include <stdlib.h>

void test_angles(){
    Canvas canvas (50, 50);
    float angle = 0;
    while(true){
        std::cin.get();
        Branch branch (10, 0, 0, 0);
        canvas.draw_branch(25, 25, angle, branch);
        canvas.print();
        angle -= M_PI / 16;
    }
}

int main(){

    srand((unsigned)time(0));
    
    Canvas canvas (200, 100);
    Branch root_branch;
    Tree tree(root_branch);

    while(true){
        canvas.clear();
        std::cin.get();
        tree.grow(1);
        canvas.draw_tree(tree);
        canvas.print();
    }

    return 0;
}
