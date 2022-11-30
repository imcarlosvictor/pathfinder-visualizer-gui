#include "../include/grid.h"

Grid::Grid(int rows, int columns) {
    this->rows_ = rows; 
    this->columns_ = columns;
    this->CreateGrid();
}

void Grid::CreateGrid() {
    int length = 30, width = 30;
    int y_coord = 0;
    // Add tiles
    for (int col = 0; col < 30; col++) {
        int x_coord = 330;
        for (int row = 0; row < 39; row++) {
            Tile* new_tile = new Tile(length, width, x_coord, y_coord);
            new_tile->CreateTile();
            this->grid.push_back(new_tile);
            x_coord += 30;
        }
        x_coord = 330;  // Reset x-coordinate
        y_coord += 30;
    }
}

void Grid::UpdateGrid(sf::RenderWindow& window) {
    for (Tile* tile : grid) {
        tile->DrawTile(window);
    }
}

void Grid::TilePressed(sf::Vector2i mouse_pos) {
    // Find the nearest coordinates
    int x = (mouse_pos.x / 30) * 30;
    int y = (mouse_pos.y - (mouse_pos.y % 30));
    /* std::cout << "X:" << x << " Y:" << y << std::endl; */

    // Find the tile with the coordinates in the vector
    for (Tile* tile : grid) {
        if (tile->getXCoord() == x && tile->getYCoord() == y) {
            std::cout << "Tile X:" << tile->getXCoord() << " " << "Tile Y:" << tile->getYCoord() << "   | Tile State:" << tile->getTileState() << std::endl;
            tile->setBorder();
            std::cout << "Tile State:" << tile->getTileState() << std::endl;
            break;
        }
    }

}
