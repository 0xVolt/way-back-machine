#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <process.h>

void main()
	{
		fstream f1;
      int c = 0;
      char ch[20];
      f1.open("story.txt", ios :: in);
      while(f1 >> ch)
      	c++;
      f1.close();
      cout << "The number of words in the file opened is = " << c;
      cout << "\n\nPress any key to continue...";
      getch();
   }
