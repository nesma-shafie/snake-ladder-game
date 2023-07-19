#include "NewGame.h"
#include"ApplicationManager.h"
#include"Grid.h"

NewGame::NewGame(ApplicationManager* pApp):Action(pApp)
{
}

void NewGame::ReadActionParameters()
{//there is no parameters
}

void NewGame::Execute()
{
	Output* pout = Action::pManager->GetGrid()->GetOutput();  //GET POINTER TO OUTPUT CLASS

	Input* pin = Action::pManager->GetGrid()->GetInput();            //GET POINTER TI INPUT  CLASS

	Grid* pGrid = Action::pManager->GetGrid();                        //GET POINTER TO GRID

	pGrid->setPlayersTurnCount(0);        //set the players turn count=0
	pGrid->setPlayersWallet(100);         //set the players wallet=100
	pGrid->setPlayersPosition(1);         //set the players position with the first cell
	pGrid->setcurrentplayer(0);           //set the turn with the first player
	}

NewGame::~NewGame()
{
}
