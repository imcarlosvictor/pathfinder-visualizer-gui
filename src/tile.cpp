# include "../include/tile.h"

Tile::Tile(int length, int width, int x_coord, int y_coord) {
    this->tile_ = sf::RectangleShape(sf::Vector2f(this->length_, this->width_));
    this->state_ = Unexplored;
    this->length_ = length;
    this->width_ = width;
    this->x_coord_ = x_coord;
    this->y_coord_ = y_coord;
}

void Tile::CreateTile() {
    this->tile_.setSize(sf::Vector2f(this->length_, this->width_));
    /* this->tile_.setFillColor(sf::Color(243,246,244));  // off-white */
    this->tile_.setFillColor(sf::Color(213,213,213));  // off-white
    this->tile_.setOutlineColor(sf::Color(64,64,64));
    this->tile_.setOutlineThickness(.5);
    this->tile_.setPosition(this->x_coord_, this->y_coord_);
}

void Tile::DrawTile(sf::RenderWindow& window) {
    window.draw(this->tile_);
}

void Tile::setStartpoint() {
    this->tile_.setFillColor(sf::Color(34,139,34));
    this->state_ = Start;
}

void Tile::setEndpoint() {
    this->tile_.setFillColor(sf::Color(244,48,10));
    this->state_ = End;
}

void Tile::setPath() {
    this->tile_.setFillColor(sf::Color(255,123,0));
    this->state_ = Path;
}

void Tile::setExplored() {
    this->tile_.setFillColor(sf::Color(220,226,254));
    this->state_ = Explored;
}

void Tile::setUnexplored() {
    this->tile_.setFillColor(sf::Color(213,213,213));
    this->state_ = Unexplored;
}

void Tile::setBorder() {
    this->tile_.setFillColor(sf::Color(64,64,64));
    this->state_ = Border;
}

void Tile::setCoordinate(int x, int y) {
    this->x_coord_ = x;
    this->y_coord_ = y;
}

int Tile::getXCoord() {
    return x_coord_;
}

int Tile::getYCoord() {
    return y_coord_;
}

TileState Tile::getTileState() {
    return this->state_;
}

