8)	Write a program to apply various 3D transformations and parallel and perspective projection a 3D object.

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<process.h>
#include<math.h>
#include<iomanip.h>
#include<dos.h>
double op[4][4];
double c[8][4];
double mat[8][4];
double r1[4][4];
double r2[4][4];
double r3[4][4];
double tr[4][4];
void oper()
{
for(int i=0;i<4;i++)
{
 for(int j=0;j<4;j++)
 {
  if(i==j)
       op[i][j]=1;
  else
       op[i][j]=0;
 }
}
}

void display()
{
	cout<<"\nConversion matrix \n";
	for(int i=0;i<8;i++)
	{
	 for(int j=0;j<4;j++)
	 {
	 cout<<setw(14)<<c[i][j];
	 }
	 cout<<"\n";
	}
}

void draw()
{
for(int i=0;i<8;i++)
{
   for(int j=0;j<2;j++)
   {
      if(j==0)
	    c[i][j]=c[i][j]+getmaxy()/2;
      else
	    c[i][j]=c[i][j]+getmaxy()/2;
   }
}
display();
getch();
clrscr();
setcolor(10);
line(c[0][0],c[0][1],c[1][0],c[1][1]);
setcolor(20);
line(c[1][0],c[1][1],c[2][0],c[2][1]);
setcolor(30);
line(c[2][0],c[2][1],c[3][0],c[3][1]);
setcolor(40);
line(c[3][0],c[3][1],c[0][0],c[0][1]);
setcolor(50);
line(c[4][0],c[4][1],c[5][0],c[5][1]);
setcolor(60);
line(c[5][0],c[5][1],c[6][0],c[6][1]);
setcolor(70);
line(c[6][0],c[6][1],c[7][0],c[7][1]);
setcolor(80);
line(c[7][0],c[7][1],c[4][0],c[4][1]);
setcolor(90);
line(c[3][0],c[3][1],c[7][0],c[7][1]);
setcolor(100);
line(c[0][0],c[0][1],c[4][0],c[4][1]);
setcolor(110);
line(c[2][0],c[2][1],c[6][0],c[6][1]);
setcolor(120);
line(c[1][0],c[1][1],c[5][0],c[5][1]);
}

void multiply(double m1[8][4],double m2[4][4])
{
for(int i=0;i<8;i++)
{
	for(int j=0;j<4;j++)
	{
		c[i][j]=0;
		for(int k=0;k<4;k++)
		{
			c[i][j]+=m1[i][k]*m2[k][j];
		}
	}
}
}

void operation(int s)
{
	op[s-1][s-1]=0;
	cout<<"Operation matrix :\n";
	for(int i=0;i<4;i++)
	{
	 for(int j=0;j<4;j++)
	 {
	  cout<<setw(10)<<op[i][j];
	 }
	 cout<<"\n";
	}
}

void init_r(double fi,double theta)
{
  r1[0][0]=cos(fi);
  r1[0][1]=sin(fi)*sin(theta);
  r1[1][0]=0;
  r1[1][1]=cos(theta);
  r1[2][0]=sin(fi);
  r1[2][1]=cos(fi)*sin(theta)*-1;
  for(int i=0;i<4;i++)
  {
    r1[i][2]=0;
    r1[i][3]=0;
  }
  r1[3][0]=r1[3][1]=r1[3][2]=0;
  r1[3][3]=1;
}

void display_ortho(int s)
{
	setcolor(RED);
	if(s==1)
	{
	line(c[0][0],c[0][1],c[4][0],c[4][1]);
	line(c[4][0],c[4][1],c[7][0],c[7][1]);
	line(c[7][0],c[7][1],c[3][0],c[3][1]);
	line(c[3][0],c[3][1],c[3][0],c[3][1]);
	}
	else if(s==2)
	{
	line(c[3][0],c[3][1],c[2][0],c[2][1]);
	line(c[2][0],c[2][1],c[6][0],c[6][1]);
	line(c[6][0],c[6][1],c[7][0],c[7][1]);
	line(c[7][0],c[7][1],c[3][0],c[3][1]);
	}
	else
	{
	line(c[4][0],c[4][1],c[5][0],c[5][1]);
	line(c[5][0],c[5][1],c[6][0],c[6][1]);
	line(c[6][0],c[6][1],c[7][0],c[7][1]);
	line(c[7][0],c[7][1],c[4][0],c[4][1]);
	}
}
void point()
{
for(int i=0;i<8;i++)
{
	for(int j=0;j<4;j++)
	{
		c[i][j]=c[i][j]/c[i][3];
	}
}
}
void init_r()
{
//Rotation about x-axis
for(int i=0;i<4;i++)
{
 for(int j=0;j<4;j++)
 {
  if(i==j)
       r1[i][j]=1;
  else
       r1[i][j]=0;
 }
}

//Rotation about y-axis
for(i=0;i<4;i++)
{
 for(int j=0;j<4;j++)
 {
  if(i==j)
       r2[i][j]=1;
  else
       r2[i][j]=0;
 }
}

//Rotation about z-axis
for(i=0;i<4;i++)
{
 for(int j=0;j<4;j++)
 {
  if(i==j)
       r3[i][j]=1;
  else
       r3[i][j]=0;
 }
}
}

void x_rotate(int y)
{
r1[1][1]=cos(y);
r1[1][2]=sin(y);
r1[2][1]=-sin(y);
r1[2][2]=cos(y);
for(int i=0;i<4;i++)
{
   for(int j=0;j<4;j++)
   {
    cout<<setw(14)<<r1[i][j];
   }
   cout<<"\n";
}
multiply(mat,r1);
}

void y_rotate(int y)
{
r2[0][0]=cos(y);
r2[0][2]=-sin(y);
r2[2][0]=sin(y);
r2[2][2]=cos(y);
for(int i=0;i<4;i++)
{
   for(int j=0;j<4;j++)
   {
    cout<<setw(14)<<r2[i][j];
   }
   cout<<"\n";
}
multiply(mat,r2);
}

void z_rotate(int y)
{
r3[0][0]=cos(y);
r3[0][1]=sin(y);
r3[1][0]=-sin(y);
r3[1][1]=cos(y);
for(int i=0;i<4;i++)
{
   for(int j=0;j<4;j++)
   {
    cout<<setw(14)<<r3[i][j];
   }
   cout<<"\n";
}
multiply(mat,r3);
}



void project(double fi,double theta)
{
int ch1;
cout<<"\nMENU:\n1.fi<0,theta>0";
cout<<"\n2.fi<0,theta<0";
cout<<"\n3.fi>0,theta>0";
cout<<"\n4.fi>0,theta<0";
cout<<"\nEnter Your choice :";
cin>>ch1;
switch(ch1)
{
case 1:fi=-1*fi;
       break;
case 2:fi=-1*fi;
	theta=-1*theta;
	break;
case 3:break;
case 4:theta=-1*theta;
	break;
default:exit(10);
}

init_r(fi,theta);
multiply(c,r1);
draw();
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
int s,x1,y1,l;
cout<<"Coordinates for the cube :";
cout<<"\nEnter Xmin : ";
cin>>x1;
cout<<"Enter Ymin : ";
cin>>y1;
cout<<"Enter the length of cube :";
cin>>l;
for(int i=0;i<8;i++)
{
 for(int j=0;j<4;j++)
 {
  if(j<3)
  {
  mat[i][j]=0;
  }
  else
  mat[i][j]=1;
 }
}
//z coordinate
for(i=0;i<4;i++)
{
mat[i][2]=l;
}
mat[0][0]=x1;
mat[0][1]=y1;
mat[1][0]=x1+l;
mat[1][1]=y1;
mat[2][0]=x1+l;
mat[2][1]=y1+l;
mat[3][0]=x1;
mat[3][1]=y1+l;
mat[4][0]=x1;
mat[4][1]=y1;
mat[5][0]=x1+l;
mat[5][1]=y1;
mat[6][0]=x1+l;
mat[6][1]=y1+l;
mat[7][0]=x1;
mat[7][1]=y1+l;
cout<<"\n3D matrix\n";
for(i=0;i<8;i++)
{
 for(int j=0;j<4;j++)
 {
 c[i][j]=mat[i][j];
 cout<<mat[i][j]<<" ";
 }
 cout<<"\n";
}

int ch=1,ch1=1,ch2=1,ch3=1,ch4=1,ch5=1;
double f,t,fx;
int sx,sy,sz;
while(ch3!=3)
{
cout<<"MENU";
cout<<"\n1.Transformations.";
cout<<"\n2.Projections.";
cout<<"\n3.Exit.";
cout<<"\nEnter your choice : ";
cin>>ch3;
switch(ch3)
{
case 1 :while(ch5!=6)
	{
	cout<<"\nTRANSFORMATION MENU";
	cout<<"\n1.Scaling.";
	cout<<"\n2.Shearing.";
	cout<<"\n3.Rotation.";
	cout<<"\n4.Reflection.";
	cout<<"\n5.Exit.";
	cout<<"\n6.Go back.";
	cout<<"\nEnter your choice : ";
	cin>>ch5;
	switch(ch5)
	{
	case 1 :cout<<"Enter scale along x-axis :";
		cin>>sx;
		cout<<"Enter scale along y-axis :";
		cin>>sy;
		cout<<"Enter scale along z-axis :";
		cin>>sz;
		oper();
		op[0][0]=sx;
		op[1][1]=sy;
		op[2][2]=sz;
		multiply(mat,op);
		display();
		getch();
		break;
	case 2 :oper();
		cout<<"Enter scale factor b :";
		cin>>sx;
		cout<<"Enter scale factor c :";
		cin>>sy;
		cout<<"Enter scale factor d :";
		cin>>sz;
		op[0][1]=sx;
		op[0][2]=sy;
		op[1][0]=sz;
		cout<<"Enter scale factor f :";
		cin>>sx;
		cout<<"Enter scale factor g :";
		cin>>sy;
		cout<<"Enter scale factor i :";
		cin>>sz;
		op[1][2]=sx;
		op[2][0]=sy;
		op[2][1]=sz;
		multiply(mat,op);
		display();
		getch();
		break;
	case 3 :cout<<"\nEnter rotation angle : ";
		cin>>sy;
		cout<<"\nROTATION MENU";
		cout<<"\n1.Rotation along x-axis.";
		cout<<"\n2.Rotation along y-axis.";
		cout<<"\n3.Rotation along z-axis.";
		cout<<"\nEnter your choice : ";
		cin>>sx;
		init_r();
		if(sx==1)
			x_rotate(sy);
		else if(sx==2)
			y_rotate(sy);
		else
			z_rotate(sy);
		display();
		getch();
		break;
	case 4 :oper();
		cout<<"\nREFLECTION MENU";
		cout<<"\n1.Reflection along x-axis.";
		cout<<"\n2.Reflection along y-axis.";
		cout<<"\n3.Reflection along z-axis.";
		cout<<"\nEnter your choice : ";
		cin>>sx;
		op[sx-1][sx-1]=-1;
		multiply(mat,op);
		display();
		getch();
		break;
	case 5 :exit(0);
	case 6 :break;
	default:cout<<"Wrong choice..";
	}
	}
case 2 :while(ch!=4)
	{
	oper();
	cout<<"\nPROJECTION MENU";
	cout<<"\n1.Parallel Projection.";
	cout<<"\n2.Perspective Projection.";
	cout<<"\n3.Exit.";
	cout<<"\n4.Go back.";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	ch1=ch2=1;
	switch(ch)
	{
	case 1 :while(ch1!=4)
		{
		clrscr();
		cout<<"\nPARALLEL PROJECTION MENU";
		cout<<"\n1.Orthographic projection.";
		cout<<"\n2.Axanometric projection.";
		cout<<"\n3.Exit.";
		cout<<"\n4.Go back.";
		cout<<"\nEnter your choice : ";
		cin>>ch1;
		switch(ch1)
		{
		case 1 :cout<<"\nEnter the Projection plane :";
			cout<<"\n1. X-plane";
			cout<<"\n2. Y-plane";
			cout<<"\n3. Z-plane";
			cout<<"\nEnter your choice ";
			cin>>s;
			operation(s);
			multiply(mat,op);
			clrscr();
			display_ortho(s);
			getch();
			break;
		case 2 :while(ch2!=5)
			{
			clrscr();
			cout<<"\nAXANOMETRIC PROJECTION MENU";
			cout<<"\n1.Trimetric Projection.";
			cout<<"\n2.Dimetric Projection.";
			cout<<"\n3.Isometric Projection.";
			cout<<"\n4.Exit.";
			cout<<"\n5.Go back.";
			cout<<"\nEnter your choice : ";
			cin>>ch2;
			switch(ch2)
			{
			case 1 :cout<<"\nEnter fi : ";
				cin>>f;
				cout<<"\nEnter theta : ";
				cin>>t;
				init_r(f,t);
				multiply(mat,r1);
				draw();
				getch();
				break;
			case 2 :cout<<"\nEnter fx : ";
				cin>>fx;
				t=asin(fx/sqrt(2));
				f=asin(fx/sqrt((2-pow(fx,2))));
				project(f,t);
				break;
			case 3: fx=0.8165;
				t=asin(fx/sqrt(2));
				f=asin(fx/sqrt((2-pow(fx,2))));
				project(f,t);
				break;
			case 4 :exit(0);
			case 5 :break;
			default:cout<<"\nWrong choice..";
			}
			}
			break;
		case 3 :exit(0);
		case 4 :break;
		default:cout<<"Wrong choice..";
		}
		}
		break;
	case 2 :while(ch2!=3)
		{
		int rx,ry,rz;
		clrscr();
		cout<<"\nPERSPECTIVE PROJECTION MENU";
		cout<<"\n1.Single point projection";
		cout<<"\n2.Exit.";
		cout<<"\n3.Go back.";
		cout<<"\nEnter your choice : ";
		cin>>ch2;
		switch(ch2)
		{
		case 1 :cout<<"\nEnter the value of z ";
			cin>>rz;
			op[2][3]=-rz;
			op[2][2]=0;
			operation(3);
			multiply(c,op);
			point();
			draw();
			getch();
			break;
		case 2 :exit(0);
		case 3 :break;
		default:cout<<"Wrong choice";
		}
		}
		break;
	case 3 :exit(0);
	case 4 :break;
	default:cout<<"Wrong choice..";
	}
	}
	break;
case 3 :exit(0);
default:cout<<"Wrong choice..";
}
}
getch();
}
