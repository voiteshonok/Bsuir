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
	TComboBox *ComboBox1;
	TMemo *Memo1;
	TListBox *ListBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *IdEdit;
	TEdit *DestinationEdit;
	TEdit *DayEdit;
	TEdit *HHEdit;
	TEdit *MMEdit;
	TEdit *SeatsEdit;
	TButton *OK;
	TButton *Show;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ShowClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall OKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
