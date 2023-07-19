#pragma once
#include"Player.h"
#include"Grid.h"
#include"Card.h"

class Card7:public Card
{public:
	Card7(const CellPosition& pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);
	virtual ~Card7();
};

