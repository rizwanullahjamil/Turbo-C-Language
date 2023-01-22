/************ THIS PROGRAMME CAN PRINT NAME ,ADDRESS  AND PHONE NO *******/
/************ PROGRAMMED BY  ALI KHAN **************************************/
/************ PROGRAMME NAME  TEL ******************************************/
/************ PROGRAMME DATE  16-01-1990 ***********************************/
# define TRUE 1
# include<stdio.h>
# include<string.h>
# include <conio.h>
FILE *fp;
/******************* MAIN ()*************************/
struct A
{
    char name[30];
    char adrs1[20];
    char adrs2[20];
    char phone[10];
    char cntry[12];
}   text;
char path[10],ch,mode[1],*mptr;
main()
{
      void main_menu(void);
      void screen(void);
      void submnu_one(void);
      void submnu_two(void);
      void submnu_tre(void);
      void data_lookup(void);
      void add_new_rec(void);
      void ask_menu(char *);
      main_menu();
  }
  /******************** DISPLAY MAIN MENU ***************/
  void main_menu()
  {
      void ask_menu(char *);
      char ch;
      int a,b;
	      clrscr();
	      textcolor(4);
	      a=19;
	      while(a<=65)
	      {
	      textcolor(1);gotoxy(a,4);
	      cprintf("%c",219);
	      textcolor(1);gotoxy(a,18);
	      cprintf("%c",219);
	      a++;
	      }
	      b=5;
	      while(b<=17)
	      {
	      textcolor(1);gotoxy(65,b);
	      cprintf("%c",219);
	      textcolor(1);gotoxy(19,b);
	      cprintf("%c",219);
	      b++;
	      }
	      gotoxy(35,5);textcolor(1);cprintf("MAIN MENU");
	      gotoxy(25,7);textcolor(1);cprintf("1. Data Entry functions");
	      gotoxy(25,9);textcolor(1);cprintf("2. Queries & Reports");
	      gotoxy(25,11);textcolor(1);cprintf("3. System Maintenance functions");
	      gotoxy(25,13);textcolor(1);cprintf("4. Exit to Dos");
	      gotoxy(25,15);textcolor(5);cprintf("Enter Selection :- (1-4)");gotoxy(54,15);ask_menu(&ch);
	      gotoxy(25,22);textcolor(4);cprintf("Programmed By  Ali Khan");
	      switch(ch)
	 {
	 case '1':
		   submnu_one();
		   break;
	 case '2':
		   submnu_two();
		   break;
	 case '3':
		   submnu_tre();
		   break;
	 case '4':
		  close(fp);
		  exit();
	 }
   }
  /* ********************** ASK MENU ********************** */
void ask_menu(char *ch)
{
  *ch = 'u';
  while(!(strchr("1234",*ch)))
  *ch = getch();
  return;
  }
  /************************ SUBMENU ************************/          											/* *** ALI KHAN *** */
  void submnu_one()
  {
	 char ch;
	 while(1)
	 {
		    int a,b;
		 clrscr();
		 textcolor(4);
		 a=19;
		 while(a<=65)
		 {
		 textcolor(2);gotoxy(a,4);
		 cprintf("%c",219);
		 textcolor(2);gotoxy(a,18);
		 cprintf("%c",219);
		 a++;
		 }
		 b=5;
		 while(b<=17)
		 {
		 textcolor(2);gotoxy(65,b);
		 cprintf("%c",219);
		 textcolor(2);gotoxy(19,b);
		 cprintf("%c",219);
		 b++;
		 }
		 gotoxy(25,6);textcolor(4);cprintf("DATA ENTRY FUNCTIONS");
		 gotoxy(25,8);textcolor(4);cprintf("1. Add New Records");
		 gotoxy(25,10);textcolor(4);cprintf("2. Update");
		 gotoxy(25,12);textcolor(4);cprintf("3. Delete/Undelete ");
		 gotoxy(25,14);textcolor(4);cprintf("4. Return to Main Menu");
		 gotoxy(25,16);textcolor(7);cprintf("Enter Selection :- (1-4)");gotoxy(54,16);ask_menu(&ch);
		 gotoxy(25,22);textcolor(4);cprintf("Programmed By Ali Khan");
		 switch(ch)
	 {
	 case '1':
		strcpy(mode,"w");
		add_new_rec();
		break;
	case '2':
		submnu_two();
		break;
	case '3':
		submnu_tre();
		break;
       case '4':
		main_menu();
	 }
 }
 }

 /************************ SUBMNU-TWO() ************************/

 void submnu_two()
 {
       int a,b;
       void ask_menu(char *);
       void data_lookup(void);
       char ch;
       while(1)
       {
	    clrscr();
       textcolor(4);
       a=19;
       while(a<=65)
       {
       gotoxy(a,4);
       textcolor(3);cprintf("%c",219);
       gotoxy(a,18);
       textcolor(3);cprintf("%c",219);
       a++;
       }
       b=5;
       while(b<=17)
       {
       gotoxy(65,b);
       textcolor(3);cprintf("%c",219);
       gotoxy(19,b);
       textcolor(3);cprintf("%c",219);
       b++;
       }
	    gotoxy(25,7);textcolor(9);cprintf("QUERIES & REPORTS");
	    gotoxy(25,9);textcolor(9);cprintf("1. Data lookup");
	    gotoxy(25,11);textcolor(9);cprintf("2. Print Report");
	    gotoxy(25,13);textcolor(9);cprintf("3. Mailing list");
	    gotoxy(25,15);textcolor(9);cprintf("4. Return to Main Menu");
	    gotoxy(25,17);textcolor(12);cprintf("Enter Selection :- (1-4)");gotoxy(54,17);ask_menu(&ch);
	    gotoxy(25,22);textcolor(4);cprintf("Programmed By Ali Khan");
	    switch(ch)
    {
    case '1':
	     data_lookup();
	     fclose(fp);
	     break;
    case '2':
	     submnu_two();
	     break;
    case '3':
	     submnu_tre();
	     break;
    case '4':
	     main_menu();
	     }
   }
   }

   /*************************************************/
   void add_new_rec(void)
   {
	     void screen(void);
	     int true=1;
	     clrscr();
	     gotoxy(40,8);textcolor(3);cprintf("Enter file name ?");
	     gotoxy(40,10);textcolor(1);gets(path);
	     if((fp =fopen(path,mptr))==NULL)
	     {
		     gotoxy(40,14);perror(" The error is");
		     gotoxy(50,16);getch();
    }
	while(true)
	{
	       clrscr();
	       textcolor(4);cprintf("INPUT RECORD SECTION \n");
	       textcolor(4);cprintf("---------------------\n");
	       screen();
	       textcolor(4);
	       gotoxy(40,8);gets(text.name);
	       gotoxy(40,9);gets(text.adrs1);
	       gotoxy(40,10);gets(text.adrs2);
	       gotoxy(40,11);gets(text.phone);
	       gotoxy(40,12);gets(text.cntry);
	       gotoxy(25,22);textcolor(4);cprintf("Programmed By Ali Khan");
	       fputs(text.name,fp);
	       fputs(text.adrs1,fp);
	       fputs(text.adrs2,fp);
	       fputs(text.phone,fp);
	       fputs(text.cntry,fp);
	       gotoxy(34,24);
	       textcolor(13);cprintf("	INPUT ANY MORE RECORDS (Y/N)  ?  ");
	       if(toupper(ch=getche()) == 'Y')
		 true = 1;
	       else
		 true = 0;
    }
    fclose(fp);
}
/***************************** DATA-LOOKUP () FUNCTION ****************/
void data_lookup()
{
	void screen(void);
	clrscr();
	gotoxy(32,12);textcolor(4);cprintf("Enter file Name   ? ");
	gotoxy(55,12);gets(path);
	if((fp = fopen(path,"r")) == NULL)
		gotoxy(40,16);textcolor(6);perror("The Error Is  ");
	clrscr();
  textcolor(9);cprintf("                    DATA LOOKUP SECTION \n");
  textcolor(9);cprintf("                    ------------------- \n");
  screen();
/* do         */
  {
  fgets(text.name,30,fp);
  fgets(text.adrs1,20,fp);
  fgets(text.adrs2,20,fp);
  fgets(text.phone,10,fp);
  fgets(text.cntry,12,fp);
		 gotoxy(40,8);textcolor(1);cprintf(text.name);
		 gotoxy(40,9);textcolor(1);cprintf(text.adrs1);
		 gotoxy(40,10);textcolor(1);cprintf(text.adrs2);
		 gotoxy(40,11);textcolor(1);cprintf(text.phone);
		 gotoxy(40,12);textcolor(1);cprintf(text.cntry);
		 gotoxy(24,24);textcolor(1);cprintf("Press any key to continue . . . . ");
		 ch = getch();
		 }
/*		 while(!feof(fp));                */
}
/******************* SYSTEM MAINTENANCE ******************/
void submnu_tre()
{
       char ch,cd[15],fname[8],newname[8];
       while(1)
       {
       clrscr();
       gotoxy(25,7);textcolor(11);cprintf(" SYSTEM MAINTENANCE FUNCTIONS ");
       gotoxy(25,9);textcolor(11);cprintf("1. Rename a file(s)");
       gotoxy(25,11);textcolor(11);cprintf("2. Remove a file(s)");
       gotoxy(25,13);textcolor(11);cprintf("3. Change directory");
       gotoxy(25,15);textcolor(11);cprintf("4. Return to Main Menu");
       gotoxy(25,17);textcolor(9);cprintf("Enter Selection (1-4)");gotoxy(54,17);ask_menu(&ch);
       switch(ch)
       {
       case '1':
		clrscr();
		gotoxy(30,10);textcolor(3);cprintf("Enter old file name ?");
		gotoxy(52,10);gets(fname);
		gotoxy(30,12);textcolor(3);cprintf("Enter new file name ?");
		gotoxy(52,12);gets(newname);
		rename(fname,newname);
		break;
       case '2':
	       clrscr();
	       gotoxy(30,10);textcolor(4);cprintf("Enter file name ?");
	       gotoxy(50,10);gets(fname);
	       remove(fname);
	       break;
      case '3':
	      clrscr();
	      gotoxy(30,10);textcolor(5);cprintf("Enter Drive Name A,B or C");
	      gotoxy(55,10);gets(cd);
	      chdir(cd);
	      break;
      case '4':
	       main_menu();
	       }

     }
     }
     void screen(void)
     {
     gotoxy(25,8);textcolor(14);cprintf(" NAME        :");
     gotoxy(25,9);textcolor(14);cprintf("ADDRESS      :");
     gotoxy(25,10);textcolor(14);cprintf("ADDRESS     :");
     gotoxy(25,11);textcolor(14);cprintf("PHONE.NO     :");
     gotoxy(25,12);textcolor(14);cprintf("COUNTRY       :");
     }
