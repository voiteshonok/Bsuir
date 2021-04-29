//---------------------------------------------------------------------------

#ifndef MyAppH
#define MyAppH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TApp : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo;
	TLabel *Label;
	TEdit *EditSize;
	TButton *ButtonRandom;
	TButton *ButtonFind;
	TButton *ButtonDelete;
	TButton *ButtonFindMin;
	TEdit *EditFindOrDelete;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonRandomClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonFindMinClick(TObject *Sender);
	void __fastcall ButtonFindClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TApp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TApp *App;
//---------------------------------------------------------------------------
#endif
