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
	m_falling = true;
	m_fallDelay = 1000;
	m_fallTimer = 0;
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

	if (m_falling)
	{
		m_fallTimer += dt;
		if (m_fallTimer > m_fallDelay)
		{
			m_position.y += Tile::GetHeight();
			setPosition(m_position);	//	Moves the individual

			m_fallTimer = 0;
		}
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
/// Rotates he current shape
///</summary>
void Shape::rotateShape()
{
	
	if (m_type != "Square")
	{
		rotate();
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
	m_shapeTiles.push_back(new Tile(m_position, sf::Color::Yellow, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()), sf::Color::Yellow, true));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2)), sf::Color::Yellow, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2)), sf::Color::Yellow, false));
}

///<summary>
/// Makes a R shaped Tetris piece.
///</summary>
void Shape::getR()
{
	m_shapeTiles.push_back(new Tile(m_position, sf::Color::Cyan, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()), sf::Color::Cyan, true));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + (Tile::GetHeight() * 2)), sf::Color::Cyan, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + (Tile::GetHeight() * 2)), sf::Color::Cyan, false));
}

///<summary>
/// Makes a Z shaped tetris piece.
///</summary>
void Shape::getZ()
{
	m_shapeTiles.push_back(new Tile(m_position, sf::Color::Red, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), sf::Color::Red, true));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()), sf::Color::Red, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight()), sf::Color::Red, false));
}

///<summary>
/// Makes a S shaped tetris piece.
///</summary>
void Shape::getS()
{
	m_shapeTiles.push_back(new Tile(m_position, sf::Color::Green, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y), sf::Color::Green, true));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - Tile::GetWidth(), m_position.y + Tile::GetHeight()), sf::Color::Green, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x - (Tile::GetWidth() * 2), m_position.y + Tile::GetHeight()), sf::Color::Green, false));
}

///<summary>
/// Makes a Square shaped tetris piece.
///</summary>
void Shape::getSquare()
{
	m_shapeTiles.push_back(new Tile(m_position, sf::Color::Magenta, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), sf::Color::Magenta, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x, m_position.y + Tile::GetHeight()), sf::Color::Magenta, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()), sf::Color::Magenta, false));
}

///<summary>
/// Makes a | shaped tetris piece.
///</summary>
void Shape::getI()
{
	m_shapeTiles.push_back(new Tile(m_position, sf::Color::Blue, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), sf::Color::Blue, true));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y), sf::Color::Blue, false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 3), m_position.y), sf::Color::Blue, false));
}

///<summary>
///	Makes a T shaped tetris piece.
///</summary>
void Shape::getT()
{
	m_shapeTiles.push_back(new Tile(m_position, sf::Color(220, 142, 65, 255), false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y), sf::Color(220, 142, 65, 255), true));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + (Tile::GetWidth() * 2), m_position.y), sf::Color(220, 142, 65, 255), false));
	m_shapeTiles.push_back(new Tile(sf::Vector2f(m_position.x + Tile::GetWidth(), m_position.y + Tile::GetHeight()), sf::Color(220, 142, 65, 255), false));
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

sf::Vector2f Shape::getPosition()
{
	return m_position;
}

void Shape::setFalling(bool falling)
{
	m_falling = falling;
}


///<summary>
///	
///</summary>
void Shape::rotate()
{
	sf::Vector2f rotatePos;
	for (Tile * t : m_shapeTiles) {
		if (t->is_rotate_piece) {
			rotatePos = sf::Vector2f(t->getSprite().getPosition().x + 15,t->getSprite().getPosition().y + 15);
		}
	}
	for (Tile * t : m_shapeTiles) {
		t->getSprite().setOrigin(rotatePos - t->getSprite().getPosition());
		std::cout << t->getSprite().getOrigin().x << ", " << t->getSprite().getOrigin().y << std::endl;
		
		t->getSprite().rotate(90);

		t->getSprite().setOrigin(sf::Vector2f(0, 0));
	}
}