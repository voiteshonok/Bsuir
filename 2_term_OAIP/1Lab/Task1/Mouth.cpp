//---------------------------------------------------------------------------

#pragma hdrstop

#include "Mouth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Mouth:: Mouth(TForm *im)
	  {
		   Move(x1,x2,y,r,im);
	  }

Mouth::~Mouth(){}

void Mouth::Move(int x1, int x2,int y,int r,TForm *im)
	  {
            //Redraw(im);
		   im->Canvas->Ellipse(x1,y-r,x2,y+r);
	  }
