#pragma once

#include "./tile.h"

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


struct Coordinates {
	long unsigned int x_coord;
	long unsigned int y_coord;
};

struct GridDimension {
	int rows;
	int columns;
};


class Grid {
	public:
		Grid(int rows, int columns);
		void CreateGrid();
		void ClearGrid();
		void ClearPath();
		void RefreshGrid(sf::RenderWindow& window);
		void TilePressed(Coordinates);
		void getTileNeighbors(Coordinates);
		/* void GenerateMazeAlgorithms(Grid* grid_ptr, MazeAlgorithms* maze_algo_ptr_, const int algo_index); */
		Coordinates getMousePos(sf::Vector2i mouse_pos);
		GridDimension getGridDimension();

	private:
		int rows_;
		int columns_;
		std::vector<Tile*> grid_;	
};
