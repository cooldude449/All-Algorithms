#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
int intersectx,intersecty;
int in_vertex_x[10],in_vertex_y[10];
const int top=0,left=1,bottom=2,right=3;
int clip_x_min,clip_x_max,clip_y_min,clip_y_max;
int inside(int testx,int testy,int clip_boundary)
{
      if(clip_boundary==top && testy>clip_y_min)
      {
	   return 1;
      }

     else if(clip_boundary==left && testx>clip_x_min)
      {
	   return 1;
      }
     else if(clip_boundary==bottom && testy<clip_y_max)
      {
	   return 1;
      }
      else if(clip_boundary==right && testx<clip_x_max)
      {
	   return 1;
      }
      return 0;
}
void intersect(int x0,int y0,int x1,int y1,int clip_boundary)
{
      int xd=x1-x0;
      int yd=y1-y0;
      if(xd==0 || yd==0)
      {
		if(clip_boundary==top)
		{
			intersectx=x0;
			intersecty=clip_y_min;

		}
		else if(clip_boundary==left)
		{
			intersectx=clip_x_min;
			intersecty=y0;
		}
		else if(clip_boundary==bottom)
		{
			intersectx=x0;
			intersecty=clip_y_max;
		}
		else if(clip_boundary==right)
		{
			intersectx=clip_x_max;
			intersecty=y0;
		}
		return;
      }
      if(clip_boundary==top)
      {
		intersectx=x0+((float)xd/yd)*(clip_y_max-y0);
		intersecty=clip_y_max;
      }
      else if(clip_boundary==left)
      {
		intersectx=clip_x_min;
		intersecty=y0+((float)yd/xd)*(clip_x_min-x0);
      }
      else if(clip_boundary==bottom)
      {
		intersectx=x0+((float)xd/yd)*(clip_y_min-y0);
		intersecty=clip_y_min;
      }
      else if(clip_boundary==right)
      {
		intersectx=clip_x_max;
		intersecty=y0+((float)yd/xd)*(clip_x_max-x0);
      }
}
void draw_rect(int xmin,int xmax,int ymin,int ymax)
{
	line(xmin,ymin,xmax,ymin);
	line(xmax,ymax,xmax,ymin);
	line(xmin,ymax,xmin,ymin);
	line(xmin,ymax,xmax,ymax);
}

int polygon_clip(int n,int in_vertex_x[],int in_vertex_y[],int clip_boundary)
{
	int out_vertex_x[40],out_vertex_y[40];
	int outcount=0;
	int sx,sy,px,py;
	int i,j;
	sx=in_vertex_x[n-1];
	sy=in_vertex_y[n-1];
	      /*	for(int i=0;i<n-1;i++)
	{
		line(in_vertex_x[i],in_vertex_y[i],in_vertex_x[i+1],in_vertex_y[i+1]);
	}
	line(in_vertex_x[n-1],in_vertex_y[n-1],in_vertex_x[0],in_vertex_y[0]);
	 getch();*/
	for(j=0;j<n;j++)
	{
		px=in_vertex_x[j];
		py=in_vertex_y[j];
		if(inside(px,py,clip_boundary))
		{
			if(inside(sx,sy,clip_boundary))
			{
				out_vertex_x[outcount]=px;
				out_vertex_y[outcount]=py;
				outcount++;
			}
			else
			{
				intersect(sx,sy,px,py,clip_boundary);
				out_vertex_x[outcount]=intersectx;
				out_vertex_y[outcount]=intersecty;
				outcount++;
				out_vertex_x[outcount]=px;
				out_vertex_y[outcount]=py;
				outcount++;
			}
		}
		else
		{
			if(inside(sx,sy,clip_boundary))
			{
				intersect(sx,sy,px,py,clip_boundary);
				out_vertex_x[outcount]=intersectx;
				out_vertex_y[outcount]=intersecty;
				outcount++;
			}
		}
		sx=px;
		sy=py;
	}
       	for( i=0;i<n;i++)
	{
		cout<<in_vertex_x[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<in_vertex_y[i];
	}
	clrscr();
	draw_rect(clip_x_min,clip_x_max,clip_y_min,clip_y_max);

	//return outcount;
	for(i=0;i<outcount;i++)
	{
		in_vertex_x[i]=out_vertex_x[i];
		in_vertex_y[i]=out_vertex_y[i];
	}
	n=outcount;
	for(i=0;i<n-1;i++)
	{
	  line(in_vertex_x[i],in_vertex_y[i],in_vertex_x[i+1],in_vertex_y[i+1]);
	}
	line(in_vertex_x[n-1],in_vertex_y[n-1],in_vertex_x[0],in_vertex_y[0]);
	return n;
}
void main()
{
	int gdriver = DETECT, gmode, errorcode;
	int xmax, ymax;
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);
	}
	cout<<"\nenter the diagonal elements of the rectangle";
	cout<<"\nenter x min";
	cin>>clip_x_min;
	cout<<"\nenter y min";
	cin>>clip_y_min;
	cout<<"\nenter x max";
	cin>>clip_x_max;
	cout<<"\nenter y max";
	cin>>clip_y_max;
	clrscr();
	draw_rect(clip_x_min,clip_x_max,clip_y_min,clip_y_max);
	int n;
	cout<<"\nenter the number of vertices";
	cin>>n;
	cout<<"\nenter the x coordinates of the edges";
	for(int i=0;i<n;i++)
	{
		cin>>in_vertex_x[i];
	}
	cout<<"\nenter the y coordinates of the edges";
	for(i=0;i<n;i++)
	{
		cin>>in_vertex_y[i];
	}
	for(i=0;i<n-1;i++)
	{
		line(in_vertex_x[i],in_vertex_y[i],in_vertex_x[i+1],in_vertex_y[i+1]);

	}
	line(in_vertex_x[n-1],in_vertex_y[n-1],in_vertex_x[0],in_vertex_y[0]);
	getch();
	clrscr();
	n=polygon_clip(n,in_vertex_x,in_vertex_y,3);
        n=polygon_clip(n,in_vertex_x,in_vertex_y,2);
        n=polygon_clip(n,in_vertex_x,in_vertex_y,1);
        n=polygon_clip(n,in_vertex_x,in_vertex_y,0);
	getch();
      }


