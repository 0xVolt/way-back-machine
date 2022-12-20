#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class FLIGHT
	{
   	int Fno;
      char From[20];
      char To[20];
      public:
      char *GetFrom();
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
   			cout<<"Enter flight number:-  ";
      		cin>>Fno;
      		cout<<"Enter starting location:-  ";
      		gets(From);
      		cout<<"Enter Destination:-  ";
      		gets(To);
   		}
		void show()
			{
   			cout<<"Flight number "<<Fno<<" from "<<From<<" to "<<To<<endl;
   		}
   };
void main()
	{
      int ch;
      fstream f1;
      FLIGHT a[4];
      do
      	{
         	cout<<"MENU\n1.Create a file with 4 records in the ascendng order of flight number.\n2.Append data to the file.\n3.Search for a record where destination is Chandigarh.\n4.Delete a record when flight number is given\n5.Modify a record when flight number is given.\n6.Insert a new record in appropriate position.\n7.Display all the records in the file.";
      		cin>>ch;
            switch (ch)
            	{
               	case 1:
                  f1.open("Flight.dat",ios::binary|ios::out);
                  int i;
                  for (i=0;i<4;++i)
                  	{
                        a[i].input;
                        f1.write((char*)&a,sizeof(a));
                     }
                  f1.close();
                  break;

                  case 2:
                  int x;
                  f1.open("Flight.dat",ios::binary|ios::app);
                  int j;
                  cout<<"Enter flight number to append:-  ";
                  cin>>x;
                  for (j=0;j<4;++j)
                  	{
                     	if(a[j].Flightno()==x)
                        	{
                           	a[j].input;
                              f1.write((char)*&a,sizeof(a));
                           }
                     }
                  f1.close();
                  break;

                  case 3:
                  int rn; char ch='n';
                  ifstream f("Flight.dat",ios::in)
                  cout<<"Searching for record with destination chandigarh...";
                  for (int k=0;k<4;++k)
                  	{
                  		while(!f.eof())
                  			{
                     			f.read((char*)&a[k],sizeof(a[k]));
                        		if(a[k].GetTo()==rn)
                        			{
                           			a[k].input();
                              		ch='y';
                              		break;
                           		}
                     		}
                     }
                  if (found=='n')
                  cout<<"No record found!"<<endl;
                  f.close();
                  break;

                  case 4:
                  int a;
                  cout<<"Enter flight number to be deleted:-  ";
                  cin>>a;
                  ifstream f("Flight.dat",ios


