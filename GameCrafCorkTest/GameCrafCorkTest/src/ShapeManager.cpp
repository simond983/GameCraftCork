#include "ShapeManager.h"

ShapeManager::ShapeManager()
{
	m_leftBound = sf::RectangleShape(sf::Vector2f(30, 600));
	m_rightBound = sf::RectangleShape(sf::Vector2f(30, 600));
	
	m_leftBound.setPosition(0, 0);
	m_rightBound.setPosition(330, 0);
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

	checkBounds(tempPosition);
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

void ShapeManager::checkBounds(sf::Vector2f* tempPos)
{
	for (int i = 0; i < 4; i++)
	{

		if (m_shapeVector.back().getShapeTiles().at(i)->getSprite().getGlobalBounds().intersects(m_leftBound.getGlobalBounds()))
		{
			//std::cout << "COLLISION" << std::endl;
			tempPos->x += Tile::GetWidth();
		}

		else if (m_shapeVector.back().getShapeTiles().at(i)->getSprite().getGlobalBounds().intersects(m_rightBound.getGlobalBounds()))
		{
			tempPos->x -= Tile::GetWidth();
		}

		
	}
}
