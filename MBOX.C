main(int i,char * v[])
{
int l=atoi(v[1]),t=atoi(v[2]),r=atoi(v[3]),b=atoi(v[4]),sd=atoi(v[5]),
    wn[4000],a,c,x,y,z=0;
gettext(1,1,80,25,wn);
x=wherex();
y=wherey();
clrscr();
if(i<6)
{
gotoxy(1,25);
printf("Enter Left Top Right Bottom SingleDouble 0/1 ? ");
i=scanf("%d %d %d %d %d",&l,&t,&r,&b,&sd)+1;
clrscr();
}
if(i!=6||l<1||r>80||t<1||b>25||l>r||t>b||(l==r&&t==b))
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
do
{
gotoxy(1,25);
cprintf("%02d %02d %02d %02d  ",l,t,r,b);
cprintf("Tab : %st Corner ",z?" Upper Lef":"Lower Righ");
c=(c=bioskey(0))&255?c&255:((c&65280)>>8)+256;
switch(c)
{
case 328: /* up */
if(z)
{
if(t>1)
{
gotoxy(l,t);
cprintf("%-*c%c",r-l,179+sd*7,179+sd*7);
t--;
gotoxy(l,t);
cprintf("%c",218-sd*17);
for(a=l+1;a<r;a++)
cprintf("%c",196+sd*9);
cprintf("%c",191-sd*4);
}
}
else
{
if(b>t+1)
{
gotoxy(l,b);
cprintf("%*c ",r-l,32);
b--;
gotoxy(l,b);
cprintf("%c",192+sd*8);
for(a=l+1;a<r;a++)
cprintf("%c",196+sd*9);
cprintf("%c",217-sd*29);
}
}
break;
case 336: /* dn */
if(z)
{
if(t<b-1)
{
gotoxy(l,t);
cprintf("%*c ",r-l,32);
t++;
gotoxy(l,t);
cprintf("%c",218-sd*17);
for(a=l+1;a<r;a++)
cprintf("%c",196+sd*9);
cprintf("%c",191-sd*4);
}
}
else
{
if(b<24)
{
gotoxy(l,b);
cprintf("%-*c%c",r-l,179+sd*7,179+sd*7);
b++;
gotoxy(l,b);
cprintf("%c",192+sd*8);
for(a=l+1;a<r;a++)
cprintf("%c",196+sd*9);
cprintf("%c",217-sd*29);
}
}
break;
case 331: /* lt */
if(z)
{
if(l>1)
{
l--;
gotoxy(l,t);
cprintf("%c%c",218-sd*17,196+sd*9);
for(a=t+1;a<b;a++)
{
gotoxy(l,a);
cprintf("%c ",179+sd*7);
}
gotoxy(l,b);
cprintf("%c%c",192+sd*8,196+sd*9);
}
}
else
{
if(r>l+1)
{
r--;
gotoxy(r,t);
cprintf("%c ",191-sd*4);
for(a=t+1;a<b;a++)
{
gotoxy(r,a);
cprintf("%c ",179+sd*7);
}
gotoxy(r,b);
cprintf("%c ",217-sd*29);
}
}
break;
case 333: /* rt */
if(z)
{
if(l<r-1)
{
l++;
gotoxy(l-1,t);
cprintf(" %c",218-sd*17);
for(a=t+1;a<b;a++)
{
gotoxy(l-1,a);
cprintf(" %c",179+sd*7);
}
gotoxy(l-1,b);
cprintf(" %c",192+sd*8);
}
}
else
{
if(r<80)
{
r++;
gotoxy(r-1,t);
cprintf("%c%c",196+sd*9,191-sd*4);
for(a=t+1;a<b;a++)
{
gotoxy(r-1,a);
cprintf(" %c",179+sd*7);
}
gotoxy(r-1,b);
cprintf("%c%c",196+sd*9,217-sd*29);
}
}
break;
case 9:   /* tab */
z=1-z;
}
}
while(c!=27);
puttext(1,1,80,25,wn);
gotoxy(x,y);
}
