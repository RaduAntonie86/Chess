//---------------------------------------------------------------------------

#ifndef sahH
#define sahH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
#include "Pion.h"
#include "Nebun.h"
#include "Cal.h"
#include "Turn.h"
#include "Rege.h"
#include "Regina.h"
#include <string>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>

class TfMain : public TForm
{
__published:	// IDE-managed Components
	TImage *imgPionAlbA;
	TImage *imgTurnAlbStanga;
	TImage *imgCalAlbStanga;
	TImage *imgNebunAlbStanga;
	TImage *imgRegeAlb;
	TImage *imgReginaAlb;
	TImage *imgCalNegruStanga;
	TImage *imgCalNegruDreapta;
	TImage *imgNebunNegruDreapta;
	TImage *imgNebunNegruStanga;
	TImage *imgPionNegruA;
	TImage *imgPionNegruD;
	TImage *imgPionNegruE;
	TImage *imgPionNegruF;
	TImage *imgPionNegruG;
	TImage *imgPionNegruH;
	TImage *imgRegeNegru;
	TImage *imgReginaNegru;
	TImage *imgTurnNegruDreapta;
	TImage *imgTurnNegruStanga;
	TImage *imgPionNegruC;
	TImage *imgPionNegruB;
	TImage *imgPionAlbB;
	TImage *imgPionAlbH;
	TImage *imgPionAlbG;
	TImage *imgPionAlbF;
	TImage *imgPionAlbC;
	TImage *imgPionAlbD;
	TImage *imgPionAlbE;
	TImage *imgCalAlbDreapta;
	TImage *imgNebunAlbDreapta;
	TImage *imgTurnAlbDreapta;
	TImage *imgTabla;
	void __fastcall imgTablaClick(TObject *Sender);
	void __fastcall imgAlbClick(TObject *Sender);
	void __fastcall imgNegruClick(TObject *Sender);

private:	// User declarations
int tabla[8][8];
Piesa *pieseNegre[16];
Piesa *pieseAlbe[16];
int selectie = INT_MAX;
TImage *img;

bool verificaOcuparea(Piesa *piese[16], int selectie, int dx, int dy, bool tura, Piesa *pieseOpuse[16], bool sahmat = false, bool captureaza = false)
{
	int xTemp = dx, yTemp = dy;
	if(selectie != 1 || selectie != 6) // Calul poate sari peste celelalte piese
	{
		while(xTemp != piese[selectie]->verificaX() || yTemp != piese[selectie]->verificaY())
		{
			if(tabla[yTemp][xTemp] == 2 - (int) tura)
			{
				return false;
			}
			if(xTemp > piese[selectie]->verificaX())
			{
				xTemp--;
			}
			else if (xTemp < piese[selectie]->verificaX())
			{
				xTemp++;
			}
			if(yTemp > piese[selectie]->verificaY())
			{
				yTemp--;
			}
			else if(yTemp < piese[selectie]->verificaY())
			{
				yTemp++;
			}
		}
		xTemp = dx;
		yTemp = dy;
		while(xTemp != piese[selectie]->verificaX() || yTemp != piese[selectie]->verificaY())
		{
			if(tabla[yTemp][xTemp] == 1 + (int) tura && !sahmat && captureaza)
			{
				for(int i=0;i<16;i++)
				{
					if(pieseOpuse[i]->verificaX() == xTemp && pieseOpuse[i]->verificaY() == yTemp && piese[selectie]->poateMisca(dx, dy))
					{
						pieseOpuse[i]->imagine->Visible = false;
						pieseOpuse[i]->moarePiesa();
					}
				}
			}
			if(xTemp > piese[selectie]->verificaX())
			{
				xTemp--;
			}
			else if (xTemp < piese[selectie]->verificaX())
			{
				xTemp++;
			}
			if(yTemp > piese[selectie]->verificaY())
			{
				yTemp--;
			}
			else if(yTemp < piese[selectie]->verificaY())
			{
				yTemp++;
			}
		}
	}
	//Label1->Caption = yTemp;
	//Label2->Caption = xTemp;
	return piese[selectie]->poateMisca(dx, dy);
}

bool sahMat(Piesa *piese[16], bool tura, Piesa *pieseOpuse[16])
{
	 int miscariPosibile = 0, sahmat = 0;
	 for(int i=-1;i<=1;i++)
	 {
		 for(int j=-1;j<=1;j++)
		 {
			if(piese[4]->verificaX() + i >= 0 && piese[4]->verificaY() + j >= 0)
			{
				if(piese[4]->verificaX() + i <= 7 && piese[4]->verificaY() + j <= 7)
				{
					if(verificaOcuparea(piese, 4, piese[4]->verificaX() + i, piese[4]->verificaY() + j, tura, pieseOpuse))
					{
						miscariPosibile++;
					}
					for(int k=0;k<16;k++)
					{
						if(verificaOcuparea(pieseOpuse, k, piese[4]->verificaX() + i, piese[4]->verificaY() + j, !tura, piese, true))
						{
							//for(int l=0;l<16;l++)
							//{
								//if(verificaOcuparea(piese, l, pieseOpuse[k]->verificaX(), pieseOpuse[k]->verificaY(), tura, pieseOpuse, true))
									//return false;
							//}
							sahmat++;
						}
					}

				}
			}
		 }
	 }
	 if(miscariPosibile - 1 <= sahmat && sahmat != 0)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
     }
}

public:		// User declarations
bool tura = false;
	__fastcall TfMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif
