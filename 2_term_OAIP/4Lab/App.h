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
	TEdit *AEdit;
	TLabel *Label1;
	TEdit *BEdit;
	TLabel *Label2;
	TEdit *CEdit;
	TLabel *Label3;
	TEdit *EEdit;
	TLabel *Label4;
	TEdit *DEdit;
	TLabel *Label5;
	TEdit *InfEdit;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *CulculateButton;
	TListBox *postForm;
	TListBox *result;
	void __fastcall CulculateButtonClick(TObject *Sender);
	void __fastcall AEditChange(TObject *Sender);
	void __fastcall BEditChange(TObject *Sender);
	void __fastcall CEditChange(TObject *Sender);
	void __fastcall DEditChange(TObject *Sender);
	void __fastcall EEditChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
