//---------------------------------------------------------------------------

#ifndef AppH
#define AppH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *PushButton;
	TEdit *PushEdit;
	TButton *SortButton;
	TButton *PopButton;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PushButtonClick(TObject *Sender);
	void __fastcall SortButtonClick(TObject *Sender);
	void __fastcall PopButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
