#include "InputDiceValueAction.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID
	string M = "please enter a dice value between 1-6";


	do
	{
		pout->PrintMessage(M);
		dicevalue = pin->GetInteger(pout);
	} while (!(dicevalue >= 1 && dicevalue <= 6));   //ask the user to enter a number between 1,6 and repeat that action until ho enters a correct number
	string s = "the entered dice value=";
	string c = to_string(dicevalue);
	string inputdicevalue = s + c;
	pout->PrintMessage(inputdicevalue);
}



void InputDiceValueAction::Execute()
{
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID
	ReadActionParameters();

	//Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	bool test = Action::pManager->GetGrid()->GetEndGame();
	if (test) {
		string endMessage = "the game ended";
		pout->PrintMessage(endMessage);
	}
	//If not ended, do the following --:Get the "current" player from pGrid.... Move the currentPlayer using function Move of class player WITH THE DICE VALUE

	if (!test) {

		Player* currentplayer = pGrid->GetCurrentPlayer();

		currentplayer->Move(pGrid, dicevalue);    //move the player with the entered dice value
		pGrid->AdvanceCurrentPlayer();          //Advance the current player number of pGrid
	}
}
InputDiceValueAction::~InputDiceValueAction() {}
