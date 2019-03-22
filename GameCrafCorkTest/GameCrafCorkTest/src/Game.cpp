#include "Game.h"

/// <summary>
/// Default constructor for the class.
/// </summary>

Game::Game() : m_window(sf::VideoMode(600, 600), "GameCraft2019", sf::Style::Default) {

	srand(time(0));


	for (int i = 0; i < m_columns; i++) {
		m_tiles.push_back(new Tile(sf::Vector2f(0, 30 * i), sf::Color::Magenta));
	}

	for (int i = 1; i < 12; i++) {
		m_tiles.push_back(new Tile(sf::Vector2f(30 * i, 30 * 19), sf::Color::Magenta));
	}

	for (int i = 18; i >= 0; i--) {
		m_tiles.push_back(new Tile(sf::Vector2f(11 * 30, i * 30), sf::Color::Magenta));
	}
	
	m_shapeManager = new ShapeManager();

	m_frameTexture.loadFromFile("assets/Frame.png");

	m_scoreSprite.setTexture(&m_frameTexture);
	m_levelSprite.setTexture(&m_frameTexture);
	m_nextSprite.setTexture(&m_frameTexture);

	m_scoreSprite.setSize(sf::Vector2f(250.0f, 150.0f));
	m_levelSprite.setSize(sf::Vector2f(250.0f, 150.0f));
	m_nextSprite.setSize(sf::Vector2f(250.0f, 190.0f));

	m_scoreSprite.setPosition(sf::Vector2f(350,75));
	m_levelSprite.setPosition(sf::Vector2f(350, 250));
	m_nextSprite.setPosition(sf::Vector2f(350, 425));

	m_font.loadFromFile("arial.ttf");

	std::string level = "Level: " + std::to_string(m_level);
	std::string score = "Score: " + std::to_string(m_score);

	setUpText(m_scoreText, sf::Vector2f(375, 125), score);
	setUpText(m_levelText, sf::Vector2f(375, 300), level);
	setUpText(m_nextBlockText, sf::Vector2f(400, 400), "Next Block: ");

	m_currentShape = generateShape(sf::Vector2f(120.0f, 30.0f));
	m_nextShape = generateShape(sf::Vector2f(450.0f, 475.0f));


	m_shapeManager->addShape(*m_currentShape);
}

void Game::setUpText(sf::Text& text, sf::Vector2f pos, std::string string) {
	text.setFont(m_font);

	text.setCharacterSize(32.0f);

	text.setPosition(pos);

	text.setString(string);
}

void Game::nextShape() {
	m_nextShape->setPosition(sf::Vector2f(120.0f, 30.0f));
	m_shapeManager->addShape(*m_nextShape);

	m_nextShape = generateShape(sf::Vector2f(450.0f, 475.0f));
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

	m_shapeManager->update(dt);
	//for (Tile * t : m_tiles) {
	//	t->update(dt);
	
}



/// <summary>
/// Renders game entities.
/// </summary>
void Game::render()
{
	m_window.clear();

	for (Tile * t : m_tiles) {
		t->render(m_window);
	}

	m_nextShape->render(m_window);

	m_shapeManager->render(m_window);

	m_window.draw(m_scoreSprite);
	m_window.draw(m_levelSprite);
	m_window.draw(m_nextSprite);

	m_window.draw(m_scoreText);
	m_window.draw(m_levelText);
	m_window.draw(m_nextBlockText);

	m_window.display();
}


Shape* Game::generateShape(sf::Vector2f position)
{

	Shape *shape = new Shape();

	int num = rand() % 7 + 1;
	
	if (num == 1) {
		shape = new Shape("L", position);
	}
	if (num == 2) {
		shape = new Shape("R", position);
	}
	if (num == 3) {
		shape = new Shape("Z", position);
	}
	if (num == 4) {
		shape = new Shape("S", position);
	}
	if (num == 5) {
		shape = new Shape("Line", position);
	}
	if (num == 6) {
		shape = new Shape("Square", position);
	}
	if (num == 7) {
		shape = new Shape("T", position);
	}
	return shape;
}

