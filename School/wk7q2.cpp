#include <iostream.h>
#include <conio.h>
#include <process.h>
#include <limits.h>												//for INT_MIN

int arr[10];
int i, j;

void Bubble_Sort(int A[], int size)
	{
   	int t, c = 0;
      for(i=0;i<10;++i)
      	{
         	for(j=0;j<9;++j)
            	{
               	if(A[j] > A[j+1])
                  	{
                     	t = A[j];
                        A[j] = A[j+1];
                        A[j+1] = t;
                     }
               }
            cout << "\nArray after iteration " << c++ << " is:\t";
            for(j=0;j<10;++j)
            	cout << A[j] << " ";  
         }
   }

void Selection_Sort(int A[], int size)
	{
   	int small, pos, t;
      for(i=0;i<10;++i)
      	{
         	small = A[i];
            pos = i;
            for(int j=i+1;j<10;++j)
            	{
               	if(A[j] < small)
                  	{
                     	small = A[j];
                        pos = j;
                     }
               }
            t = A[i];
            A[i] = A[pos];
            A[pos] = t;
            cout << "\nArray after pass " << (i + 1) << " is:\t";
            for(j=0;j<10;++j)
            	cout << A[j] << " ";
         }
   }

void Insertion_Sort(int A[], int size)
	{
   	int t, c = 0;
      for(i=1;i<10;++i)
      	{
         	t = A[i];
            j = i - 1;
            while(t < A[j] && j >= 0)
            	{
                	A[j+1] = A[j];
                  j--;
               }
            A[j+1] = t;
            cout << "\nArray after iteration " << c++ << " is:\t";
            for(j=0;j<10;++j)
            	cout << A[j] << " ";
         }
   }

void Menu()
	{
      int choice;
      int item, index;
   	cout << "\n\tM E N U\n";
      cout << "\t-------\n\n";
      cout << "1. Bubble Sort\n";
      cout << "2. Exchange Selection Sort\n";
      cout << "3. Insertion Sort\n";
      cout << "4. Exit\n\n";
      cout << "\nPlease enter your choice(1/2/3/4): ";
      cin >> choice;

      switch(choice)
      	{
         	case 1 : system("cls");
                     cout << "Please enter the elements:\n";
            			for(i=0;i<10;++i)
                     	cin >> arr[i];
                     Bubble_Sort(arr, 10);
                     cout << "\nThe sorted array is shown down below:\n";
                     for(i=0;i<10;++i)
                     	cout << arr[i] << " ";
            			cout << "\n\nPress any key to continue...\n";
                     getch();
                     system("cls");
            			break;

            case 2 : system("cls");
            			cout << "Please enter the elements:\n";
            			for(i=0;i<10;++i)
                     	cin >> arr[i];
                     Selection_Sort(arr, 10);
                     cout << "\nThe sorted array is shown down below:\n";
                     for(i=0;i<10;++i)
                     	cout << arr[i] << " ";
                     cout << "\n\nPress any key to continue...";
                     getch();
                     system("cls");
                     break;

            case 3 : system("cls");
            			cout << "Please enter the elements:\n";
            			for(i=0;i<10;++i)
                     	cin >> arr[i];
                     Insertion_Sort(arr, 10);
                     cout << "\nThe sorted array is shown down below:\n";
                     for(i=0;i<10;++i)
                     	cout << arr[i] << " ";
                     cout << "\n\nPress any key to continue...";
                     getch();
                     system("cls");
            			break;

            case 4 : exit(0);

            default : cout << "\nInvalid choice, please try again: ";
         }
   }

void main()
	{
      for(;;)
      	Menu();
   	getch();
   }