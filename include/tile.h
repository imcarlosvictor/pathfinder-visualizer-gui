#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Tile {
	public:
		Tile(int length, int width, int x_coord, int y_coord);
		/* ----------- Tile State ----------- */
		/* ----------- Manipulate Tile State ----------- */
		void setExplored();
		void setUnexplored();
		void setBorder();
		void setStartpoint();
		void setEndpoint();
		void ResetTile();
		/* ----------- Tile Creation ----------- */
		void CreateTile(sf::RenderWindow& window);


	private:
		int length_;
		int width_;
		int x_coord_;
		int y_coord_;
};
