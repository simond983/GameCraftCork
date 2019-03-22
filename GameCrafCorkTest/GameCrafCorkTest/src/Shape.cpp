#include "Shape.h"

///<summary>
///
///</summary>
Shape::Shape()
{
}

///<summary>
///
///</summary>
Shape::Shape(std::string type, sf::Vector2f pos) : 
	m_type(type),
	m_position(pos)	
{
	getShape();
}

///<summary>
///
///</summary>
Shape::~Shape()
{
}

///<summary>
/// Updates the shape.
///</summary>
void Shape::update(sf::Int32 dt)
{
	for (int i = 0; i < NUM_TILES; i++)
	{
		m_shapeTiles.at(i)->update(dt);
	}
}

///<summary>
/// Renders the shape.
///</summary>
void Shape::render(sf::RenderWindow &window)
{
	for (Tile* tile : m_shapeTiles)
	{
		tile->render(window);
	}
}

///<summary>
/// Gets all the tiles in the shape vector.
///</summary>
std::vector<Tile*> Shape::getShapeTiles()
{
	return m_shapeTiles;
}

///<summary>
/// Sets the position of each tile.
///</summary>
void Shape::setPosition(sf::Vector2f position)
{
	m_position = position;

	if (m_type == "L")
	{
		setLPosition();
	}
	else if (m_type == "R")
	{
		setRPosition();
	}
	else if (m_type == "Z")
	{
		setZPosition();
	}
	else if (m_type == "S")
	{
		setSPosition();
	}
	else if (m_type == "Line")
	{
		setIPosition();
	}
	else if (m_type == "Square")
	{
		setSquarePosition();
	}
	else if (m_type == "T")
	{
		setTPosition();
	}
}

///<summary>
/// Sets if each tile is falling or not.
///</summary>
void Shape::setFalling(bool falling)
{
	for (Tile* tile : m_shapeTiles)
	{
		tile->setFalling(falling);
	}
}

///<summary>
/// Makes a shape based on the current type.
///</summary>
void Shape::getShape()
{
	m_shapeTiles.clear();
	if (m_type == "L")
	{
		getL();
	}
	else if (m_type == "R")
	{
		getR();
	}
	else if (m_type == "Z")
	{
		getZ();
	}
	else if (m_type == "S")
	{
		getS();
	}
	else if (m_type == "Line")
	{
		getI();
	}
	else if (m_type == "Square")
	{
		getSquare();
	}
	else if (m_type == "T")
	{
		getT();
	}
}

///<summary>
/// Makes a L shaped tetris piece.
///</summary>
void Shape::getL()
{
	m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Yellow));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()), false, sf::Color::Yellow));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2)), false, sf::Color::Yellow));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2)), false, sf::Color::Yellow));
}

///<summary>
/// Makes a R shaped Tetris piece.
///</summary>
void Shape::getR()
{
	m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Cyan));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()), false, sf::Color::Cyan));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2)), false, sf::Color::Cyan));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2)), false, sf::Color::Cyan));
}

///<summary>
/// Makes a Z shaped tetris piece.
///</summary>
void Shape::getZ()
{
	m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Red));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), false, sf::Color::Red));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()), false, sf::Color::Red));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight()), false, sf::Color::Red));
}

///<summary>
/// Makes a S shaped tetris piece.
///</summary>
void Shape::getS()
{
	m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Green));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y), false, sf::Color::Green));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + Tile::GetHeight()), false, sf::Color::Green));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight()), false, sf::Color::Green));
}

///<summary>
/// Makes a Square shaped tetris piece.
///</summary>
void Shape::getSquare()
{
	m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Magenta));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), false, sf::Color::Magenta));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()), false, sf::Color::Magenta));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()), false, sf::Color::Magenta));
}

///<summary>
/// Makes a | shaped tetris piece.
///</summary>
void Shape::getI()
{
	m_shapeTiles.push_back(new Tile(m_position, false, sf::Color::Blue));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), false, sf::Color::Blue));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y), false, sf::Color::Blue));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 3), m_position.y), false, sf::Color::Blue));
}

///<summary>
///	Makes a T shaped tetris piece.
///</summary>
void Shape::getT()
{
	m_shapeTiles.push_back(new Tile(m_position, false, sf::Color(220, 142, 65, 255)));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), false, sf::Color(220, 142, 65, 255)));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y), false, sf::Color(220, 142, 65, 255)));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()), false, sf::Color(220, 142, 65, 255)));
}

///<summary>
///	
///</summary>
void Shape::setLPosition()
{
	m_shapeTiles[0]->setPosition(m_position);
	m_shapeTiles[1]->setPosition(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()));
	m_shapeTiles[2]->setPosition(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2)));
	m_shapeTiles[3]->setPosition(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2)));
}

///<summary>
///	
///</summary>
void Shape::setRPosition()
{
	m_shapeTiles[0]->setPosition(m_position);
	m_shapeTiles[1]->setPosition(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()));
	m_shapeTiles[2]->setPosition(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2)));
	m_shapeTiles[3]->setPosition(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2)));
}

///<summary>
///	
///</summary>
void Shape::setZPosition()
{
	m_shapeTiles[0]->setPosition(m_position);
	m_shapeTiles[1]->setPosition(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y));
	m_shapeTiles[2]->setPosition(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()));
	m_shapeTiles[3]->setPosition(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight()));
}

///<summary>
///	
///</summary>
void Shape::setSPosition()
{
	m_shapeTiles[0]->setPosition(m_position);
	m_shapeTiles[1]->setPosition(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y));
	m_shapeTiles[2]->setPosition(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + Tile::GetHeight()));
	m_shapeTiles[3]->setPosition(sf::Vector2f(m_position.x - (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight()));
}

///<summary>
///	
///</summary>
void Shape::setSquarePosition()
{
	m_shapeTiles[0]->setPosition(m_position);
	m_shapeTiles[1]->setPosition(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y));
	m_shapeTiles[2]->setPosition(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()));
	m_shapeTiles[3]->setPosition(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()));
}

///<summary>
///	
///</summary>
void Shape::setIPosition()
{
	m_shapeTiles[0]->setPosition(m_position);
	m_shapeTiles[1]->setPosition(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y));
	m_shapeTiles[2]->setPosition(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y));
	m_shapeTiles[3]->setPosition(sf::Vector2f(m_position.x + (Tile::GetWidth() * 3), m_position.y));
}

///<summary>
///	
///</summary>
void Shape::setTPosition()
{
	m_shapeTiles[0]->setPosition(m_position);
	m_shapeTiles[1]->setPosition(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y));
	m_shapeTiles[2]->setPosition(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y));
	m_shapeTiles[3]->setPosition(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()));
}
