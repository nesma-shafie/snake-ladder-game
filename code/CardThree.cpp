#include "CardThree.h"
CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	  Card::Apply(pGrid, pPlayer);         //Call Apply() of the base class Card to print the message that you reached this card number
	  int PlayerNum =pGrid->GetCurrentPlayerNum(pPlayer);
	  pGrid->setcurrentplayer(PlayerNum-1);

}

void CardThree::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << endl;
}

void CardThree::Load(ifstream& Infile) {
	Card::Load(Infile);
}

CardThree::~CardThree()
{
}
