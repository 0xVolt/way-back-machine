#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<conio.h>

class FLIGHT
   {
    private :
       int Fno;
       char From[20], To[20];

    public :
       char *GetFrom()
          {
           return(From);
          }
       char *GetTo()
          {
           return(To);
          }
       int Flightno()
          {
           return(Fno);
          }

       void Input()
          {
           cout<<"\nEnter the flight number : ";
           cin>>Fno;
           cout<<"Enter the starting location : ";
           gets(From);
           cout<<"Enter the destination : ";
           gets(To);
          }
       void Show()
          {
           cout<<"\n"<<Fno<<" : "<<From<<" : "<<To<<endl;
          }
   };

char Menu();

void CreateFile()
   {
    fstream fout;
    fout.open("Flight.dat",ios::binary|ios::out);
    if (!fout)
       {
        cout<<"\File could not be created";
        getch();
        Menu();
       }
    FLIGHT A;
    for (int i=0;i<4;i++)
       {
        A.Input();
        fout.write((char *)&A,sizeof(A));
       }
    fout.close();
   }

void AppendData()
   {
    fstream fapp;
    fapp.open("Flight.dat",ios::binary|ios::app);
    if (!fapp)
       {
        cout<<"\File could not be opened";
        getch();
        Menu();
       }
    FLIGHT A;
    A.Input();
    fapp.write((char *)&A,sizeof(A));
    fapp.close();
   }

void Search()
   {
    fstream fin;
    fin.open("Flight.dat",ios::binary|ios::in);
    if (!fin)
       {
        cout<<"\File could not be opened";
        getch();
        Menu();
       }
    int flag = 0;
    FLIGHT A;
    while (fin.read((char *)&A ,sizeof(A)))
       {
        if (strcmpi(A.GetTo(),"Chandigarh")==0)
           {
            flag = 1;
            break;
           }
       }
    fin.close();
    if (flag == 1)
        A.Show();
    else if(flag ==0)
        cout<<"\nEntry could not be found";

   }

void DeleteRecord()
   {
    fstream fin,fout;
    fin.open("Flight.dat",ios::binary|ios::in);
    fout.open("Temp.dat",ios::binary|ios::out);
    if (!fin || !fout)
       {
        cout<<"\File could not be opened";
        getch();
        Menu();
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

void InsertRecord()
   {
    fstream fin,fout;
    fin.open("Flight.dat",ios::binary|ios::in);
    fout.open("Temp.dat",ios::binary|ios::out);
    if (!fin || !fout)
       {
        cout<<"\File could not be opened";
        getch();
        Menu();
       }
       int flag = 0;
    FLIGHT A,B;
    B.Input();
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

void ModifyRecord()
   {
    fstream finout;
    finout.open("Flight.dat",ios::binary|ios::in|ios::out);
    if (!finout)
       {
        cout<<"\File could not be opened";
        getch();
        Menu();
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
            A.Input();
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

void Display()
   {
    fstream fin;
    fin.open("Flight.dat",ios::binary|ios::in);
    if (!fin)
       {
        cout<<"\File could not be opened";
        getch();
        Menu();
       }
    FLIGHT A;
    while (fin.read((char *)&A ,sizeof(A)))
       A.Show();
    fin.close();
   }

char Menu()
   {
    clrscr();
    int a;
    cout<<"\n             MENU";
    cout<<"\n            ------";
    cout<<"\n1. Create a file with 4 records";
    cout<<"\n2. Append data to the file";
    cout<<"\n3. Search for flight with destinstion Chandigarh";
    cout<<"\n4. Delete a record";
    cout<<"\n5. Modify a record";
    cout<<"\n6. Insert a new record";
    cout<<"\n7. Display records";
    cout<<"\n8. Exit the program";
    cout<<"\n\nSelect an option : ";
    cin>>a;
    switch (a)
       {
        case 1 : CreateFile();
                 break;
        case 2 : AppendData();
                 break;
        case 3 : Search();
                 break;
        case 4 : DeleteRecord();
                 clrscr();
                 break;
        case 5 : ModifyRecord();
                 break;
        case 6 : InsertRecord();
                 break;
        case 7 : Display();
                 break;
        case 8 : exit(0);

        default : cout<<"\nError in selection. Please enter again : ";
       }
   }

void main()
	{
   	for(;;)
      	{
         	Menu();
         	clrscr();
         }
      getch();
   }
