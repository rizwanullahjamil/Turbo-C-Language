#include"stdio.h"
#include"graphics.h"
main()
{
   char sign;
   int no1,no2;
   float ans;
   clrscr();
   printf("\t\tCalculator\n");
   printf("\t\t----------");
   gotoxy(10,5);
   printf("Enter your expression as n1 opr n2");
   gotoxy(10,6);
   scanf("%d %c %d",&no1,&sign,&no2);
   printf("\n %d %c %d\n",no1,sign,no2);
   if(sign!='+' && sign!='-' && sign!='*' && sign!='/' && sign!='%')
   {
   printf("\t\tUnrecognised calculations");
   exit();
   }
   switch(sign)
   {
       case '+':
       ans=(float)(no1+no2);
       break;
       case '-':
       ans=(float)(no1-no2);
       break;
       case '*':
       ans=(float)(no1*no2);
       break;
       case '/':
       ans=(float)(no1/no2);
       break;
       case '%':
       ans=(float)(no1%no2);
   }
   gotoxy(10,7);
   printf("%2d %c %2d = %.2f",no1,sign,no2,ans);
}
