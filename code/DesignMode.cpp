#include "DesignMode.h"

#include "Input.h"
#include "Output.h"
#include"Grid.h"
DesignMode::DesignMode(ApplicationManager* pApp) :Action(pApp) {
}

void DesignMode::ReadActionParameters() {

}

void DesignMode::Execute() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
}