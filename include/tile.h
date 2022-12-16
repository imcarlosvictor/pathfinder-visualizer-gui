#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

enum TileState {
	Start = 0,
	End,
	Path,
	Explored,
	Floor,
	Wall	
};

class Tile {
	public:
		Tile(int length, int width, int x_coord, int y_coord);
		void CreateTile();
		void DrawTile(sf::RenderWindow& window);
		void setStartpoint();
		void setEndpoint();
		void setPath();
		void setExplored();
		void setFloor();
		void setWall();
		void setCoordinate(int x, int y);
		int getXCoord();
		int getYCoord();
		TileState getTileState();


	private:
		sf::RectangleShape tile_;
		TileState state_;
		int length_;
		int width_;
		int x_coord_;
		int y_coord_;
};
