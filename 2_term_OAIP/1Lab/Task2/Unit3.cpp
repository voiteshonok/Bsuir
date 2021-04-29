//---------------------------------------------------------------------------

#pragma hdrstop
#include "math.h"
#include "Unit3.h"
#define pi 3.14
//---------------------------------------------------------------------------
#pragma package(smart_init)
Circle::Circle(TImage *Image)
{
		Image->Canvas->Rectangle(0,0,1000,1000);
		Image->Canvas->Ellipse(centreX-r/2,centreY-r/2,centreX+r/2,centreY+r/2);
}
Circle::Circle()
{
}
Circle::~Circle(){}
void Circle::draw(TImage *Image)
{
		Image->Canvas->Rectangle(0,0,1000,1000);
		Image->Canvas->Ellipse(centreX-r/2,centreY-r/2,centreX+r/2,centreY+r/2);
}
void Circle::copy(Circle tmp)
{
	 r=tmp.r;
	 p=tmp.p;
	 s=tmp.s;
     centreX=tmp.centreX;
     centreY=tmp.centreY;
}
double Circle::getP()
{
	 return r*pi;
}
double Circle::getS()
{
	 return pi*r*r/4;
}
