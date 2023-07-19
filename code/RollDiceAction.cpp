#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include"ApplicationManager.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	bool test = pGrid->GetEndGame();
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

	if (test) {
		string endMessage = "the game ended";
		pout->PrintMessage(endMessage);
	}


	// -- If not ended, do the following --:
	if (!test) {
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
		string DiceNumber = to_string(diceNumber);
		string rolledDiceValue = "the rolled dice value=" + DiceNumber;

		// 3- Get the "current" player from pGrid

		pout->PrintMessage(rolledDiceValue);
		Player* currentplayer = pGrid->GetCurrentPlayer();

		// 4- Move the currentPlayer using function Move of class player

		currentplayer->Move(pGrid, diceNumber);


		// 5- Advance the current player number of pGrid

		pGrid->AdvanceCurrentPlayer();
	}

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
