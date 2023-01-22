#include<dos.h>

main()
{
struct time ti;
long h,m,s,t,u;
clrscr();
while(!kbhit())
{
gettime(&ti);
t=ti.ti_hour*3600L+ti.ti_min*60L+ti.ti_sec;
u=(t+(double)ti.ti_hund/100L)/.864;
h=u/10000L;
m=(u-h*10000L)/100L;
s=u-h*10000L-m*100L;
gotoxy(10,10);
printf("%05ld - %02d:%02d:%02d.%02d",t,ti.ti_hour,ti.ti_min,ti.ti_sec,ti.ti_hund);
gotoxy(10,12);
printf("%05ld - %02ld:%02ld:%02ld",u,h,m,s);
}
}
