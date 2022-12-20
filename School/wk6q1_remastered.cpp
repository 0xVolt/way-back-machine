#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

fstream fin, fout;

class FLIGHT {
	int Fno;
   char From[20];
   char To[20];

   public :

   char *GetFrom() {
   	return From;
   }

   char *GetTo() {
   	return To;
   }

	int Flightno() {
   	return Fno;
   }

   void input() {
   	cout << "\nEnter the flight number:\n";
      cin >> Fno;
      cout << "\nEnter the starting location:\n";
      gets(From);
      cout << "Enter the destination:\n";
      gets(To);
   }

   void show() {
   	cout << Fno << " : " << From << " : " << To << endl;
   }
   void mod();
}a, b;

void create() {
	fout.open("flight.dat", ios :: out | ios :: binary);
   int i;
   cout << "Please enter the data in ascending order of flight number:\n";
   cout << "Enter the records:\n";
   for(i=1;i<=4;++i) {
   	a.input();
      fout.write((char*)&a, sizeof(a));
   }
   fout.close();
   cout << "\n\n";
}

void display() {
	fin.open("flight.dat", ios :: in | ios :: binary);
   cout << "Displaying contents of the file...\n";
   while(fin.read((char*)&a, sizeof(a))) {
   	a.show();
      cout << "\n";
   }
   fin.close();
}

void clean_sweep() {
   cout << "Operation Clean_Sweep Authorised!\nGoodbye....\n";
	fout.open("flight.dat", ios :: binary | ios :: out | ios :: trunc);
   fout.close();
}

void search() {
	char found = 'n';
   int flight_no;
   fin.open("flight.dat", ios :: binary | ios :: in);
   cout << "Enter the Flight number to be searched for in the file:\n";
   cin >> flight_no;
   while(fin.read((char*)&a, sizeof(a))) {
   	if(flight_no == a.Flightno()) {
      	cout << "File details found... \n";
         a.show();
         found = 'y';
         break;
      }
   }
   if(found == 'n') {
   	cout << "File details unavailable...\n\n";
   }
   fin.close();
}

void append() {
   FLIGHT b;
	fout.open("flight.dat", ios :: app | ios :: binary);
   char ans = 'y';
   while(ans == 'y') {
   	cout << "Enter the details please:\n";
      b.input();
      fout.write((char*)&b, sizeof(b));
      cout << "Records have been added to the file successfully!\n";
      cout << "Would you like to enter more records? (Y/N)\n";
      cin >> ans;
   }
   fout.close();
}

void del() {
	fin.open("flight.dat", ios :: in | ios :: binary);
   fout.open("temp.dat", ios :: out | ios :: binary);
   int flight_no;
   char found = 'f', confirm = 'n';
   cout << "Enter the flight number of the flight whose record is to be deleted:\n";
   cin >> flight_no;
   while(fin.read((char*)&a, sizeof(a))) {
   	if(a.Flightno() == flight_no) {
      	a.show();
         found = 't';
         cout << "Are you sure you want to delete this record? (Y/N)\n";
         cin >> confirm;
         if(confirm == 'n')
         	fout.write((char*)&a, sizeof(a));
      }
      else
      	fout.write((char*)&a, sizeof(a));
   }
   if(found == 'f')
   	cout << "Record was not found...\n";
   fin.close();
   fout.close();
   remove("flight.dat");
   rename("temp.dat", "flight.dat");
}

void FLIGHT :: mod() {
	cout << "Flight number: " << Fno << endl;
   cout << "starting location: " << From << endl;
   cout << "Destination: " << To << endl;
   cout << "\nEnter the new details:\n";
   int nFno;
   char nFrom[20], nTo[20];
   cout << "New Flight number: (Enter '0' to retain the old one)\n";
   cin >> nFno;
   cout << "New starting location: (Enter '.' to retain the old one)\n";
   gets(nFrom);
   cout << "New destination: (Enter '.' to retain the old one)\n";
   gets(nTo);
   if(strcmp(nFrom, ".") == 0)
   	strcpy(From, nFrom);
   if(strcmp(nTo, ".") == 0)
   	strcpy(To, nTo);
   if(nFno != 0)
   	Fno = nFno;
}

/*

void modify() {
	fin.open("flight.dat", ios :: in | ios :: out | ios :: binary);
   long pos;
   int flight_no;
   char found = 'f';
   cout << "Enter the flight number of the record whose data is to be modified:\n";
   cin >> flight_no;
   while(!fin.eof()) {
   	pos = fin.tellg();
      fin.read((char*)&a, sizeof(a));
      if(a.Flightno() == flight_no) {
      	a.input();
         fin.seekg(pos);
         fin.write((char*)&a, sizeof(a));
         found = 't';
         break;
      }
   }
   if(found == 'f')
   	cout << "Record not found...\n";
   fin.seekg(0);
   fin.close();
}

*/

void insert() {
  	fin.open("flight.dat", ios :: in | ios :: binary);
   fout.open("temp.dat", ios :: out | ios :: binary);
   char last = 'y';
   cout << "Enter the details of the flight to be inserted:\n";
   b.input();
   while(!fin.eof()) {
   	fin.read((char*)&a, sizeof(a));
      if(b.Flightno() <= a.Flightno()) {
      	fout.write((char*)&a, sizeof(a));
         last = 'n';
         break;
      }
      else
      	fin.write((char*)&a, sizeof(a));
   }
   if(last == 'y')
   	fout.write((char*)&b, sizeof(b));
   else if(!fin.eof()) {
   	while(!fin.eof()) {
      	fin.read((char*)&a, sizeof(a));
         fout.write((char*)&a, sizeof(a));
      }
   }
   fin.close();
   fout.close();
   remove("flight.dat");
   rename("temp.dat", "flight.dat");
}

void main() {

	//create();
   //display();
   //clean_sweep();
   //search();
   //append();
	//del();
   //modify();

   display();

   insert();
   display();
   getch();
}

































































































































