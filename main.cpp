#include <stdlib.h>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "cell.h"
#include "grid.h"

struct settings{
    const int width;
    const int height;
    const int sideLength;
    const int speed;
};

int main(){
    settings config = {1920/2, 1080/2, 10, 60};
    bool resized = true;
    Grid cells{config.width/config.sideLength, config.height/config.sideLength, config.sideLength};
    sf::RenderWindow window(sf::VideoMode(config.width,config.height), "SFML Project");
    window.setFramerateLimit(config.speed);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::Resized)
                    resized = true;
        }
        
        resized = false;
        window.display();
    }
    return 0;
}
