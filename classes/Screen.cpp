#include "Screen.h"
#include "Tetris.h"

namespace WinTetris
{

	Screen::Screen() : Grid(10, 22)
	{
	}

	void Screen::AddBlock(Grid *ocupp)
	{
		this->occupied = Union(this->occupied, ocupp->occupied);
	}

	void Screen::RemoveBlock(Tetris *tetris)
	{
		int j = 0;
		while (j < this->height)
		{
			if (this->isRow(j, true))
			{
				this->ShiftToDown(j);
				tetris->AdvanceScore();
			}
			else
			{
				j++;
			}
		}

	}

	Grid *Screen::Union(Grid *g1, Grid *g2)
	{
		Grid *result = new Grid(g1->width, g1->height);
		result->occupied = Union(g1->occupied, g2->occupied);

//C# TO C++ CONVERTER TODO TASK: A 'delete result' statement was not added since result was used in a 'return' or 'throw' statement.
		return result;
	}
}
