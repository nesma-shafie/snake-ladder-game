#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "AddSnakeAction.h"
#include"CutCard.h"
#include"CopyCard.h"
#include"PasteCard.h"
#include"DeleteGameObject.h"
#include"InputDiceValueAction.h"
#include"NewGame.h"
#include"DesignMode.h"
#include"PlayMode.h"
#include"Save.h"
#include"Load.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case EXIT:
		break;

	case TO_DESIGN_MODE:
		pAct = new DesignMode(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case TO_PLAY_MODE:
		if (dynamic_cast<DesignMode*>(pAct))
			delete pAct;
		pAct = new PlayMode(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;


	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case New_Game:
		pAct = new NewGame(this);
		break;



	case Input_Dice_Value:
		pAct = new InputDiceValueAction(this);
		break;

	case Copy_Card:
		pAct = new CopyCard(this);
		break;

	case Paste_Card:
		pAct = new PasteCard(this);
		break;

	case Cut_Card:
		pAct = new CutCard(this);
		break;

	case Delete_Game_Object:
		pAct = new DeleteGameObject(this);
		break;
		///TODO: Add a case for EACH Action type in the Design mode or Play mode

	case Save_Grid:
		pAct = new Save(this);
		break;

	case Open_Grid:
		pAct = new Load(this);
		break;


	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
