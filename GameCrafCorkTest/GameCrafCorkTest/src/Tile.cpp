#include "Tile.h"

//
Tile::Tile(sf::Vector2f position, bool falling, sf::Color color) : m_position(position), m_falling(falling)
{
	if (!m_texture.loadFromFile("..//GameCrafCorkTest//assets//LegoBlock.png"))
	{
		std::cout << "Texture failed to load." << std::endl;
	}

	m_sprite.setTexture(m_texture);	
	m_sprite.setPosition(position);
	m_sprite.setColor(color);

	m_falling = false;
}

Tile::Tile()
{
}

//
Tile::~Tile()
{
}

//
void Tile::update(sf::Int32 dt)
{
	if (m_falling)
	{

	}
	else
	{

	}
}

//
void Tile::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}
