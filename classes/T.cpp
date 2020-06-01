#include "T.h"

namespace WinTetris
{

	T::T()
	{
		occupied[1][0] = true;

		occupied[0][1] = true;
		occupied[1][1] = true;
		occupied[2][1] = true;
	}
}
