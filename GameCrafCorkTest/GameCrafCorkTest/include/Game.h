#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

#include "Tile.h"
#include "Shape.h"
#include "ShapeManager.h"

class Game
{
public:
	Game();
	~Game();
	void run();
	Shape* generateShape(sf::Vector2f position);
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


	Shape* m_currentShape;
	Shape* m_nextShape;

	Shape* m_shapeManager;

	int m_level = 0;
	int m_score = 0;
};
#endif // !GAME_H