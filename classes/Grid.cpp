#include "Grid.h"

namespace WinTetris
{

	Grid::Grid(int w, int h) : width(w), height(h)
	{
//C# TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in C#:
//ORIGINAL LINE: occupied = new bool[w, h];
		occupied = RectangularVectors::RectangularBoolVector(w, h);
	}

	void Grid::FillCell(int x, int y)
	{
		occupied[x][y] = true;
	}

	void Grid::UnFillCell(int x, int y)
	{
		occupied[x][y] = false;
	}

	bool Grid::isFinish(Grid *block)
	{
		for (int i = 0; i < block->occupied.size(); i++)
		{
			for (int j = 0; j < (block->occupied.size() == 0 ? 0 : block->occupied[0].size()); j++)
			{
				if (block->occupied[i][j])
				{
					if (j == 0 || this->occupied[i][j - 1])
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	std::vector<std::vector<bool>> Grid::Union(std::vector<std::vector<bool>> &c1, std::vector<std::vector<bool>> &c2)
	{
//C# TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in C#:
//ORIGINAL LINE: bool[,] result = new bool[c1.GetLength(0), c1.GetLength(1)];
		std::vector<std::vector<bool>> result = RectangularVectors::RectangularBoolVector(c1.size(), (c1.size() == 0 ? 0 : c1[0].size()));
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < (result.size() == 0 ? 0 : result[0].size()); j++)
			{
				result[i][j] = c1[i][j] | c2[i][j];
			}
		}
		return result;
	}

	bool Grid::isRow(int index, bool predicate)
	{
		Grid *g = this;
		int w = g->occupied.size();
		bool r = true;
		for (int i = 0; i < w; i++)
		{
			if (g->occupied[i][index] != predicate)
			{
				r = false;
			}
		}
		return r;
	}

	bool Grid::isColumn(int index, bool predicate)
	{
		Grid *g = this;

		int h = (g->occupied.size() == 0 ? 0 : g->occupied[0].size());
		bool r = true;
		for (int i = 0; i < h; i++)
		{
			if (g->occupied[index][i] != predicate)
			{
				r = false;
			}
		}
		return r;
	}

	void Grid::ShiftToLeft()
	{
		Grid *g = this;
		int w = g->occupied.size();
		int h = (g->occupied.size() == 0 ? 0 : g->occupied[0].size());

		for (int i = 1; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				g->occupied[i - 1][j] = g->occupied[i][j];
			}
		}
		for (int j = 0; j < h; j++)
		{
			g->occupied[w - 1][j] = false;
		}

	}

	void Grid::ShiftToRight()
	{
		Grid *g = this;
		int w = g->occupied.size();
		int h = (g->occupied.size() == 0 ? 0 : g->occupied[0].size());

		for (int i = w - 1; i > 0; i--)
		{
			for (int j = 0; j < h; j++)
			{
				g->occupied[i][j] = g->occupied[i - 1][j];
			}
		}
		for (int j = 0; j < h; j++)
		{
			g->occupied[0][j] = false;
		}
	}

	void Grid::ShiftToDown(int index)
	{
		Grid *g = this;
		int w = g->occupied.size();
		int h = (g->occupied.size() == 0 ? 0 : g->occupied[0].size());

		for (int j = index + 1; j < h; j++)
		{
			for (int i = 0; i < w; i++)
			{
				g->occupied[i][j - 1] = g->occupied[i][j];
			}
		}
		for (int i = 0; i < w; i++)
		{
			g->occupied[i][h - 1] = false;
		}
	}
}
