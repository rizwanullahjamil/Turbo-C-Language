#include<stdio.h>
main()
{
   int a,b,c,d,e,i;
   clrscr();
   printf("\n\n\tEnter min table value\t");
   scanf("%d",&a);
   printf("\n\n\tEnter max table value\t");
   scanf("%d",&b);
   for(c=a;c<=b;c++)
   {
   clrscr();
   for(d=1;d<11;d++)
   {
       e=c*d;
       printf("\n\t%d * %d = %d",c,d,e);
   }
   for(i=1;i<30000;i++);
   }
}
