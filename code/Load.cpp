#include "Load.h"
#include<string.h>
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
Load::Load(ApplicationManager* pApp) :Action(pApp) {
	pGrid = pManager->GetGrid();
}
void Load::ReadActionParameters()
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Load Grid: Enter file name please");
	FileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}
void Load::Execute()
{
	ReadActionParameters();
	ifstream InFile(FileName, ios::in);
	if (!InFile.is_open())
	{
		pGrid->PrintErrorMessage("Error: Can't open file ! Click to continue ...");
		return;
	}

	//pGrid->ClearGrid();

	int LadderCount, SnakeCount, CardCount;

	InFile >> LadderCount;

	for (int i = 0; i < LadderCount; i++) {
		Ladder* pladder = new Ladder(CellPosition(0), CellPosition(0));
		pladder->Load(InFile);
		pGrid->AddObjectToCell(pladder);
		
	}

	InFile >> SnakeCount;

	for (int i = 0; i < LadderCount; i++) {
		Snake* pSnake = new Snake(CellPosition(0), CellPosition(0));
		pSnake->Load(InFile);
		pGrid->AddObjectToCell(pSnake);
		
	}

	InFile >> CardCount;

	for (int i = 0; i < CardCount; ++i)
	{
		int cardNum;
		Card* pCard = NULL;

		InFile >> cardNum;
		switch (cardNum)
		{
		case 1:
			pCard = new CardOne(CellPosition(0));
			break;
		case 2:
			pCard = new CardTwo(CellPosition(0));
			break;
		case 3:
			pCard = new CardThree(CellPosition(0));
			break;
		case 4:
			pCard = new CardFour(CellPosition(0));
			break;
		case 5:
			pCard = new CardFive(CellPosition(0));
			break;
		case 6:
			pCard = new CardSix(CellPosition(0));
			break;
		case 9:
			pCard = new Card9(CellPosition(0));
			break;
		case 10:
			pCard = new Card10(CellPosition(0));
			break;
		case 11:
			pCard = new Card11(CellPosition(0));
			break;
		case 12:
			pCard = new Card12(CellPosition(0));
			break;

		default:
			break;
		}

		if (pCard == NULL)
		{
			continue;
		}

		pCard->Load(InFile);

		if (pGrid->GetGameObject(pCard->GetPosition()))
		{
			delete pCard;
			continue;
		}

		bool added = pGrid->AddObjectToCell(pCard);
		if (!added)
		{
			delete pCard;
		}
	}
}

