//---------------------------------------------------------------------------

#ifndef ReginaH
#define ReginaH
#include "Piesa.h"
//---------------------------------------------------------------------------
class Regina:public Piesa
{
public:
	Regina(int x, int y):Piesa(x, y){}
	bool poateMisca(int dx, int dy, bool captureaza = false);
};
#endif
