#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class render
{
	private:
		int height = 768;
		int width = 1050;
		float fperspective, roadW, clipW, LGrass, RGrass, RClip, LClip, fCarPos, fMiddlePoint;
		float grassColor, clipColor,fDistance,fElapsed;
		sf::RectangleShape rect;
		sf::Texture bg;
		sf::Texture Car;
	public:
		render()
		{
			fCarPos = 0.0f;
			fMiddlePoint = 0.5f;
			fElapsed = 0.0f;
			fDistance = 0.0f;
		}
		void drawBG(sf::RenderWindow& w);
		void updateBG(sf::Clock clock);
};

