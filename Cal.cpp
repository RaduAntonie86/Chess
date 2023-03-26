//---------------------------------------------------------------------------

#pragma hdrstop

#include "Cal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool Cal::poateMisca(int dx, int dy, bool captureaza)
{
	if(esteViu)
	{
		if((abs(dx - pozitieX)== 2 && abs(dy - pozitieY)== 1) || (abs(dx - pozitieX)== 1 && abs(dy - pozitieY)== 2))
		{
			return true;
		}
	}
	return false;
}
