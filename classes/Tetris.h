#pragma once

#include "rectangularvectors.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace WinTetris { class Screen; }
namespace WinTetris { class Block; }
namespace WinTetris { class Grid; }

namespace WinTetris
{
	class Tetris
	{
	public:
		static int DIRECT;
		static int LEFT;
		static int RIGHT;
		static int ROTATE;

		Screen *screen;
		Block *block;
		int score = 0;

		virtual ~Tetris()
		{
			delete screen;
			delete block;
		}

		Tetris();
		void RunOneStep(int dir);
		Grid *GetGmaeFrame();
void AddBlock();
		void AdvanceScore();
	};
}
