#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

void ModeMenuShow(RenderWindow& window, int& com, int& player) {
	Texture MenuTextureEsy, MenuTextureNormal, MenuTextureHard, menuBackground, MenuTexturePlayer1, MenuTexturePlayer2, MenuTextureGo;
	Sprite Esy, Normal, Hard, Single, Two, about, menuBg, go;
	bool isMenu = 1;
	int menuNum = 0;

	MenuTextureEsy.loadFromFile("images/Easy.png");
	MenuTextureNormal.loadFromFile("images/Normal.png");
	MenuTextureHard.loadFromFile("images/Hard.png");
	MenuTexturePlayer1.loadFromFile("images/Single.png");
	MenuTexturePlayer2.loadFromFile("images/Multiplayer.png");
	MenuTextureGo.loadFromFile("images/Go.png");
	menuBackground.loadFromFile("images/FonDifficult.png");

	Esy.setTexture(MenuTextureEsy);
	Normal.setTexture(MenuTextureNormal);
	Hard.setTexture(MenuTextureHard);
	Single.setTexture(MenuTexturePlayer1);
	Two.setTexture(MenuTexturePlayer2);
	go.setTexture(MenuTextureGo);

	menuBg.setTexture(menuBackground);
		
	Esy.setPosition(427, 350);
	Normal.setPosition(400, 425);
	Hard.setPosition(427, 500);
	Single.setPosition(34, 575);
	Two.setPosition(612, 570);
	menuBg.setPosition(0, 0);
	go.setPosition(345, 789);

	while (isMenu)
	{
		//Заглушка//
		sf::Event event;
		while (window.pollEvent(event)) {}
		///////////

		if (com == 1) { Esy.setColor(Color::Green); Normal.setColor(Color::White); Hard.setColor(Color::White); com = 1; }
		if (com == 2) { Esy.setColor(Color::White); Normal.setColor(Color(186, 52, 135)); Hard.setColor(Color::White); com = 2; }
		if (com == 3) { Esy.setColor(Color::White); Normal.setColor(Color::White); Hard.setColor(Color::Red); com = 3; }
		if (player == 1) { Single.setColor(Color(196, 0, 171)); Two.setColor(Color::White); player = 1; }
		if (player == 2) { Two.setColor(Color(196, 0, 171)); Single.setColor(Color::White); player = 2; }
		if(com == 0){ Esy.setColor(Color::White); Normal.setColor(Color::White); Hard.setColor(Color::White);}
		if(player == 0) { Single.setColor(Color::White); Two.setColor(Color::White);}

		go.setColor(Color::White);
		menuNum = 0;

		if (IntRect(427, 350, 102, 28).contains(Mouse::getPosition(window))) { Esy.setColor(Color(43, 224, 108)); menuNum = 1; }
		if (IntRect(400, 425, 161, 28).contains(Mouse::getPosition(window))) { Normal.setColor(Color(43, 224, 108));   menuNum = 2; }
		if (IntRect(427, 500, 107, 29).contains(Mouse::getPosition(window))) { Hard.setColor(Color(43, 224, 108));  menuNum = 3; }
		if (IntRect(34, 575, 317, 178).contains(Mouse::getPosition(window))) { Single.setColor(Color(43, 224, 108)); menuNum = 4; }
		if (IntRect(612, 570, 310, 186).contains(Mouse::getPosition(window))) { Two.setColor(Color(43, 224, 108)); menuNum = 5;  }
		if (IntRect(345, 789, 273, 184).contains(Mouse::getPosition(window))) { go.setColor(Color(43, 224, 108)); menuNum = 6; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { com = 1; }
			if (menuNum == 2) { com = 2; }
			if (menuNum == 3) { com = 3; }
			if (menuNum == 4) { player = 1; }
			if (menuNum == 5) { player = 2; }

			if (menuNum == 6) {
				go.setColor(Color::Red);  
				if (com != 0 && player != 0) {
					isMenu = false;
				}
			}
		}

		window.draw(menuBg);
		window.draw(Esy);
		window.draw(Normal);
		window.draw(Hard);
		window.draw(Single);
		window.draw(Two);
		window.draw(go);

		window.display();
	}

};