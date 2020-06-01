#pragma once

#include "Block.h"
#include "rectangularvectors.h"

namespace WinTetris
{
	class Square : public Block
	{
	public:
		Square();

		void Rotate() override;
	};
}
