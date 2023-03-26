//---------------------------------------------------------------------------

#pragma hdrstop

#include "Nebun.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool Nebun::poateMisca(int dx, int dy, bool captureaza)
{
	if(esteViu)
	{
		if(abs(dy - verificaY()) == abs(dx - verificaX()))
		{
			return true;
		}
	}
	return false;
}
