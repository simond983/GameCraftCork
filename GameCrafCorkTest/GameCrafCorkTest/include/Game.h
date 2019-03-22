#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

#include "Tile.h"

class Game
{
public:
	Game();
	~Game();
	void run();

	void setUpText(sf::Text &text, sf::Vector2f pos, std::string string);
private:
	void update(sf::Int32 dt);
	void render();

	sf::RenderWindow m_window;

	std::vector<Tile*> m_tiles;

	const int m_rows = 20;
	const int m_columns = 20;

	sf::Texture m_frameTexture;

	sf::RectangleShape m_scoreSprite;
	sf::RectangleShape m_levelSprite;
	sf::RectangleShape m_nextSprite;

	sf::Font m_font;
	sf::Text m_scoreText;
	sf::Text m_levelText;
	sf::Text m_nextBlockText;
};
#endif // !GAME_H