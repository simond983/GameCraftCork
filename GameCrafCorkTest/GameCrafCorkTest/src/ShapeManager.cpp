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
	for (int i = 0; i < m_shapeVector.size(); i++)
	{
		m_shapeVector[i].update(dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_shapeVector.back().setPosition(sf::Vector2f(m_shapeVector.back().getPosition().x - Tile::GetWidth(), m_shapeVector.back().getPosition().y));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_shapeVector.back().setPosition(sf::Vector2f(m_shapeVector.back().getPosition().x + Tile::GetWidth(), m_shapeVector.back().getPosition().y));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_shapeVector.back().setPosition(sf::Vector2f(m_shapeVector.back().getPosition().x, m_shapeVector.back().getPosition().y + Tile::GetHeight()));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		m_shapeVector.back().setPosition(sf::Vector2f(m_shapeVector.back().getPosition().x - Tile::GetWidth(), m_shapeVector.back().getPosition().y));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
	{
		m_shapeVector.back().setPosition(sf::Vector2f(m_shapeVector.back().getPosition().x - Tile::GetWidth(), m_shapeVector.back().getPosition().y));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_shapeVector.back().rotateShape();
	}
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