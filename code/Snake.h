#pragma once
#include "GameObject.h"
class Snake :
    public GameObject
{
    CellPosition endCellPos;
public:
	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut, int n) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& Infile);

	virtual bool IsOverlapping(GameObject* newObj) const;

	virtual ~Snake(); // Virtual destructor
};

