#pragma once

#include "Block.h"
#include "rectangularvectors.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace WinTetris { class Grid; }

namespace WinTetris
{
	class Rectangle : public Block
	{
	private:
		Grid *state1;
		Grid *state2;

	public:
		virtual ~Rectangle()
		{
			delete state1;
			delete state2;
		}

		Rectangle();
		void Rotate();
	};
}
