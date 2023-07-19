#pragma once
#include"Action.h"
#include"Grid.h"
#include<fstream>
class Save:public Action
{
	string FileName;
	Grid* pGrid;
public:
	Save(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

