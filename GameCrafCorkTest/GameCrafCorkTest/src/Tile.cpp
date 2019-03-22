#include "Tile.h"

//
Tile::Tile(sf::Vector2f position) : m_position(position)
{
	if (!m_texture.loadFromFile("..//GameCrafCorkTest//assets//LegoBlock.png"))
	{
		std::cout << "Texture failed to load." << std::endl;
	}

	m_sprite.setTexture(m_texture);	
	m_sprite.setPosition(m_position);

	m_fallDelay = 1000;
	m_fallTimer = 0;
	m_falling = true;
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

		m_fallTimer += dt;

		if (m_fallTimer > m_fallDelay)
		{
			m_position.y += HEIGHT;
			m_fallTimer = 0;
		}

		
	}

	m_sprite.setPosition(m_position);

}

//
void Tile::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

int Tile::GetWidth()
{
	return WIDTH;
}

int Tile::GetHeight()
{
	return HEIGHT;
}
