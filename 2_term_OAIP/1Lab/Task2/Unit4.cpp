//---------------------------------------------------------------------------

#pragma hdrstop
#include "math.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

double DegToRad(int x){
	return ((double)x)/180*acos(-1);
}

double dsin(int x){
	return sin(DegToRad(x));
}
double dcos(int x){
	return cos(DegToRad(x));
}

MyPolygon::MyPolygon(int num)
{
	n=num;
}
MyPolygon::MyPolygon()
{
}

MyPolygon::~MyPolygon(){}
MyPolygon::MyPolygon(TImage *Image,int num)
{
	n=num;
	int cen = 300,r=120;
	for(int i=0;i<n;i++)
	{
		masX[i]=cen+r*dcos(360/n*i);
		masY[i]=cen+r*dsin(360/n*i);
	}
	draw(Image,n);

}

void MyPolygon::draw(TImage *Image,int n)
{
	Image->Canvas->Rectangle(0,0,1000,1000);
	 Image->Canvas->MoveTo(masX[0],masY[0]);
	 Image->Canvas->Ellipse(masX[0]-8,masY[0]-8,masX[0]+8,masY[0]+8);
	 for(int i=1;i<n;i++)
	{
		Image->Canvas->Ellipse(masX[i]-8,masY[i]-8,masX[i]+8,masY[i]+8);
		Image->Canvas->LineTo(masX[i],masY[i]);
	}
	Image->Canvas->LineTo(masX[0],masY[0]);
}
void MyPolygon::copy(MyPolygon tmp)
{
	 n=tmp.n;
	 s=tmp.s;
	 p=tmp.p;
	 for(int i=0;i<n;i++)
	 {
		 masX[i]=tmp.masX[i];
         masY[i]=tmp.masY[i];
	 }
	 centreX=tmp.centreX;
     centreY=tmp.centreY;
}
double sqr(double x)
{
			return x*x;
}
double MyPolygon::getP()
{
	 double p=0;
	 for(int i=1;i<n;i++)
	 {
		 p+=sqrt(sqr(masX[i]-masX[i-1])+sqr(masY[i]-masY[i-1]));
	 }
	 p+=sqrt(sqr(masX[0]-masX[n-1])+sqr(masY[0]-masY[n-1]));
     return p;
}
double MyPolygon::getS()
{
	 double s=0;
	 for(int i =1; i<n;i++)
	 {
		double sq=  (masY[i]+masY[i-1])/2*(masX[i]-masX[i-1]+1);
		s+=sq;
	 }
		double sq=(masY[0]+masY[n-1])/2*(masX[0]-masX[n-1]);
		s+=sq;
	 return abs(s);
}

double MyPolygon::getXcentre()
{
	 double s=0,x=0;
	 for(int i =1; i<n;i++)
	 {
		double sq=  (masY[i]+masY[i-1])/2*(0.0011+masX[i]-masX[i-1]),x1=masX[i-1],y1=masY[i-1]/2,x2=masX[i],y2=masY[i]/2,y3=masY[i-1]+masY[i],y4=-masY[i-1],k1=(y2-y1)/(x2-x1+0.0011),k2=(y3-y4)/(0.001+x1-x2),b1=y2-k1*x2,b2=y3-x1*k2;
		x+=sq*(b2-b1)/(k1-k2);
		s+=sq;
	 }
	  double sq=(masY[0]+masY[n-1])/2*(0.0011+masX[0]-masX[n-1]),x1=masX[n-1],y1=masY[n-1]/2,x2=masX[0],y2=masY[0]/2,y3=masY[n-1]+masY[0],y4=-masY[n-1],k1=(y2-y1)/(x2-x1+0.0011),k2=(y3-y4)/(x1-x2+0.0011),b1=y2-k1*x2,b2=y3-x1*k2;
	  x+=sq*(b2-b1)/(k1-k2);
	  x/=getS();
	  centreX=abs(x);
	 return abs(x);
}
double MyPolygon::getYcentre()
{
	 double s=0,y=0;
     for(int i =1; i<n;i++)
	 {
		double sq=  (masY[i]+masY[i-1])/2*(masX[i]-masX[i-1]+1),x1=masX[i-1],y1=masY[i-1]/2,x2=masX[i],y2=masY[i]/2,y3=masY[i-1]+masY[i],y4=-masY[i-1],k1=(y2-y1)/(x2-x1+1),k2=(y3-y4)/(x1-x2+0.0011),b1=y2-k1*x2,b2=y3-x1*k2;
		y+=sq*((b2-b1)/(k1-k2)*k2+b2);
		s+=sq;
	 }
	  double sq=(masY[0]+masY[n-1])/2*(masX[0]-masX[n-1]+0.0011),x1=masX[n-1],y1=masY[n-1]/2,x2=masX[0],y2=masY[0]/2,y3=masY[n-1]+masY[0],y4=-masY[n-1],k1=(y2-y1)/(x2-x1+0.0011),k2=(y3-y4)/(x1-x2+0.0011),b1=y2-k1*x2,b2=y3-x1*k2;
	  y+=sq*((b2-b1)/(k1-k2)*k2+b2);
	  y/=getS();
      centreY=abs(y);
	 return abs(y);
}
