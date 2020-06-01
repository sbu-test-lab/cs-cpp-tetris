#pragma once

#include "Grid.h"
#include "rectangularvectors.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace WinTetris { class Grid; }
namespace WinTetris { class Tetris; }

namespace WinTetris
{
	class Screen : public Grid
	{
	public:
		Screen();
		void AddBlock(Grid *ocupp);
		void RemoveBlock(Tetris *tetris);
		Grid *Union(Grid *g1, Grid *g2);

	};
}
