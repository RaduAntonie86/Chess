//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "sah.h"
#include <string>
#include "Victorie.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMain *fMain;
//---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner)
	: TForm(Owner)
{
	for(int i = 0;i<8;i++)
	{
		tabla[0][i] = 1;
		tabla[1][i] = 1;
		tabla[6][i] = 2;
		tabla[7][i] = 2;
		pieseNegre[i+8] = new Pion(i, 1);
		pieseAlbe[i+8] = new Pion(i, 6);
	}

	pieseNegre[0] = new Turn(0, 0); pieseNegre[0]->imagine = imgTurnNegruStanga;
	pieseNegre[1] = new Cal(1, 0); pieseNegre[1]->imagine = imgCalNegruStanga;
	pieseNegre[2] = new Nebun(2, 0); pieseNegre[2]->imagine = imgNebunNegruStanga;
	pieseNegre[3] = new Regina(3, 0); pieseNegre[3]->imagine = imgReginaNegru;
	pieseNegre[4] = new Rege(4, 0); pieseNegre[4]->imagine = imgRegeNegru;
	pieseNegre[5] = new Nebun(5, 0); pieseNegre[5]->imagine = imgNebunNegruDreapta;
	pieseNegre[6] = new Cal(6, 0); pieseNegre[6]->imagine = imgCalNegruDreapta;
	pieseNegre[7] = new Turn(7, 0); pieseNegre[7]->imagine = imgTurnNegruDreapta;
	pieseNegre[8]->imagine = imgPionNegruA;
	pieseNegre[9]->imagine = imgPionNegruB;
	pieseNegre[10]->imagine = imgPionNegruC;
	pieseNegre[11]->imagine = imgPionNegruD;
	pieseNegre[12]->imagine = imgPionNegruE;
	pieseNegre[13]->imagine = imgPionNegruF;
	pieseNegre[14]->imagine = imgPionNegruG;
	pieseNegre[15]->imagine = imgPionNegruH;
	pieseAlbe[0] = new Turn(0, 7); pieseAlbe[0]->imagine = imgTurnAlbStanga;
	pieseAlbe[1] = new Cal(1, 7); pieseAlbe[1]->imagine = imgCalAlbStanga;
	pieseAlbe[2] = new Nebun(2, 7); pieseAlbe[2]->imagine = imgNebunAlbStanga;
	pieseAlbe[3] = new Regina(3, 7); pieseAlbe[3]->imagine = imgReginaAlb;
	pieseAlbe[4] = new Rege(4, 7); pieseAlbe[4]->imagine = imgRegeAlb;
	pieseAlbe[5] = new Nebun(5, 7); pieseAlbe[5]->imagine = imgNebunAlbDreapta;
	pieseAlbe[6] = new Cal(6, 7); pieseAlbe[6]->imagine = imgCalAlbDreapta;
	pieseAlbe[7] = new Turn(7, 7); pieseAlbe[7]->imagine = imgTurnAlbDreapta;
	pieseAlbe[8]->imagine = imgPionAlbA;
	pieseAlbe[9]->imagine = imgPionAlbB;
	pieseAlbe[10]->imagine = imgPionAlbC;
	pieseAlbe[11]->imagine = imgPionAlbD;
	pieseAlbe[12]->imagine = imgPionAlbE;
	pieseAlbe[13]->imagine = imgPionAlbF;
	pieseAlbe[14]->imagine = imgPionAlbG;
	pieseAlbe[15]->imagine = imgPionAlbH;

}
//---------------------------------------------------------------------------

void __fastcall TfMain::imgTablaClick(TObject *Sender)
{
	TPoint p_rel_scr = Mouse->CursorPos;
	TPoint p_rel_frm = fMain->ScreenToClient(p_rel_scr);
	int x_position = (int) p_rel_frm.x / 78;
	int y_position = (int) p_rel_frm.y / 78;
	if(selectie != INT_MAX)
	{
		if(tura && verificaOcuparea(pieseNegre, selectie, x_position, y_position, tura, pieseAlbe))
		{
			tabla[y_position][x_position] = 1;
			tabla[pieseNegre[selectie]->verificaY()][pieseNegre[selectie]->verificaX()] = 0;
			pieseNegre[selectie]->miscaPiesa(x_position, y_position);
			pieseNegre[selectie]->deselecteaza();
			tura = false;
			selectie = INT_MAX;
			if(sahMat(pieseAlbe, tura, pieseNegre))
			{
				fVictorie->ShowModal();
			}
		}
		else if(!tura && verificaOcuparea(pieseAlbe, selectie, x_position, y_position, tura, pieseNegre))
		{
			tabla[y_position][x_position] = 2;
			tabla[pieseAlbe[selectie]->verificaY()][pieseAlbe[selectie]->verificaX()] = 0;
			pieseAlbe[selectie]->miscaPiesa(x_position, y_position);
			pieseAlbe[selectie]->deselecteaza();
			tura = true;
			selectie = INT_MAX;
			if(sahMat(pieseNegre, tura, pieseAlbe))
			{
				fVictorie->ShowModal();
			}
		}
	}
}

void __fastcall TfMain::imgAlbClick(TObject *Sender)
{
	img = (TImage*)Sender;
	for(int i = 0; i < 16; i++)
	{
		if(pieseAlbe[i]->imagine == img)
		{
			if(!tura && pieseAlbe[i]->verificaViata())
			{
				if(selectie != i)
				{
					pieseAlbe[i]->imagine->Width = 64;
					pieseAlbe[i]->imagine->Height = 64;
					pieseAlbe[i]->imagine->Top+=7;
					pieseAlbe[i]->imagine->Left+=7;
					if(selectie != INT_MAX)
					{
						pieseAlbe[selectie]->imagine->Width = 78;
						pieseAlbe[selectie]->imagine->Height = 78;
						pieseAlbe[selectie]->imagine->Top-=7;
						pieseAlbe[selectie]->imagine->Left-=7;
					}
					selectie = i;
				}
			}
			else if(selectie < 16 && i != 4)
			{
				if(verificaOcuparea(pieseNegre, selectie, pieseAlbe[i]->verificaX(), pieseAlbe[i]->verificaY(), tura, pieseAlbe, false, true))
				{
					tabla[pieseNegre[selectie]->verificaY()][pieseNegre[selectie]->verificaX()] = 0;
					pieseNegre[selectie]->miscaPiesa(pieseAlbe[i]->verificaX(), pieseAlbe[i]->verificaY());
					pieseAlbe[i]->imagine->Visible = false;
					pieseAlbe[i]->moarePiesa();
					tabla[pieseNegre[selectie]->verificaY()][pieseNegre[selectie]->verificaX()] = 1;
					pieseNegre[selectie]->deselecteaza();
					tura = false;
					selectie = INT_MAX;
					if(sahMat(pieseAlbe, tura, pieseNegre))
					{
						fVictorie->ShowModal();
					}
				}
			}
		}
	}
}

void __fastcall TfMain::imgNegruClick(TObject *Sender)
{
	img = (TImage*)Sender;
	for(int i = 0; i < 16; i++)
	{
		if(pieseNegre[i]->imagine == img)
		{
			if(tura && pieseNegre[i]->verificaViata())
			{
				if(selectie != i)
				{
					pieseNegre[i]->imagine->Width = 64;
					pieseNegre[i]->imagine->Height = 64;
					pieseNegre[i]->imagine->Top+=7;
					pieseNegre[i]->imagine->Left+=7;
					if(selectie != INT_MAX)
					{
						pieseNegre[selectie]->imagine->Width = 78;
						pieseNegre[selectie]->imagine->Height = 78;
						pieseNegre[selectie]->imagine->Top-=7;
						pieseNegre[selectie]->imagine->Left-=7;
					}
					selectie = i;
				}
			}
			else if(selectie < 16 && i != 4)
			{
				if(verificaOcuparea(pieseAlbe, selectie, pieseNegre[i]->verificaX(), pieseNegre[i]->verificaY(), tura, pieseNegre, false, true))
				{
					tabla[pieseAlbe[selectie]->verificaY()][pieseAlbe[selectie]->verificaX()] = 0;
					pieseAlbe[selectie]->miscaPiesa(pieseNegre[i]->verificaX(), pieseNegre[i]->verificaY());
					pieseNegre[i]->imagine->Visible = false;
					pieseNegre[i]->moarePiesa();
					tabla[pieseAlbe[selectie]->verificaY()][pieseAlbe[selectie]->verificaX()] = 2;
					pieseAlbe[selectie]->deselecteaza();
					tura = true;
					selectie = INT_MAX;
					if(sahMat(pieseNegre, tura, pieseAlbe))
					{
						fVictorie->ShowModal();
					}
				}
			}
		}
	}
}
//---------------------------------------------------------------------------



