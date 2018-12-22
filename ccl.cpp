#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<graphics.h>
#include<process.h>

class variable
{
  public:
  int value;

  char rep[20];

  variable()
  { value = 0;
  }
/*  void initialise(int a,char b)
  {
    value=a;
    rep=b;
    cout<<a<<"\t"<<b<<"\t";
  }
  char retrep()
  { return rep;
  }
  int retval()
  {  return value;
  }
  void display()
  { cout<<rep<<"\n";
    cout<<value<<"\n";
  } */
}var[10];

void feeder(char code[][20])
{
  ifstream fin;
  char str[20];
  fin.open("language.txt",ios::in);
  int i=1;


  while(!fin.eof())
  {
   if(i!=2)
   { fin.getline(str,20,' ');
   strcpy(code[i],str);
    }
    i++;
  }
  fin.close();

}

void createfeed()
{
  ofstream fout;
  char str[20];
  fout.open("language.txt",ios::out);
  cleardevice();
  setbkcolor(9);
  settextstyle(3,HORIZ_DIR,4);
   setcolor(15);
   outtextxy(90,50,"Enter the new language controls :");

   outtextxy(120,80,"Printing:");

   outtextxy(120,115,"Addition:");

   outtextxy(120,145,"Subtract:");

   outtextxy(120,175,"Multiply:");

   outtextxy(120,210,"Divide:");

   outtextxy(120,235,"Differentiation:");

   outtextxy(120,265,"Integration:");

//   outtextxy(120,295,"GIF:");


 //  rectangle(280,150,380,100);
    gotoxy(55,7);
    gets(str);
  fout<<str<<" ";
    gotoxy(55,9);
  gets(str);
  fout<<str<<" ";
    gotoxy(55,11);
  gets(str);
  fout<<str<<" ";
    gotoxy(55,13);
  gets(str);
  fout<<str<<" ";
    gotoxy(55,15);

  gets(str);
  fout<<str<<" ";
     gotoxy(55,17);
  gets(str);
  fout<<str<<" ";
     gotoxy(55,19);
  gets(str);
  fout<<str<<" ";
     gotoxy(55,21);
  gets(str);



  fout.close();
  cleardevice();

}
 void menu(void);




void main()
{

 clrscr();
 int driver,mode;
 driver=DETECT;
 initgraph(&driver,&mode,"C:\\tc\\bgi\\");
 void start();
 start();

}



  void start()  //Function definition
  {
   void play(char str[80]);  //Function prototype
   void gamescreen();        //Function prototype
   char str[80];
   setbkcolor(9);
   settextstyle(3,HORIZ_DIR,4);
   setcolor(15);
   outtextxy(170,175,"Enter your name :");
   rectangle(220,245,380,280);
   gotoxy(34,17);
   gets(str);
   cleardevice();
   menu();     }
   void workspace(void);
  // workspace();


 int stack[10],sti=0;
void menu()
{  int choice;
   setbkcolor(9);
   settextstyle(3,HORIZ_DIR,4);
   setcolor(15);
   outtextxy(170,50,"MENU");
   outtextxy(150,80,"1.Start Coding");
   outtextxy(150,110,"2.Change language settings");
   outtextxy(150,140,"3.Exit");
   gotoxy(34,18);
   cin>>choice;
   if(choice==1)
   { workspace();
   }
   else if(choice==2)
   {createfeed();
   }
   else if(choice==3)
   { exit(0);
   }

}

void workspace()
{
  clrscr();
  char str[20],fname[15],strr[10][20];
  int ch,p,i=0,index=0;
  char v,e,code[20][20];
  int chtoint(char*);

   cleardevice();
   setbkcolor(9);
   settextstyle(3,HORIZ_DIR,4);
   setcolor(15);
   outtextxy(180,160,"Open project");
   outtextxy(170,200,"Enter file name");
   rectangle(220,250,380,280);
   gotoxy(34,17);
  gets(fname);
  char choice;

   cleardevice();
   outtextxy(90,50,"Start coding");
  gotoxy(10,8);
  int ycod=10;
  ofstream fout;
  fout.open(fname,ios::out);
  while(strcmpi(strr[i-1],"end ) ;")!=0)
 { gotoxy(10,ycod);
  gets(strr[i]);
  ycod+=2;
   strcat(strr[i]," ) ;");
   fout<<strr[i]<<" ";
   i++;
    }
  fout.close();
  feeder(code);

  cout<<"Press any key\n";
  getch();
  int a,b;
  char x,pow;
  int power;
  int operation[10],opi=0;
  ifstream fin;
  fin.open(fname,ios::in);

  int execute(int,int,int);
  int flg=0,k,equalflg=0;
  char d;

  cout<<"\t\tOUTPUT\n";

  while(!fin.eof())
  {
    fin.getline(str,80,' ');
    d=*str;
  //  cout<<str<<" ";
  //  cout<<code[1];
    if(strcmpi(str,code[1])==0)           //print
    { flg=1;

    }


    else if(strcmpi(str,code[3])==0)     //sum
    {
	operation[opi]=3;
	opi++;
    }
    else if(strcmpi(str,code[4])==0)      //difference
    { 	operation[opi]=4;
	opi++;
    }
    else if(strcmpi(str,code[5])==0)      //multiplication
    {
	operation[opi]=5;
	opi++;


    }

    else if(strcmpi(str,code[6])==0)      //division
    {
	operation[opi]=6;
	opi++;
    }
    else if(strcmpi(str,code[7])==0)     //differentiate
    {
       cin>>x>>pow>>power;
       cout<<power<<x<<pow<<power-1;

    }
    else if(strcmpi(str,"end")==0)
    {  break;
    }


    else if(strcmpi(str,code[8])==0)     //integrate
    {   cin>>x>>pow>>power;
	cout<<"(1/"<<power+1<<")"<<x<<pow<<power+1;
    }
    else if(strcmpi(str,"=")==0)
    {
       operation[opi]=3;
       opi++;
       equalflg=1;
    }
    else if(isdigit(*str))
    {   stack[sti]=atoi(str);
	sti++;
       //	flg==1;
    }

    else if(strcmp(str,")")==0)
    {
	int a,b,cd;
	a=stack[sti-2];
	b=stack[sti-1];
	cd=operation[opi-1];
	opi--;
	stack[sti-2]=execute(a,b,cd);
	stack[sti-1]=0;
	sti--;
    //	if(flg==1)
      //	 cout<<stack[0];

	if(equalflg==1)
	 { //cout<<cd<<"\n";
	   var[index].value=stack[sti-1];
	   index++;
	   equalflg=0;

	 }

    }
      else if(isalpha(d))
      {  int f1=0;

	  for( k=0;k<10;k++)
	  {
	   // cout<<" "<<var[k].value<<" ";
	    if((strcmpi(str,var[k].rep)==0)&&(flg==1))
	    {
	    // cout<<"found";
	     cout<<var[k].value;
	    }
	    else if(strcmp(str,var[k].rep)==0)
	     {
	       stack[sti]= var[k].value;
	       f1=1;
	     if(!equalflg==1)
	      {
	       index = k;
	      }
	       sti++;
	       break;
	     }


	  }
	  cout<<endl;


	  if(f1==0)
	  {
	    strcpy(var[index].rep,str);
	     stack[sti]= var[index].value;
	     sti++;


	  }

      }

     else if(flg==1)
    {if(strcmp(str,";")==0)
     {// cout<<endl<<stack[sti-1];

      flg=0;
      sti=0;
     }
     else if(strcmp(str,"\"")==0)
     {
	int strflg=0;
	 while(strflg==0)
	 {
	   fin.getline(str,80,' ');

	   if(strcmp(str,"\"")==0)
	   { strflg=1;
	     break;
	   }
	   cout<<str<<" ";

	 }
     }


    }

  }

  fin.close();

  getch();
  cleardevice();
  menu();
}


int execute(int a,int b,int c)
{
   int r;
   if(c==3)
   { r=a+b;
   }
   else if(c==4)
   { r=a-b;
   }
   else if(c==5)
   { r=a*b;
   }
   else if(c==6)
   { r=a/b;
   }


   return r;
}
