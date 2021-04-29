//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdlib.h>
#include "string"
#include <math.h>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Circle C;
MyPolygon P;
Circle *Circ = NULL;
MyPolygon *Pol = NULL;
int n=-1,drag=-1,arrX[100],arrY[100];

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	  Image1->Canvas->Rectangle(0,0,1000,1000);
      Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClearAllClick(TObject *Sender)
{
	  Image1->Canvas->Rectangle(0,0,1000,1000);
	  Circ=NULL;
	  Pol=NULL;
	  n=-1;
	  ListBox1->Items->Clear();
	  ListBox2->Items->Clear();
	  ListBox3->Items->Clear();
	  ListBox4->Items->Clear();
	  HowManyVertex->Clear();
      AngleEdit->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int number;
	try{  number = StrToInt(HowManyVertex->Text);
	} catch(Exception &exception)
	{
		  number = -1;
    }
	  if(number==0 || number >2)
	  {
			Image1->Canvas->Rectangle(0,0,1000,1000);
		   if(number==0)
		   {
			   Circle tmp(Image1);
			   Pol=NULL;
			   C.copy(tmp);
			   Circ=&C;
			   ListBox1->Items->Clear();
				ListBox2->Items->Clear();
				ListBox3->Items->Clear();
				ListBox4->Items->Clear();
				ListBox1->Items->Add(Circ->getP());
				ListBox2->Items->Add(Circ->getS());
				ListBox3->Items->Add(Circ->centreX);
				ListBox4->Items->Add(Circ->centreY);
				Image1->Canvas->Ellipse((Circ->centreX)-8,(Circ->centreY)-8,(Circ->centreX)+8,(Circ->centreY)+8);

		   }else
		   {
				Circ=NULL;
				MyPolygon tmp(Image1, number);
				P.copy(tmp);
			   Pol = &P;
			   ListBox1->Items->Clear();
				ListBox2->Items->Clear();
				ListBox3->Items->Clear();
				ListBox4->Items->Clear();
				ListBox1->Items->Add(Pol->getP());
				ListBox2->Items->Add(Pol->getS());
				Image1->Canvas->Ellipse((Pol->centreX)-8,(Pol->centreY)-8,(Pol->centreX)+8,(Pol->centreY)+8);
				ListBox3->Items->Add(Pol->centreX);
				ListBox4->Items->Add(Pol->centreY);
				//Image1->Canvas->Ellipse(Pol->getXcentre()-8,Pol->getYcentre()-8,Pol->getXcentre()+8,Pol->getYcentre()+8);

		   }
      }

}
//---------------------------------------------------------------------------
bool isEpsiloned(int X,int Y ,int x , int y)
 {
	  return (abs(X-x)<=10 && abs(Y-y)<=10);
 }

 double sqr(double x)
{
			return x*x;
}

bool isClose(double a,double b)
{
	   if(abs(a-b)<=16)
	   {
		   return true;
	   }else
	   {
		   return false;
       }
}


void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(Circ!=NULL)
	{
		  if(isEpsiloned(X,Y,Circ->centreX,Circ->centreY))
		  {
			  drag=-2;
		  }else if(drag==-2)
		  {
			  drag=-1;
			  Circ->centreX+=X-Circ->centreX;
			  Circ->centreY+=Y-Circ->centreY;
			  Circ->draw(Image1);
			  ListBox1->Items->Clear();
				ListBox2->Items->Clear();
				ListBox3->Items->Clear();
				ListBox4->Items->Clear();
				ListBox1->Items->Add(Circ->getP());
				ListBox2->Items->Add(Circ->getS());
				ListBox3->Items->Add(Circ->centreX);
				ListBox4->Items->Add(Circ->centreY);
				Image1->Canvas->Ellipse((Circ->centreX)-8,(Circ->centreY)-8,(Circ->centreX)+8,(Circ->centreY)+8);
		  }else if(isClose((Circ->r)/2,sqrt(sqr(Circ->centreX-X)+sqr(Circ->centreY-Y))))
		  {
			  drag = -3;
		  }else if(drag==-3)
		  {
                drag=-1;
			  Circ->r=(sqrt(sqr(Circ->centreX-X)+sqr(Circ->centreY-Y)))*2;
			  Circ->draw(Image1);
			  ListBox1->Items->Clear();
				ListBox2->Items->Clear();
				ListBox3->Items->Clear();
				ListBox4->Items->Clear();
				ListBox1->Items->Add(Circ->getP());
				ListBox2->Items->Add(Circ->getS());
				ListBox3->Items->Add(Circ->centreX);
				ListBox4->Items->Add(Circ->centreY);
				Image1->Canvas->Ellipse((Circ->centreX)-8,(Circ->centreY)-8,(Circ->centreX)+8,(Circ->centreY)+8);
          }

	}else if(Pol!=NULL)
	{
		if(isEpsiloned(X,Y,Pol->centreX,Pol->centreY)){
			  drag=-2;
		}else if(drag==-2)
		{
		   drag = -1;
		   double delx=X-Pol->centreX,dely=Y-Pol->centreY;
		   for(int i=0;i<Pol->n;i++)
		   {
			   Pol->masX[i]+=delx;
			   Pol->masY[i]+=dely;
		   }
				ListBox3->Items->Clear();
				ListBox4->Items->Clear();
				ListBox3->Items->Add(Pol->getXcentre());
				ListBox4->Items->Add(Pol->getYcentre());

				Image1->Canvas->Ellipse((Pol->centreX)-8,(Pol->centreY)-8,(Pol->centreX)+8,(Pol->centreY)+8);
		   Pol->draw(Image1,Pol->n);
		   Image1->Canvas->Ellipse((Pol->centreX)-8,(Pol->centreY)-8,(Pol->centreX)+8,(Pol->centreY)+8);
		}else if(drag>-1)
		{
			Pol->masX[drag]=X;
			Pol->masY[drag]=Y;
			Pol->draw(Image1,(Pol->n));
			drag=-1;
			ListBox1->Items->Clear();
				ListBox2->Items->Clear();
				ListBox3->Items->Clear();
				ListBox4->Items->Clear();
				ListBox1->Items->Add(Pol->getP());
				ListBox2->Items->Add(Pol->getS());
				ListBox3->Items->Add(Pol->getXcentre());
				ListBox4->Items->Add(Pol->getYcentre());

				Image1->Canvas->Ellipse((Pol->centreX)-8,(Pol->centreY)-8,(Pol->centreX)+8,(Pol->centreY)+8);
				//Image1->Canvas->Ellipse(Pol->getXcentre()-8,Pol->getYcentre()-8,Pol->getXcentre()+8,Pol->getYcentre()+8);

		}else
		{
			for(int i=0;i<Pol->n;i++)
			{
				if(isEpsiloned(X,Y,Pol->masX[i],Pol->masY[i]))
				{
					drag=i;
					break;
				}
			}
		}
	}else if(Pol==NULL)
	{
		if(n>=0 && isEpsiloned(X,Y,arrX[0],arrY[0])){

				 arrX[++n]=arrX[0];
				 arrY[n]=arrY[0];
				MyPolygon tmp(n);
				for(int i=0;i<=n;i++)
				{
					tmp.masX[i]=arrX[i];
					tmp.masY[i]=arrY[i];
				}
				P.copy(tmp);
				Pol=&P;
				Pol->draw(Image1,n);
				ListBox1->Items->Clear();
				ListBox2->Items->Clear();
				ListBox3->Items->Clear();
				ListBox4->Items->Clear();
				ListBox1->Items->Add(Pol->getP());
				ListBox2->Items->Add(Pol->getS());
				ListBox3->Items->Add(Pol->getXcentre());
				ListBox4->Items->Add(Pol->getYcentre());
				//Image1->Canvas->Ellipse(Pol->getXcentre()-8,Pol->getYcentre()-8,Pol->getXcentre()+8,Pol->getYcentre()+8);
				Image1->Canvas->Ellipse((Pol->centreX)-8,(Pol->centreY)-8,(Pol->centreX)+8,(Pol->centreY)+8);
		}else
		{
              arrX[++n]=X;
			arrY[n]=Y;
			Image1->Canvas->Ellipse(arrX[n]-8,arrY[n]-8,arrX[n]+8,arrY[n]+8);
        }


	}
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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int angle=0;
	try{
	angle = StrToInt(AngleEdit->Text);
	} catch(Exception &exception)
	{
		  angle = -1;
	}
	if(angle>0 && Pol!=NULL)
	{
		 for(int i=0;i<Pol->n;i++)
		 {
			 double r=sqrt(sqr(Pol->centreX-Pol->masX[i])+sqr(Pol->centreY-Pol->masY[i])),del=atan((Pol->centreY-Pol->masY[i])/(Pol->centreX-Pol->masX[i]-0.0000001));;
			if(Pol->masX[i]<Pol->centreX)
			 {
				   del+=acos(-1);
			 }
			 Pol->masX[i]=Pol->centreX+r*dcos(del*180/acos(-1)+angle);
			 Pol->masY[i]=Pol->centreY+r*dsin(del*180/acos(-1)+angle);
		 }
		Pol->draw(Image1,Pol->n);
		Image1->Canvas->Ellipse((Pol->centreX)-8,(Pol->centreY)-8,(Pol->centreX)+8,(Pol->centreY)+8);
    }
}
//---------------------------------------------------------------------------


