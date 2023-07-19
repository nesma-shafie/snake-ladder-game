#include "DeleteGameObject.h"
#include "Action.h"
#include"Grid.h"
#include"GameObject.h"
DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{
	OBJ = NULL;
}

DeleteGameObject::~DeleteGameObject()
{
}

void DeleteGameObject::ReadActionParameters()
{
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID

	string message = "please click on the source cell";
	pout->PrintMessage(message);
	OBJcell = pin->GetCellClicked();               //get the cell that has the gameobject
	OBJ = pGrid->GetGameObject(OBJcell);            //get the game object in that cell
}

void DeleteGameObject::Execute()
{
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID
	ReadActionParameters();
	if (OBJ != NULL) {                 //if that cell already has gameobject
		pGrid->RemoveObjectFromCell(OBJcell);           //remove if from celllist
	
		OBJ->Draw(pout,-1);                    //draw it with the cells color
	}


}
