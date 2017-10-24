# include <iostream.h>
# include <graphics.h>
# include <conio.h>
# include <math.h>



 void show_screen( );

 void Bezier_curve(const int [8]);

 double nCr(int,int);
 double factorial(int);

 void Dashed_line(const int,const int,const int,const int,const int=0);


 int main( )
    {
       int driver=VGA;
       int mode=VGAHI;

       int control_points[8]={0};

       do
	  {
	     show_screen( );

	     for(int count=0;count<=3;count++)
		{
		   gotoxy(8,10);
		   cout<<"Coordinates of Point-"<<count<<" (x"<<count<<",y"<<count<<") :";

		   gotoxy(8,11);
		   cout<<"อออออออออออออออออออออออออออออออออ";

		   gotoxy(12,13);
		   cout<<"Enter the value of x"<<count<<" = ";
		   cin>>control_points[(count*2)];

		   gotoxy(12,15);
		   cout<<"Enter the value of y"<<count<<" = ";
		   cin>>control_points[((count*2)+1)];

		   gotoxy(8,10);
		   cout<<"                                            ";

		   gotoxy(12,13);
		   cout<<"                                            ";

		   gotoxy(12,15);
		   cout<<"                                            ";
	     }

	     initgraph(&driver,&mode,"..\\Bgi");

	     setcolor(15);
	       Bezier_curve(control_points);

	     setcolor(15);
	       outtextxy(110,460,"Press <Enter> to continue or any other key to exit.");

	     int key=int(getch( ));

	     if(key!=13)
		break;
	  }
       while(1);

       return 0;
    }


 void Bezier_curve(const int cp[8])
    {
       int color=getcolor( );

       setcolor(7);

       for(int count=0;count<3;count++)
	  Dashed_line(cp[(count*2)],cp[((count*2)+1)],
				    cp[((count+1)*2)],cp[(((count+1)*2)+1)]);

       float x;
       float y;

       for(float u=0.0005;u<=1;u+=0.0005)
	  {
	     x=0;
	     y=0;

	     for(int k=0;k<=3;k++)
		{
		   x+=(cp[(k*2)]*nCr(3,k)*pow(u,k)*powl((1-u),(3-k)));
		   y+=(cp[((k*2)+1)]*nCr(3,k)*pow(u,k)*powl((1-u),(3-k)));
		}

	     putpixel((int)(x+0.5),(int)(y+0.5),color);
	  }
    }


 double nCr(int n,int r)
    {
       double nf;
       double rf;
       double nrf;
       double ncr;

       nf=factorial(n);
       rf=factorial(r);
       nrf=factorial((n-r));

       ncr=(nf/(rf*nrf));

       return ncr;
    }


 double factorial(int number)
    {
       double factorial=1;

       if(number==0 || number==1);

       else
	  {
	     for(int count=1;count<=number;count++)
		factorial=factorial*count;
	  }

       return factorial;
    }


 void Dashed_line(const int x_1,const int y_1,const int x_2,
					  const int y_2,const int line_type)
    {
       int count=0;
       int color=getcolor( );

       int x1=x_1;
       int y1=y_1;

       int x2=x_2;
       int y2=y_2;

       if(x_1>x_2)
	  {
	     x1=x_2;
	     y1=y_2;

	     x2=x_1;
	     y2=y_1;
	  }

       int dx=abs(x2-x1);
       int dy=abs(y2-y1);
       int inc_dec=((y2>=y1)?1:-1);

       if(dx>dy)
	  {
	     int two_dy=(2*dy);
	     int two_dy_dx=(2*(dy-dx));
	     int p=((2*dy)-dx);

	     int x=x1;
	     int y=y1;

	     putpixel(x,y,color);

	     while(x<x2)
		{
		   x++;

		   if(p<0)
		      p+=two_dy;

		   else
		      {
			 y+=inc_dec;
			 p+=two_dy_dx;
		      }

		   if((count%2)!=0 && line_type==0)
		      putpixel(x,y,color);

		   else if((count%5)!=4 && line_type==1)
		      putpixel(x,y,color);

		   else if((count%10)!=8 && (count%10)!=9 && line_type==2)
		      putpixel(x,y,color);

		   else if((count%20)!=18 && (count%20)!=19 && line_type==3)
		      putpixel(x,y,color);

		   else if((count%12)!=7 && (count%12)!=8 &&
			    (count%12)!=10 && (count%12)!=11 && line_type==4)
		      putpixel(x,y,color);

		   count++;
		}
	  }

       else
	  {
	     int two_dx=(2*dx);
	     int two_dx_dy=(2*(dx-dy));
	     int p=((2*dx)-dy);

	     int x=x1;
	     int y=y1;

	     putpixel(x,y,color);

	     while(y!=y2)
		{
		   y+=inc_dec;

		   if(p<0)
		      p+=two_dx;

		   else
		      {
			 x++;
			 p+=two_dx_dy;
		      }

		   if((count%2)!=0 && line_type==0)
		      putpixel(x,y,color);

		   else if((count%5)!=4 && line_type==1)
		      putpixel(x,y,color);

		   else if((count%10)!=8 && (count%10)!=9 && line_type==2)
		      putpixel(x,y,color);

		   else if((count%20)!=18 && (count%20)!=19 && line_type==3)
		      putpixel(x,y,color);

		   else if((count%12)!=7 && (count%12)!=8 &&
			    (count%12)!=10 && (count%12)!=11 && line_type==4)
		      putpixel(x,y,color);

		   count++;
		}
	  }
    }


 void show_screen( )
    {
       restorecrtmode( );
       clrscr( );
       textmode(C4350);

       cprintf("\n********************************************************************************");
       cprintf("*-**************************-                      -**************************-*");
       cprintf("*---------------------------- ");

       textbackground(1);
       cprintf(" Bezier Curve ");
       textbackground(8);

       cprintf(" ----------------------------*");
       cprintf("*-**************************-                      -**************************-*");
       cprintf("*-****************************************************************************-*");

       for(int count=0;count<42;count++)
	  cprintf("*-*                                                                          *-*");

       gotoxy(1,46);
       cprintf("*-****************************************************************************-*");
       cprintf("*------------------------------------------------------------------------------*");
       cprintf("********************************************************************************");

       gotoxy(1,2);
    }

