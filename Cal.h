//---------------------------------------------------------------------------

#ifndef CalH
#define CalH
#include "Piesa.h"
//---------------------------------------------------------------------------
class Cal:public Piesa
{
public:
	Cal(int x, int y):Piesa(x, y){}
    bool poateMisca(int dx, int dy, bool captureaza = false);
};

#endif
