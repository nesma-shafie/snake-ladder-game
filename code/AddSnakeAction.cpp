#include "AddSnakeAction.h"
#include"CellPosition.h"
#include"Action.h"
#include "Input.h"
#include "Output.h"
#include"Snake.h"
AddSnakeAction::AddSnakeAction(ApplicationManager* pApp):Action(pApp)
{

}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Cell* pCell = new Cell(endPos);
	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	if (startPos.VCell() < endPos.VCell() && startPos.HCell() == endPos.HCell())
	{
		if ((pCell->GetGameObject()))
			pGrid->PrintErrorMessage("End Cell Can Not be a Start Of Another Ladder or Snake !");

		else {
			Snake* pSnake = new Snake(startPos.VCell(), endPos.VCell());
		}
	}
	else
		pGrid->PrintErrorMessage("The cells clicked are not Valid");
	pOut->ClearStatusBar();


}
void AddSnakeAction::Execute()
{
	
	ReadActionParameters();

	// Create a Snake object with the parameters read from the user
	Snake* pSnake= new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Snake Can Not be here ");
	}
	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction

}
AddSnakeAction::~AddSnakeAction()
{
	
}