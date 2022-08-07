#include "render.h"

void render::drawBG(sf::RenderWindow& w)
{
	clipW = 0.15 * roadW;
	rect.setSize(sf::Vector2f(8, 8));
	bg.loadFromFile("images/bg.png");
	bg.setRepeated(true);
	sf::Sprite sBackground(bg);
	sBackground.setTextureRect(sf::IntRect(0, 0, 5000, 411));
	sBackground.setPosition(-2000, 0);
	w.draw(sBackground);
	

	for (int y = 0; y < height / 2; y++)
	{
		sf::Color grassColor =sinf(30.0f*powf(1-fperspective,3)+0.1f*fDistance)>0?sf::Color::Green:sf::Color(0,100,0);
		sf::Color clipColor= sinf(80.0f * powf(1 - fperspective, 2)+0.1f*fDistance)>0?sf::Color::White:sf::Color::Black;
		for (int x = 0; x < width; x++)
		{
			fperspective = y / (height / 2.0f);
			roadW = 0.1f + fperspective * 0.8f;
			clipW = 0.15 * roadW;
			roadW *= 0.5;
			LGrass = (fMiddlePoint - roadW - clipW) * width;
			RGrass = (fMiddlePoint + roadW + clipW) * width;
			RClip = (fMiddlePoint + roadW) * width;
			LClip = (fMiddlePoint - roadW) * width;
			rect.setPosition(x, y + height / 2);
			if (x > 0 && x < LGrass)
			{
					rect.setFillColor(grassColor);
					w.draw(rect);
			}
			else if (x > LGrass && x < LClip)
			{
				rect.setFillColor(clipColor);
				w.draw(rect);
				
			}
			else if (x > LClip && x < RClip)
			{
				rect.setFillColor(sf::Color(105, 105, 105));
				w.draw(rect);
			}
			else if (x > RClip && x < RGrass)
			{
				rect.setFillColor(clipColor);
				w.draw(rect);
			}
			else if (x > RGrass && x < width)
			{
				rect.setFillColor(grassColor);
				w.draw(rect);
			}
		}
	}
	Car.loadFromFile("images/car.png");
	sf::Sprite sCar(Car);
	sCar.setTextureRect(sf::IntRect(0, 0, 500, 500));
	sCar.setPosition(width / 2 + (fCarPos * width) / 2 - 300, height / 2 + 80);
	w.draw(sCar);
}

void render::updateBG(sf::Clock clock)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		fElapsed = clock.getElapsedTime().asSeconds();
		fDistance = 10*fElapsed;
		std::cout << fElapsed << std::endl;
	}
}