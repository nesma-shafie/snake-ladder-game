#pragma once
#include"Card7.h"
class Card8:public Card
{
	int amountTobeFree; //amount the player should pay to go out of the prison
public:
	Card8(const CellPosition& pos); // A constructor that take the card position
	virtual void ReadCardParameters(Grid* pGrid); //read the amount that the player should pay to go free
	virtual void Apply(Grid* pGrid, Player* pPlayer); //Apply the card function 
	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);
	virtual ~Card8();

};

