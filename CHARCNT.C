#include<stdio.h>
#include<ctype.h>

main()
{
char fn[25];
int ch,c[27];
FILE *fi;
clrscr();
printf("Enter File Name : ");
gets(fn);
if((fi=fopen(fn,"rb"))==NULL)
{
perror("Can't open input file ");
exit();
}
for(ch=0;ch<27;ch++)
c[ch]=0;
while((ch=getc(fi))!=EOF)
if(isalpha(ch))
c[toupper(ch)-64]++;
else
c[0]++;
for(ch=1;ch<27;ch++)
printf("%c = %4d\t",ch+64,c[ch]);
printf("Other = %d",c[0]);
}
