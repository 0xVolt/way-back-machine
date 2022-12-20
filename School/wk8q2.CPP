#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <process.h>

int i;

struct NODE
	{
   	int empcode;
      char name[20];
      float salary;
      NODE *next;
   };

class Stack
	{
   	NODE *Top;

      public:

      Stack()
      	{Top = NULL;}
      ~Stack()
      	{cout << "Destorying Stack!!";}

      void push();
      void pop();
      void isempty();
      void Count();
      void Display();
   };

void Stack :: push()
	{
    	NODE *ptr;
      ptr = new NODE;
      if(!ptr)
      	{
         	cout << "Insufficient memory";
            exit(0);
         }
      cout << "Enter the details of the employee..\n";
      cout << "Enter the employee code:\n";
      cin >> ptr->empcode;
      cout << "Enter the name of the employee:\n";
      gets(ptr->name);
      cout << "Enter the salary of the employee:\n";
      cin >> ptr->salary;
      ptr->next == NULL;
      if(Top == NULL)
			{
         	Top = ptr;
         }
      else
      	{
         	ptr->next = Top;
            Top = ptr;
         }
   }

void Stack :: pop()
	{
   	NODE *ptr;
      if(Top == NULL)
      	cout << "Stack Underflow!\n";
      else
      	{
         	ptr = Top;
            cout << "Popped element: \n";
            cout << ptr->empcode << endl;
            cout << ptr->name << endl;
            cout << ptr->salary << endl;
            Top = Top->next;
            delete ptr;
         }
   }

void Stack :: isempty()
	{
   	if(Top == NULL)
      	cout << "Stack is empty!\n\n";
      else
      	cout << "Stack is not empty!\n\n";
   }

void Stack :: Count()
	{
   	int ct = 0;
      NODE *ptr;
      if(Top == NULL)
      	cout << "Number of elements is: " << 0;
      else
      	{
         	ptr = Top;
            while(ptr != NULL)
            	{
               	ct++;
                  ptr = ptr->next;
               }
            cout << "Number of elements is: " <<(ct + 1);
         }
   }

void Stack :: Display()
	{
   	NODE *ptr;
      if(Top == NULL)
      	cout << "No elements in the stack to display!\n";
      else
      	{
         	ptr = Top;
            while(ptr != NULL)
            	{
                  cout << ptr->empcode << endl;
                  cout << ptr->name << endl;
                  cout << ptr->salary << endl;
                  cout << "\n";
                  ptr = ptr->next;
               }
         }
   }

void menu()
	{
      Stack a;
      int ans;
    	for(;;)
      	{
         	cout << "\n\n------\nM E N U\n------\n\n";
            cout << "1. Push an element to a stack\n";
            cout << "2. Pop an element from a stack\n";
            cout << "3. Check whether a stack is empty\n";
            cout << "4. Count the number of elements in a stack\n";
            cout << "5. Display elements in a stack\n";
            cout << "6. Exit\n";
            cout << "\n\nEnter you choice (1 to 6): ";
            cin >> ans;
            switch(ans)
            	{
               	case 1 : a.push();
                  			break;

                  case 2 : a.pop();
                  			break;

                  case 3 : a.isempty();
                  			break;

                  case 4 : a.Count();
                  			break;

                  case 5 : a.Display();
                  			break;

                  case 6 : exit(0);

                  default : cout << "\nInvalid choice entered!!!\nPlease try again: ";
               }
         }
   }

void main()
	{
      system("cls");
      menu();
   	getch();
   }