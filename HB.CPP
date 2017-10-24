#include<iostream.h>
#include<conio.h>
#include<graphics.h>

float p1[2][2],p2[2][2],p3[2][2],p4[2][2],r1[2][2],r4[2][2],xn,yn;
int ch,i,j;


void hermite(float x[2][2],float x1[2][2])
{
  for(float t=0;t<1;t=t+0.001)
 {
  xn=((2*(t*t*t)-3*(t*t)+1)*x[0][0]+(-2*(t*t*t)+3*(t*t))*x[1][0]+((t*t*t)-2*(t*t)+t)*x1[0][0]+((t*t*t)-(t*t))*x1[1][0]);
  yn=((2*(t*t*t)-3*(t*t)+1)*x[0][1]+(-2*(t*t*t)+3*(t*t))*x[1][1]+((t*t*t)-2*(t*t)+t)*x1[0][1]+((t*t*t)-(t*t))*x1[1][1]);
  putpixel(xn,yn,2);
 }
}

void bezier(float x[2][2], float x1[2][2])
 {
  for(float t=0;t<=1;t=t+0.001)
 {
  xn=(((1-t)*(1-t)*(1-t))*x[0][0]+3*t*((1-t)*(1-t))*x1[0][0]+3*(t*t)*(1-t)*x1[0][1]+(t*t*t)*x[0][1]);
    yn=(((1-t)*(1-t)*(1-t))*x[1][0]+3*t*((1-t)*(1-t))*x1[1][0]+3*(t*t)*(1-t)*x1[1][1]+(t*t*t)*x[1][1]);
  putpixel(xn,yn,4);
 }
 line(x[0][0],x[0][1],x[1][0],x[1][1]);
  line(x[0][0],x[0][1],x1[0][0],x1[0][1]);
  line(x1[0][0],x1[0][1],x1[1][0],x1[1][1]);
  line(x[1][0],x[1][1],x1[1][0],x1[1][1]);
}

void main()
{
 int i,gd = DETECT,gm;
   initgraph(&gd,&gm,"");

 cout<<"\n Press 1 for hermite curve  2 for bezier curve";
 cin>>ch;
if(ch==1)
 { cout<<"\n    HERMITE CURVE";
   cout<<"\n Enter the 2 end points and 2 control points:";
   for( i=0;i<2;i++)
   {
    for(j=0;j<2;j++)
    {
     cin>>p1[i][j];
    }
   }
    for( i=0;i<2;i++)
   {
    for(j=0;j<2;j++)
    {
   cin>>r1[i][j];
    }
   }
 hermite(p1,r1);
}
else
{  cout<<"\n    BEZIER CURVE";
   cout<<"\n Enter the 2 end points and 2 control points:";
   for( i=0;i<2;i++)
   {
    for(j=0;j<2;j++)
    {
     cin>>p1[i][j];
    }
   }
    for( i=0;i<2;i++)
   {
    for(j=0;j<2;j++)
    {
   cin>>r1[i][j];
    }
   }
 bezier(p1,r1);
}
getch();
}