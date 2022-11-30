# include "../include/node.h"

Node::Node(int length, int width, int x_coord, int y_coord) {
    this->node = sf::RectangleShape(sf::Vector2f(this->length_, this->width_));
    this->state_ = Unexplored;
    this->length_ = length;
    this->width_ = width;
    this->x_coord_ = x_coord;
    this->y_coord_ = y_coord;
}

void Node::setExplored() {
}

void Node::setUnexplored() {
}

void Node::setBorder() {
    this->node.setFillColor(sf::Color(0,0,0));
    this->state_ = Border;
}

void Node::setStartpoint() {
}

void Node::setEndpoint() {
}

void Node::setCoordinate(int x, int y) {
    this->x_coord_ = x;
    this->y_coord_ = y;
}

int Node::getXCoord() {
    return x_coord_;
}

int Node::getYCoord() {
    return y_coord_;
}

NodeState Node::getNodeState() {
    return this->state_;
}

void Node::CreateNode(sf::RenderWindow& window) {
    this->node.setSize(sf::Vector2f(this->length_, this->width_));
    this->node.setFillColor(sf::Color(243,246,244));  // off-white
    this->node.setOutlineColor(sf::Color::Black);
    this->node.setOutlineThickness(.5);
    this->node.setPosition(this->x_coord_, this->y_coord_);
    window.draw(this->node);
}

