#include "Save.h"
#include<string.h>
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
Save::Save(ApplicationManager* pApp):Action(pApp) {
	pGrid = pManager->GetGrid();
}

void Save::ReadActionParameters(){
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Saveing: Enter file name please");
	FileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

void Save::Execute(){
	ReadActionParameters();

	ofstream OutFile(FileName, ios::out);
	if (!OutFile.is_open())
	{
		pGrid->PrintErrorMessage("The file is already used");
		return;
	}
	

	OutFile << pGrid->GetNumberOfLadders() << endl;
	pGrid->SaveAllLadders(OutFile);
	OutFile << pGrid->GetNumberOfSnakes() << endl;
	pGrid->SaveAllSnakes(OutFile);
	OutFile << pGrid->GetNumberOfCards() << endl;
	pGrid->SaveAllCards(OutFile);

	OutFile.close();
}