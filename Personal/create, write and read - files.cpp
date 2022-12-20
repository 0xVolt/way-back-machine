#include <fstream.h>
#include <conio.h>
#include <stdio.h>

void main()
	{
   	int i;
      char name[20];
      float mark;
      fstream a, b;
      a.open("student.txt", ios :: out);
      for(i=0;i<5;++i)
      	{
         	cout << "Enter the details of student " << i+1 << "\n";
            cout << "Enter the Student's Name : ";
            gets(name);
            cout << "Enter the marks of the student : ";
            cin >> mark;
            a << name << "\n" << mark;
         }
		a.close();
      cout << "\n\n";
      b.open("student.txt", ios :: in);
      for(i=0;i<5;++i)
      	{
         	b >> name >> mark;
            cout << name << "\n" << mark << "\n";
         }
      b.close();
      getch();
   }
