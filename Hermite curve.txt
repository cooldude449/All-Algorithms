9)	Write a program to draw hermite curve.

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
double arr[4][2];

void hermite(int fx,int fy)
{
	double t=0.0;
	double b0,b1,b2,b3,x,y;
	for(;t<=1.0;t=t+0.0001)
	{
		b0=2*(pow(t,3))-3*(pow(t,2))+1;
		b1=-2*(pow(t,3))+3*(pow(t,2));
		b2=pow(t,3)-2*(pow(t,3));
		b3=pow(t,3)-pow(t,2);
		x=b0*arr[0][0]+b1*arr[1][0]+b2*arr[2][0]+b3*arr[3][0];
		y=b0*arr[0][1]+b1*arr[1][1]+b2*arr[2][1]+b3*arr[3][1];
		putpixel(x+fx,fy-y,GREEN);
	}
}
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\TurboC4\TC\BGI");
	int fx=getmaxx()/2;
	int fy=getmaxy()/2;
	cout<<"Enter the x-coordinate of first end-point : ";
	cin>>arr[0][0];
	cout<<"Enter the y-coordinate of first end-point : ";
	cin>>arr[0][1];
	cout<<"Enter the x-coordinate of second end-point : ";
	cin>>arr[1][0];
	cout<<"Enter the y-coordinate of second end-point : ";
	cin>>arr[1][1];
	cout<<"Enter the x-coordinate of first tangent : ";
	cin>>arr[2][0];
	cout<<"Enter the y-coordinate of first tangent : ";
	cin>>arr[2][1];
	cout<<"Enter the x-coordinate of 2nd tangent : ";
	cin>>arr[3][0];
	cout<<"Enter the y-coordinate of 2nd tangent : ";
	cin>>arr[3][1];
	clrscr();
	hermite(fx,fy);
	getch();
}
