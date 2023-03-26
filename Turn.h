//---------------------------------------------------------------------------

#ifndef TurnH
#define TurnH
#include "Piesa.h"
//---------------------------------------------------------------------------
class Turn:public Piesa
{
public:
	Turn(int x, int y):Piesa(x, y){}
	bool poateMisca(int dx, int dy, bool captureaza = false);
};
#endif
