#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
#include<fstream.h>

class diabetes
	 {
	    public:
		    char name[40];
		    float age;
		    int wt;
		    float ht;
		    char sex;
		    char *s;
		    int result;
	    public:
		  void welcome_screen(void);
		  void getvalue(void);
		  void getlevel1_symptoms(void);
		  void getlevel2_symptoms(void);
		  void getlevel3_symptoms(void);
		  int analyse_symptoms(int);
		  char display_message(int,int);
		  void show(void);
	 };

fstream fp;
diabetes dts;

 void write_info()
 {
	fp.open("information.data",ios::out|ios::app);
	fp.write((char*)&dts,sizeof(diabetes));
	fp.close();
 }

 void display_report()
 {
	fp.open("information.data",ios::in);
	while(fp.read((char*)&dts,sizeof(diabetes)));
	{
		dts.show();
	}
	fp.close();
	gotoxy(54,25);
	cputs("PRESS ANY KEY TO QUIT");
	getch();
 }

int main()
	{
	 char ch,choice,cho,r;
	 //int m,n=2;
	 float m;
	 int n=1;
	 void diagnosis(void);
	 dts.welcome_screen();
	 dts.getvalue();
	 diagnosis();
	 dts.getlevel1_symptoms();
	 m=dts.analyse_symptoms(n);
	 choice=dts.display_message(m,n);
	 choice=toupper(choice);
	 if(choice=='Y')
	 {
	  ++n;
	  dts.getlevel2_symptoms();
	  m=dts.analyse_symptoms(n);
	  choice=dts.display_message(n,m);
	  choice=toupper(choice);
	  if(choice=='Y')
	  {
	   ++n;
	   dts.getlevel3_symptoms();
	   m=dts.analyse_symptoms(n);
	   cho=dts.display_message(n,m);
	   cho=toupper(cho);
	   if(cho=='Y')
	   {
	    ++n;
	    dts.getlevel3_symptoms();
	    m=dts.analyse_symptoms(n);
	    choice=dts.display_message(m,n);
	   }
	  }
	 }
	 gotoxy(46,25);
	 cputs("PRESS R TO SEE YOUR REPORT     ");
	 cin>>r;
	 if(r=='R'||r=='r')
	 {
		display_report();
	 }
	 else
		exit(0);
	 return 0;
	}

void diabetes::show(void)
{
	 system("cls");
	 textcolor(WHITE);
	 cout<<"\n";
	 cout<<"\n\t\tN A M E        :"<<name;
	 cout<<"\n\t\tA G E          :"<<age;
	 cout<<"\n\t\tW E I G H T    :"<<wt;
	 cout<<"\n\t\tH E I G H T(cm):"<<ht;
	 cout<<"\n\t\tS E X (M/F)    :"<<sex;
     int i=0;
     textcolor(WHITE);
     cout<<"\n";
     cout<<"\t\tAPPETITE (H(HIGH),/L(LOW),/N(NORMAL):  "<<s[i];
      ++i;
      cout<<endl;
     cout<<"\t\tFREQUENCY OF THIRST(H(HIGH),/L(LOW)/N(NORMAL):  "<<s[i];
      ++i;
      cout<<endl;
     cout<<"\t\tFREQUENCY OF URINATION(H(HIGH),/L(LOW),/N(NORMAL):  "<<s[i];
      ++i;
      cout<<endl;
     cout<<"\t\tVISION (I(IMPAIRMENT),/N(NORMAL):  "<<s[i];
      ++i;
      cout<<endl;
     cout<<"\t\tURINE SUGAR(P(PASSIVE)/A(ACTIVE):  "<<s[i];
      ++i;
      cout<<endl;
     cout<<"\t\tKETONUREA(P(PASSIVE)/A(ACTIVE):  "<<s[i];
      ++i;
      cout<<endl;
     cout<<"\t\tFASTING BLOOD SUGAR(H(HIGH)/L(LOW)/N(NOMAL):  "<<s[i];
      ++i;
      cout<<endl;
     cout<<"\t\tR B S (H(HIGH)/L(LOW)/N(NORMAL):  "<<s[i];
      ++i;
      cout<<endl;
     cout<<"\t\tFAMILY HISTORY OF DIABETES(P(PASSIVE)/A(ACTIVE):  "<<s[i];
      ++i;
      cout<<endl;
     cout<<"\t\tOGTT(D(Done)/N(Not Done)):"<<s[i];
     ++i;
     cout<<endl;
     getch();
}
void diabetes::welcome_screen()
	 {
	   system("cls");
	   gotoxy(25,7);
	   textcolor(YELLOW);
	   cputs("********* W E L C O M E ********* " );
	   gotoxy(20,9);
	   cputs(" DEPARTMENT OF COMPUTER SCIENCE AND APPLICATIONS "  );
	   gotoxy(18,12);
	   cputs(" M E D I C A L   D I A G N O S I S   S O F T W A R E  ");
	   textcolor(GREEN);
	   for(int x=50;x>=30;x--)
	   {
	    delay(60);
	    gotoxy(x,14);
	    cputs("M A D E  B Y  : ");
	    gotoxy(x,16);
	    cputs("Smriti Bansal ");
	    gotoxy(43,18);

	   }
	   gotoxy(20,25);
	   cputs("******** PRESS ANY KEY TO CONTINUE ********* ");
	   getch();
	   return;
	}


	void diabetes::getvalue()
	{
	 system("cls");
	 textcolor(WHITE);
	 gotoxy(20,8);
	 cputs(" P E R S O N A L   I N F O R M A T I O N");
	 gotoxy(25,10);
	 cputs("N A M E        :");
	 gotoxy(25,12);
	 cputs("A G E          :");
	 gotoxy(25,14);
	 cputs("W E I G H T    :");
	 gotoxy(25,16);
	 cputs("H E I G H T(cm):");
	 gotoxy(25,18);
	 cputs("S E X (M/F)    :");
	 textcolor(GREEN);
	 gotoxy(42,10);
	 gets(name);
	 gotoxy(42,12);
	 cin>>age;
	 fflush(stdin);
	 gotoxy(42,14);
	 cin>>wt;
	 gotoxy(42,16);
	 cin>>ht;
	 gotoxy(42,18);
	 cin>>sex;
	 getch();
	 return;
	}


void diagnosis(void)
     {
     system("cls");
     textcolor(WHITE);
     gotoxy(20,5);
     cputs(" **  D I A G N O S I S   W I N D O W **   ");
     cout<<"\n\n\n";
     cputs(" Let's have alook at  symptoms.........");
     cout<<"\n\n\n";
     cputs(" Please enter the form in next page .");
     cout<<"\n\n\n\n\n\n\t\t\t ";
     textcolor(YELLOW);
     cputs("***** PRESS ANY KEY ***** ");
     getch();
     }

void diabetes::getlevel1_symptoms(void)
    {
     system("cls");
     int i=0;
     gotoxy(23,3);
     textcolor(WHITE);
     cputs( " *** MEDICAL DIAGONOSIS FORM *** ");
     gotoxy( 3,6);
     cputs("APPETITE (H(HIGH),/L(LOW),/N(NORMAL):") ;
     gotoxy(64,6);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
     gotoxy(3,8);
     cputs("FREQUENCY OF THIRST(H(HIGH),/L(LOW)/N(NORMAL):");
     gotoxy(64,8);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
     gotoxy(3,10);
     cputs("FREQUENCY OF URINATION(H(HIGH),/L(LOW),/N(NORMAL):");
     gotoxy(64,10);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
     gotoxy(3,12);
     cputs("VISION (I(IMPAIRMENT),/N(NORMAL):");
     gotoxy(64,12);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
     gotoxy(3,14);
     cputs("URINE SUGAR(P(PASSIVE)/A(ACTIVE):");
     gotoxy(64,14);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
     gotoxy(3,16);
     cputs("KETONUREA(P(PASSIVE)/A(ACTIVE):");
     gotoxy(64,16);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
     gotoxy(3,18);
     cputs("FASTING BLOOD SUGAR(H(HIGH)/L(LOW)/N(NOMAL):");
     gotoxy(64,18);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
     gotoxy(3,20);
     cputs("R B S (H(HIGH)/L(LOW)/N(NORMAL):");
     gotoxy(64,20);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
     gotoxy(3,22);
     cputs("FAMILY HISTORY OF DIABETES(P(PASSIVE)/A(ACTIVE):");
     gotoxy(64,22);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
     gotoxy(3,24);
     cputs("OGTT(D(Done)/N(Not Done)):");
     gotoxy(64,24);
     cin>>s[i];
     s[i]=toupper(s[i]);
     ++i;
    }

int diabetes::analyse_symptoms(int n)

    {
      int i=0;
      int count=0;
      int result=0;
      switch(n)
	{
	 case 1:    if(s[9]=='D' )
			result=-1;
		    else if(s[5]=='P'&& s[6]=='H' && s[7]=='H')
			  result=-1;
		    else
			  {
			    for(i=0;i<10;i++)
			    {
			      if(s[i]=='H'||s[i]=='P'||s[i]=='D'||s[i]=='I')
				count++;
			     }
			     if(count>5)
				result=-1;
			     else
			     {
				system("cls");
				gotoxy(10,10);
				cout<<"PLEASE GET THE OGTT TEST DONE!";
				sleep(2);
				exit(0);
			     }
			  }
		       break;

	 case 2: if((s[0]=='P')||(s[1]=='P')||(s[2]=='P')||(s[3]=='H')||(s[4]=='P')||(s[5]=='P')||(s[6]=='P'))
		     result=-1;
		 else
		     result=0;
		     break;
	 case 3: if((s[0]=='Y')&&(s[1]=='N')&&(s[2]=='W')&&(s[3]=='P')&&(s[4]=='P')||

	 (s[0]=='Y')&&(s[1]=='B')&&(s[2]=='W')&&(s[3]=='P')&&(s[4]=='P')||

	 (s[0]=='Y')&&(s[1]=='N')&&(s[2]=='M')&&(s[3]=='P')&&(s[4]=='P')||

	 (s[0]=='Y')&&(s[1]=='N')&&(s[2]=='Y')&&(s[3]=='P')&&(s[4]=='P'))
		  result=0;
		else
		   result=-1;
		 break;
	 default:break;
	}
       return(result);
      }

char diabetes::display_message(int n,int m)

      {
       char ch;
       system("cls");
       switch(n)
	 {
	  case 1:
		  switch(m);
		      {
		       case 0: gotoxy(20,12);
			       cputs("THE PERSON IS NOT DIABETIC");
			       gotoxy(50,20);
			       cputs("PRESS ANY KEY TO QUIT." );
			      // gotoxy(70,20);
			       //cin>>ch;
			       //break;
			       exit(0);

		       case -1:

			       gotoxy(10,10);
			       cputs("THE PERSON IS DIABETIC! ");
			       gotoxy(54,20);
			       cputs("\nPROCEED (Y/N)  ?");
			       gotoxy(72,21);
			       cin>>ch;
			       break;

		     //  default: break;
		      }





		case 2:
			switch(m)
			{
			   case 0: gotoxy(20,12);
				   cputs("THE PERSON IS SUFFERING FROM PRIMARY DIABETES.");
				   gotoxy(50,25);
				   cputs("\nProceed(Y/N)?");
				   gotoxy(70,25);
				   cin>>ch;
				   break;

			   case -1: gotoxy(20,12);
				   cputs("THE PERSON IS SUFFERING FROM SECONDARY DIABETES");
				   sleep(5);
				   break;

				   }
			break;

		case 3:switch(m)
		 {
			   case 0: gotoxy(30,12);
				cputs("INSULIN DEPENDENT DIABETES IS DIAGNOSED");
				sleep(5);
				break;


			   case -1: gotoxy(30,12);
			       cputs("NON INSULIN DEPENDENT DIABETES IS DIAGNOSED");
			       sleep(5);
			       break;

		      //	   default: break;

		 }

	      // break ;
	       //	default : break;
	       }
	       return (ch);
	     }



void diabetes::getlevel2_symptoms()
	       {
		system("cls");
		int j=0;
		  gotoxy(20,8);
		  cputs("PANCREATITIS(P(Present)/A(Absent))  :");
		  gotoxy(60,8);
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  j++;
		  gotoxy(20,10);
		  cputs("CARCINOMA(P(Present)/A(Absent))     :");
		  gotoxy(60,10);
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		  gotoxy(20,12);
		  cputs("CIRHHOSIS(P(Present)/A(Absent))     :");
		  gotoxy(60,12);
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		  gotoxy(20,14);
		  cputs("HCTS (H(High)/L(Low)/N(Normal))     :");
		  gotoxy(60,14);
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		  gotoxy(20,16);
		  cputs("HEPATITIS(P(Presnt)/A(Absent))     :");
		  gotoxy(60,16);
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		  gotoxy(19,18);
		  cputs(" HORMONAL DISORDER(P(Presnt)/A(Absent)):");

		  gotoxy(60,18);
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		  gotoxy(19,20);
		  cputs(" PANCREATECTOMY(P(Presnt)/A(Absent)):");
		  gotoxy(60,20);
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		  return;
	      }

void diabetes::getlevel3_symptoms()
	     {
		 int k=0;
		 system("cls");
		 gotoxy(10,8);
		 cputs(" AGE(young(Y)/Middle aged(M)/Elderly(E))");
		 gotoxy(73,8);
		 cin>>s[k];
		 s[k]= toupper (s[k]);
		 ++k;
		 gotoxy(10,12);
		 cputs("BODY WEIGHT(normal(N)/Above normal(A)/Below normal(B)/obese(O))");
		 gotoxy(73,12);
		 cin>>s[k];
		 s[k]= toupper(s[k]);
		 ++k;
		 gotoxy(10,16);
		 cputs(" DURATION (weeks(W)/Months(M)/Years(Y))");
		 gotoxy(73,16);
		 cin>>s[k];
		 s[k]= toupper(s[k]);
		 ++k;

		gotoxy(10,20);
		 cputs("KETONUREA(P(Passive)/A(Active))");
		 gotoxy(73,20);
		 cin>>s[k];
		 s[k]= toupper(s[k]);
		 ++k;
		 gotoxy(10,24);
		 cputs("AUTO ANTIBODIES(P(Passive)/A(Active))");
		 gotoxy(73,24);
		 cin>>s[k];
		 s[k]= toupper(s[k]);
		 ++k;
		 return;
	}
