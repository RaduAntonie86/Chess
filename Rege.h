//---------------------------------------------------------------------------

#ifndef RegeH
#define RegeH
#include "Piesa.h"
//---------------------------------------------------------------------------
class Rege:public Piesa
{
public:
	Rege(int x, int y):Piesa(x, y){}
	bool poateMisca(int dx, int dy, bool captureaza = false);
};
#endif
