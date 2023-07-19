#include "PlayMode.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"
PlayMode::PlayMode(ApplicationManager* pApp):Action(pApp){
}

void PlayMode::ReadActionParameters(){

}

void PlayMode::Execute(){
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
}