#include<stdio.h>
main()
{
   int a,b,c,d,e,f,g,h;
   clrscr();
   printf("\t\tExamination Score\n");
   printf("\t\t-----------------\n");
   printf("\nEnter R.No.\t = ");
   scanf("%d",&a);
   printf("\n Physics   \t = ");
   scanf("%d",&b);
   printf("\n Chemistry \t = ");
   scanf("%d",&c);
   printf("\n Maths     \t = ");
   scanf("%d",&d);
   printf("\n Biology   \t = ");
   scanf("%d",&e);
   printf("\n Practical \t = ");
   scanf("%d",&f);
   g=b+c+d+e+f;
   h=g/5;
   printf("\n %d has scored \n",a);
   printf(" Total Nos = %d",g);
   printf("\n Out of 500");
   printf("\n Percentage is %d %",h);
}
