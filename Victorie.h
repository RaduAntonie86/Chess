//---------------------------------------------------------------------------

#ifndef VictorieH
#define VictorieH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TfVictorie : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *tVictorie;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfVictorie(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfVictorie *fVictorie;
//---------------------------------------------------------------------------
#endif
