//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Victorie.h"
#include "sah.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfVictorie *fVictorie;
//---------------------------------------------------------------------------
__fastcall TfVictorie::TfVictorie(TComponent* Owner)
	: TForm(Owner)
{
	if(fMain->tura)
		tVictorie->Caption = "Jucatorul negru a castigat!";
	else
		tVictorie->Caption = "Jucatorul alb a castigat!";
}
//---------------------------------------------------------------------------
void __fastcall TfVictorie::Button1Click(TObject *Sender)
{
	exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TfVictorie::FormClose(TObject *Sender, TCloseAction &Action)
{
	exit(0);
}
//---------------------------------------------------------------------------

