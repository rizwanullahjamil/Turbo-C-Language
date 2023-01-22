#include<stdio.h>
#include<conio.h>

#define MX 60

main(int c,char *v[])
{
unsigned char f[60];
int ch;
unsigned x,y,z=1;
FILE *fp;
clrscr();
if(c>1)
strcpy(f,v[1]);
else
{
cprintf("Enter any data file name [filename.ext] ");
gets(f);
}
gotoxy(1,1);
if((fp=fopen(f,"r"))==NULL)
{
cputs(f);
perror(" : Can't open a file becaues ");
exit();
}
gotoxy(1,2);
while((ch=getc(fp))>-1)
{
x=wherex();
y=wherey();
textattr(96);
if(x<2&&(y<3||y>24))
{
gotoxy(1,1);
cprintf("          %-60sX%02d Y%04d ",f,x,z);
}
else
{
gotoxy(72,1);
cprintf("%02d Y%04d",x,z);
}
textattr(7);
gotoxy(x,y);
putchar(ch);
if(ch=='\n')
z++;
}
}
