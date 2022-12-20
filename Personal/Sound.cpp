#include <iostream.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>

void main()
	{
   	clrscr();
      int freq, dur;
      cout << "Please enter a value for the sound : ";
      cin >> freq;
      cout << "Please enter the duration (in seconds) : ";
      cin >> dur;
      dur *= 1000;
      cout << "The sound is as follows: ";
      sound(freq * 100);
      delay(dur);
      nosound();
      getch();
   }