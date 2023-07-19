#pragma once
#include "Action.h"
#include"CellPosition.h"
#include"Grid.h"
#include"GameObject.h"
#include"Cell.h"
#include"Card.h"
class CutCard :
    public Action
{
private:
    CellPosition cardcell;
    Card* CutedCard;

public:
    CutCard(ApplicationManager* pApp);
    virtual ~CutCard();
    void ReadActionParameters();
    void Execute();
};
