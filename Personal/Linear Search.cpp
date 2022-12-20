#include <iostream.h>
#include <conio.h>

int i;

int lsearch(int Arr[], int s, int VAL)
	{
   	for(i=0;i<s;++i)
      	{
         	if(Arr[i] == VAL)
            	return i+1;
            else if(Arr[i] > VAL)
            	return -1;
         }
   }

void main()
	{
   	int n, A[100], x, answer;
      cout << "Please enter the number of elements:\n";
      cin >> n;
      cout << "Please enter the array to be searched:\n";
      for(i=0;i<n;++i)
      	cin >> A[i];
      cout << "Please enter the nu,ber to seach for:\n";
      cin >> x;
      answer = lsearch(A, n, x);
      if(answer > 0)
      	cout << "The number " << x << " was found at position " << answer;
      else
      	cout << "Sorry, the number " << x << " was not found...";
      getch();
   }