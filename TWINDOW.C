/* twindow.c -- test text windoe functions */
#include"conio.h"
#include"graphics.h"
#define H_LINE '\xc4'
#define V_LINE '\xb3'
#define DH_LINE '\xcd'
#define DV_LINE '\xba'
#define TLC '\xda'
#define TRC '\xbf'
#define BLC '\xc0'
#define BRC '\xd9'
#define DTLC '\xc9'
#define DTRC '\xbb'
#define DBLC '\xc8'
#define DBRC '\xbc'
#define SINGLE_BORDER 1
#define TWIN_BORDER 2
struct text_info mytext;
void underline(void)
{
textcolor(BLUE);
textbackground(BLACK);
}
void reversevideo(void)
{
textcolor(BLACK);
textbackground(WHITE);
}
void hide(void)
{
textcolor(BLACK);
textbackground(BLACK);
}
int my_hline(int startx,int starty,int endx,char line_char)
{
int i;
gotoxy(startx,starty);
if(startx==endx)
return(0);
if(startx<endx)
{
for(i=startx;i<=endx;i++)
putch(line_char);
return(i-startx);
}
gotoxy(endx,starty);
for(i=endx;i<=startx;i++)
putch(line_char);
return(i-endx);
}
int my_vline(int startx,int starty,int endy,char line_char)
{
int i;
if(starty==endy)
return(0);
if(starty<endy)
{
for(i=starty;i<=endy;i++)
{
gotoxy(startx,i);
putch(line_char);
}
return(i-starty);
}
for(i=endy;i<=starty;i++)
{
gotoxy(startx,i);
putch(line_char);
}
return(endy-i);
}
int my_rect(int tlx,int tly,int brx,int bry,int style)
{
int w,h;
char hline_ch,vline_ch,tlc,trc,blc,brc;
switch(style)
{
case 1:
case 0:
hline_ch=H_LINE;
vline_ch=V_LINE;
tlc=TLC;
trc=TRC;
blc=BLC;
brc=BRC;
break;
case 2:
hline_ch=DH_LINE;
vline_ch=DV_LINE;
tlc=DTLC;
trc=DTRC;
blc=DBLC;
brc=DBRC;
break;
default:
return (0);
}
gotoxy(tlx,tly);
putch(tlc);
w=my_hline(tlx+1,tly,brx-1,hline_ch);
putch(trc);
h=my_vline(brx,tly+1,bry-1,vline_ch);
gotoxy(brx,bry);
putch(brc);
my_hline(brx-1,bry,tlx+1,hline_ch);
gotoxy(tlx,bry);
putch(blc);
my_vline(tlx,bry-1,tly+1,vline_ch);
return(w*h);
}
void main(void)
{
int graphmode,graphdriver,himode,lomode;
char savewin1[300],savewin2[300];
clrscr();
directvideo=1;
detectgraph(&graphdriver,&graphmode);
getmoderange(graphdriver,&lomode,&himode);
textmode(C80);
gettextinfo(&mytext);
my_rect(9,7,49,20,SINGLE_BORDER);
my_rect(10,8,48,11,TWIN_BORDER);
window(11,9,47,10);
gotoxy(2,1);
reversevideo();
cprintf("driver = %d, max mode = %d",graphdriver,graphmode);
gettext(12,9,47,9,savewin1);
normvideo();
window(1,1,80,25);
my_rect(10,14,48,17,TWIN_BORDER);
window(11,15,47,16);
gotoxy(2,1);
underline();
cprintf("TxtMod = %d, WinLeft = %d, WinTop = %d",
mytext.currmode,mytext.winleft,mytext.wintop);
gotoxy(2,2);
normvideo();
cprintf("LoMode = %d, HiMode = %d",lomode,himode);
gettext(12,15,47,16,savewin2);
normvideo();
highvideo();
cputs("    <CR>...");
getch();
gotoxy(1,1);
clrscr();
puttext(12,15,47,15,savewin1);
window(11,9,47,10);
gotoxy(1,1);
clrscr();
puttext(12,9,47,10,savewin2);
}
