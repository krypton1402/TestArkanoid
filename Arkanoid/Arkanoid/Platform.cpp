#include "Platform.h"

Platform::Platform(int com, int n) { 
	platform_image.loadFromFile("images/platform.png");//загружаем файл дл€ пол€
	platform_image.createMaskFromColor(Color(255, 255, 255));//
	platform.loadFromImage(platform_image);//зар€жаем текстуру картинкой
	s_platform.setTexture(platform);//заливаем текстуру спрайтом

	this->com = com;
	vx = 0.5;
	this->n = n;

	xleft = xright = yleft = yright = borderL = borderR = platformsise = 0;
}
Platform::~Platform() {

}

void Platform::Draw(RenderWindow* window) {
	window->draw(s_platform);
}

void Platform::MoveXleft(float time) {
	this->xleft -= (time * vx);
	this->xright -= (time * vx);
	if (xleft <= borderL) {
		xleft = borderL;
		xright = borderL + platformsise;
		return;
	}
	s_platform.setPosition(xleft, yleft);
}

void Platform::MoveXright(float time) {
	this->xleft += (time * vx);
	this->xright += (time * vx);
	if (xright >= borderR) {
		xright = borderR;
		xleft = borderR - platformsise;
		return;
	}
	s_platform.setPosition(xleft, yleft);
}

void Platform::SetFild(PlayingField* fild) {
	this->yleft = fild->GetYR() - 20;
	this->yright = fild->GetYR() - 10;

	switch (n) {
	//один игрок
	case(0):
		switch (this->com) {
		case(1):
			platformsise = 80;
			s_platform.setTextureRect(IntRect(0, 0, platformsise, 10));
			break;
		case(2):
			platformsise = 60;
			s_platform.setTextureRect(IntRect(0, 10, platformsise, 10));
			break;
		case(3):
			platformsise = 40;
			s_platform.setTextureRect(IntRect(0, 20, platformsise, 10));
			break;
		}

		this->xleft = (fild->GetXR() / 2) - (platformsise / 2);
		this->xright = (fild->GetXR() / 2) + (platformsise / 2);
		this->borderL = fild->GetXL();
		this->borderR = fild->GetXR();
		break;

	//первый игрок
	case(1):
		switch (this->com) {
		case(1):
			platformsise = 80 / 2;
			s_platform.setTextureRect(IntRect(0, 0, platformsise, 10));
			break;
		case(2):
			platformsise = 60 / 2;
			s_platform.setTextureRect(IntRect(0, 10, platformsise, 10));
			break;
		case(3):
			platformsise = 40 / 2;
			s_platform.setTextureRect(IntRect(0, 20, platformsise, 10));
			break;
		}

		this->xleft = (fild->GetXR() / 2) - (platformsise);
		this->xright = (fild->GetXR() / 2);
		this->borderL = fild->GetXL();
		this->borderR = fild->GetXR() / 2;
		break;

	//¬торой игрок
	case(2):
		switch (this->com) {
		case(1):
			platformsise = 80 / 2;
			s_platform.setTextureRect(IntRect(platformsise, 0, platformsise * 2, 10));
			break;
		case(2):
			platformsise = 60 / 2;
			s_platform.setTextureRect(IntRect(platformsise, 10, platformsise * 2, 10));
			break;
		case(3):
			platformsise = 40 / 2;
			s_platform.setTextureRect(IntRect(platformsise, 20, platformsise * 2, 10));
			break;
		}

		this->xleft = (fild->GetXR() / 2);
		this->xright = (fild->GetXR() / 2) + platformsise;
		this->borderL = fild->GetXR() / 2;
		this->borderR = fild->GetXR();
		break;
	}

	s_platform.setPosition(xleft, yleft);//«адаем позицию спрайта
}
