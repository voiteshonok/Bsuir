//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "App.h"
#include "Solution.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
auto queue = new Solution;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    delete queue;
}
//---------------------------------------------------------------------------
void show(TMemo *mem)
{
    mem->Clear();
	Node *tmp = queue->head;int i=1;
	while(tmp!=NULL)
	{
		mem->Lines->Add(IntToStr(tmp->data));
		tmp=tmp->prev;
		i++;
    }
}

void __fastcall TForm1::PushButtonClick(TObject *Sender)
{
   try
   {
	   queue->push(StrToInt(PushEdit->Text));
   }catch(...){}
   PushEdit->Clear();
   show(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SortButtonClick(TObject *Sender)
{
	if(queue->head!=queue->tail)
	{
       queue->sort();
		show(Memo1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PopButtonClick(TObject *Sender)
{
	if(queue->head!=NULL)
	{
		queue->pop();
    }
    show(Memo1);
}
//---------------------------------------------------------------------------

