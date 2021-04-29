//---------------------------------------------------------------------------

#ifndef MouthH
#define MouthH
#include <vcl.h>
#include "MyFigure.h"
#include "Eyes.h"
//---------------------------------------------------------------------------
class Mouth : public MyFigure
{
	  public:
	  int x1=270,x2=470,y=320,r=50;
	  Mouth(TForm *im);

	  ~Mouth();

	  void Move(int x1, int x2,int y,int r,TForm *im);
};
#endif
