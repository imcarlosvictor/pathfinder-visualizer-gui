#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Tile {
	public:
		Tile(int length, int width, int row, int col);
		/* ----------- Tile State ----------- */
		/* ----------- Manipulate Tile State ----------- */
		void setExplored();
		void setUnexplored();
		void setBorder();
		void setStartpoint();
		void setEndpoint();
		void ResetTile();
		/* ----------- Tile Creation ----------- */
		void CreateTile();


	private:
		int length_;
		int width_;
		int row_;
		int col_;
};
