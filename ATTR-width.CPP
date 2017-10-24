#include <graphics.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "BRESENHA.H"

int main(void)
{
   /* request auto detection */
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
   int xi,yi,xe,ye,n;
   setcolor(getmaxcolor());
   cout<<"Enter the first and last points of the line. :";
   cin>>xi>>yi>>xe>>ye;
   cout<<endl<<"Enter the thickness of the line: ";
   cin>>n;
   bresenham(xi,yi,xe,ye,n);


   /* clean up */
   getch();
   closegraph();
   return 0;
}
