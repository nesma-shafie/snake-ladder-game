#pragma once
#include "Card.h"
#include"RollDiceAction.h"
// [ CardThree ] Summary:
// // Its Apply() Function:taking extra dice roll
// Its Parameters:there is no parameters
class CardThree : public Card
{

public:
	CardThree(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);// Applies the effect of CardThree on the passed Player
													  // by  gives the player an extra dice roll.

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);

	virtual ~CardThree(); // A Virtual Destructor
};

