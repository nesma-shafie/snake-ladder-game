#include "Snake.h"
#include "Ladder.h"
#include<fstream>
#include"Player.h"
#include"Cell.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	//if(endCellPos.GetCellNum()!=99)
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut, int n) const
{
	//if (position.HCell() != 10)

	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	//////////////
	Output* pOut = NULL;
	pOut = pGrid->GetOutput();
	Input* pIn = NULL;
	pIn = pGrid->GetInput();
	int x, y; // 2 variables to enter as arguments for wait mouseclick function

	pOut->PrintMessage("You have reached a ladder. Click to continue ... ");
	pIn->GetPointClicked(x, y);

	
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	GameObject* pGameObj = pGrid->GetGameObject(endCellPos);
	if (pGameObj)
	{
		pGameObj->Apply(pGrid, pPlayer);
	}

}

void Snake::Save(ofstream& OutFile) {
	OutFile << position.GetCellNum() << ' ' << endCellPos.GetCellNum() << endl;
}

void Snake::Load(ifstream& Infile) {
	int startCell, endCell;
	Infile >> startCell >> endCell;

	position = CellPosition(startCell);
	endCellPos = CellPosition(endCell);
}


CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

bool Snake::IsOverlapping(GameObject* newObj) const
{
	Snake* newSnake = dynamic_cast<Snake*>(newObj);
	if (newSnake)
	{
		CellPosition newPos = newSnake->GetPosition();
		CellPosition newEndPos = newSnake->GetEndPosition();
		if (newPos.HCell() != position.HCell())
		{
			return false;
		}
		if (position.VCell() < newPos.VCell())
		{
			return (endCellPos.VCell() > newPos.VCell());
		}
		else
		{
			return (position.VCell() < newEndPos.VCell());
		}
	}
	return false;
}
Snake::~Snake()
{
}
