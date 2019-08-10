#include <iostream>
#include "Branch.h"
#include "Canvas.h"

int main(){
    Canvas myCanvas (200, 50);
    Branch rootBranch (20, 2, 0.5, 1);
    Branch childBranch1 (5, 1, -2, 0.5);
    Branch childBranch2 (8, 0, 1, 1);

    Branch childBranch3 (6, 0, 2, 0.8);
    rootBranch.add_child(childBranch3);

    Branch childBranch4 (10, 0, 2, 0.4);
    rootBranch.add_child(childBranch4);

    Branch childBranch5 (12, 0, -2, 0.1);
    rootBranch.add_child(childBranch5);


    childBranch1.add_child(childBranch2);
    rootBranch.add_child(childBranch1);
  myCanvas.draw_branch(50, 40, 0, rootBranch);
    myCanvas.print();
    return 0;
}
