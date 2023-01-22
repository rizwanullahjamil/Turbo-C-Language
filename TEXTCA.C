/*textca.c
This program shows randomly selected one-dimensional cellular
automata in text mode.
Pressing any key other than Q changes the rule; Q exits.*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
main()
{
int ruletable[8]={0,1,1,1,1,0,0,0}; /* This is changeable */
int i,nabecode,key,exitflag=0,oldbuff[80],newbuff[80];
for(i=0;i<80;i++) /* Empty out the buffers */
oldbuff[i]=newbuff[i]=0;
oldbuff[40]=1; /* Turn one cell on */
while(!exitflag)
{
for(i=1;i<79;i++)
{
nabecode=4*oldbuff[i-1]+2*oldbuff[i]+oldbuff[i+1];
newbuff[i]=ruletable[nabecode]; /* 0<=nabecode <=8 */
}
for(i=0;i<80;i++) /* We show all 80 cells, BUT we */
{                 /* update ONLY the center 78 cells */
if(newbuff[i]==1)
printf("%c",219); /* 219 is ASCII number of block */
else
printf(".");
oldbuff[i]=newbuff[i];
}
if(kbhit())
{
key=getch();
if(key=='q'||key=='Q')
exitflag=1;
else /* Change the rule table */
for(i=0;i<8;i++)
ruletable[i]=rand()&1; /* Either 0 or 1 */
}
}
}
