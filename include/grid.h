#pragma once

#include "./tile.h"

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class Grid {
	public:
		Grid(int rows, int columns);
		void CreateGrid(sf::RenderWindow& window);
		void ChangeTile(sf::Vector2i mouse_pos);

	private:
		int rows_;
		int columns_;
		std::vector<Tile*> grid;	
};
