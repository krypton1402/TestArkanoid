#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

void LeadMenuShow(RenderWindow& window) {
	Texture menuTextureStart, menuTextureExit, menuBackground;
	Sprite Start, Exit, menuBg;
	bool isMenu = true;
	int menuNum = 0;

	menuTextureStart.loadFromFile("images/Start.png");
	menuTextureExit.loadFromFile("images/Exit.png");
	menuBackground.loadFromFile("images/Menu.jpg");

	Start.setTexture(menuTextureStart);
	Exit.setTexture(menuTextureExit);
	menuBg.setTexture(menuBackground);

	Start.setPosition(40, 350);
	Exit.setPosition(40, 500);
	menuBg.setPosition(0, 0);

	while (isMenu)
	{
		//Заглушка//
		sf::Event event;
		while (window.pollEvent(event)) { }
		///////////

		Start.setColor(Color::White);
		Exit.setColor(Color::White);
		menuNum = 0;
		
		if (IntRect(40, 350, 230, 100).contains(Mouse::getPosition(window))) { Start.setColor(Color(63, 224, 208)); menuNum = 1; }
		if (IntRect(40, 500, 220, 100).contains(Mouse::getPosition(window))) { Exit.setColor(Color(63, 224, 208)); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			if (menuNum == 3) { window.close(); isMenu = false; }
		}

		window.draw(menuBg);
		window.draw(Start);
		window.draw(Exit);

		window.display();
	};
};
