//---------------------------------------------------------------------------

#ifndef NebunH
#define NebunH
#include "Piesa.h"
//---------------------------------------------------------------------------

class Nebun:public Piesa
{
public:
	Nebun(int x, int y):Piesa(x, y){}
    bool poateMisca(int dx, int dy, bool captureaza = false);
};
#endif
