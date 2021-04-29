//---------------------------------------------------------------------------


#ifndef EyesH
#define EyesH
#include <vcl.h>
#include "MyFigure.h"
#include "Mouth.h"
//---------------------------------------------------------------------------
class Eyes : public MyFigure
{
	  public:
	  int x0,y0,r=30,x1,y1;
	  Eyes(TForm *im,int x,int y,int a,int b);

	  ~Eyes();

      void Move(int x, int y,int a,int b,int r1, TForm *im);
};
#endif
