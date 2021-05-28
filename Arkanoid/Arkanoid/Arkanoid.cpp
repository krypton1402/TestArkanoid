#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "OneManager.h"
#include "DoubleManager.h"
#include "LeadMenu.h"
#include "ModeMenu.h"
using namespace sf;

int main() {
	sf::RenderWindow window(sf::VideoMode(950, 900), "ARKANOID_1.2");//Создаем окно
	Music music;
	music.openFromFile("music.ogg");
	
	bool GamePlay;//проверка игры
	int com;//Уровень сложности
	int player;//Количество игроков
	OneManager* oneManager;
	DoubleManager* doubleManager;

	while (true)
	{
		music.setLoop(true);	
		music.play();

		com = 0;
		player = 0;

		LeadMenuShow(window);

		if (!window.isOpen())
			return 0;

		ModeMenuShow(window, com, player);
		GamePlay = true;

		Clock clock; //создаем переменную времени
		
		if (player == 1) {
			oneManager = new OneManager(com);

			while (GamePlay) {
				sf::Event event;
				while (window.pollEvent(event)) {}

				if (Keyboard::isKeyPressed(Keyboard::Space)) {
					oneManager->Pause();
				}

				if (Keyboard::isKeyPressed(Keyboard::Escape)) {
					GamePlay = false;
				}

				float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
				clock.restart(); //перезагружает время
				time = time / 800; //скорость игры

				//Движение///
				if (Keyboard::isKeyPressed(Keyboard::A)) {
					oneManager->MoveGoLeft(time);
				}

				if (Keyboard::isKeyPressed(Keyboard::D)) {
					oneManager->MoveGoRight(time);
				}
				/////////////

				oneManager->Move(time);

				//Отрисовка//
				window.clear();//Очистка

				oneManager->Draw(&window);

				window.display();//Отрисовка
				/////////////
			}
			delete oneManager;
		}


		else if (player == 2) {
			doubleManager = new DoubleManager(com);

			while (GamePlay) {
				sf::Event event;
				while (window.pollEvent(event)) {}

				if (Keyboard::isKeyPressed(Keyboard::Space)) {
					doubleManager->Pause();
				}

				if (Keyboard::isKeyPressed(Keyboard::Escape)) {
					GamePlay = false;
				}

				float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
				clock.restart(); //перезагружает время
				time = time / 800; //скорость игры

				//Движение///
				if (Keyboard::isKeyPressed(Keyboard::A)) {
					doubleManager->OneMoveGoLeft(time);
				}

				if (Keyboard::isKeyPressed(Keyboard::D)) {
					doubleManager->OneMoveGoRight(time);
				}

				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					doubleManager->TwoMoveGoLeft(time);
				}

				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					doubleManager->TwoMoveGoRight(time);
				}
				/////////////

				doubleManager->Move(time);

				//Отрисовка//
				window.clear();//Очистка

				doubleManager->Draw(&window);

				window.display();//Отрисовка
				/////////////
			}
			delete doubleManager;
		}

	}
}
