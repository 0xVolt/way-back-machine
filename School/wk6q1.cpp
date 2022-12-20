#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdio.h>
#include <process.h>

int i;

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

void create()
	{
   	fstream f1;
      FLIGHT a;
      f1.open("flight.dat", ios :: out | ios :: binary);
      cout << "Please enter in the ascending order of Flight number:\n\n";
      for(i=1;i<=4;++i)
      	{
         	a.input();
            f1.write((char*)&a, sizeof(a));
         }
      f1.close();
      cout << "File with 4 record created...\n\n";
   }

void append()
	{
   	fstream f1;
      FLIGHT a;
      int n;
      cout << "Enter the number of records to append:\n";
      cin >> n;
      f1.open("flight.dat", ios :: in | ios :: out | ios :: binary | ios :: app);
		for(i=0;i<n;++i)
      	{
          	a.input();
            f1.write((char*)&a, sizeof(a));
         }
      f1.close();
   }

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

void search()
	{
   	fstream f1;
      FLIGHT a;
      int f = 0;
      char dest[20];
      cout << "Enter the destination : \n";
      gets(dest);
      f1.open("flight.dat", ios :: in | ios :: binary);
      while(f1.read((char*)&a, sizeof(a)))
      	{
         	if(strcmpi(dest, a.GetTo()) == 0)
            	{
               	f = 1;
                  a.show();
               }
         }
      f1.close();
      if(f = 0)
      	cout << "sorry the record wasnt found...\n\n";
   }

void modify()
   {
    fstream finout;
    finout.open("Flight.dat",ios::binary|ios::in|ios::out);
    if (!finout)
       {
        cout<<"\File could not be opened";
        getch();
       }
    int Fnum,chk = 0;
    cout<<"\nEnter flight number to be modified : ";
    cin>>Fnum;
    FLIGHT A;
    while (finout.read((char *)&A ,sizeof(A)))
       {
        if (Fnum == A.Flightno())
           {
            cout<<"\nEnter new values :";
            A.input();
            finout.seekp(-1*sizeof(A) , ios::cur);
            finout.write((char *)&A ,sizeof(A));
            chk = 1;
            break;
           }
       }
    if (chk == 0)
       cout<<"\nEntry not found";
    finout.close();
   }

void insert()
   {
    fstream fin,fout;
    fin.open("Flight.dat",ios::binary|ios::in);
    fout.open("Temp.dat",ios::binary|ios::out);
    if (!fin || !fout)
       {
        cout<<"\File could not be opened";
        getch();
       }
       int flag = 0;
    FLIGHT A,B;
    B.input();
    while (fin.read((char *)&A ,sizeof(A)))
       {
        if ((A.Flightno() > B.Flightno()) && flag==0)
           {
            flag=1;
            fout.write((char *)&B,sizeof(B));
            fout.write((char *)&A,sizeof(A));

           }
        else
           {
            fout.write((char *)&A,sizeof(A));
           }
       }
    while(fin.read((char *)&A ,sizeof(A)))
       fout.write((char *)&A,sizeof(A));
    fin.close();
    fout.close();
    remove("Flight.dat");
    rename("Temp.dat","Flight.dat");
   }

void delfile()
   {
    fstream fin,fout;
    fin.open("Flight.dat",ios::binary|ios::in);
    fout.open("Temp.dat",ios::binary|ios::out);
    if (!fin || !fout)
       {
        cout<<"\File could not be opened";
        getch();
       }
    int Fnum;
    cout<<"\nEnter flight number to be deleted : ";
    cin>>Fnum;
    FLIGHT A;
    while (fin.read((char *)&A ,sizeof(A)))
       {
        if (Fnum != A.Flightno())
            fout.write((char *)&A,sizeof(A));
        else
           {
            cout<<"\nRecord has been deleted";
           }
       }
    fin.close();
    fout.close();
    remove("Flight.dat");
    rename("Temp.dat","Flight.dat");
   }

void clear()
	{
   	fstream fout;
      fout.open("flight.dat", ios :: binary | ios :: out | ios :: trunc);
      fout.close();
   }

void main()
	{
      int ans;
      for(;;)
      	{
         	cout << "------M E N U------\n\n";
            cout << "1. Create a file with 4 records in ascending order of Flight number\n";
            cout << "2. Append data to the file\n";
            cout << "3. Search for a record where the destination is Chandigarh\n";
            cout << "4. Delete a record where the Flight number is given\n";
            cout << "5. Modify a record where the Flight number is given\n";
            cout << "6. Insert a new record in appropriate position according to flight number\n";
            cout << "7. Display all records in a file\n";
            cout << "8. Delete all data in the file\n";
            cout << "9. Exit";
            cout << "\n\nEnter you choice: ";
            cin >> ans;
            switch(ans)
            	{
               	case 1 : create();
                  			break;

                  case 2 : append();
                  			break;

                  case 3 : search();
                  			break;

                  case 4 : delfile();
                  			break;

                  case 5 : modify();
                  			break;

                  case 6 : insert();
                  			break;

                  case 7 : display();
                  			break;

                  case 8 : clear();
                  			break;

                  case 9 : exit(0);

                  default : cout << "\nInvalid choice entered!!!\nPlease try again: ";
               }
         }

   }