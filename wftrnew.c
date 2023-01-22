#include<stdio.h>
#include<ctype.h>

void main(int c,char *v[])
{
int ch,inspace=0;
unsigned char fr[60],fw[60];
FILE *fi,*fo;
clrscr();
if(c>1)
strcpy(fr, v[1]);
else
{
cprintf("Enter any data file name [filename.ext] ");
gets(fr);
}
if((fi=fopen(fr,"r"))==NULL)
{
cputs(fr);
perror(" : Can't open a file for read because ");
exit();
}
for(ch=0;ch<60;ch++)
if(fr[ch]=='.')
break;
else
fw[ch]=fr[ch];
fw[ch]='\0';
strncat(fw,".obj",4);
if((fo=fopen(fw,"w"))==NULL)
{
cputs(fw);
perror(" : Can't open a file for write because ");
exit();
}
while((ch=getc(fi))>-1)
{
if(ch==' '||ch=='\n'||ch=='\t')
{
if(!inspace)
{
ch='\n';
putc(ch,fo);
inspace=1;
}
else
continue;
}
else
{
inspace=0;
if(isalpha(ch))
putc(ch,fo);
}
}
}
