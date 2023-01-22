chr(x,y,c)
{
gotoxy(x,y);
printf("%c",c);
}

main(int c,char *v[])
{
int a,l=atoi(v[1]),t=atoi(v[2]),r=atoi(v[3]),b=atoi(v[4]),sd=atoi(v[5])%4;
if(c<2)
{
gotoxy(1,23);
printf("Enter Left Top Right Bottom Status ");
c=scanf("%d %d %d %d %d",&l,&t,&r,&b,&sd)+1;
}
if(c!=6||l<1||r>80||l>r||t<1||b>25||t>b)
printf("\tUsage is : BOX [Left Top Right Bottom Status]\n");
else
{
if(l==r)
for(a=t;a<=b;a++)
chr(l,a,(sd<2)?179+sd*7:219+sd);
else
if(t==b)
for(a=l;a<=r;a++)
chr(a,t,(sd<2)?196+sd*9:214+sd*3);
else
{
chr(l,t,(sd<2)?218-sd*17:216+sd*2);
chr(l,b,(sd<2)?192+sd*8:225-sd);
for(a=l+1;a<r;a++)
{
chr(a,t,(sd<2)?196+sd*9:214+sd*3);
chr(a,b,(sd<2)?196+sd*9:229-sd*3);
}
chr(r,t,(sd<2)?191-sd*4:218+sd);
chr(r,b,(sd<2)?217-sd*29:227-sd*2);
for(a=t+1;a<b;a++)
{
chr(l,a,(sd<2)?179+sd*7:219+sd);
chr(r,a,(sd<2)?179+sd*7:224-sd);
}
}
}
chr(1,23,13);
}
