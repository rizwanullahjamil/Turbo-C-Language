#include<stdio.h>
#include<ctype.h>

main()
{
int c,inspace=0;
while((c=getchar())!=-1)
{
if(c==' '||c=='\n'||c=='\t')
{
if(!inspace)
{
c='\n';
putchar(c);
inspace=1;
}
else
continue;
}
else
{
inspace=0;
if(isalpha(c))
putchar(c);
}
}
}
