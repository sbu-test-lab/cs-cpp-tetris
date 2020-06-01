#include "Square.h"

namespace WinTetris
{

	Square::Square() : Block(2)
	{
		occupied[0][0] = true;
		occupied[0][1] = true;
		occupied[1][0] = true;
		occupied[1][1] = true;
	}

	void Square::Rotate()
	{
	}
}
