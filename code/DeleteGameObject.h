#pragma once
#include "Action.h"
class DeleteGameObject :
    public Action
{
private:
    CellPosition OBJcell;
    GameObject * OBJ;
public:
    DeleteGameObject(ApplicationManager* pApp);
    virtual ~DeleteGameObject();
    void ReadActionParameters();
    void Execute();
};

