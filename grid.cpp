#include "grid.h"

Grid::Grid(int width, int height, int side, sf::Color defaultColor): width{width}, height{height}, side{side}, defaultColor{defaultColor} {
    for(int i = 0; i < width*height; i++){
        cells.push_back(Cell{i%width, i/width, side, side, defaultColor.r, defaultColor.g, defaultColor.b});
    }
}

int Grid::size(){
    return height;
}

int Grid::getHeight(){
    return height;
}

int Grid::getWidth(){
    return width;
}

Cell& Grid::getCell(int x, int y){
    return getCell(x+y*width);
}

Cell& Grid::getCell(int oneDIndex){
    return cells[oneDIndex];
}

sf::Color Grid::getDefaultColor(){
    return defaultColor;
}

std::vector<Cell>& Grid::getCells(){
    return cells;
}

void Grid::setColor(int x, int y, int r, int g, int b){
    cells[x+width*y].setFillColor(sf::Color{r,g,b});
}

std::vector<Cell> Grid::operator[](int i){
    return std::vector<Cell>{cells.begin()+i*width, cells.begin()+(i+1)*width};
}

