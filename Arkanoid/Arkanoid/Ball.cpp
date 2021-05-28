#include "Ball.h"

Ball::Ball(int com) {
	bal_image.loadFromFile("images/bol.png");//загружаем файл для поля
	bal_image.createMaskFromColor(Color(255, 255, 255));

	bal.loadFromImage(bal_image);//заряжаем текстуру картинкой
	s_bal.setTexture(bal);//заливаем текстуру спрайтом
	
	switch (com) {
	case(1):
		live = 4;
		break;
	case(2):
		live = 3;
		break;
	case(3):
		live = 2;
		break;
	};

	this->V_X = 0.1 + 0.03 * com;
	this->V_Y = 0.1 + 0.03 * com;
	this->r = 7;

	this->vx = V_X;
	this->vy = -V_Y;

	s_bal.setTextureRect(IntRect((14 * live) - 14, 0, 14, 14));

	x = y = 0;
	OnePlatform = nullptr;
	TwoPlatform = nullptr;
	field = nullptr;
	obsarr = nullptr;
}
Ball::~Ball() {
	
}


void Ball::Draw(RenderWindow* window) {
	window->draw(s_bal);
}

void Ball::Move(float time) {
	//реакция на границы
	if ((this->x >= field->GetXR() - 2 * r) && (this->vx > 0))
		this->vx = -(this->vx);
	if ((this->x <= field->GetXL()) && (this->vx < 0))
		this->vx = -(this->vx);
	if ((this->y >= field->GetYR() - 2 * r) && (this->vy > 0)) {
		this->vy = -(this->vy);
		if (live != 0) {
			this->live--;
			if (live != 0)
				s_bal.setTextureRect(IntRect((14 * live) - 14, 0, 14, 14));
		}
	}
	if ((this->y <= field->GetYL()) && (this->vy < 0))
		this->vy = -(this->vy);
	
	//реакция на платформу 1
	if ((OnePlatform->GetY_L() - y <= r * 2)) {
		if ((x + r * 2 >= OnePlatform->GetX_L()) && (x <= OnePlatform->GetX_L() + OnePlatform->GetSise()))
			if ((x + r * 2 >= OnePlatform->GetX_L()) && (x + r * 2 < OnePlatform->GetSise() / 4 + OnePlatform->GetX_L())) {
				vx = -(V_X + 0.035);
				vy = -(V_Y - 0.035);
			}
			else if ((x <= OnePlatform->GetX_R() && (x > OnePlatform->GetX_R() - OnePlatform->GetSise() / 4))) {
				vx = V_X + 0.035;
				vy = -(V_Y - 0.035);
			}
			else {
				if (vx > 0)
					vx = V_X;
				if (vx < 0)
					vx = -V_X;
				vy = -V_Y;
			}
	}

	//реакция на платформу 2
	if (TwoPlatform != nullptr) {
		if ((TwoPlatform->GetY_L() - y <= r * 2)) {
			if ((x + r * 2 >= TwoPlatform->GetX_L()) && (x <= TwoPlatform->GetX_L() + TwoPlatform->GetSise()))
				if ((x + r * 2 >= TwoPlatform->GetX_L()) && (x + r * 2 < TwoPlatform->GetSise() / 4 + TwoPlatform->GetX_L())) {
					vx = -(V_X + 0.035);
					vy = -(V_Y - 0.035);
				}
				else if ((x <= TwoPlatform->GetX_R() && (x > TwoPlatform->GetX_R() - TwoPlatform->GetSise() / 4))) {
					vx = V_X + 0.035;
					vy = -(V_Y - 0.035);
				}
				else {
					if (vx > 0)
						vx = V_X;
					if (vx < 0)
						vx = -V_X;
					vy = -V_Y;
				}
		}
	}
		
	//реакция на препятствия
	for (int i = 0; i < obsarr->Getmax(); i++) {
		if (obsarr->invalid[i] != 0) {
			//проверка на нижнюю границу
			if (y <= obsarr->obstacles[i]->Get_yBottom() + 1  && obsarr->obstacles[i]->Get_yBottom() - r  <= y) {
				if (x + r * 2 >= obsarr->obstacles[i]->Get_xLeft() + r && x <= obsarr->obstacles[i]->Get_xRight() - r) {//если по центру
					vy = -vy;
					obsarr->obstacles[i]->LiveDown();
				}
				else if (x + r * 2 >= obsarr->obstacles[i]->Get_xLeft()  && x + r * 2 <= obsarr->obstacles[i]->Get_xLeft() + r) {//если с левого края
					if (vx > 0 && vy < 0) {
						vx = -vx;
						vy = -vy;
						obsarr->obstacles[i]->LiveDown();
					}
					else if (vx < 0 && vy < 0) {
						vy = -vy;
						obsarr->obstacles[i]->LiveDown();
					}
					else if (vx > 0 && vy > 0) {
						vx = -vx;
						obsarr->obstacles[i]->LiveDown();
					}
				}
				else if (x <= obsarr->obstacles[i]->Get_xRight()  && x >= obsarr->obstacles[i]->Get_xRight() - r) {//если с прового края
					if (vx > 0 && vy < 0) {
						vy = -vy;
						obsarr->obstacles[i]->LiveDown();
					}
					else if (vx < 0 && vy < 0) {
						vy = -vy;
						vx = -vx;
						obsarr->obstacles[i]->LiveDown();
					}
					else if (vx < 0 && vy > 0) {
						vx = -vx;
						obsarr->obstacles[i]->LiveDown();
					}
				}
			}
			//проверка на верхнюю границу
			else if (y + r * 2 >= obsarr->obstacles[i]->Get_yTop() - 1  && y + r * 2 <= obsarr->obstacles[i]->Get_yTop() + r) {
				 if (x + r * 2 >= obsarr->obstacles[i]->Get_xLeft() + r && x <= obsarr->obstacles[i]->Get_xRight() - r) {//если по центру
					vy = -vy;
					obsarr->obstacles[i]->LiveDown();
				}
				 else if (x + r * 2 >= obsarr->obstacles[i]->Get_xLeft() && x + r * 2 <= obsarr->obstacles[i]->Get_xLeft() + r) {//если с левого края
					if (vx > 0 && vy > 0) {
						vx = -vx;
						vy = -vy;
						obsarr->obstacles[i]->LiveDown();
					}
					else if (vx < 0 && vy > 0) {
						vy = -vy;
						obsarr->obstacles[i]->LiveDown();
					}
					else if (vx > 0 && vy < 0) {
						vx = -vx;
						obsarr->obstacles[i]->LiveDown();
					}
				}
				 else if (x <= obsarr->obstacles[i]->Get_xRight() && x >= obsarr->obstacles[i]->Get_xRight() - r) {//если с прового края
					if (vx > 0 && vy > 0) {
						vy = -vy;
						obsarr->obstacles[i]->LiveDown();
					}
					else if (vx < 0 && vy > 0) {
						vy = -vy;
						vx = -vx;
						obsarr->obstacles[i]->LiveDown();
					}
					else if (vx < 0 && vy < 0) {
						vx = -vx;
						obsarr->obstacles[i]->LiveDown();
					}
				}
			}
			//Проверка на левую границу
			else if (x + r * 2 >= obsarr->obstacles[i]->Get_xLeft() - 1 && x + r * 2 <= obsarr->obstacles[i]->Get_xLeft() + r) {
				if (y + r * 2 >= obsarr->obstacles[i]->Get_yTop() + r  && y  <= obsarr->obstacles[i]->Get_yBottom() - r ) {
					vx = -vx;
					obsarr->obstacles[i]->LiveDown();
				}
			}
			//Проверка на правую границу
			else if (x <= obsarr->obstacles[i]->Get_xRight() + 1  && x >= obsarr->obstacles[i]->Get_xRight() - r) {
				if (y + r * 2 >= obsarr->obstacles[i]->Get_yTop() + r && y  <= obsarr->obstacles[i]->Get_yBottom() - r ) {
					vx = -vx;
					obsarr->obstacles[i]->LiveDown();
				}
			}

			//Проверка на конец игры
			if (obsarr->obstacles[i]->Get_yBottom() >= field->GetYR()) {
				live = 0;
			}
		}	
	}
	
	float dx = vx * (double)time;
	float dy = vy * (double)time;
	this->x += dx;
	this->y += dy;

	s_bal.setPosition(x, y);
}

void Ball::SetFild(PlayingField* field) {
	this->field = field;
	this->x = field->GetXR() / 2;
	this->y = field->GetYR() - 50;
}

void Ball::SetOnePlatform(Platform* pl) {
	OnePlatform = pl;
}

void Ball::SetTwoPlatform(Platform* pl) {
	TwoPlatform = pl;
}

void Ball::SetObstaclArry(ObstaclesArray* obs) {
	this->obsarr = obs;
}

void Ball::StartPozition() {
	this->x = field->GetXR() / 2;
	this->y = field->GetYR() - 50;
	this->vx = V_X;
	this->vy = -V_Y;
}

