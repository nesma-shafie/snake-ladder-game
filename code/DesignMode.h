#pragma once
#include "Action.h"
class DesignMode :
    public Action
{
public:
	DesignMode(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

