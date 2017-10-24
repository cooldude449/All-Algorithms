void thicknver(int x1,int y1, int x2, int y2,int n)
{
	for(int i=0;i<(n/2);i++)
	{
		putpixel(x1,++y1,RED);
		putpixel(x2,--y2,RED);
	}

}
void thicknhor(int x1,int y1, int x2, int y2,int n)
{
	for(int i=0;i<(n/2);i++)
	{
		putpixel(--x1,y1,RED);
		putpixel(++x2,y2,RED);
	}

}
void bresenham(int x1,int y1,int x2,int y2,int n){
  int dy,dx,b,xu,yu,xb,yb;         //declaration of x's and y's
   float m,d;
   if(x1>x2 && y1>y2)
   {
	int temp=x1;
	x1=x2;
	x2=temp;
	temp=y1;
	y1=y2;
	y2=temp;
   }
   dy=y2-y1;
   dx=x2-x1;
   m=(float)dy/(float)dx;
   if(m<=1)
   {
	if(y1>y2)
	{
		d=(float)dy+(float)dx/2;
		while(x1<x2)
		{
			if(d<=0)
			{       xu=xb=++x1; yu=yb=--y1;
				thicknver(xu,yu,xb,yb,n);
				putpixel(x1++,y1--,RED);
				d=d+dy+dx;
			}
			else if(d>0)
			{        xu=xb=++x1; yu=yb=y1;
				thicknver(xu,yu,xb,yb,n);
				putpixel(x1,y1,RED);
				d=d+dy;
			}
		}
	}
	else if(x1>x2)
	{
		d=-(float)(dy/2)-(float)dx;
		while(y1<y2)
		{
			if(d<=0) //N
			{
				 xu=xb=x1; yu=yb=++y1;
				thicknver(xu,yu,xb,yb,n);
				putpixel(x1,y1,RED);
				d=d-dx;
			}
			else if(d>0)          //NW
			{
				 xu=xb=--x1; yu=yb=++y1;
				thicknver(xu,yu,xb,yb,n);
				putpixel(x1,y1,RED);
				d=d-dy-dx;
			}
		}
	}
	else
	{
		d=dy-(float)(dx/2);
		while(x1<x2)
		{
			if(d<=0)          //E
			{
				 xu=xb=++x1; yu=yb=y1;
				thicknver(xu,yu,xb,yb,n);
				putpixel(x1,y1,RED);
				d=d+dy;
			}
			else if(d>0)
			{
				 xu=xb=++x1; yu=yb=++y1;
				thicknver(xu,yu,xb,yb,n);
				putpixel(x1,y1,RED);
				d=d+dy-dx;
			}
		}
	}
   }
	else if(m>1)
	{
		d=(float)(dy/2)-dx;
		while(y1<y2)
		{
			if(d<=0)
			{
				 xu=xb=++x1; yu=yb=++y1;
				thicknhor(xu,yu,xb,yb,n);
				putpixel(x1,y1,RED);
				d=d+dy-dx;
			}
			else if(d>0)
			{
				 xu=xb=x1; yu=yb=++y1;
				thicknhor(xu,yu,xb,yb,n);
				putpixel(x1,y1,RED);
				d=d-dx;
			}
		}
	}

}
