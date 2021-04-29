//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "MyFigure.h"
#include "Eyes.h"
#include "MyFigure.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
double DegToRad(int x){
	return ((double)x)/180*acos(-1);
}

double dsin(int x){
	return sin(DegToRad(x));
}
double dcos(int x){
	return cos(DegToRad(x));
}


Mouth *mouth;

Eyes *eyes;

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	   Timer1->Enabled=false;
	   MyFigure tmp(Form1);
	   eyes = new Eyes(Form1,305,230,440,230);
	   mouth = new Mouth(Form1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EyesButtonClick(TObject *Sender)
{
	for(int i=1;i<36000000;i++)
	{
			if(i%100000==0){
			eyes->Redraw(Form1);
			eyes->Move(eyes->x0+eyes->r*dcos(i/100000),eyes->y0+eyes->r*dsin(i/100000),eyes->x1+eyes->r*dcos(i/100000),eyes->y1+eyes->r*dsin(i/100000), 10, Form1);
			mouth->Move(mouth->x1,mouth->x2,mouth->y,mouth->r,Form1);
			}

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	for(int i=1;i<36000000;i++)
	{
			if(i%200000==0){
				eyes->Redraw(Form1);
				mouth->Move(mouth->x1,mouth->x2,mouth->y,mouth->r*dcos(i/200000),Form1);
				eyes->Move(eyes->x0+eyes->r,eyes->y0,eyes->x1+eyes->r,eyes->y1, 10, Form1);

			}

	}
}
//---------------------------------------------------------------------------

