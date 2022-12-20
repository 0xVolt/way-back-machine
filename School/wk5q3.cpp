#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>

void main()
	{
   	fstream f1, f2;
      char t[80];
      int c = 0;
      f1.open("story.txt", ios :: in);
      f2.open("found.txt", ios :: out);
      while(f1.getline(t, 80))
      	{
         	if(t[0] == 'R' || t[0] == 'D')
            	{
               	c++;
                  f2 << t << "\n";
                  puts(t);
               }
         }
      f2.close();
      f1.close();
      cout << "The number of line starting with the letter \'R\' or \'D\' in the file story.txt: ";
      cout << c;
      cout << "\n\nPress any key to exit...";
      getch();
   }