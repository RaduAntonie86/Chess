//---------------------------------------------------------------------------

#pragma hdrstop

#include "Piesa.h"
#include "sah.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Piesa::Piesa(int x, int y)
{
	pozitieX = x;
	pozitieY = y;
    esteViu = true;
}

void Piesa::moarePiesa()
{
	esteViu = false;
}


void Piesa::deselecteaza()
{
	imagine->Width = 78;
	imagine->Height = 78;
}

int Piesa::verificaX()
{
	return pozitieX;
}

int Piesa::verificaY()
{
	return pozitieY;
}

bool Piesa::verificaViata()
{
	return esteViu;
}

void Piesa::miscaPiesa(int dx, int dy)
{
	pozitieX = dx;
	pozitieY = dy;
	imagine->Left = dx - (dx - dx * 78);
	imagine->Top = dy - (dy - dy * 78);
}
