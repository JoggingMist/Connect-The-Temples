#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Game.h"

using namespace sf;

int Game() {
	int gameWidth = 800;
	int gameHeight = 600;
	String gameName = "Connect-The-Temple";
	int gameSSyle = Style::Fullscreen;
	RenderWindow window(VideoMode(gameWidth, gameHeight), gameName, gameSSyle);

	// Load the sounds used in the game
	sf::SoundBuffer ballSoundBuffer;
	if (!ballSoundBuffer.loadFromFile("resources/ball.wav"))
		return EXIT_FAILURE;
	sf::Sound ballSound(ballSoundBuffer);

	// Load the text font
	sf::Font font;
	if (!font.loadFromFile("resources/sansation.ttf"))
		return EXIT_FAILURE;

	// Initialize the pause message
	sf::Text pauseMessage;
	pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(40);
	pauseMessage.setPosition(170.f, 150.f);
	pauseMessage.setFillColor(sf::Color::White);
	pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");

	window.setVerticalSyncEnabled(true);
	while (window.isOpen())
	{
		// handle event
		Event event;
		while (window.pollEvent(event))
		{
			// Window closed or escape key pressed: exit
			if ((event.type == Event::Closed) ||
				((event.type == Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}