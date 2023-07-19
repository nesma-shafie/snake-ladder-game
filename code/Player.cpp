#include "Player.h"
#include"Ladder.h"
#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this->prevented = false;
	this->NumOfUnplayedTurns = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}
int Player::GetPlayerNumber() const
{
	return playerNum;
}

int Player::GetjustRolledDiceNum() {

	return justRolledDiceNum;
}
int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::SetTurnCount(int turn)
{
	turnCount = turn;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}


// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	this->turnCount++;


	// 3- Set the justRolledDiceNum with the passed diceNumber
	this->justRolledDiceNum = diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = pCell->GetCellPosition();
	if (!(this->NumOfUnplayedTurns >= 1 && this->NumOfUnplayedTurns <= 3))
	{
		if (turnCount < 3 && wallet >= 0) {
			pos.AddCellNum(diceNumber);
		}
		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
		if (wallet >= 0) {
			pGrid->UpdatePlayerCell(this, pos);

		}
	}

	if (this->turnCount == 3) {
		this->turnCount = 0;
	}

	if (!(this->NumOfUnplayedTurns >= 1 && this->NumOfUnplayedTurns <= 3))
	{
		// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
		if (this->turnCount == 0) {
			this->wallet += diceNumber * 10;
		}
		// 6- Apply() the game object of the reached cell (if any)
		if (this->turnCount != 0) {
			if (pCell->GetGameObject()) {
				GameObject* pGameObj = pCell->GetGameObject();
				pGameObj->Apply(pGrid, this);
			}
		}
	}
	else NumOfUnplayedTurns--;
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	int location = pCell->GetCellPosition().GetCellNum();
	if (location >= NumHorizontalCells * NumVerticalCells) {
		pGrid->SetEndGame(true);
	}

}



void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
void Player::setprevented(bool condition)
{
	prevented = condition;
}
bool Player::getprevented()
{
	return prevented;
}
void Player::setNumOfUnplayedTurns(int num)
{
	NumOfUnplayedTurns = num;
}
int Player::getNumOfUnplayedTurns()
{
	return NumOfUnplayedTurns;
}