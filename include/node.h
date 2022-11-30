#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

enum NodeState {
	Start = 0,
	End,
	Explored,
	Unexplored,
	Border
};

class Node {
	public:
		Node(int length, int width, int x_coord, int y_coord);
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
		NodeState getNodeState();
		void CreateNode(sf::RenderWindow& window);
		void ResetNode();


	private:
		sf::RectangleShape node;
		NodeState state_;
		int length_;
		int width_;
		int x_coord_;
		int y_coord_;
};
