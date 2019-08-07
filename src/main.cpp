#include <iostream>
#include "Branch.h"
#include "Canvas.h"

int main(){
    Canvas myCanvas (100, 40);
    Branch branch (10, 1, -3);
    myCanvas.draw_branch(25, 40,branch);
    myCanvas.print();
    return 0;
}
