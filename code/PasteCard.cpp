#include "PasteCard.h"

PasteCard::PasteCard(ApplicationManager* pApp) :Action(pApp)
{
}

PasteCard::~PasteCard()
{
}

void PasteCard::ReadActionParameters()
{Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID

	pout->PrintMessage("click on the destination cell");
	dCell = pin->GetCellClicked();                        //get the cell that you want to paste the card in
	GameObject* gameObject = pGrid->GetClipboard();       //get the game object the saved in clipboard
	pastedCard = dynamic_cast<Card*>(gameObject);          //check if the gameobject is card 
	
	pastedCard->GameObject::setposittion(dCell);          //set the card position with the cell that you want to paste the card in
	}

void PasteCard::Execute()
{
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID

	

	ReadActionParameters();


	if (pGrid->AddObjectToCell(pastedCard)) {  //if that cell is valid to add game object in it
		if (pastedCard != NULL) {        // if the gameobject from clipboard is a card
			pGrid->AddObjectToCell(pastedCard);     //add the card in the distination cell

	}
	}
	else pout->PrintMessage("cell is not valid");


}
