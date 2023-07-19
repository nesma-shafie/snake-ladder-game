#include "CardTwo.h"
#include"Ladder.h"


CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (1 here)
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);        //  Call Apply() of the base class Card to print the message that you reached this card number
	Ladder* nextLadder;
	nextLadder = pGrid->GetNextLadder(Card::GetPosition());         //get pointer on the next ladder
	if (nextLadder != NULL)
	{
		CellPosition StartCellOfNextLadder = nextLadder->GameObject::GetPosition();            //get start cell of the next ladder
		int movement =( StartCellOfNextLadder.GetCellNum()) - (Card::GetPosition().GetCellNum());     //movement = the diffirance between the current cell number and the start cell of the next ladder number
		pPlayer->Move(pGrid, movement);
		pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);
	}
}

void CardTwo::Save(ofstream& OutFile) {
	Card::Save(OutFile);
	OutFile << endl;
}

void CardTwo::Load(ifstream& Infile) {
	Card::Load(Infile);
}

CardTwo::~CardTwo(void)
{}