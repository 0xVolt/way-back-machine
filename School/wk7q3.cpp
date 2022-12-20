#include <iostream.h>
#include <conio.h>
#include <process.h>

int A[5], B[5];

void Merge_Sort(int A[], int m, int B[], int n)
	{
   	int C[50], i ,j, k;
      i = j = k = 0;
      while(i < m && j < n)
      	{
         	if(A[i] < B[j])
            	C[k++] = A[i++];
            else
            	C[k++] = B[j++];
         }
      while(i < m)
      	C[k++] = A[i++];
      while(j < n)
      	C[k++] = B[j++];
      cout << "The merged array is:\t";
      for(i=0;i<m+n;++i)
      	cout << C[i] << " ";
   }

void main()
	{
      int i;
   	cout << "Please enter 5 integers in ascending order to the first array:\n";
      for(i=0;i<5;++i)
      	cin >> A[i];
      cout << "Please enter 5 integers in ascending order to the second array:\n";
      for(i=0;i<5;++i)
      	cin >> B[i];
      Merge_Sort(A, 5, B, 5);
      getch();
   }

