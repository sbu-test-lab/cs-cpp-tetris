#include "Rectangle.h"
#include "Grid.h"

namespace WinTetris
{

	Rectangle::Rectangle() : Block(4)
	{
		state1 = new Grid(4, 4);
		state1->occupied[1][0] = true;
		state1->occupied[1][1] = true;
		state1->occupied[1][2] = true;
		state1->occupied[1][3] = true;

		state2 = new Grid(4, 4);
		state2->occupied[0][2] = true;
		state2->occupied[1][2] = true;
		state2->occupied[2][2] = true;
		state2->occupied[3][2] = true;

		this->occupied = state1->occupied;
	}

	void Rectangle::Rotate()
	{
		if (this->occupied.Equals(state1->occupied))
		{
			this->occupied = state2->occupied;
		}
		else
		{
			this->occupied = state1->occupied;
		}
	}
}
