//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *HowManyVertex;
	TButton *Button1;
	TButton *ClearAll;
	TLabel *Label3;
	TLabel *Label4;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TTimer *Timer1;
	TLabel *Label5;
	TLabel *Label6;
	TListBox *ListBox3;
	TListBox *ListBox4;
	TLabel *Label7;
	TEdit *AngleEdit;
	TButton *Button2;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ClearAllClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
