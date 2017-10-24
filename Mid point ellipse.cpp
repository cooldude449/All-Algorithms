4)	Write a program to implement mid-point ellipse drawing algorithm.

#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
void putellipse1(int x,int y,int x1,int y1,int c)
{
putpixel(x+x1,y+y1,c);
putpixel(-x+x1,y+y1,c);
putpixel(x+x1,-y+y1,c);
putpixel(-x+x1,-y+y1,c);
}
void putellipse2(int x,int y,int x1,int y1,int c)
{
putpixel(x+x1,y+y1,c);
putpixel(x+x1,-y+y1,c);
putpixel(-x+x1,y+y1,c);
putpixel(-x+x1,-y+y1,c);
}
void ellipse(int x1,int y1,double a,double b)
{
clrscr();
int x=0,y=b,c=0;
double d1,d2;
d1=pow(b,2)+pow(a,2)*(0.25-b);
putellipse1(x,y,x1,y1,c);
randomize();
while((pow(a,2)*(y-0.5))>(pow(b,2)*(x+1)))
{
	if(d1<0)
	{
	d1=d1+pow(b,2)*((2*x)+3);
	}
	else
	{
		d1=d1+pow(b,2)*((2*x)+3)+pow(a,2)*((-2*y)+2);
		y--;
	}
	x++;
	c=rand()%100;
	putellipse1(x,y,x1,y1,c);
}
d2=pow(b,2)*pow((x+0.5),2)+pow(a,2)*(pow(y-1,2))-(pow(a,2)*pow(b,2));
randomize();
while(y>0)
{
	if(d2<0)
	{
	d2=d2+pow(b,2)*((2*x)+2)+pow(a,2)*((-2*y)+3);
	x++;
	}
	else
	{
		d2=d2+pow(a,2)*((-2*y)+3);
	}
	y--;
	c=rand()%100;
	putellipse2(x,y,x1,y1,c);
}
}
void main()
{
 clrscr();
 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver, &gmode,"");
 errorcode = graphresult();
 if (errorcode != grOk)
 {
  cout<<"Graphics error: %s\n"<<grapherrormsg(errorcode);
  cout<<"\nPress any key to halt:";
  getch();
  exit(1);
 }
 int x,y;
 double a,b;
 cout<<"Enter the coordinates of center : \n";
 cin>>x;
 cin>>y;
 cout<<"Enter a : ";
 cin>>a;
 cout<<"Enter b : ";
 cin>>b;
 ellipse(x,y,a,b);
 getch();
}
 
