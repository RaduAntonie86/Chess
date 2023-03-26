//---------------------------------------------------------------------------

#ifndef PiesaH
#define PiesaH
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------


class Piesa
{
protected:
	int pozitieX;
	int pozitieY;
	bool esteViu;
public:
	TImage *imagine;
	Piesa(int x, int y);
	void miscaPiesa(int dx, int dy);
	virtual bool poateMisca(int dx, int dy, bool captureaza = false) = 0;
	void moarePiesa();
	void selecteaza();
	void deselecteaza();
	int verificaX();
	int verificaY();
	bool verificaViata();
};
#endif
