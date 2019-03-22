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
	std::vector<Shape> getShapeVector();
	Shape* generateShape(sf::Vector2f position);

private:
	void nextShape();
	std::vector<Shape> m_shapeVector;
	void checkBounds(sf::Vector2f* tempPos);
	sf::RectangleShape m_rightBound, m_leftBound, m_bottomBound;

	Shape* m_currentShape;
	Shape* m_nextShape;

	bool m_controlA;
	bool m_controlE;
	bool m_controlS;
	bool m_controlD;
	bool m_controlQ;
	bool m_controlW;
};
#endif

