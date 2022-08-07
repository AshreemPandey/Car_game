#include"render.h"

int main()
{
	render game;
	sf::RenderWindow app(sf::VideoMode(1050,768), "Car Game");
	app.setFramerateLimit(60);
	sf::Clock clock;
	while (app.isOpen())
	{
		sf::Event e;
		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				app.close();
			}
		}
		app.clear();
		game.updateBG(clock);
		game.drawBG(app);
		app.display();
	}
	return 0;
}