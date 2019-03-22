#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

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

	Tile m_test;
};
#endif // !GAME_H