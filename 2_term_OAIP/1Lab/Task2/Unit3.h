//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
 #include <vcl.h>
#include "Unit2.h"
class Circle:public MyFigure
{
	public:
	int r=200;

	 public:
	 Circle(TImage *Image);
	 Circle();
	 void copy(Circle tmp);
	 double getP();
	 double getS();
	 void draw(TImage *Image);
     ~Circle();
};
#endif
