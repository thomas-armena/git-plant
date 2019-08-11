#include <iostream>
#include "Branch.h"
#include "Canvas.h"

int main(){
    Canvas myCanvas (50, 50);

    Branch rootBranch (20, 4, 0, 1);

    Branch childBranch3 (6, 7, 200, 0.8);
    rootBranch.add_child(childBranch3);

    Branch childBranch4 (10, 2, 2, 0.4);
    rootBranch.add_child(childBranch4);

    Branch childBranch5 (12, 2, -2, 0.1);
    rootBranch.add_child(childBranch5);


    Branch childBranch1 (5, 3, 0, 1);
    Branch childBranch2 (8, 2, 3, 1);
    childBranch1.add_child(childBranch2);

    rootBranch.add_child(childBranch1);

    myCanvas.draw_branch(20, 49, 0, rootBranch);
    myCanvas.print();
    return 0;
}
