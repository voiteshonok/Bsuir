//---------------------------------------------------------------------------

#ifndef MyFigureH
#define MyFigureH
#include <vcl.h>
//---------------------------------------------------------------------------
class MyFigure{
	public :
	MyFigure(TForm *im);
    MyFigure();

	static void Redraw(TForm *im);

	void Move(TForm *im,int x0,int y0,int r);

	void Move(TForm *im,int x0,int y0,int x1,int y1);
	~MyFigure();

};

#endif
