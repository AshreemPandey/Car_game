#include<SFML/Graphics.hpp>
#include<iostream>

int height = 768;
int width = 1050;
float sElapsedTime;

void drawBG(sf::RenderWindow& w,sf::Clock &clock)
{ 

	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(8, 8));
	float fCarPos = 0.0f;
	float middlePoint = 0.5f;
	float fDistance = 0.0f;
	float fElapsedTime = 0.0f;
	for (int y = 0; y < height / 2; y++)
	{
		for (int x = 0; x < width; x++)
		{
			float fperspective = y / (height / 2.0f);
			float roadW =0.1f + fperspective*0.8f;
			float clipW = 0.15 * roadW;
			roadW *= 0.5;
			float LGrass = (middlePoint - roadW - clipW) * width;
			float RGrass = (middlePoint + roadW + clipW) * width;
			float RClip = (middlePoint + roadW) * width;
			float LClip = (middlePoint - roadW) * width;
			rect.setPosition(x, y + height / 2);
			if (x > 0 && x < LGrass)
			{
				rect.setFillColor(sf::Color::Green);
				w.draw(rect);
			}
			else if (x > LGrass && x < LClip)
			{
				rect.setFillColor(sf::Color::Red);
				w.draw(rect);
			}
			else if (x > LClip && x < RClip)
			{
				rect.setFillColor(sf::Color(105,105,105));
				w.draw(rect);
			}
			else if (x > RClip && x < RGrass)
			{
				rect.setFillColor(sf::Color::Red);
				w.draw(rect);
			}
			else if (x > RGrass && x < width)
			{
				rect.setFillColor(sf::Color::Green);
				w.draw(rect);
			}
		}
	}
	sf::Texture bg;
	bg.loadFromFile("images/bg.png");
	bg.setRepeated(true);
	sf::Sprite sBackground(bg);
	sBackground.setTextureRect(sf::IntRect(0, 0, 5000, 411));
	sBackground.setPosition(-2000,0);
	w.draw(sBackground);
	sf::Texture Car;
    Car.loadFromFile("images/car.png");
    sf::Sprite sCar(Car);
    sCar.setTextureRect(sf::IntRect(0, 0, 500, 500));
    sCar.setPosition(width/2+(fCarPos*width)/2-300, height / 2+80);
	w.draw(sCar);
	sElapsedTime= clock.getElapsedTime().asSeconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		fDistance += sElapsedTime * 10.0f;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		fDistance += sElapsedTime * 2.0f;
	}
	else
	{
		fDistance += sElapsedTime * 4.0f;
	}
}

int main()
{
	sf::RenderWindow app(sf::VideoMode(width, height), "Car Game");
	app.setFramerateLimit(80);
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
		drawBG(app,clock);
		app.display();
	}
	return 0;
}
