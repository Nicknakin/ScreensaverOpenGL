#include "grid.h"

Grid::Grid(int width, int height, int side, sf::Color defaultColor): width{width}, height{height}, side{side}, defaultColor{defaultColor} {
    for(int i = 0; i < width*height; i++){
        cells.push_back(Cell{i%width, i/width, side, side, (float) defaultColor.r, (float) defaultColor.g, (float) defaultColor.b});
    }
}

Cell& Grid::getChangedCell(int i){
    return changedCells[i];
}

void Grid::popChangedCell(){
    changedCells.erase(changedCells.begin(), changedCells.begin()+1);
}

int Grid::getChangedCellSize(){
    return changedCells.size();
}

int Grid::size(){
    return height*width;
}

int Grid::getHeight(){
    return height;
}

int Grid::getWidth(){
    return width;
}

Cell& Grid::getCell(int x, int y){
    changedCells.push_back(cells[x+y*width]);
    return cells[x+y*width];
}

Cell& Grid::getCell(int oneDIndex){
    changedCells.push_back(cells[oneDIndex]);
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

void Grid::setColor(int x, int y, sf::Color color){
    cells[x+width*y].setFillColor(color);
}

std::vector<Cell> Grid::operator[](int i){
    return std::vector<Cell>{cells.begin()+i*width, cells.begin()+(i+1)*width};
}

