#pragma once
#include <SFML/Graphics.hpp>
#include "PlayingField.h"
#include "Platform.h"
#include "Ball.h"
#include "LVL.h"
#include "ObstaclesArray.h"
#include "GameStatus.h"


class DoubleManager {
private:
	Ball* bal;//Шар
	PlayingField* field;//Поле
	Platform* OnePlatform;//Платформа 1
	Platform* TwoPlatform;//Платформа 2
	ObstaclesArray* obss;//враги
	GameStatus* status;//Статус
	LVL lvl;//Уровень

	int lvl_number;
	bool pause;
	bool win;
	bool looz;

public:
	DoubleManager(int com);
	~DoubleManager();
	void Move(float time);
	void Draw(RenderWindow* window);
	void OneMoveGoLeft(float time);
	void OneMoveGoRight(float time);
	void TwoMoveGoLeft(float time);
	void TwoMoveGoRight(float time);
	void Pause();
};

