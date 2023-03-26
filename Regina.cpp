//---------------------------------------------------------------------------

#pragma hdrstop

#include "Regina.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


bool Regina::poateMisca(int dx, int dy, bool captureaza)
{
	if(esteViu)
	{
		if(abs(pozitieX - dx) == 0 || abs(pozitieY - dy) == 0 || abs(dy - verificaY()) == abs(dx - verificaX()))
		{
			return true;
		}
	}
	return false;
}