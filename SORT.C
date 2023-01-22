# include"stdio.h"
# include"graphics.h"
main()
{
   char name[100];
/*
={'r','i','z','w','a','n',' ','u','l','l','a','h',' ','j','a','m','i','l'};
*/
   char ch;
   int i,j,k;
   clrscr();
   gotoxy(1,10);
   printf("Enter your name in block leters ");
   for(i=0;i<101;i++)
   {
       name[i]=getche();
   if(name[i]==13)
   break;
   }
   perror("The error is ");
   k=strlen(name);
   gotoxy(30,12);
   puts(name);
   for(i=0;i<k;i++)
   {
       for(j=i+1;j<k;j++)
       {
	   if(toupper(name[i])>toupper(name[j]))
	   {
	       ch=name[i];
	       name[i]=name[j];
	       name[j]=ch;
	   }
       }
   }
   gotoxy(10,13);
   puts(name);
   gotoxy(10,14);
   for(i=k;i>=0;i--)
   printf("%c",name[i]);
}
