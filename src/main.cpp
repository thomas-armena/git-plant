#include <iostream>
#include "Branch.h"
#include "Canvas.h"

int main(){
    Canvas myCanvas (100, 40);

    Branch branch (10, 1, 3);
    branch.add_child(Branch(10, 1, -3));
    branch.add_child(Branch(10, 1, -1));

    Branch branch2 (4, 1, 0);
    branch2.add_child(branch);

    myCanvas.draw_branch(25, 40, 0, branch2);
    myCanvas.print();
    return 0;
}
