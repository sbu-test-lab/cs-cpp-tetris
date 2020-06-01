#include "Polygon.h"

namespace WinTetris
{

	Polygon::Polygon() : Block(3)
	{
	}

	void Polygon::Rotate()
	{
//C# TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in C#:
//ORIGINAL LINE: bool[,] rot = new bool[this.width, this.width];
		std::vector<std::vector<bool>> rot = RectangularVectors::RectangularBoolVector(this->width, this->width);
		for (int i = 0; i < this->height; i++)
		{
			rot[i][2] = this->occupied[0][i];
			rot[i][1] = this->occupied[1][i];
			rot[i][0] = this->occupied[2][i];
		}
		this->occupied = rot;
	}
}
