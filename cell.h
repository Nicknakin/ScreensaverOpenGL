#ifndef cellInc
#define cellInc

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>

class Cell: public sf::RectangleShape{
    public:
        Cell(int x, int y, int width, int height, float r = 255, float g = 255, float b = 255);
        std::string toString() const;
        void setColor(int r, int g, int b);
        sf::Color getColor();
        friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
        float r,g,b;

    private:
        int x, y, width, height;
};

#endif
