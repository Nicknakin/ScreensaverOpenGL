#include "cell.h"
#include <sstream>

Cell::Cell(int x, int y, int width, int height, float r, float g, float b): x{x}, y{y}, width{width}, height{height}, r{r/255}, g{g/255}, b{b/255}, sf::RectangleShape(sf::Vector2<float>{width, height}) {
    setPosition(x*width, y*height);
    setFillColor(sf::Color{r*255, g*255, b*255});
}

std::string Cell::toString() const{
    std::stringstream buffer{};
    buffer << x << " " << y << " " << width << " " << height << " (" << (int) r*255 << "," << (int) g*255 << "," << (int) b*255 << ")";
    return buffer.str();
}


std::ostream& operator<<(std::ostream& os, const Cell& cell){
    return os << cell.toString();
}

void Cell::setColor(int r, int g, int b){
    setFillColor(sf::Color(r,g,b));
}
