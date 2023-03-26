//---------------------------------------------------------------------------

#pragma hdrstop

#include "Rege.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool Rege::poateMisca(int dx, int dy, bool captureaza)
{
	if(esteViu)
	{
		if(abs(pozitieX - dx) <= 1 && abs(pozitieY - dy) <= 1)
		{
			return true;
		}
	}
	return false;
}
