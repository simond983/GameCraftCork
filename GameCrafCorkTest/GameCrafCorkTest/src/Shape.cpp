#include "Shape.h"

Shape::Shape()
{
}

Shape::Shape(std::string type, sf::Vector2f pos) : m_position(pos)
{
	if (type == "L")
	{
		m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Yellow));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()), false, sf::Color::Yellow));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2)), false, sf::Color::Yellow));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2)), false, sf::Color::Yellow));
	}

	else if (type == "R")
	{
		m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Cyan));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()), false, sf::Color::Cyan));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2)), false, sf::Color::Cyan));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2)), false, sf::Color::Cyan));
	}

	else if (type == "Z")
	{
		m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Red));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), false, sf::Color::Red));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()), false, sf::Color::Red));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight()), false, sf::Color::Red));
	}

	else if (type == "S")
	{
		m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Green));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y), false, sf::Color::Green));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + Tile::GetHeight()), false, sf::Color::Green));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight()), false, sf::Color::Green));
	}

	else if (type == "Line")
	{
		m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Blue));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), false, sf::Color::Blue));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y), false, sf::Color::Blue));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 3), m_position.y), false, sf::Color::Blue));
	}

	else if (type == "Square")
	{
		m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Magenta));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), false, sf::Color::Magenta));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()), false, sf::Color::Magenta));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()), false, sf::Color::Magenta));
	}

	else if (type == "T")
	{
		m_shapeTiles.push_back(new Tile(m_position, false, sf::Color(220, 142, 65, 255)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), false, sf::Color(220, 142, 65, 255)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y), false, sf::Color(220, 142, 65, 255)));
		m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()), false, sf::Color(220, 142, 65, 255)));
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
