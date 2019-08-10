#include <iostream>
#include "Branch.h"
#include "Canvas.h"

int main(){
    Canvas myCanvas (100, 40);
    Branch rootBranch (20, 0, 1, 1);
    Branch childBranch1 (10, 0, -2, 0.5);
    Branch childBranch2 (10, 0, 1, 1);
    childBranch1.add_child(childBranch2);
    rootBranch.add_child(childBranch1);
    myCanvas.draw_branch(25, 30, 0, rootBranch);
    myCanvas.print();
    return 0;
}
