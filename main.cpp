#include <stdlib.h>
#include <assert.h>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "cell.h"
#include "grid.h"

struct setting{
    const int width;
    const int height;
    const int sideLength;
    const int speed;
};

struct operators{
    int activeX, activeY;
    int xIncrement, yIncrement;
    int xLimit, yLimit;
    std::vector<sf::Color> colors{sf::Color{255,0,0}, sf::Color{255, 128, 0}, sf::Color{0,255,0}, sf::Color{0, 128, 255}, sf::Color{0, 0, 255}, sf::Color{255, 0 , 128}, sf::Color{255, 255, 255}, sf::Color{255, 255, 0}, sf::Color{255, 0, 255}, sf::Color{0, 255, 255}, sf::Color{0, 0, 0}};
};

void update(setting config, operators& ops, Grid& cells);

int main(int argc, char** argv){
    try{
        //Initialize settings, if there are enough arguments use each one for width height sideLengthand speed respectively.
        setting config = {(argc >= 2)? std::stoi(argv[1]): 1920/2, (argc >= 3)? std::stoi(argv[2]): 1080/2, (argc >= 4)? std::stoi(argv[3]): 2, (argc >= 5)? std::stoi(argv[4]): 200};
 
        operators ops = {0, 0, 1, 1, config.width/config.sideLength-1, config.height/config.sideLength-1};

        //Argument used to know whether the window has been resized.
        bool resized = true;

        //Initialize the Grid of cells based on configs
        Grid cells{config.width/config.sideLength, config.height/config.sideLength, config.sideLength};

        //Create window with SFML and set framerate
        sf::RenderWindow window(sf::VideoMode(config.width,config.height), "SFML Project");
        window.setFramerateLimit(config.speed);

        //Execution loop
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

            update(config, ops, cells);
            
            while(!resized && cells.getChangedCellSize() > 0){
                window.draw(cells.getChangedCell(0));
                cells.popChangedCell();
            }
            
            if(resized){
                for(int i = 0; i < cells.size(); i++){
                    window.draw(cells.getCell(i));
                }
            }

            resized = false;
            window.display();
        }
    } catch(const std::exception& e){
        return 1;
    }
    return 0;
}

void update(setting config, operators& ops, Grid& cells){
    while(ops.activeX != ops.xLimit && ops.activeY != ops.yLimit){
        cells.change(ops.activeX, ops.activeY);
        Cell& activeCell = cells.getCell(ops.activeX, ops.activeY);
        activeCell.setValue((activeCell.getValue() + 1) % ops.colors.size());
        activeCell.setFillColor(ops.colors[activeCell.getValue()]);
        ops.activeX += ops.xIncrement;
        ops.activeY += ops.yIncrement;
    }
    if(ops.activeX == ops.xLimit){
        ops.xIncrement *= -1;
        ops.xLimit = cells.getWidth() - 1 - ops.xLimit;
    }
    if(ops.activeY == ops.yLimit){
        ops.yIncrement *= -1;
        ops.yLimit = cells.getHeight() - 1 - ops.yLimit;
    }
}
