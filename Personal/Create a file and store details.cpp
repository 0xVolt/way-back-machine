#include <fstream.h>
#include <conio.h>

void main()
	{
   	fstream a;
      a.open("Marks.txt" , ios :: out);
      char ans = 'y';
      float marks;
      int rollno;
      while(ans == 'y' || ans == 'Y')
      	{
         	cout<<"Enter the Rollno of student : ";
            cin>>rollno;
            cout<<"Enter Average marks : ";
            cin>>marks;
            a<<rollno<<"\n"<< marks;
            cout<<"Continue ? ";
            cin>>ans;
         }
      a.close();
      getch();
   }