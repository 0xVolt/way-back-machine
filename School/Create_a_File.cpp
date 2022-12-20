#include <fstream.h>
#include <conio.h>
#include <stdio.h>

void main()
	{
   	ofstream f1;
      char t[80];
      f1.open("story.txt", ios :: out);
      cout << "Enter the contents to store in the file: ";
      gets(t);
      f1 << t;
      f1.close();
      getch();
   }
