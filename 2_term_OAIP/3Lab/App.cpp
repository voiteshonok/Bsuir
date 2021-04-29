//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "App.h"
#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
List *list = new List;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear();
	ComboBox1->Items->Add("Add");
    ComboBox1->Items->Add("Find trains by day");
    ComboBox1->Items->Add("Display trains in direction no later than");
    ComboBox1->Items->Add("Book seats by ID");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
     delete list;
}
//---------------------------------------------------------------------------
void showByNode(TMemo *mem,Node *n)
{
	 mem->Lines->Add("ID: "+IntToStr(n->getId())+" Destination: "+ n->getDestination()+" Day: "+n->getDay()+" "+IntToStr(n->getHH())+":"+IntToStr(n->getMM())+" Seats:"+IntToStr(n->getSeats()));
}

void show(TMemo *mem)
{
	mem->Clear();
	for(Node* q=list->head;q!=NULL;q=q->next)
			{
				showByNode(mem,q);
			}
}

void __fastcall TForm1::ShowClick(TObject *Sender)
{
	show(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	ListBox1->Clear();
	IdEdit->Clear();
	DayEdit->Clear();
	DestinationEdit->Clear();
	HHEdit->Clear();
	SeatsEdit->Clear();
	MMEdit->Clear();
	if(ComboBox1->ItemIndex==0)
	{
		DayEdit->Enabled=true;
		DestinationEdit->Enabled=true;
		HHEdit->Enabled=true;
		SeatsEdit->Enabled=true;
		MMEdit->Enabled=true;
		if(list->head)
		{
			IdEdit->Text=list->head->getId();
		}else
		{
			IdEdit->Text=0;
        }
	   IdEdit->Enabled=false;
	}else if(ComboBox1->ItemIndex==1)
	{
		IdEdit->Enabled=false;
		DayEdit->Enabled=true;
		DestinationEdit->Enabled=false;
		HHEdit->Enabled=false;
		SeatsEdit->Enabled=false;
		MMEdit->Enabled=false;
	}else if(ComboBox1->ItemIndex==2)
	{
		IdEdit->Enabled=false;
		DayEdit->Enabled=true;
		DestinationEdit->Enabled=false;
		HHEdit->Enabled=true;
		SeatsEdit->Enabled=false;
		MMEdit->Enabled=true;
	}else
	{
		IdEdit->Enabled=true;
		DayEdit->Enabled=false;
		DestinationEdit->Enabled=false;
		HHEdit->Enabled=false;
		SeatsEdit->Enabled=true;
		MMEdit->Enabled=false;
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::OKClick(TObject *Sender)
{
	ListBox1->Clear();
    Memo1->Clear();
	 if(ComboBox1->ItemIndex==0)
	{
		try
		{
			Node *tmp = new Node;
			tmp->setDay(DayEdit->Text);
			tmp->setDestination(DestinationEdit->Text);
			tmp->setHH(StrToInt(HHEdit->Text));
			tmp->setMM(StrToInt(MMEdit->Text));
			tmp->setSeats(StrToInt(SeatsEdit->Text));
			if(list->head)
			{
				tmp->setId(1+list->head->getId());
			}else
			{
				 tmp->setId(1);
			}
			for(Node* q=list->head;q!=NULL;q=q->next)
			{
				if(q->getDay()==tmp->getDay() && q->getDestination()==tmp->getDestination() && q->getHH()==tmp->getHH() && q->getMM()==tmp->getMM())
				{
					throw String("there is already such train");
				}
			}
			list->Push(tmp);
			IdEdit->Text=list->head->getId();
            show(Memo1);
		}catch(String str)
		{
			ListBox1->Items->Add(str);
		}catch(...){
			 ListBox1->Items->Add("invalid input");
		}
	}else if(ComboBox1->ItemIndex==1)
	{
		bool ok=false;
		 for(Node* q=list->head;q!=NULL;q=q->next)
			{
			   if(q->getDay()==DayEdit->Text)
			   {
				   showByNode(Memo1,q);
				   ok=true;
			   }
			}
		 if(!ok)
		 {
			 ListBox1->Items->Add("there is no trains for this day");
		 }
	}else if(ComboBox1->ItemIndex==2)
	{
        for(Node* q=list->head;q!=NULL;q=q->next)
			{
			   if(q->getDay()==DayEdit->Text && q->getMM()>=StrToInt(MMEdit->Text) && q->getHH()>=StrToInt(HHEdit->Text))
			   {
				   showByNode(Memo1,q);
               }
			}
	}else
	{
		try
		{
		   for(Node* q=list->head;q!=NULL;q=q->next)
			{
			   if(q->getId()==StrToInt(IdEdit->Text))
			   {
				   if(q->getSeats()>=StrToInt(SeatsEdit->Text))
				   {
					   q->setSeats(q->getSeats()-StrToInt(SeatsEdit->Text));
                       show(Memo1);
						break;
				   }else{
					   throw 1;
				   }
			   }
			}
		}
		catch(...)
		{
			ListBox1->Items->Add("impossible to perform an order");
		}
	}
}
//---------------------------------------------------------------------------

