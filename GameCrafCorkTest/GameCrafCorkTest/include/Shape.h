#ifndef  SHAPE_H
#define SHAPE_H

#include <vector>
#include <string>
#include "Tile.h"

class Shape
{
public:
	Shape();
	Shape(std::string type, sf::Vector2f pos);
	~Shape();
	std::vector<Tile*> getShapeTiles();
	void update(sf::Int32 dt);
	void render(sf::RenderWindow &window);
private:
	std::vector<Tile*> m_shapeTiles;
	const int NUM_TILES = 4;
	sf::Vector2f m_position;

};

#endif // ! TILECOLLECTION_H
