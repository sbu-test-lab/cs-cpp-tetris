#include "Tetris.h"
#include "Screen.h"
#include "Block.h"
#include "Grid.h"
#include "Square.h"
#include "Rectangle.h"
#include "L.h"
#include "S.h"
#include "T.h"
#include "Z.h"
#include "ReverseL.h"

namespace WinTetris
{

int Tetris::DIRECT = 0;
int Tetris::LEFT = 1;
int Tetris::RIGHT = 2;
int Tetris::ROTATE = 3;

	Tetris::Tetris()
	{
		screen = new Screen();
		score = 0;
		AddBlock();
	}

	void Tetris::RunOneStep(int dir)
	{
		if (!screen->isFinish(block->BeAddedToScreen()))
		{
			if (dir == LEFT)
			{
				block->MoveLeft();
			}
			else if (dir == RIGHT)
			{
				block->MoveRight();
			}
			else if (dir == ROTATE)
			{
				block->Rotate();
			}
			else
			{
				block->MoveDown();
			}
		}
		else
		{
			screen->AddBlock(block->BeAddedToScreen());
			AddBlock();
		}
		screen->RemoveBlock(this);
	}

	Grid *Tetris::GetGmaeFrame()
	{
		return screen->Union(screen, block->BeAddedToScreen());
	}

	void Tetris::AddBlock()
	{
	Random *r = new Random(DateTime::Now.Millisecond);
	switch (r->Next(8))
	{
		case 0:
			block = new Square();
			break;
		case 1:
			block = new Rectangle();
			break;
		case 2:
			block = new Square();
			break;
		case 3:
			block = new L();
			break;
		case 4:
			block = new S();
			break;
		case 5:
			block = new T();
			break;
		case 6:
			block = new Z();
			break;
		case 7:
			block = new ReverseL();
			break;
	}

	delete r;
	}

	void Tetris::AdvanceScore()
	{
		score += 10;
	}
}
