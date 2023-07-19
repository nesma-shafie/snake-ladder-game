#pragma once
#include"Action.h"
#include"Grid.h"
#include "CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"Card7.h"
#include"Card8.h"
#include"Card9.h"
#include"Card10.h"
#include"Card11.h"
#include "Card12.h"
#include<fstream>
class Load :
    public Action
{
	Grid* pGrid;
	string FileName;
public:

	Load(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

