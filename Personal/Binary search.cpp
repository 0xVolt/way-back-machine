#include <iostream.h>
#include <conio.h>

int i;

int bsearch(int Arr[], int s, int v)
	{
   	int l, u, mid;
      l = 0;
      u = s - 1;
      while(l <= u)
			{
         	mid = (l + u) / 2;
            if(Arr[mid] == v)
            	return mid + 1;
            else if(v > Arr[mid])
            	l = mid + 1;
            else
            	u = mid - 1;
         }
      return -1;
   }

void main()
	{
   	int A[100], n, x;
      cout << "Please enter the number of terms:\n";
      cin >> n;
      cout << "Please enter the Array:\n";
      for(i=0;i<n;++i)
      	cin >> A[i];
      cout << "Please enter the number to search for:\n";
      cin >> x;
      int ans = bsearch(A, n, x);
      if(ans > 0)
      	cout << "The number " << x << " is present at position " << ans;
      else
      	cout << "The number " << x << " is not found...";
      getch();
   }