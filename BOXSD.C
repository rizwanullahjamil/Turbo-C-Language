main()
{
int a,l,t,r,b,sd,wn[4000],x,y;
gettext(1,1,80,25,wn);
x=wherex();
y=wherey();
clrscr();
while(1)
{
gotoxy(1,24);
printf("Enter Left,Top,Right,Bottom,SingleDouble 0/1 ? ");
scanf("%d,%d,%d,%d,%d",&l,&t,&r,&b,&sd);
if(l<1||r>80||t<1||b>25||l>r||t>b||(l==r&&t==b))
{
puttext(1,1,80,25,wn);
gotoxy(x,y);
exit();
}
if(l==r)
{
for(a=t;a<=b;a++)
{
gotoxy(l,a);
cprintf("%c",179+sd*7);
}
}
else
if(t==b)
{
for(a=l;a<=r;a++)
{
gotoxy(a,t);
cprintf("%c",196+sd*9);
}
}
else
{
gotoxy(l,t);
cprintf("%c",218-sd*17);
gotoxy(l,b);
cprintf("%c",192+sd*8);
for(a=l+1;a<r;a++)
{
gotoxy(a,t);
cprintf("%c",196+sd*9);
gotoxy(a,b);
cprintf("%c",196+sd*9);
}
gotoxy(r,t);
cprintf("%c",191-sd*4);
gotoxy(r,b);
cprintf("%c",217-sd*29);
for(a=t+1;a<b;a++)
{
gotoxy(l,a);
cprintf("%c",179+sd*7);
gotoxy(r,a);
cprintf("%c",179+sd*7);
}
}
}
}
