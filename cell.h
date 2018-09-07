#ifndef cellInc
#define cellInc

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>

class Cell: public sf::RectangleShape{
    public:
        Cell(int x, int y, int width, int height, float r = 255, float g = 255, float b = 255, int value = 0);
        std::string toString() const;
        sf::Color getColor();
        int getR();
        int getG();
        int getB();
        int getValue();
        void setValue(int val);
        void setColor(sf::Color color);
        void setColor(int r, int g, int b);
        friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
        
        float r,g,b;

    private:
        int x, y, width, height;
        int value;
};

#endif
