#include "Card9.h"
int Card9::count = 0;
Player* Card9::pOwner = NULL;
bool Card9::sold = false;
int Card9::CardPrice = 0;
int Card9::Fees = 0;
Card9::Card9(const CellPosition& pos) :Card(pos)
{
	cardNumber = 9;
	count++;
	sold = false;
	pOwner = NULL;
}
void Card9::ReadCardParameters(Grid* pGrid)
{
	if (count == 1)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("New Card 9 : Please Enter The price of The Station ");
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
 int Card9::getcount()
{
	return count;
}
 int Card9::GetCardPrice() {
	 return CardPrice;
 }
 bool Card9::getstate() {
	 return sold;
 }
 Player* Card9::getOwner() {
	 return pOwner;
 }
 void Card9::setOwner(Player* pPlayer) {
	 pOwner = pPlayer;
 }
 

void Card9::Apply(Grid* pGrid, Player* pPlayer)
{Card::Apply(pGrid, pPlayer);
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

void Card9::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << ' ' << count << ' ' << CardPrice << ' ' << Fees << endl;
}

void Card9::Load(ifstream& Infile) {
	Card::Load(Infile);
	Infile >> count >> CardPrice >> Fees;
}

Card9::~Card9()
{

}
