//---------------------------------------------------------------------------

#pragma hdrstop

#include "MyFigure.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
MyFigure::MyFigure(TForm *im)
	{
		  Redraw(im);
	}

MyFigure::MyFigure()
	{}

 void MyFigure::Redraw(TForm *im)
	{
		im->Canvas->Brush->Color = clWhite;
		im->Canvas->FillRect(Rect(0,0,1920,1000));
		im->Canvas->Ellipse(220,163,520,380);
		im->Canvas->Ellipse(190,143,250,400);
		im->Canvas->Ellipse(490,143,550,400);
		im->Canvas->Ellipse(250,143,490,183);
		im->Canvas->Ellipse(265,190,345,270);
		im->Canvas->Ellipse(400,190,480,270);
	}

 void MyFigure::Move(TForm *im,int x0,int y0,int r)
	{
		Move(im, x0-r,y0-r,x0+r,y0+r);
	}

	void MyFigure::Move(TForm *im,int x0,int y0,int x1,int y1)
	{
		Redraw(im);
		im->Canvas->Ellipse(x0,y0,x1,y1);
	}

	MyFigure::~MyFigure(){}
