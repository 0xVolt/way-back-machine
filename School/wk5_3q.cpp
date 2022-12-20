#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
void create()
{
fstream f1;
char line[80],ch;
f1.open("story.txt",ios::out);
do{
cout<<"Enter a line";
gets(line);
f1<<line<<endl;
cout<<"do you want to enter more lines";
cin>>ch;
}while(ch=='y'||ch=='Y');
if(!f1)
{cout<<"Error";
exit(0);
}
f1.close();
}
void count()
{
fstream f1,f2;
char str[100];
int line=0;
f1.open("story.txt",ios::in);
f2.open("found.txt",ios::out);
while(f1.getline(str,100))
{
if(str[0]=='R'||str[0]=='D')
{
line++;
f2<<str<<endl;
}
}
cout<<"No. of lines"<<line;
f1.close();
f2.close();
}
void main()
{
create();
count();
getch();
}


