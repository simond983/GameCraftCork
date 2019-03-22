#ifndef TILE_H
#define TILE_H

#include "SFML\Graphics.hpp"
#include <iostream>

class Tile
{
public:
	Tile(sf::Vector2f position);
	~Tile();

	void update(sf::Int32 dt);
	void render(sf::RenderWindow& window);

private:
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	bool m_falling;

	const int WIDTH = 30;
	const int HEIGHT = 30;
};
#endif // !TILE_H
