#include "OneManager.h"

OneManager::OneManager(int com) {
	lvl_number = 1;
	pause = false;
	win = false;
	looz = false;

	bal = new Ball(com);

	field = new PlayingField();
	bal->SetFild(field);

	platform = new Platform(com, 0);
	platform->SetFild(field);
	bal->SetOnePlatform(platform);

	lvl.StartLVL(lvl_number);

	obss = new ObstaclesArray(com);
	obss->SetField(field);
	obss->Add(lvl.GetLVL());
	bal->SetObstaclArry(obss);

	status = new GameStatus(com);
	status->GetBal(bal);
	status->GetObs(obss);
}

OneManager::~OneManager() {
	delete bal;
	delete field;
	delete platform;
	delete obss;
	delete status;
}

void OneManager::Move(float time) {
	if (pause == true || win == true || looz == true)
		return;
	
	if (bal->Getlive() == 0) {
		looz = true;
		status->Dead();
		return;
	}

	if (obss->GetCount() == 0) {
		lvl_number++;
		if (lvl_number == 7) {
			win = true;
			status->Win();
			lvl_number = 6;
		}
		if (win == false) {
			lvl.StartLVL(lvl_number);
			bal->StartPozition();
			obss->Add(lvl.GetLVL());
		}
	}

	obss->Move(time);
	bal->Move(time);
	status->Apdate(lvl_number);

}

void OneManager::Draw(RenderWindow* window) {
	field->Draw(window);
	platform->Draw(window);
	bal->Draw(window);
	obss->Draw(window);
	status->Drow(window);
}

void OneManager::MoveGoLeft(float time) {
	if (pause == true || win == true || looz == true)
		return;

	platform->MoveXleft(time);
}

void OneManager::MoveGoRight(float time) {
	if (pause == true || win == true || looz == true)
		return;

	platform->MoveXright(time);
}

void OneManager::Pause() {
	if (win == true || looz == true)
		return;

	if (pause == false)
		pause = true;
	else
		pause = false;
}