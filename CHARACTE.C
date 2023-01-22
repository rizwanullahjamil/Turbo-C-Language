# include<stdio.h>
# include<graphics.h>
main()
{
char a[20],b[30],c[1];
puts("\nEnter Your Name ");
gets(a);
puts("\nEnter Your Address ");
gets(b);
puts("Is that correct (Y / N) ");
gets(c);
clrscr();
printf("\n\n\t Mr.%s Address %s corrected %c",a,b,c);
}
