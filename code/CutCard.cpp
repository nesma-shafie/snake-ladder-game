#include "CutCard.h"

CutCard::CutCard(ApplicationManager* pApp) : Action(pApp)
{
	CutedCard = NULL;
}

CutCard::~CutCard()
{
}

void CutCard::ReadActionParameters()
{Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID

	string message = "please click on the source cell";
	pout->PrintMessage(message);
	cardcell = pin->GetCellClicked();                       //get the cell that has the card

	GameObject* gameObject = pGrid->GetGameObject(cardcell);        //get the game object in that cell
	CutedCard = dynamic_cast<Card*>(gameObject);                     //check if that gameobject is a card
	
}

void CutCard::Execute()
{
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID
	
	ReadActionParameters();

	if (CutedCard != NULL) {           //if it is a card
		pGrid->SetClipboard(CutedCard);         //copy it in clipboard
		CutedCard->Draw(pout, -1);               //draw it with the cell-has no card color
		pGrid->RemoveObjectFromCell(cardcell);    //remove if from celllist
	}
	else { pout->PrintMessage("there is no card to cut"); }   //if it is not a card print a message


}
