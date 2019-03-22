#include "Shape.h"

Shape::Shape()
{
}

Shape::Shape(std::string type, sf::Vector2f pos) : m_position(pos)
{
	std::cout << Tile::GetHeight() << std::endl;
	if (type == "L")
	{
		m_shapeTiles.push_back(new Tile(m_position));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight())));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2))));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2))));
	}

	else if (type == "R")
	{
		m_shapeTiles.push_back(new Tile(m_position));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight())));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2))));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2))));
	}

	else if (type == "Z")
	{
		m_shapeTiles.push_back(new Tile(m_position));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight())));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight())));
	}

	else if (type == "S")
	{
		m_shapeTiles.push_back(new Tile(m_position));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + Tile::GetHeight())));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight())));
	}

	else if (type == "Line")
	{
		m_shapeTiles.push_back(new Tile(m_position));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 3), m_position.y)));
	}

	else if (type == "Square")
	{
		m_shapeTiles.push_back(new Tile(m_position));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight())));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight())));
	}

	else if (type == "T")
	{
		m_shapeTiles.push_back(new Tile(m_position));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight())));
	}
}

Shape::~Shape()
{
}

std::vector<Tile*> Shape::getShapeTiles()
{
	return m_shapeTiles;
}

void Shape::update(sf::Int32 dt)
{
	for (int i = 0; i < NUM_TILES; i++)
	{
		m_shapeTiles.at(i)->update(dt);
	}
}

void Shape::render(sf::RenderWindow &window)
{
	for (Tile* t : m_shapeTiles)
	{
		t->render(window);
	}
}
