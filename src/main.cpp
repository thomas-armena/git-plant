#include <iostream>
#include "Tree.h"
#include "Branch.h"
#include "Canvas.h"

int main(){
    Canvas canvas (50, 50);
    Tree tree;
    while(true){
        std::cin.get();
        tree.grow(1);
        canvas.draw_tree(tree);
        canvas.print();
    }



    canvas.print();
    return 0;
}
