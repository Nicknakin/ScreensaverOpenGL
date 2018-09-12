#ifndef gridinc
#define gridinc

#include <vector>
#include <SFML/Graphics.hpp>

#include "cell.h"

class Grid{
    public:
        Grid(int width, int height, int side = 1, sf::Color defaultColor = sf::Color(0,0,0));
        Cell& getCell(int x, int y);
        Cell& getCell(int oneDIndex);
        Cell& getChangedCell(int onDIndex);
        void popChangedCell();
        int getChangedCellSize();
        int size();
        int getWidth();
        int getHeight();
        sf::Color getDefaultColor();
        std::vector<Cell> operator[](int i);
        std::vector<Cell>& getCells();
        void setColor(int x, int y, sf::Color color);
        void setColor(int x, int y, int r, int g, int b);
        void change(int x, int y);

    private:
        int width, height, side;
        const sf::Color defaultColor;
        std::vector<Cell> cells;
        std::vector<int> changedCells;
};

#endif
