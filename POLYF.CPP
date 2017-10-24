#include <graphics.h>
#include<math.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define GET_SIZE 500

/*
a list is made up of nodes, we have to make several nodes with parateres
like ymax, ymin, 1/m aka rm and a pointer next to point to the next node.
*/

class node{
	public:
		int ymax;
		float xmin;
		float rm;
		node* next;
		node(int y,int x,float m)
		{
			ymax=y;
			xmin=x;
			rm=m;
			next=0;
		}
};


/*
A class "list" is needed for creating GET and AET table. It consists of
del(), copy(), sort().
*/
class list{
	public:
		node* head;
		node* tail;
		void print(int);
		int isEmpty()
		{
			if(head==0)
				return 1;
			return 0;
		}
		void copy(int);
		void del(int);
		void sort();
		list()
		{
			head=tail=0;
		}
		void shift_the_tail(node* &tail);
		void putpix(int y);

};

// An array GET that will point to lists (Linked lists).
list* GET[GET_SIZE]={0};
/*
copy() method will copy a list of nodes from GET based on the parameter y
and intsert it into the tail of the AET. (cp is a temporary pointer that
will hold the head ofthe copied list.
)
*/
void list::copy(int y)
{
	node* cp;
	if(GET[y]!=0)
	{
		cp=GET[y]->head;
		if(head==0)
		{
			head=cp;
			tail=GET[y]->tail;
		}
		else
		{
			tail->next=cp;
			tail=GET[y]->tail;
		}
	}
	else
		cout<<"\nno list present\n";
}

void list::shift_the_tail(node* &tail)
{
	node* temp=tail;
	while(temp->next->next!=0)
	{
		temp=temp->next;
	}
	tail= temp->next;
}
/*
the delete method del() takes the y as parameter and delete the node whose
ymax == y.
*/
int flag=0;
void list::del(int y)
{
	  node* temp=head;node* temp0;
	while(temp!=0)
	{

	if(head==tail&&head->ymax==y)
	{
		head=0;
		tail=0;
		temp=0;
	}
	else
	{


		if(head==temp&&head->ymax!=y)
		{
			temp0=head;
		}
		if(y==temp->ymax)
		{       if(temp==head)
				head=head->next;
			else
			{
				temp0->next=temp->next;
				if(temp==tail)
					tail=temp0;
			}

		}
		else
			temp0=temp;
		temp=temp->next;
	}}
}
/*
The sort() method is for sorting the AET linked list using the Selection sort
with the help of pointers current, walker, smallest.
*/
void list::sort()
{
	node* current=head;node* walker;node* shortest=head;
	while(current->next!=0)         // scaning via current pointer
	{
		walker=current;
		while(walker->next!=0)    //scaning via walker pointer
		{
			if(walker->next->xmin<shortest->xmin)
			{
				shortest=walker->next;
			}
			walker=walker->next;
		}
		int temp1,temp2;float temp3;

		//swap

		temp1=shortest->ymax;
		temp2=shortest->xmin;
		temp3=shortest->rm;
		shortest->ymax=current->ymax;
		shortest->xmin=current->xmin;
		shortest->rm=current->rm;
		current->ymax=temp1;
		current->xmin=temp2;
		current->rm=temp3;

		//point to next node

		 shortest=current=current->next;
	}
}
int vertices[20][2];

int read()
{
	cout<<"Enter the number of vertices";
	int num;
	cin>>num;

	for(int i=0;i<num;i++)
	{
		cout<<"\nEnter the vertice "<<i+1<<" of the poligon:  ";
		cin>>vertices[i][0]>>vertices[i][1];
	}
	cout<<"\n OK...";
	return num;
}
int ylarge=0;

void create_GET(int vert[][2],int num)
{
	int x0,y0,x1,y1; float m;
	for(int i=0;i<num;i++)
	{
		if(i<num-1)
		{
			x0=vert[i][0];
			y0=vert[i][1];
			x1=vert[i+1][0];
			y1=vert[i+1][1];
		}
		else
		{
		      x0=vert[0][0];
			y0=vert[0][1];
			x1=vert[i][0];
			y1=vert[i][1];
		}


		if(y0<y1)
		{
			m=(float)(y1-y0)/(float)(x1-x0);
			if(GET[y0]==0)
			{
				GET[y0]=new list();
				GET[y0]->head=GET[y0]->tail=new node(y1,x0,(float)1/m);
				}
			else
			{
				GET[y0]->tail->next=new node(y1,x0,float(1/m));
				GET[y0]->tail=GET[y0]->tail->next;
			}
			if(y1>ylarge)
				ylarge=y1;
		}
		else if(y1<y0)
		{
			m=(float)(y0-y1)/(float)(x0-x1);
			if(GET[y1]==0)
			{
				GET[y1]=new list();
				GET[y1]->head=GET[y1]->tail=new node(y0,x1,(float)1/m);
			}
			else
			{
				GET[y1]->tail->next=new node(y0,x1,float(1/m));
				GET[y1]->tail=GET[y1]->tail->next;
			}
			if(y0>ylarge)
				ylarge=y0;
		}
	}
	getch();
	node* temp1;
	for(int k=0;k<=GET_SIZE;k++)
	{

		if(GET[k]!=0)
		{
			temp1=GET[k]->head;
			while(temp1!=0)
			{
				cout<<"\n["<<temp1->ymax<<"-"<<temp1->xmin<<"-"<<temp1->rm<<"]";
				temp1=temp1->next;
			}
		}
	}
       cout<<"\nGlobal edge table created...\n";
}
void list::print(int y)
{
	node* temp=head;
	while(temp!=0)
	{
		cout<<"\n["<<y<<"--"<<temp->xmin<<"]";
		temp=temp->next;
	}
}

void list::putpix(int y)
{
	if(head!=0)
	{	node* temp=head;
		float f;



		while(temp!=0)
		{
			line(floor(temp->xmin+0.5),y,floor(temp->next->xmin+0.5),y);
			temp->xmin=temp->xmin+temp->rm;
			temp->next->xmin=temp->next->xmin+temp->next->rm;
			temp=temp->next->next;

		}
	}
}

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "C:\TC\BGI");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }
   list AET;
   int num=read();
   create_GET(vertices,num);
   int y=0;
   if(GET[y]!=0)
   {
   AET.copy(y);

   getch();
   AET.sort();
   getch();
   }
   while(y<ylarge)
   {
	AET.putpix(y);
	y++;
	if(GET[y]!=0)
	{
		cout<<"gfdgfdgfdg";
		if(!AET.isEmpty())
			AET.del(y);
		AET.copy(y);
		AET.sort();
	}
   }

   /* clean up */
   getch();
   closegraph();
   return 0;
}