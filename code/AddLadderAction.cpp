#include "AddLadderAction.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Cell* pCell = new Cell( endPos);

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	
	if (startPos.VCell() > endPos.VCell() && startPos.VCell() != 0)
	{
		if (startPos.HCell() != endPos.HCell())
			pGrid->PrintErrorMessage("End Cell and Start Cell are not in the same column !");
	     if ((pCell->GetGameObject()))
			pGrid->PrintErrorMessage("End Cell Can Not be a Start Of Another Ladder or Snake !");

		else {
			Ladder* pLadder = new Ladder(startPos.VCell(), endPos.VCell());
		}
	}
	
	else
		pGrid->PrintErrorMessage("End Cell Can Not be Smaller than Start Cell !");
		

    

	///TODO: Make the needed validations on the read parameters

	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Ladder Can Not Be here ");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}

