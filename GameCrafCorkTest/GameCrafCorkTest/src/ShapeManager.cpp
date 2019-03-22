#include "ShapeManager.h"

ShapeManager::ShapeManager()
{

}

ShapeManager::~ShapeManager()
{

}

///
// Update the current game objects shapes
///
void ShapeManager::update(sf::Int32 dt)
{
	for (int i = 0; i <= m_shapeVector.size(); i++)
	{
		m_shapeVector[i].update(dt);
	}
}

///
// Draw the current game objects shapes
///
void ShapeManager::render(sf::RenderWindow &window)
{
	for (int i = 0; i <= m_shapeVector.size(); i++)
	{
		m_shapeVector[i].render(window);
	}
}

void ShapeManager::addShape(Shape *shape)
{
	m_shapeVector.push_back(shape);
}