1)	Write a program to implement DDA line drawing algorithm.


#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<math.h>
void main()
{
clrscr();
int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   int x1,y1,x2,y2;
   float m,p;
   cout<<"Enter X1 coordinate :";
   cin>>x1;
   cout<<"Enter Y1 coordinate :";
   cin>>y1;
   cout<<"Enter X2 coordinate :";
   cin>>x2;
   cout<<"Enter Y2 coordinate :";
   cin>>y2;
   clrscr();
   if((x2-x1)==0)
   {
   if(y1>y2)
   {     int temp;
       temp=y1;
       y1=y2;
       y2=temp;
   }
      for(int i=y1;i<=y2;i++)
	   putpixel(x1,i,RED);
    }
    else if((y2-y1)==0)
    {
    if(x1>x2)
    {     int temp;
       temp=x1;
       x1=x2;
       x2=temp;
    }
      for(int i=x1;i<=x2;i++)
	  putpixel(i,y1,RED);
    }
  else
  {
   m=(float((y2-y1))/(x2-x1));

   if(fabs(m)<1)
   {
   p=y1;
   putpixel(x1,y1,RED);
   if(x1>x2)
   {     int temp;
       temp=x1;
       x1=x2;
       x2=temp;
   }
   for(int i=x1+1;i<=x2;i++)
   {
   p=p+m;
   y1=floor(p+0.5);
   putpixel(i,y1,RED);
   }
   }
   else  if(m>=1)
   {
   p=x1;
   putpixel(x1,y1,RED);
   if(y1>y2)
   {     int temp;
       temp=y1;
       y1=y2;
       y2=temp;
   }
   for(int i=y1+1;i<=y2;i++)
   {
   p=p+1/m;
   x1=floor(p+0.5);
   putpixel(x1,i,RED);
   }
   }
   }
   getch();
}
