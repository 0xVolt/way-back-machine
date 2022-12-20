#include <iostream.h>
#include <conio.h>
#include <stdio.h>

//Q1
/*
struct QUEUE
{
int Data[10];
int rear, front;
}S1;

void QUEUE()
{S1.rear=S1.front=-1;}

void Insert()
{
if (S1.rear==9)
	cout<<"Queue is FULL\n\n\n";
else if (S1.rear==-1&&S1.front==-1)
	{
   S1.rear=S1.front=0;
   cout<<"Enter data: ";
   cin>>S1.Data[S1.rear];
   cout<<"\n\n\n";
   }
else
	{
   S1.rear++;
   cout<<"Enter data: ";
   cin>>S1.Data[S1.rear];
   cout<<"\n\n\n";
   }
}

void Delete()
{
if (S1.front==-1)
	cout<<"Queue is EMPTY\n\n\n";
else if (S1.rear==S1.front)
	{
   cout<<"Deleted data: ";
   cout<<S1.Data[S1.front]<<"\n\n\n";
   S1.rear=S1.front=-1;
   }
else
	{
   cout<<"Deleted data: ";
   cout<<S1.Data[S1.front--]<<"\n\n\n";
   }
}

void Isempty()
{
if (S1.front==-1)
	cout<<"Queue is EMPTY\n\n\n";
else
	cout<<"Queue is NOT empty\n\n\n";
}

void Isfull()
{
if (S1.rear==9)
	cout<<"Queue is FULL\n\n\n";
else
	cout<<"Queue is NOT full\n\n\n";
}

void Count()
{
cout<<"Number of elements= "<<(S1.rear-S1.front)<<"\n\n\n";
}

void Display()
{
if (S1.front==-1)
	cout<<"Queue is EMPTY\n\n\n";
else
	{
	for (int i=0;i<=S1.front;i++)
   	cout<<S1.Data[i]<<" ";
   cout<<"\n\n\n";
   }
}

void main()
{
int c;
for (;;)
	{
	cout<<"\t\tMenu\n1. Insert an element to a Queue\n2. Delete an element from a Queue\n3. Check if the Queue is empty\n4. Check if the Queue is full\n5. Count the no. of elements in the Queue\n6. Display the elements in the Queue\nEnter your choice: ";
   cin>>c;
   cout<<"\n\n";
   switch (c)
   	{
	   case 1:Insert();		break;
	   case 2:Delete();		break;
	   case 3:Isempty();		break;
      case 4:Isfull();  	break;
      case 5:Count(); 	 	break;
      case 6:Display();		break;
      default:cout<<"\nTry Again\n\n";
      }
   }
}
*/

//Q2

struct node
	{
   char name[25];
   long int Telno;
   node *link;
	};

class QUEUE
	{
   node *FRONT, *REAR;
   public:
   QUEUE() {FRONT=REAR=NULL;}
   ~QUEUE() {cout<<"\nDestroying Queue";}
   void Insert();
   void Delete();
   void Isempty();
   void Count();
   void Display();
   }q;

void QUEUE :: Insert()
	{
   node *ptr;
   ptr=new node;
   cout<<"\nEnter the name: ";
   gets(ptr->name);
   cout<<"\nEnter tel. no.: ";
   cin>>ptr->Telno;
   ptr->link=NULL;
	if (REAR==NULL)
      REAR=FRONT=ptr;
   else
   	{
      REAR->link=ptr;
      REAR=ptr;
      }
   }

void QUEUE :: Delete()
	{
   node *ptr;
   if (FRONT==NULL)
   	cout<<"\nQueue is Empty";
   else if (FRONT==REAR)
   	{
      ptr=FRONT;
      cout<<"\nName deleted is "<<FRONT->name<<"\n"<<FRONT->Telno;
      FRONT=NULL;
      delete ptr;
      }
   else
   	{
      ptr=FRONT;
      cout<<"\nName deleted is "<<FRONT->name<<"\n"<<FRONT->Telno;
      FRONT=FRONT->link;
      delete ptr;
      }
   }

void QUEUE :: Isempty()
	{
   if (FRONT==NULL)
   	cout<<"\nQueue is Empty";
   else
   	cout<<"\nQueue is not Empty";
   }

void QUEUE :: Count()
	{
   int c=0;
   node *ptr;
   ptr=FRONT;
   if (FRONT==NULL)
   	cout<<"\nQueue is Empty";
   else
   	{
      while (ptr!=NULL)
      	{
         c++;
         ptr=ptr->link;
         }
      cout<<"\nNo. of elements: "<<c;
      }
   }

void QUEUE :: Display()
	{
   int c=0;
   node *ptr;
   ptr=FRONT;
   if (FRONT==NULL)
   	cout<<"\nQueue is Empty";
   else
      while (ptr!=NULL)
      	{
         cout<<"\nName: "<<ptr->name;
         cout<<"\nTelephone no.: "<<ptr->Telno;
         ptr=ptr->link;
         }
   }

void main()
	{
   char c;
	for (;;)
		{
      getch();
      clrscr();
		cout<<"\t\tMenu\n1. Insert an element to a Queue\n2. Delete an element from a Queue\n3. Check if the Queue is empty\n4. Count the no. of elements in the Queue\n5. Display the elements in the Queue\nEnter your choice: ";
	   c=getche();
	   cout<<"\n\n";
	   switch (c)
	   	{
		   case '1':q.Insert();			break;
		   case '2':q.Delete();			break;
		   case '3':q.Isempty();		break;
	      case '4':q.Count(); 	 		break;
	      case '5':q.Display();		break;
	      default:cout<<"\nTry Again\n\n";
	      }
	   }
   }
