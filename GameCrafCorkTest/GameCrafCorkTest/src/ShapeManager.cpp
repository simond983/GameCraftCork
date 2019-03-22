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
	sf::Vector2f* tempPosition = new sf::Vector2f(m_shapeVector.back().getPosition());

	for (int i = 0; i < m_shapeVector.size(); i++)
	{
		m_shapeVector[i].update(dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x - Tile::GetWidth(), m_shapeVector.back().getPosition().y);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x + Tile::GetWidth(), m_shapeVector.back().getPosition().y);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x, m_shapeVector.back().getPosition().y + Tile::GetHeight());
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x - Tile::GetWidth(), m_shapeVector.back().getPosition().y);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x - Tile::GetWidth(), m_shapeVector.back().getPosition().y);
	}

	
	m_shapeVector.back().setPosition(*tempPosition);
	delete tempPosition;
}

///
// Draw the current game objects shapes
///
void ShapeManager::render(sf::RenderWindow &window)
{
	for (int i = 0; i < m_shapeVector.size(); i++)
	{
		m_shapeVector[i].render(window);
	}
}

void ShapeManager::addShape(Shape &shape)
{
	m_shapeVector.push_back(shape);
}

std::vector<Shape> ShapeManager::getShapeVector()
{
	return m_shapeVector;
}
