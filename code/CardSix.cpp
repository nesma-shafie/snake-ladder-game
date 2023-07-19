#include "CardSix.h"
int CardSix::count = 0;
int CardSix::destenation = 0;
CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (1 here)
	count++;
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	if (count == 1) {
		Input* pIn = NULL;
		pIn = pGrid->GetInput();

		Output* pOut = NULL;
		pOut = pGrid->GetOutput();

		// after getting Input and output pointers I can now print messages and take user inputs

		pOut->PrintMessage("Enter the new destnation (Cell Number)");
		int newCell = pIn->GetInteger(pOut);
		if (newCell > 1)
			destenation = newCell;

		pOut->ClearStatusBar();
	}
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{//HimaFineCode

	Card::Apply(pGrid, pPlayer);

	CellPosition SuperCell(destenation);

	pGrid->UpdatePlayerCell(pPlayer, SuperCell);

	pGrid->UpdateInterface();
}
void CardSix::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << ' '<<count<<' '<<destenation<<endl;
}

void CardSix::Load(ifstream& Infile) {
	Card::Load(Infile);
	Infile >> count >> destenation;
}