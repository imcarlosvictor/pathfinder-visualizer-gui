#include "../include/maze.h"

Map::Map(int rows, int columns) {
    this->rows_ = rows; 
    this->columns_ = columns;
}

void Map::CreateMap(sf::RenderWindow& window) {
    // loop through y and x axis
    int x_coord = 0;
    int y_coord = 0;
    for (int y = 0; y < 30; y++) {
        /* // Add tile on y axis */
        /* Tile* y_tile = new Tile(30, 30, x_coord, y_coord); */
        /* y_tile->CreateTile(window); */
        /* this->map[y].push_back(y_tile); */
        /* x_coord += 30; */

        // Add tile on x_axis
        for (int x = 0; x < 38; x++) {
            Tile* x_tile = new Tile(30, 30, x_coord, y_coord);
            x_tile->CreateTile(window);
            this->map[y].push_back(x_tile);
            x_coord += 30;
        }
        
        y_coord += 30;
    }
}
