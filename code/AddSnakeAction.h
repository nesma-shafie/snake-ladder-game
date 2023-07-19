#pragma once
#include"CellPosition.h"
#include"Action.h"

class AddSnakeAction :public Action
{
	CellPosition startPos;  //head
	CellPosition endPos;   //tail
public:
	AddSnakeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~AddSnakeAction();

};

