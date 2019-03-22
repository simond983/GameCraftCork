#ifndef TILE_H
#define TILE_H

#include "SFML\Graphics.hpp"

class Tile
{
public:
	Tile();
	~Tile();

	void update();
	void render(sf::RenderWindow& window);

private:
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	bool falling;

	const int WIDTH = 30;
	const int HEIGHT = 30;
};
#endif // !TILE_H
