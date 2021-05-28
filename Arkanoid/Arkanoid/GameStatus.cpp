#include "GameStatus.h"

GameStatus::GameStatus(int com) {
	status_image.loadFromFile("images/status.png");//загружаем файл для поля
	status.loadFromImage(status_image);//заряжаем текстуру картинкой
	s_status.setTexture(status);//заливаем текстуру спрайтом
	s_status.setTextureRect(IntRect(0, 0, 350, 900));
	s_status.setPosition(600, 0);

	front.loadFromFile("front.ttf");
	TLvl = new Text("", front, 30);
	Tcore = new Text("", front, 30);

	this->com = com;
	obs_count = 0;
	core = 0;
	lvl = 0;
	obs = nullptr;
	bal = nullptr;
}

GameStatus::~GameStatus() {
	delete TLvl;
	delete Tcore;
}

void GameStatus::Apdate(int lvl) {
	this->lvl = lvl;
	if (obs_count != obs->GetCount()) {
		core += (2 * com) - 1;
		obs_count = obs->GetCount();
	}
}

void GameStatus::Drow(RenderWindow* window) {
	std::ostringstream strLvl;
	strLvl << lvl;
	TLvl->setString(strLvl.str());
	TLvl->setPosition(840, 405);

	std::ostringstream strCore;
	strCore << core;
	Tcore->setString(strCore.str());
	Tcore->setPosition(840, 460);

	window->draw(s_status);
	window->draw(*TLvl);
	window->draw(*Tcore);
}

void GameStatus::GetObs(ObstaclesArray* obs) {
	this->obs = obs;
	obs_count = obs->GetCount();
}

void GameStatus::GetBal(Ball* bal) {
	this->bal = bal;
}

void GameStatus::Win() {
	s_status.setTextureRect(IntRect(700, 0, 350, 900));
}

void GameStatus::Dead() {
	s_status.setTextureRect(IntRect(350, 0, 350, 900));
}