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
	Ball* bal;//���
	PlayingField* field;//����
	Platform* OnePlatform;//��������� 1
	Platform* TwoPlatform;//��������� 2
	ObstaclesArray* obss;//�����
	GameStatus* status;//������
	LVL lvl;//�������

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

