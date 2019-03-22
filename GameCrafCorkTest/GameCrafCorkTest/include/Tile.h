#ifndef TILE_H
#define TILE_H

#include "SFML\Graphics.hpp"
#include <iostream>

class Tile
{
public:
	Tile(sf::Vector2f position, sf::Color color);
	Tile();
	~Tile();

	void update(sf::Int32 dt);
	void render(sf::RenderWindow& window);

	static int GetWidth();
	static int GetHeight();

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);
	sf::Sprite getSprite();

private:
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	static const int WIDTH = 30;
	static const int HEIGHT = 30;
};
#endif // !TILE_H
