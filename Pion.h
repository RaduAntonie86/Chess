//---------------------------------------------------------------------------

#ifndef PionH
#define PionH
#include "Piesa.h"
//---------------------------------------------------------------------------

class Pion:public Piesa
{
public:
	bool primaMana;
	Pion(int x, int y);
    bool poateMisca(int dx, int dy, bool captureaza = 0);
};
#endif
