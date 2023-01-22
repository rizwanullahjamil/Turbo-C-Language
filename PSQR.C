#include<dos.h>

int a,n,z[226];

void tm()
{
static int b=0;
struct time ti;
gettime(&ti);
gotoxy(1+(b++)*12,23);
printf("%02d:%02d:%02d.%02d",ti.ti_hour,ti.ti_min,ti.ti_sec,ti.ti_hund);
}

void matprn()
{
int l,m,p,q,r,c;
for(l=m=0,r=1;r<=n;r++)
{
for(p=q=0,c=1;c<=n;c++)
{
p+=z[(r-1)*n+c];
q+=z[(c-1)*n+r];
}
if(p!=a||q!=a)
return;
l+=z[r*n+r-n];
m+=z[r*n-r+1];
}
if(l!=a||m!=a)
return;
for(r=1;r<=n;r++)
for(c=1;c<=n;c++)
{
gotoxy(c*5-4,r+2);
printf("%5d",z[(r-1)*n+c]);
}
tm();
gotoxy(20,25);
printf("Press any key to see next set,  Esc - Exit");
if(bioskey(0)==283)
exit();
gotoxy(20,25);
printf("                                          ");
}

void psqr(int x)
{
int i,j;
for(i=1;i<=n*n;i++)
{
for(j=1;j<x;j++)
if(z[j]==i)
j=x;
if(j>x)
continue;
z[x]=i;
if(x==n*n)
matprn();
psqr(x+1);
}
}

void main()
{
clrscr();
gotoxy(20,24);
printf("Enter any number between 3 to 15 : ");
scanf("%d",&n);
if(n<3||n>15)
exit();
a=(n*n*n+n)/2;
tm();
psqr(1);
}
