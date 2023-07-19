#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"Card7.h"
#include"Card8.h"
#include"Card9.h"
#include"Card10.h"
#include"Card11.h"
#include "Card12.h"
AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}



void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	
	
	// 2- Read the "cardNumber" parameter and set its data member
	
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member

	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
	//menna
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	
	Cell* pCell;
	
	Card* pCard;
	CellPosition cellpos_Entered;
	pOut->PrintMessage("Type Card Number :");
	int cardnumentered = pIn->GetInteger(pOut);
	if (cardnumentered > 0 && cardnumentered <= 12)
	{
		cardNumber = cardnumentered;
		pOut->PrintMessage("Click on Card Cell:");
		cellpos_Entered = pIn->GetCellClicked();
		if (cellpos_Entered.GetCellNum() != 99 && cellpos_Entered.GetCellNum() != 1)
		{
			pCell = new Cell(cellpos_Entered);
			if ((pCell->GetGameObject()))
			{
				pGrid->PrintErrorMessage("Error !This Cell Has Already An Object");
				pOut->ClearStatusBar();
			}
			else {
				cardPosition = cellpos_Entered;
				pCard = new Card(cardPosition);
				pCard->SetCardNumber(cardNumber);

				pOut->ClearStatusBar();

			}
		}
		else pGrid->PrintErrorMessage("The Card Can not be here at the first cell or end cell ");
	}
	
	
	

}

void AddCardAction::Execute() 
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);
		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new Card7(cardPosition);
		break;
	case 8:
		pCard = new Card8(cardPosition);
		break;
	case 9:
		pCard = new Card9(cardPosition);
		break;
	case 10:
		pCard = new Card10(cardPosition);
		break;
	case 11:
		pCard = new Card11(cardPosition);
		break;
	case 12:
		pCard = new Card12(cardPosition);
		break;
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		if (!(pGrid->AddObjectToCell(pCard)))
		{
			pGrid->PrintErrorMessage("Error The Card Can not be here ");
		}

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
AddCardAction::~AddCardAction()
{
	
}