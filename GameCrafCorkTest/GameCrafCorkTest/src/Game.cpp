#include "Game.h"

/// <summary>
/// Default constructor for the class.
/// </summary>
Game::Game() :
	m_window(sf::VideoMode(600, 600), "GameCraft2019", sf::Style::Default),
	m_test(sf::Vector2f())
{
	srand(time(0));
}



/// <summary>
/// Deconstructor for the class.
/// </summary>
Game::~Game()
{
}



/// <summary>
/// Update loop for the game.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	timeSinceLastUpdate = clock.restart();

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}

		timeSinceLastUpdate += clock.restart();
		if (timeSinceLastUpdate > timePerFrame)
		{
			update(timeSinceLastUpdate.asMilliseconds());
			timeSinceLastUpdate = sf::Time::Zero;
		}

		render();
	}
}



/// <summary>
/// Updates game entities.
/// </summary>
void Game::update(sf::Int32 dt)
{
	m_test.update(dt);
}



/// <summary>
/// Renders game entities.
/// </summary>
void Game::render()
{
	m_window.clear();

	m_test.render(m_window);

	m_window.display();
}
