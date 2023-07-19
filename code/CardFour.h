#pragma once
#include "Card.h"
class CardFour : public Card
{ public:
	CardFour(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);// Applies the effect of CardThree on the passed Player
													  // by   preventing the player an extra dice roll.

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);
	virtual ~CardFour(); // A Virtual Destructor
};

