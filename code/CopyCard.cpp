#include "CopyCard.h"

CopyCard::CopyCard(ApplicationManager* pApp) : Action(pApp)
{
	CopiedCard = NULL;
}

CopyCard::~CopyCard()
{
}

void CopyCard::ReadActionParameters()
{
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID

	string message = "please click on the source cell";           
	pout->PrintMessage(message);
	cardcell  = pin->GetCellClicked();                          //get the cell that has the card
	GameObject * gameObject = pGrid->GetGameObject(cardcell);    //get the gameobject in the cell
	CopiedCard = dynamic_cast<Card*>(gameObject);               //check if the gameobject is card 
	
}

void CopyCard::Execute()
{
	ReadActionParameters();
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID
	
	
	if (CopiedCard != NULL)                   //if it is a card
	      pGrid->SetClipboard(CopiedCard);     //copy it in clipboard

	else
		pout->PrintMessage("there is no card to be copied");     //if not print a message



}

