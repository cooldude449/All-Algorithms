3)	Write a program to implement mid-point circle drawing algorithm.


#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void plotpixel(int x,int y,int xc,int yc,int d)
{
  putpixel(x+xc,y+yc,d);
  putpixel(y+xc,x+yc,d);
  putpixel(y+xc,-x+yc,d);
  putpixel(x+xc,-y+yc,d);
  putpixel(-x+xc,-y+yc,d);
  putpixel(-y+xc,-x+yc,d);
  putpixel(-y+xc,x+yc,d);
  putpixel(-x+xc,y+yc,d);
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
 int xc,yc,x,y,r,d,c=1;
 float m;
 cout<<"\nEnter the origin";
 cout<<"\nEnter x coordinate: ";
 cin>>xc;
 cout<<"\nEnter the y coordinate: ";
 cin>>yc;
 cout<<"\nEnter the radius of the circle: ";
 cin>>r;
 x=0;
 y=r;
 d=1-r;
 clrscr();
 plotpixel(x,y,xc,yc,c);
 randomize();
 while(x<=y)
 {
  if(d<0)
    d=d+(2*x)+3;
  else
  {
   d=d+(2*x)+5-(2*y);
   y--;
  }
  x++;
  c=rand()%100;
  plotpixel(x,y,xc,yc,c);
 }
 getch();
 closegraph();
}

