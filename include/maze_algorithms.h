#pragma once

#include "./grid.h"

#include <iostream>
#include <string>
#include <vector>

class MazeAlgorithms {
	public:
		void RecursiveDivision(Grid* grid_ptr);
		void Divide(Grid* grid_ptr, std::string orientation);
};
