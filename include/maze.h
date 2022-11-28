#pragma once

#include "./tile.h"

#include <vector>
#include <SFML/Graphics.hpp>


class Map {
	public:
		Map(int rows, int columns);
		void CreateMap(sf::RenderWindow& window);

	private:
		int rows_;
		int columns_;
		std::vector<Tile*> map;	
};
