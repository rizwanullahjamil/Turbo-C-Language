#include"stdio.h"
#include"dos.h"
main()
{
int a,b;
clrscr();
printf("Enter frequency : ");
scanf("%d",&a);
printf("Enter duration  : ");
scanf("%d",&b);
sound(a);
delay(b);
nosound();
}
