#include "Block.h"

namespace WinTetris
{

	Block::Block(int len) : Grid(len, len)
	{
		y_position = 22 - height;
		x_position = 3;
	}

	void Block::MoveRight()
	{
		if (x_position + width < 10)
		{
			x_position++;
		}
		else if (this->isColumn(width - 1,false))
		{
			this->ShiftToRight();
		}
	}

	void Block::MoveLeft()
	{
		if (x_position > 0)
		{
			x_position--;
		}
		else if (this->isColumn(0,false))
		{
			this->ShiftToLeft();
		}
	}

	void Block::MoveDown()
	{
		if (y_position > 0)
		{
			y_position--;
		}
		else if (this->isRow(0,false))
		{
			this->ShiftToDown(0);
		}
	}

	void Block::Rotate()
	{

	}

	Grid *Block::BeAddedToScreen()
	{
		Grid *result = new Grid(10,22);
		for (int i = 0; i < this->width; i++)
		{

			for (int j = 0; j < this->height; j++)
			{

					result->occupied[x_position + i][y_position + j] = this->occupied[i][j];
			}
		}

//C# TO C++ CONVERTER TODO TASK: A 'delete result' statement was not added since result was used in a 'return' or 'throw' statement.
		return result;
	}
}
