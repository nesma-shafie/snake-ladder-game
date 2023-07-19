#include "Card11.h"
int Card11::count = 0;
Player* Card11::pOwner = NULL;
bool Card11::sold = false;
int Card11::CardPrice = 0;
int Card11::Fees = 0;
Card11::Card11(const CellPosition& pos) :Card(pos)
{
	cardNumber = 11;
	count++;
	
}
void Card11::ReadCardParameters(Grid* pGrid)
{
	if (count == 1)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("New Card 11 : Please Enter The price of The Station ");
		int Price_Entered = pIn->GetInteger(pOut);
		if (Price_Entered > 0)
			CardPrice = Price_Entered;
		pOut->ClearStatusBar();
		pOut->PrintMessage("Please Enter the fees to Pay by Passing Players :");
		int fees_Entered = pIn->GetInteger(pOut);
		if (fees_Entered > 0)
			Fees = fees_Entered;
		pOut->ClearStatusBar();
	}
}
int Card11::getcount()
{
	return count;
}
int Card11::GetCardPrice() {
	return CardPrice;
}
bool Card11::getstate() {
	return sold;
}
Player* Card11::getOwner() {
	return pOwner;
}
void Card11::setOwner(Player* pPlayer) {
	pOwner = pPlayer;
}

void Card11::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int choose;
	
	
	if (!sold) // checks if the station is sold or not 
	{
		pOut->PrintMessage("Do you want to buy this station? if yes press 1 otherwise press 0");
		choose = pIn->GetInteger(pOut);
		if (choose == 1)
		{
			pOut->PrintMessage("You are the Owner of the Station ");
			sold = true;
			pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
			 pOwner = pPlayer;
		}



	}
	else {
		pOut->PrintMessage("Your wallet will be Decreased");
		if (pPlayer->GetWallet() - Fees < 0)
		{
			pPlayer->SetWallet(0);
			pOwner->SetWallet(pOwner->GetWallet() + Fees);
		}

		else {
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees);   //decrease the wallet of the player that stops at the station
			pOwner->SetWallet(pOwner->GetWallet() + Fees);
		}
	}

}
void Card11::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << ' ' << count << ' ' << CardPrice << ' ' << Fees << endl;
}

void Card11::Load(ifstream& Infile) {
	Card::Load(Infile);
	Infile >> count >> CardPrice >> Fees;
}

Card11::~Card11()
{

}
