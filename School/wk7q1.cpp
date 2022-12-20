#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <process.h>

int arr[10], i;

int Binary_Search(int A[], int size, int item)
	{
   	int beg, mid, last;
      beg = 0;
      last = size - 1;
      while(beg <= last)
      	{
         	mid = (beg + last) / 2;
            if(item == A[mid])
            	return mid;
            else if(item > A[mid])
            	beg = mid + 1;
            else
            	last = mid - 1;
         }
      return -1;                 																//control only reaches here if the item isnt found in the array
   }

int Linear_Search(int A[], int size, int item)
	{
   	for(i=0;i<size;++i)
      	{
         	if(A[i] == item)
            	return i;
         }
      return -1;																						//control only reaches here if the item isnt found in the array
   }

void Menu()
	{
      int choice;
      int var, index, position;
   	cout << "\n\tM E N U\n";
      cout << "\t-------\n\n";
      cout << "1. Linear search\n";
      cout << "2. Binary search\n";
      cout << "3. Exit\n";
      cout << "\nPlease enter your choice(1/2/3): ";
      cin >> choice;

      switch(choice)
      	{
         	case 1 : system("cls");
            			cout << "Please enter the elements of the array:\n";
            			for(i=0;i<10;++i)
                     	cin >> arr[i];
                     cout << "Enter the element to be searched for:\n";
                     cin >> var;
                     index = Linear_Search(arr, 10, var);
                     if(index == -1)
                     	cout << "Unfortunately, the element was not found...\n";
                     else
                     	{
                        	position = index + 1;
                           cout << "The element was found at position: " << position;
                        }
                     cout << "\n\n\nPress any key to continue...\n";
                     getch();
                     system("cls");
                     break;

            case 2 : system("cls");
            			cout << "Please enter an array of 10 integers in ascending order:\n";
      					for(i=0;i<10;++i)
      						cin >> arr[i];
      					cout << "Enter the element to look for:\n";
      					cin >> var;
      					index = Binary_Search(arr, 10, var);
                     if(index == -1)
                     	cout << "Unfortunately, the element was not found...\n";
                     else
      					{
                     	position = index + 1;
      						cout << "The element was found at position : " << position;
                     }
                     cout << "\n\n\nPress any key to continue...\n";
                     getch();
                     system("cls");
                     break;

            case 3 : exit(0);

            default : cout << "\nInvalid choice, please try again: ";
         }
   }

void main()
	{
      for(;;)
      	Menu();
   	getch();
   }