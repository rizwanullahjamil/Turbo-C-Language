main()
{
int a=79,b=0,c=0,i,j;
char z[57]={"Welcome To The Wonderful World Of Micro Computer Science "};
clrscr();
for(i=0;i<135;i++)
{
gotoxy(a,12);
for(j=b;j<=c;j++)
printf("%c",z[j]);
for(j=0;j<32767;j++);
if(a>2)
a--;
else
b++;
if(c<56)
c++;
}
}
