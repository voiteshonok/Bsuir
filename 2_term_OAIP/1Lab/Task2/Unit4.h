//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
 #include <vcl.h>
#include "Unit2.h"
 class MyPolygon:public MyFigure
 {
	public:
	  int masX[100];
	  int masY[100];
      int n=0;

        public:
	 MyPolygon(TImage *Image,int num);
	 MyPolygon(int num);
     ~MyPolygon();
     MyPolygon();
	 void draw(TImage *Image,int n);
     void copy(MyPolygon tmp);
	 double getP();
	 double getS();
	 double getXcentre();
	 double getYcentre();
 };
 #endif
