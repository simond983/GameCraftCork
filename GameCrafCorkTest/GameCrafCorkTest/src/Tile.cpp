#include "Tile.h"

//
Tile::Tile(sf::Vector2f position)
{
	if (!m_texture.loadFromFile("..//GameCrafCorkTest//assets//LegoBlock.png"))
	{
		std::cout << "Texture failed to load." << std::endl;
	}

	m_sprite.setTexture(m_texture);	
	m_sprite.setPosition(m_position);

	m_falling = false;
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
