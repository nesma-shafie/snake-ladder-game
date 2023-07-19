#pragma once

#include "Card.h"

class CardFive : public Card
{


public:
	CardFive(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);

	virtual ~CardFive(); // A Virtual Destructor
};

