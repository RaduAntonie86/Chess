//---------------------------------------------------------------------------

#pragma hdrstop

#include "Pion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Pion::Pion(int x, int y):Piesa(x, y)
{
    primaMana = false;
}

bool Pion::poateMisca(int dx, int dy, bool captureaza)
{
	if(esteViu)
	{
		if(abs(dy - verificaY()) - 1 + (int) primaMana < 2 && dx - verificaX() == 0 && !captureaza)
		{
			primaMana = true;
			return true;
		}
		else if(captureaza && abs(dy - pozitieY) == 1 && abs(dx - pozitieX) == 1)
		{
			return true;
		}
	}
	return false;
}
