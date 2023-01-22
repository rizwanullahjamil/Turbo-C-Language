#include<dos.h>

char *cdow(struct date dt)
{
int p,q=dt.da_year-1,r[12]={0,3,3,6,1,4,6,2,5,0,3,5};
p=dt.da_day+r[dt.da_mon-1]+q*1.25-q/100+q/400-q/4000;
if(dt.da_mon>2&&q==(q/4)*4&&(q%100||q==(q/400)*400)&&q%4000)
p++;
switch(p%7)
{
case 1:
return "Monday";
case 2:
return "Tuesday";
case 3:
return "Wednesday";
case 4:
return "Thursday";
case 5:
return "Friday";
case 6:
return "Saturday";
default:
return "Sunday";
}
}

char *cmon(struct date dt)
{
switch(dt.da_mon)
{
case 1:
return "January";
case 2:
return "February";
case 3:
return "March";
case 4:
return "April";
case 5:
return "May";
case 6:
return "June";
case 7:
return "July";
case 8:
return "August";
case 9:
return "September";
case 10:
return "October";
case 11:
return "November";
default:
return "December";
}
}

void main(int c,char *v[])
{
char s[3]={"th"};
struct time ti;
struct date da;
clrscr();
if(c==4)
{
da.da_day=atoi(v[1]);
da.da_mon=atoi(v[2]);
da.da_year=atoi(v[3]);
}
else
getdate(&da);
if(da.da_day==1||da.da_day==21||da.da_day==31)
strcpy(s,"st");
else
if(da.da_day==2||da.da_day==22)
strcpy(s,"nd");
else
if(da.da_day==3||da.da_day==23)
strcpy(s,"rd");
gotoxy(1,1);
printf("%s, %s %d%s, %d.",cdow(da),cmon(da),da.da_day,s,da.da_year);
do
{
gettime(&ti);
gotoxy(72,1);
printf("%02d:%02d:%02d",ti.ti_hour,ti.ti_min,ti.ti_sec);
}
while(!kbhit());
}
