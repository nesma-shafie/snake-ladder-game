#include "Card7.h"
#include "Grid.h"
#include"Player.h"
#include"Output.h"
#include"Input.h"
Card7::Card7(const CellPosition& pos) :Card(pos)
{
	cardNumber = 7;
}
Card7::~Card7()
{

}
void Card7::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Cell* pCell = new Cell(8, 0);
	Player* pNext = pGrid->GetNextplayer(pPlayer->GetCell()->GetCellPosition());
	if (pNext)
	{

		pOut->PrintMessage("The Next Player will be in the first cell ");
		pGrid->UpdatePlayerCell(pNext, pCell->GetCellPosition());

		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	else {
		pOut->PrintMessage("There is not a player next to you");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	
	
	

}
void Card7::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << endl;
}

void Card7::Load(ifstream& Infile) {
	Card::Load(Infile);
}