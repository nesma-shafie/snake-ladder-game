#include "CardFour.h"
CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);         //Call Apply() of the base class Card to print the message that you reached this card number
	pPlayer->setNumOfUnplayedTurns(1);    //orevent him from playing for one time
	
		
}
void CardFour::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << endl;
}

void CardFour::Load(ifstream& Infile) {
	Card::Load(Infile);
}
CardFour::~CardFour()
{
}
