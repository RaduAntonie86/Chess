//---------------------------------------------------------------------------

#pragma hdrstop

#include "Turn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool Turn::poateMisca(int dx, int dy, bool captureaza)
{
	if(esteViu)
	{
		if(abs(pozitieX - dx) == 0 || abs(pozitieY - dy) == 0)
		{
			return true;
		}
	}
	return false;
}
