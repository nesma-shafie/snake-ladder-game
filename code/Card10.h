#pragma once
#include"Card.h"
#include"Player.h"
class Card10 :public Card
{
	static int CardPrice;
	static int Fees;
	static int count;  //this count sees if the card first created to take the inputs once
	static bool sold;
	static Player* pOwner;
public:
	Card10(const CellPosition& pos);
	static int getcount();
	bool getstate();
	static int GetCardPrice();
	Player* getOwner();
	void setOwner(Player* pPlayer);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual ~Card10();
};

