#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

class FLIGHT
	{
   	int Fno;
      char From[20];
      char To[20];

      public :

      char *GetFrom()
      	{
         	return From;
         }
      char *GetTo()
      	{
         	return To;
         }
      int Flightno()
      	{
         	return Fno;
         }
		void input()
      	{
         	cout << "\nEnter the Flight number: ";
            cin >> Fno;
            cout << "Enter the starting location: ";
            gets(From);
            cout << "Enter the destination: ";
            gets(To);
         }

      void show()
      	{
         	cout << Fno << " : " << From << " : " << To << endl;
         }
   };

void display()
	{
   	fstream f1;
      FLIGHT a;
      f1.open("flight.dat", ios :: in | ios :: binary);
      while(f1.read((char*)&a, sizeof(a)))
      	{
         	a.show();
            cout << "\n";
         }
      f1.close();
   }

void main()
	{
   	fstream fin, fout;
      FLIGHT a;
      fin.open("Flight.dat", ios :: binary | ios :: in);
      fout.open("Temp.dat", ios :: binary | ios :: out);
      while(fin.read((char *)&a, sizeof(a)))
      	{
         	if(strcmpi(a.GetTo(), "Delhi") == 0)
            	{
               	fout.write((char *)&a, sizeof(a));
                  break;
               }
            else
            	cout << "Record not found...\n";
         }
      display();
      fin.close();
      fout.close();
      remove("Flight.dat");
      rename("Temp.dat", "flight.dat");
      getch();
   }