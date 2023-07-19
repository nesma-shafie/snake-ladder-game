#pragma once
#include "Action.h"
#include"Grid.h"
#include"Player.h"
class InputDiceValueAction : public Action

{
private:
	int dicevalue;
public:
	InputDiceValueAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValueAction();
};

