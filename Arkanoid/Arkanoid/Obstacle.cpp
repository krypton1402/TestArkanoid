#include "Obstacle.h"

Obstacle::Obstacle(float xLeft, float yTop, float xRight, float yBottom, int live, int com) {
	obs_image.loadFromFile("images/Enemy3.png");//загружаем файл для поля
	obs_image.createMaskFromColor(Color(255, 255, 255));
	obs.loadFromImage(obs_image);//заряжаем текстуру картинкой
	s_obs.setTexture(obs);//заливаем текстуру спрайтом
	
	this->xLeft = xLeft;
	this->xRight = xRight;
	this->yTop = yTop;
	this->yBottom = yBottom;
	this->live = live;
	this->V_Y = (0.0008 * com);

	Ytikstur = (54 * live) - 54;
	CurientTime = 0;

	s_obs.setTextureRect(IntRect(0, Ytikstur, 54, 54));
}
Obstacle::~Obstacle() {
	
}

void Obstacle::Draw(RenderWindow* window) {
	window->draw(s_obs);
}

void Obstacle::Move(float time) {
	CurientTime += 0.005 * time;
	if (CurientTime > 3) CurientTime -= 3;
	s_obs.setTextureRect(IntRect(54 * (int)CurientTime, Ytikstur, 54, 54));

	float dy = V_Y * time;
	this->yTop += dy;
	this->yBottom += dy;

	s_obs.setPosition(xLeft, yTop);
}

void Obstacle::LiveDown() {
	this->live--;
}


