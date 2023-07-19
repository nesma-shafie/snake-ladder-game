#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; //
	hCell = -1; //

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	//Done by Hima Fine Code

	if (v < NumVerticalCells && v >= 0) {
		vCell = v;
		return true;
	}
	else
	{
		return false;
	}


}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	//Done by Hima Fine Code

	if(h < NumHorizontalCells && h >= 0) {
		hCell = h;
		return true;
	}
	else
	{
		return false;
	}

}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	//Done by Hima Fine Code

	if ((vCell <= (NumVerticalCells-1) && vCell >= 0)&&(hCell <= (NumHorizontalCells-1) && hCell >= 0)) {
		return true;
	}
	else {
		return false; // this line sould be changed with your implementation

	}
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it
	int num=1,x,y;
	///TODO: Implement this function as described in the .h file
	//Done by Hima Fine Code

	x = 1 + cellPosition.HCell();
	y = NumVerticalCells - 1 - cellPosition.VCell();

	num = x + y * NumHorizontalCells;

	
	return num; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	//Done by Hima Fine Code

	int x = 0, y = 0; float k;
	if (cellNum <= (NumHorizontalCells* NumVerticalCells) && cellNum >= 1) {
		k = (cellNum / float(NumHorizontalCells));
		if ((k - (cellNum / NumHorizontalCells)) > 0) {
			y = NumVerticalCells - (cellNum / NumHorizontalCells) - 1;
		}
		else {
			y = NumVerticalCells - ((cellNum - 1) / NumHorizontalCells) - 1;
		}
		if ((cellNum % NumHorizontalCells) != 0) {
			x = (cellNum % NumHorizontalCells) - 1;
		}
		else {
			x = NumHorizontalCells - 1;
		}
	}
	else {
		x = -1;
		y = -1;
	}
	position.SetHCell(x);
	position.SetVCell(y);
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it

	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO: Implement this function as described in the .h file
	CellPosition shiftedCell;
	int cellNum = GetCellNum()+addedNum;
	shiftedCell= GetCellPositionFromNum(cellNum);
	vCell = shiftedCell.VCell();
	hCell = shiftedCell.HCell();
	// Note: this function updates the data members (vCell and hCell) of the calling object

}