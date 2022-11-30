#pragma once

#include "./node.h"

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class Graph {
	public:
		Graph(int rows, int columns);
		void CreateGraph(sf::RenderWindow& window);
		void ChangeNode(sf::Vector2i mouse_pos);

	private:
		int rows_;
		int columns_;
		std::vector<Node*> graph;	
};
