#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>

void count()
	{
   	fstream f1;
      char c[20];
      int c_his = 0, c_her = 0;
      f1.open("story.txt", ios :: in);
      while(f1 >> c)
      	{
         	if(strcmpi(c, "his") == 0)
            	c_his++;
            else if(strcmpi(c, "her") == 0)
            	c_her++;
         }
      f1.close();
   	cout << "The count for \'Her\' in the file = " << c_her << endl;
      cout << "The count for \'His \'in the file = " << c_his << endl;
   }

void main()
	{
   	count();
      getch();
   }
