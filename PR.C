#include<stdio.h>

main(int argc,char *argv[])
{
FILE *ip,*op;
int l=0;
char c,in[20]={"vtdata.dta"},ot[20]={"prn"};
if(argc>1)
strcpy(in,argv[1]);
if(argc>2)
strcpy(ot,argv[2]);
else
strcpy(ot,"PRN");
if((ip=fopen(in,"rb"))!=NULL&&(op=fopen(ot,"wt"))!=NULL)
{
while((c=getc(ip))!=26)
{
putch(c);
if(c==13)
{
getc(ip);
putch('\012');
putc('\n',op);
l+=1;
if(l>61)
{
l=0;
putc('\014',op);
}
}
else
putc(c,op);
}
}
if(ip==NULL)
printf("Input File not found ! Read Error Fault !");
if(op==NULL)
printf("Output File not created ! Write Error Fault !");
if(l)
putc('\014',op);
}
