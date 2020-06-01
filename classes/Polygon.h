#pragma once

#include "Block.h"
#include <vector>
#include "rectangularvectors.h"

namespace WinTetris
{
	class Polygon : public Block
	{
	public:
		Polygon();
		void Rotate() override;
	};
}
