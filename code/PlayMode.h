#pragma once
#include"Action.h"
class PlayMode :public Action
{
public:
	PlayMode(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

