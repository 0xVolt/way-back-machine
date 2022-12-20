#include <iostream.h>
#include <conio.h>

int i;

void selsort(int Arr[], int x)
	{
   	int pos, small, j;
      for(i=0;i<x;++i)
      	{
         	small = Arr[i];
            pos = i;
            for(j=i+1;j<x;++j)
            	{
               	if(Arr[i] < small)
                  	{
                     	small = Arr[j];
                        pos = j;
                     }
               }
            Arr[pos] = Arr[i];
            Arr[i] = small;
         }
      cout << "Sorted Array:\n";
      for(i=0;i<x;++i)
      	cout << Arr[i] << endl;
   }

void main()
	{
   	int A[100], n;
      cout << "Please enter the number of elements:\n";
      cin >> n;
      cout << "Please enter the Unsorted Array:\n";
      for(i=0;i<n;++i)
      	cin >> A[i];
      selsort(A, n);
      getch();
   }