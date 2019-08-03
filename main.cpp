#include <iostream>
#include <vector>

class Canvas {
    int width, height;
    std::vector<std::vector<char>> pixels;
public:
    Canvas(int, int);
    void draw_pixel(int, int, char);
    void print();
};

Canvas::Canvas(int width, int height) {
    Canvas::width = width;
    Canvas::height = height;
    for(int y = 0; y < Canvas::height; y++) {
        std::vector<char> newRow;
        for(int x = 0; x < width; x++) {
            newRow.push_back('.');
        }
        Canvas::pixels.push_back(newRow);
    }
}

void Canvas::draw_pixel (int x, int y, char pixel) {
    Canvas::pixels[y][x] = pixel;
}

void Canvas::print () {
    for(int y = 0; y < Canvas::height; y++){
        for(int x = 0; x < Canvas::width; x++){
            std::cout << Canvas::pixels[y][x];
        }
        std::cout << std::endl;
    }
}

int main(){
    Canvas myCanvas (20, 10);
    myCanvas.draw_pixel(0,0,'x');
    myCanvas.draw_pixel(1,1,'y');
    myCanvas.print();
    return 0;
}
