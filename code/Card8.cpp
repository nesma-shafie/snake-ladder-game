#include "Card8.h"

Card8::Card8(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8; //set the number of the Card 
}
void Card8::ReadCardParameters(Grid* pGrid)
{
	
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int amount;
	
	pOut->PrintMessage("New Card 8: Please Enter the amount that the player should pay to be free of the prison");
	amount = pIn->GetInteger(pOut);
	if (amount > 0)
		amountTobeFree = amount;
	pOut->ClearStatusBar();



}
void Card8::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply( pGrid,  pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int choice;
	 
		pOut->PrintMessage("Enter '1' if you want to pay instead of being in prison "); 
		
		
		choice=pIn->GetInteger(pOut);
	
		if (choice == 1)
		{
			if (pPlayer->GetWallet() == 0)
				pPlayer->SetWallet(0);
			else pPlayer->SetWallet(pPlayer->GetWallet() - amountTobeFree);
	}
	else if (choice == 0)
	{
		pPlayer->setprevented(true);
		pPlayer->setNumOfUnplayedTurns(3);
	}
	
	
}
void Card8::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << ' ' << amountTobeFree << endl;
}

void Card8::Load(ifstream& Infile) {
	Card::Load(Infile);
	Infile >> amountTobeFree;
}

Card8::~Card8()
{

}
