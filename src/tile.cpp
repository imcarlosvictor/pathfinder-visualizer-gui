# include "../include/tile.h"

Tile::Tile(int length, int width, int row, int col) {
    this->length_ = length;
    this->width_ = width;
    this->row_ = row;
    this->col_ = col;
}

/* ---------------------------- Public ----------------------------*/
void Tile::setExplored() {
}

void Tile::setUnexplored() {
}

void Tile::setBorder() {
}

void Tile::setStartpoint() {
}

void Tile::setEndpoint() {
}

void Tile::CreateTile() {
    sf::RectangleShape tile = sf::RectangleShape(sf::Vector2f(this->length_, this->width_));
    tile.setSize(sf::Vector2f(this->length_, this->width_));
    tile.setFillColor(sf::Color(243,246,244));  // off-white
}
