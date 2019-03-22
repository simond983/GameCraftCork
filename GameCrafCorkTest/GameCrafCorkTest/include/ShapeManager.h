#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <vector>
#include "Tile.h"
#include "Shape.h"

class ShapeManager
{
public:
	ShapeManager();
	~ShapeManager();

	void update(sf::Int32 dt);
	void render(sf::RenderWindow &window);

	void addShape(Shape &shape);
private:
	std::vector<Shape> m_shapeVector;

};

#endif

