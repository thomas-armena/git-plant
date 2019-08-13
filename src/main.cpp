#include <iostream>
#include "Tree.h"
#include "Branch.h"
#include "Canvas.h"
#include <cmath>

int main(){
    Canvas canvas (50, 50);
    float angle = 0;
    while(true){
        std::cin.get();
        Branch branch (10, 0, 0, 0);
        canvas.draw_branch(25, 25, angle, branch);
        canvas.print();
        angle += M_PI / 16;
    }
    

    // Tree tree;
    // while(true){
    //     std::cin.get();
    //     tree.grow(1);
    //     canvas.draw_tree(tree);
    //     canvas.print();
    // }

    // canvas.print();
    return 0;
}
