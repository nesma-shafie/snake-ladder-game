#pragma once
#include "Action.h"
#include"Grid.h"
#include"CellPosition.h"
#include"Card.h"
#include"AddCardAction.h"
class PasteCard :
    public Action
{
private:
    Card* pastedCard;
    Card* CopiededCard;
    CellPosition dCell;
public:
    PasteCard(ApplicationManager* pApp);
    virtual ~PasteCard();
    void ReadActionParameters();
    void Execute();
};

