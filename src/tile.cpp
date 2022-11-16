# include "../include/tile.h"

Tile::Tile(int length, int width, int x_coord, int y_coord) {
    this->length_ = length;
    this->width_ = width;
    this->x_coord_ = x_coord;
    this->y_coord_ = y_coord;
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

void Tile::CreateTile(sf::RenderWindow& window) {
    sf::RectangleShape tile = sf::RectangleShape(sf::Vector2f(this->length_, this->width_));
    tile.setSize(sf::Vector2f(this->length_, this->width_));
    tile.setFillColor(sf::Color(243,246,244));  // off-white
    tile.setOutlineColor(sf::Color::Black);
    tile.setOutlineThickness(1);
    tile.setPosition(this->x_coord_, this->y_coord_);
    window.draw(tile);
}
