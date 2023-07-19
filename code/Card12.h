#pragma once
#include "Card.h"
#include"Player.h"
#include"Card9.h"
#include"Card10.h"
#include"Card11.h"
class Card12 : public Card
{

public:
	Card12(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);

	virtual ~Card12();
};

