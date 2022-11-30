#include "../include/graph.h"

Graph::Graph(int rows, int columns) {
    this->rows_ = rows; 
    this->columns_ = columns;
}

void Graph::CreateGraph(sf::RenderWindow& window) {
    int length = 30, width = 30;
    int y_coord = 0;
    // Add nodes
    for (int col = 0; col < 30; col++) {
        int x_coord = 330;
        for (int row = 0; row < 39; row++) {
            Node* new_node = new Node(length, width, x_coord, y_coord);
            new_node->CreateNode(window);
            this->graph.push_back(new_node);
            x_coord += 30;
        }
        x_coord = 330;  // Reset x-coordinate
        y_coord += 30;
    }
}

void Graph::ChangeNode(sf::Vector2i mouse_pos) {
    // Find the nearest coordinates
    int x = (mouse_pos.x / 30) * 30;
    int y = (mouse_pos.y - (mouse_pos.y % 30));
    /* std::cout << "X:" << x << " Y:" << y << std::endl; */

    // Find the node with the coordinates in the vector
    for (Node* node : graph) {
        if (node->getXCoord() == x && node->getYCoord() == y) {
            std::cout << "Tile X:" << node->getXCoord() << " " << "Tile Y:" << node->getYCoord() << "   | Tile State:" << node->getNodeState() << std::endl;
            node->setBorder();
            std::cout << "Tile State:" << node->getNodeState() << std::endl;
            break;
        }
    }

}
