#include "CardFive.h"

CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}

CardFive::~CardFive(void)
{
}

void CardFive::ReadCardParameters(Grid * pGrid)
{


}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{//HimaFineCode

	Card::Apply(pGrid, pPlayer);

	CellPosition backCell = pPlayer->GetCell()->GetCellPosition();

	backCell.AddCellNum(- pPlayer->GetjustRolledDiceNum());

	pGrid->UpdatePlayerCell(pPlayer, backCell);

	pGrid->UpdateInterface();
}
void CardFive::Save(ofstream& OutFile){
	Card::Save(OutFile);
	OutFile << endl;
}

void CardFive::Load(ifstream& Infile){
	Card::Load(Infile);
}
