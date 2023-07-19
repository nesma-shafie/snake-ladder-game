#pragma once
#include "Card.h"
// [ CardTwo ] Summary:
// // Its Apply() Function:movement to the next ladder start cell
// Its Parameters:there is no parameters
class CardTwo : public Card
{
public:
	CardTwo(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount
	virtual void Apply(Grid* pGrid, Player* pPlayer);// Applies the effect of CardTwo on the passed Player

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);
	// by moving the player to the start cell of the next ladder
	virtual ~CardTwo(); // A Virtual Destructor
};