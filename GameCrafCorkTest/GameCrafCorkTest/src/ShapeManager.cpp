#include "ShapeManager.h"

/// <summary>
/// 
/// </summary>
ShapeManager::ShapeManager() :
	m_controlA(true),
	m_controlE(true),
	m_controlS(true),
	m_controlD(true),
	m_controlQ(true),
	m_controlW(true)
{
	m_leftBound = sf::RectangleShape(sf::Vector2f(30, 600));
	m_rightBound = sf::RectangleShape(sf::Vector2f(30, 600));
	m_bottomBound = sf::RectangleShape(sf::Vector2f(360, 30));
	
	m_leftBound.setPosition(0, 0);
	m_rightBound.setPosition(330, 0);
	m_bottomBound.setPosition(0, 570);

	m_currentShape = generateShape(sf::Vector2f(120.0f, 30.0f));
	m_nextShape = generateShape(sf::Vector2f(450.0f, 475.0f));

	addShape(*m_currentShape);
}

/// <summary>
/// 
/// </summary>
ShapeManager::~ShapeManager()
{

}

/// <summary>
/// Update the current game objects shapes
/// </summary>
void ShapeManager::update(sf::Int32 dt)
{
	sf::Vector2f* tempPosition = new sf::Vector2f(m_shapeVector.back().getPosition());	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && m_controlA == true)
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x - Tile::GetWidth(), m_shapeVector.back().getPosition().y);
		m_controlA = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && m_controlD == true)
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x + Tile::GetWidth(), m_shapeVector.back().getPosition().y);
		m_controlD = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && m_controlS == true)
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x, m_shapeVector.back().getPosition().y + Tile::GetHeight());
		m_controlS = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && m_controlQ == true)
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x - Tile::GetWidth(), m_shapeVector.back().getPosition().y);
		m_controlQ = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) && m_controlE == true)
	{
		*tempPosition = sf::Vector2f(m_shapeVector.back().getPosition().x - Tile::GetWidth(), m_shapeVector.back().getPosition().y);
		m_controlE = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && m_controlW == true)
	{
		m_shapeVector.back().rotateShape();
		m_controlW = false;
	}

	 if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_controlA = true;
	}

	 if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_controlD = true;
	}

	 if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_controlS = true;
	}

	 if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		m_controlQ = true;
	}

	 if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
	{
		m_controlE = true;
	}
	
	 if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_controlW = true;
	}
	

	checkBounds(tempPosition);
	m_shapeVector.back().setPosition(*tempPosition);
	delete tempPosition;

	for (int i = 0; i < m_shapeVector.size(); i++)
	{
		m_shapeVector[i].update(dt);
	}
}

/// <summary>
/// 
/// </summary>
void ShapeManager::render(sf::RenderWindow &window)
{
	for (int i = 0; i < m_shapeVector.size(); i++)
	{
		m_shapeVector[i].render(window);
	}


	m_nextShape->render(window);
}

/// <summary>
/// 
/// </summary>
void ShapeManager::addShape(Shape &shape)
{
	m_shapeVector.push_back(shape);
}

/// <summary>
/// 
/// </summary>
std::vector<Shape> ShapeManager::getShapeVector()
{
	return m_shapeVector;
}

Shape * ShapeManager::generateShape(sf::Vector2f position)
{
	Shape *shape = new Shape();

	int num = rand() % 7 + 1;

	if (num == 1) {
		shape = new Shape("L", position);
	}
	if (num == 2) {
		shape = new Shape("R", position);
	}
	if (num == 3) {
		shape = new Shape("Z", position);
	}
	if (num == 4) {
		shape = new Shape("S", position);
	}
	if (num == 5) {
		shape = new Shape("Line", position);
	}
	if (num == 6) {
		shape = new Shape("Square", position);
	}
	if (num == 7) {
		shape = new Shape("T", position);
	}
	return shape;
}

/// <summary>
/// 
/// </summary>
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
		
		if (m_shapeVector.back().getShapeTiles().at(i)->getSprite().getGlobalBounds().intersects(m_bottomBound.getGlobalBounds()))
		{
			m_shapeVector.back().setFalling(false);
			nextShape();
			m_shapeVector.back().setPosition(sf::Vector2f(300, 0));
		}
	}
}

void ShapeManager::nextShape() {
	m_nextShape->setPosition(sf::Vector2f(120.0f, 30.0f));
	addShape(*m_nextShape);

	m_nextShape = generateShape(sf::Vector2f(450.0f, 475.0f));
}
