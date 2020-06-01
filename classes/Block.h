#pragma once

#include "Grid.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace WinTetris { class Grid; }

namespace WinTetris
{
	class Block : public Grid
	{
	public:
		int x_position = 0, y_position = 0;


		Block(int len);

		void MoveRight();

		void MoveLeft();
		void MoveDown();
		virtual void Rotate();


		Grid *BeAddedToScreen();

	};
}
