#include "Game.h"

/// <summary>
/// Default constructor for the class.
/// </summary>
Game::Game() : m_window(sf::VideoMode(600, 600), "GameCraft2019", sf::Style::Default) {

	srand(time(0));

	for (int i = 0; i < m_columns; i++) {
		m_tiles.push_back(new Tile(sf::Vector2f(0, 30 * i), false, sf::Color::Magenta));
	}

	for (int i = 1; i < 12; i++) {
		m_tiles.push_back(new Tile(sf::Vector2f(30 * i, 30 * 19), false, sf::Color::Magenta));
	}

	for (int i = 18; i >= 0; i--) {
		m_tiles.push_back(new Tile(sf::Vector2f(11 * 30, i * 30), false, sf::Color::Magenta));
	}

	m_scoreSprite.setTexture(&m_scoreTexture);
	m_levelSprite.setTexture(&m_levelTexture);

	m_scoreSprite.setPosition(sf::Vector2f(0,0));
	m_levelSprite.setPosition(sf::Vector2f(0, 0));

	m_font.loadFromFile("arial.ttf");
	setUpText(m_scoreText, sf::Vector2f(400, 100), "Score: ");
	setUpText(m_levelText, sf::Vector2f(400, 250), "Level: ");
	setUpText(m_nextBlockText, sf::Vector2f(400, 400), "Next Block: ");
}

void Game::setUpText(sf::Text& text, sf::Vector2f pos, std::string string) {
	text.setFont(m_font);

	text.setCharacterSize(32.0f);

	text.setPosition(pos);

	text.setString(string);
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
	for (Tile * t : m_tiles) {
		t->update(dt);
	}
}



/// <summary>
/// Renders game entities.
/// </summary>
void Game::render()
{
	m_window.clear();

	//m_test.render(m_window);

	for (Tile * t : m_tiles) {
		t->render(m_window);
	}

	m_window.draw(m_scoreSprite);
	m_window.draw(m_levelSprite);

	m_window.draw(m_scoreText);
	m_window.draw(m_levelText);
	m_window.draw(m_nextBlockText);

	m_window.display();
}
