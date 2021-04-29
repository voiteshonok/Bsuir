//---------------------------------------------------------------------------

#pragma hdrstop

#include "Eyes.h"
#include "Mouth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 Eyes::Eyes(TForm *im,int x,int y,int a,int b)
	  {
			x0=x;
			y0=y;
			x1=a;
			y1=b;
			Move(x0+r,y0,x1+r,y1,10,im);
	  }
 Eyes::~Eyes(){}

 void Eyes::Move(int x, int y,int a,int b,int r1, TForm *im)
	  {
		  //Redraw(im);
		  im->Canvas->Ellipse(x-r1,y-r1,x+r1,y+r1);
		  im->Canvas->Ellipse(a-r1,b-r1,a+r1,b+r1);
	  }

 
