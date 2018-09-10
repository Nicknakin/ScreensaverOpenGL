#include "cell.h"
#include <sstream>

Cell::Cell(int x, int y, int width, int height, float r, float g, float b, int value): x{x}, y{y}, width{width}, height{height}, sf::RectangleShape(sf::Vector2<float>{width, height}), value{value} {
    this->r = (float) r/255.f;
    this->g = (float) g/255.f;
    this->b = (float) b/255.f;
    setPosition(x*width, y*height);
    setFillColor(sf::Color{r, g, b});
}

std::string Cell::toString() const{
    std::stringstream buffer{};
    buffer << x << " " << y << " " << width << " " << height << " (" << (int) r*255 << "," << (int) g*255 << "," << (int) b*255 << ")";
    return buffer.str();
}


std::ostream& operator<<(std::ostream& os, const Cell& cell){
    return os << cell.toString();
}

int Cell::getR(){
    return getFillColor().r;
}

int Cell::getG(){
    return getFillColor().g;
}

int Cell::getB(){
    return getFillColor().b;
}

int Cell::getValue(){
    return value;
}

void Cell::setValue(int val){
    value = val;
}

void Cell::setColor(sf::Color color){
    setFillColor(color);
    r = (float) color.r/255.f;
    g = (float) color.g/255.f;
    b = (float) color.b/255.f;
}

void Cell::setColor(int r, int g, int b){
    setFillColor(sf::Color(r,g,b));
}
