#include <iostream.h>
#include <fstream.h>
#include <conio.h>

void main()
	{
   	fstream f1;
      char ch;
      int c_alph = 0;
      int c_digi = 0;
      f1.open("story.txt", ios :: in);
		while(f1 >> ch)
      	{
         	if(ch >= 'A' && ch <= 'z')
            	c_alph++;
            else
            	c_digi++;
         }
					 /*
      				Use isalpha and isdigit...
			       */
      f1.close();
      cout << "The number of letters: " << c_alph << endl;
      cout << "The number of digits: " << c_digi;
      getch();
   }
