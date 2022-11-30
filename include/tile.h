#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

enum TileState {
	Start = 0,
	End,
	Explored,
	Unexplored,
	Border
};

class Tile {
	public:
		Tile(int length, int width, int x_coord, int y_coord);
		/* ----------- Tile State ----------- */
		/* ----------- Manipulate Tile State ----------- */
		void setStartpoint();
		void setEndpoint();
		void setExplored();
		void setUnexplored();
		void setBorder();
		void setCoordinate(int x, int y);
		int getXCoord();
		int getYCoord();
		TileState getTileState();
		void CreateTile(sf::RenderWindow& window);
		void ResetTile();


	private:
		sf::RectangleShape tile;
		TileState state_;
		int length_;
		int width_;
		int x_coord_;
		int y_coord_;
};
