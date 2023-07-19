
#pragma once
#include"Action.h"
#include"CellPosition.h"
#include"Grid.h"
#include"GameObject.h"
#include"Cell.h"
#include"Card.h"
    class CopyCard :
        public Action
    {
    private:
        CellPosition cardcell;
        Card* CopiedCard;

    public:
        CopyCard(ApplicationManager* pApp);
        virtual ~CopyCard();
        void ReadActionParameters();
        void Execute();
};

