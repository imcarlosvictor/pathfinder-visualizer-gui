#include "../include/maze.h"

Map::Map(int rows, int columns) {
    this->rows_ = rows; 
    this->columns_ = columns;
}

void Map::CreateMap(sf::RenderWindow& window) {
    // loop through y and x axis
    int x_coord = 330;
    int y_coord = 0;
    // Add tiles
    for (int col = 0; col < 30; col++) {
        for (int row = 0; row < 39; row++) {
            Tile* new_tile = new Tile(30, 30, x_coord, y_coord);
            new_tile->CreateTile(window);
            this->map.push_back(new_tile);
            x_coord += 30;
        }
        x_coord = 330;  // Reset x-coordinate
        y_coord += 30;
    }
}
