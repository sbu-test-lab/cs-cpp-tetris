#pragma once

#include <vector>
#include "rectangularvectors.h"

namespace WinTetris
{
	class Grid
	{
	public:
		const int width, height;
		std::vector<std::vector<bool>> occupied;
		Grid(int w, int h);
		void FillCell(int x, int y);
		void UnFillCell(int x, int y);
		bool isFinish(Grid *block);
		std::vector<std::vector<bool>> Union(std::vector<std::vector<bool>> &c1, std::vector<std::vector<bool>> &c2);
		bool isRow(int index, bool predicate);
		bool isColumn(int index, bool predicate);

		void ShiftToLeft();
		void ShiftToRight();
		void ShiftToDown(int index);

	};
}
