7)	Write a program to apply various 2D transformations on a 2D object(use homogeneous coordinates).

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<process.h>
double m[3][3];
double **multiply(double m1[3][3],double m2[3][1])
{
	double **c1;
	*c1 = new double[3];
	for (int i=0;i<3;i++)
		c1[i] = new double[1];
	for(i=0;i<3;i++)
	{
		for(int j=0;j<1;j++)
		{
			c1[i][j]=0;
		for(int k=0;k<3;k++)
		{
			c1[i][j]+=m1[i][k]*m2[k][j];
		}
	}
}
	return c1;
}
void translate()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
			{
				m[i][j]=1;
			}
			else
			{
				m[i][j]=0;
			}
		}
}
double tx,ty,x1,y1,x2,y2,obj[3][1],mat[4][2];
obj[2][0]=1;
cout<<"Enter X1 : ";
cin>>x1;
cout<<"Enter Y1 : ";
cin>>y1;
cout<<"Enter X2 : ";
cin>>x2;
cout<<"Enter Y2 : ";
cin>>y2;
cout<<"Enter tx : ";
cin>>tx;
cout<<"Enter ty : ";
cin>>ty;
m[0][2]=tx;
m[1][2]=ty;
mat[0][0]=x1;
mat[0][1]=y1;
mat[1][0]=x2;
mat[1][1]=y1;
mat[2][0]=x2;
mat[2][1]=y2;
mat[3][0]=x1;
mat[3][1]=y2;
clrscr();
setcolor(BLUE);
line(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
line(mat[1][0],mat[1][1],mat[2][0],mat[2][1]);
line(mat[3][0],mat[3][1],mat[2][0],mat[2][1]);
line(mat[0][0],mat[0][1],mat[3][0],mat[3][1]);
double **c;
for(i=0;i<4;i++)
{
obj[0][0]=mat[i][0];
obj[1][0]=mat[i][1];
c=multiply(m,obj);
mat[i][0]=c[0][0];
mat[i][1]=c[1][0];
}
getch();
clrscr();
setcolor(RED);
line(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
line(mat[1][0],mat[1][1],mat[2][0],mat[2][1]);
line(mat[2][0],mat[2][1],mat[3][0],mat[3][1]);
line(mat[3][0],mat[3][1],mat[0][0],mat[0][1]);
getch();
}

void rotate()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
			{
				m[i][j]=1;
			}
			else
			{
				m[i][j]=0;
			}
		}
}
double tx,ty,x1,y1,x2,y2,obj[3][1],mat[4][2];
obj[2][0]=1;
cout<<"Enter X1 : ";
cin>>x1;
cout<<"Enter Y1 : ";
cin>>y1;
cout<<"Enter X2 : ";
cin>>x2;
cout<<"Enter Y2 : ";
cin>>y2;
cout<<"Enter Cos_ : ";
cin>>tx;
cout<<"Enter Sin_ : ";
cin>>ty;
m[0][0]=tx;
m[0][1]=-ty;
m[1][0]=ty;
m[1][1]=tx;
mat[0][0]=x1;
mat[0][1]=y1;
mat[1][0]=x2;
mat[1][1]=y1;
mat[2][0]=x2;
mat[2][1]=y2;
mat[3][0]=x1;
mat[3][1]=y2;
clrscr();
setcolor(BLUE);
line(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
line(mat[1][0],mat[1][1],mat[2][0],mat[2][1]);
line(mat[3][0],mat[3][1],mat[2][0],mat[2][1]);
line(mat[0][0],mat[0][1],mat[3][0],mat[3][1]);
double **c;
for(i=0;i<4;i++)
{
obj[0][0]=mat[i][0];
obj[1][0]=mat[i][1];
c=multiply(m,obj);
mat[i][0]=c[0][0];
mat[i][1]=c[1][0];
}
getch();
clrscr();
setcolor(RED);
line(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
line(mat[1][0],mat[1][1],mat[2][0],mat[2][1]);
line(mat[2][0],mat[2][1],mat[3][0],mat[3][1]);
line(mat[3][0],mat[3][1],mat[0][0],mat[0][1]);
}
void scale()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
			{
				m[i][j]=1;
			}
			else
			{
				m[i][j]=0;
			}
		}
	}
double tx,ty,x1,y1,x2,y2,obj[3][1],mat[4][2];
obj[2][0]=1;
cout<<"Enter X1 : ";
cin>>x1;
cout<<"Enter Y1 : ";
cin>>y1;
cout<<"Enter X2 : ";
cin>>x2;
cout<<"Enter Y2 : ";
cin>>y2;
cout<<"Enter sx : ";
cin>>tx;
cout<<"Enter sy : ";
cin>>ty;
m[0][0]=tx;
m[1][1]=ty;
mat[0][0]=x1;
mat[0][1]=y1;
mat[1][0]=x2;
mat[1][1]=y1;
mat[2][0]=x2;
mat[2][1]=y2;
mat[3][0]=x1;
mat[3][1]=y2;
clrscr();
setcolor(BLUE);
line(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
line(mat[1][0],mat[1][1],mat[2][0],mat[2][1]);
line(mat[3][0],mat[3][1],mat[2][0],mat[2][1]);
line(mat[0][0],mat[0][1],mat[3][0],mat[3][1]);
double **c;
for(i=0;i<4;i++)
{
obj[0][0]=mat[i][0];
obj[1][0]=mat[i][1];
c=multiply(m,obj);
mat[i][0]=c[0][0];
mat[i][1]=c[1][0];
}
getch();
clrscr();
setcolor(RED);
line(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
line(mat[1][0],mat[1][1],mat[2][0],mat[2][1]);
line(mat[2][0],mat[2][1],mat[3][0],mat[3][1]);
line(mat[3][0],mat[3][1],mat[0][0],mat[0][1]);
getch();
}
void shear()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
			{
				m[i][j]=1;
			}
			else
			{
				m[i][j]=0;
			}
		}
	}
double tx,ty,x1,y1,x2,y2,obj[3][1],mat[4][2];
obj[2][0]=1;
cout<<"Enter X1 : ";
cin>>x1;
cout<<"Enter Y1 : ";
cin>>y1;
cout<<"Enter X2 : ";
cin>>x2;
cout<<"Enter Y2 : ";
cin>>y2;
cout<<"Enter shx : ";
cin>>tx;
cout<<"Enter shy : ";
cin>>ty;
clrscr();
m[0][1]=tx;
m[1][0]=ty;
mat[0][0]=x1;
mat[0][1]=y1;
mat[1][0]=x2;
mat[1][1]=y1;
mat[2][0]=x2;
mat[2][1]=y2;
mat[3][0]=x1;
mat[3][1]=y2;
clrscr();
setcolor(BLUE);
line(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
line(mat[1][0],mat[1][1],mat[2][0],mat[2][1]);
line(mat[3][0],mat[3][1],mat[2][0],mat[2][1]);
line(mat[0][0],mat[0][1],mat[3][0],mat[3][1]);
double **c;
for(i=0;i<4;i++)
{
obj[0][0]=mat[i][0];
obj[1][0]=mat[i][1];
c=multiply(m,obj);
mat[i][0]=c[0][0];
mat[i][1]=c[1][0];
}
getch();
clrscr();
setcolor(RED);
line(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
line(mat[1][0],mat[1][1],mat[2][0],mat[2][1]);
line(mat[2][0],mat[2][1],mat[3][0],mat[3][1]);
line(mat[3][0],mat[3][1],mat[0][0],mat[0][1]);
getch();
}

void main()
{
   clrscr();
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;
   initgraph(&gdriver, &gmode,"C:\TurboC4\TC\BGI");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   int ch;
   do
   {
   cout<<"\n\n\n\n MAIN MENU"
       <<"\n\n 1.translate"
       <<"\n\n 2.rotate"
       <<"\n\n 3.scale"
       <<"\n\n 4.shear"
       <<"\n\n 5.exit"
       <<"\n\nenter your choice";
       cin>>ch;
  switch(ch)
  {
	case 1:cout<<"\n\nTRANSLATE";
	       translate();
	       break;
	case 2:cout<<"\n\nROTATE";
	       rotate();
	       break;
	case 3:cout<<"\n\nSCALE";
	       scale();
	       break;
	case 4:cout<<"\n\nSHEAR";
	       shear();
	       break;
	case 5:exit(0);
	default:cout<<"wrong choice";
   }
  }while(ch<=5);
  getch();
}
 
