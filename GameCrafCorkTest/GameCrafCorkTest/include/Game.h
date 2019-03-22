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
private:
	void update(sf::Int32 dt);
	void render();

	sf::RenderWindow m_window;

	std::vector<Tile*> m_tiles;

	const int m_rows = 20;
	const int m_columns = 20;
};
#endif // !GAME_H