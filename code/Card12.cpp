#include "Card12.h"
#include<iostream>
using namespace std;
Card12::Card12(const CellPosition& pos):Card(pos) {

	cardNumber = 12;
}
 void Card12::ReadCardParameters(Grid* pGrid){
 
 }
 void Card12::Apply(Grid* pGrid, Player* pPlayer) {

	 Card::Apply(pGrid, pPlayer);
	 Output* pOut = pGrid->GetOutput();
	 Input* pIn = pGrid->GetInput();
	 int HighestPrice = 0;
	 Card9* c9 = NULL; Card10* c10 = NULL; Card11* c11 = NULL;
	 Player* SmallOne = pGrid->GetCurrentPlayer();
	 for (int i = 0; i < MaxPlayerCount - 1; i++) {
		 pGrid->AdvanceCurrentPlayer();

		 if (pGrid->GetCurrentPlayer()->GetWallet() < SmallOne->GetWallet())
			 SmallOne = pGrid->GetCurrentPlayer();
	 }
	 for (int i = 1; i < NumHorizontalCells * NumVerticalCells; i++) {

		 Card9* c = dynamic_cast<Card9*>(pGrid->GetGameObject(i));

		 if (c->getOwner()==pPlayer) {
			 c9 = c;
			 break;
		 }
	 }
	 if (c9->getOwner() == pPlayer) {
		 c9->setOwner(SmallOne);
		 //cout<< SmallOne->GetPlayerNumber();
	 }
	 for (int i = 1; i < NumHorizontalCells * NumVerticalCells; i++) {

		 Card10* c = dynamic_cast<Card10*>(pGrid->GetGameObject(i));

		 if (c->getOwner() == pPlayer) {
			 c10 = c;
			 break;
		 }
	 }
	 if (c10->getOwner() == pPlayer) {
		 c10->setOwner(SmallOne);
		 //cout<< SmallOne->GetPlayerNumber();
	 }
	 for (int i = 1; i < NumHorizontalCells * NumVerticalCells; i++) {

		 Card11* c = dynamic_cast<Card11*>(pGrid->GetGameObject(i));

		 if (c->getOwner() == pPlayer) {
			 c11 = c;
			 break;
		 }
	 }
	 if (c11->getOwner() == pPlayer) {
		 c11->setOwner(SmallOne);
	 }
 }
 void Card12::Save(ofstream& OutFile) {
	 Card::Save(OutFile);
	 OutFile << endl;
 }

 void Card12::Load(ifstream& Infile) {
	 Card::Load(Infile);
 }
 Card12::~Card12(){
 
 }