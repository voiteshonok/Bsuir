//---------------------------------------------------------------------------

#ifndef MyAppH
#define MyAppH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TApp : public TForm
{
__published:	// IDE-managed Components
	TMemo *groomsMemo;
	TMemo *bridesMemo;
	TButton *SaveButton;
	TButton *ShowButton;
	TComboBox *optionComboBox;
	TButton *OpenButton;
	TLabel *DeleteByIdLabel;
	TEdit *DeletedIdEdit;
	TButton *DeleteByIdButton;
	TButton *pairsButton;
	TLabel *Id1;
	TLabel *Id2;
	TButton *makePairButton;
	TEdit *Id1Edit;
	TEdit *Id2Edit;
	TLabel *Label1;
	TLabel *Label2;
	TComboBox *sexComboBox;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label14;
	TLabel *Label17;
	TEdit *idEdit;
	TEdit *nameEdit;
	TEdit *ageEdit;
	TEdit *heightEdit;
	TEdit *weightEdit;
	TEdit *habbitEdit;
	TEdit *hobbyEdit;
	TEdit *maxHeightEdit;
	TEdit *minHeightEdit;
	TEdit *maxWeightEdit;
	TEdit *minWeightEdit;
	TEdit *maxAgeEdit;
	TEdit *minAgeEdit;
	TButton *AddButton;
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall optionComboBoxChange(TObject *Sender);
	void __fastcall idEditKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ShowButtonClick(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall DeleteByIdButtonClick(TObject *Sender);
	void __fastcall pairsButtonClick(TObject *Sender);
	void __fastcall makePairButtonClick(TObject *Sender);
	void __fastcall OpenButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TApp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TApp *App;
//---------------------------------------------------------------------------
#endif
