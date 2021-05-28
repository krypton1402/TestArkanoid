#include "DoubleManager.h"

DoubleManager::DoubleManager(int com) {
	lvl_number = 1;
	pause = false;
	win = false;
	looz = false;

	bal = new Ball(com);

	field = new PlayingField();
	bal->SetFild(field);

	OnePlatform = new Platform(com, 1);
	TwoPlatform = new Platform(com, 2);
	OnePlatform->SetFild(field);
	TwoPlatform->SetFild(field);
	bal->SetOnePlatform(OnePlatform);
	bal->SetTwoPlatform(TwoPlatform);

	lvl.StartLVL(lvl_number);

	obss = new ObstaclesArray(com);
	obss->SetField(field);
	obss->Add(lvl.GetLVL());
	bal->SetObstaclArry(obss);

	status = new GameStatus(com);
	status->GetBal(bal);
	status->GetObs(obss);
}

DoubleManager::~DoubleManager() {
	delete bal;
	delete field;
	delete OnePlatform;
	delete TwoPlatform;
	delete obss;
	delete status;
}

void DoubleManager::Move(float time) {
	if (pause == true || win == true || looz == true)
		return;

	if (bal->Getlive() == 0) {
		looz = true;
		return;
	}

	if (obss->GetCount() == 0) {
		lvl_number++;
		if (lvl_number == 7) {
			win = true;
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

void DoubleManager::Draw(RenderWindow* window) {
	field->Draw(window);
	OnePlatform->Draw(window);
	TwoPlatform->Draw(window);
	bal->Draw(window);
	obss->Draw(window);
	status->Drow(window);
}

void DoubleManager::OneMoveGoLeft(float time) {
	if (pause == true || win == true || looz == true)
		return;

	OnePlatform->MoveXleft(time);
}

void DoubleManager::OneMoveGoRight(float time) {
	if (pause == true || win == true || looz == true)
		return;

	OnePlatform->MoveXright(time);
}


void DoubleManager::TwoMoveGoLeft(float time) {
	if (pause == true || win == true || looz == true)
		return;

	TwoPlatform->MoveXleft(time);
}
void DoubleManager::TwoMoveGoRight(float time) {
	if (pause == true || win == true || looz == true)
		return;

	TwoPlatform->MoveXright(time);
}

void DoubleManager::Pause() {
	if (win == true || looz == true)
		return;

	if (pause == false)
		pause = true;
	else
		pause = false;
}