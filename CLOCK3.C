# include<stdio.h>
# include<graphics.h>
# define C clrscr();
# define G gotoxy
# define P printf
# define F for
main(){
int h,m,i;
float s;
C
G(30,10);
P("********************");
G(30,11);
P("*      Timing      *");
G(30,12);
P("*                  *");
G(30,13);
P("*      Rizwan      *");
G(30,14);
P("********************");
F(h=0;h<24;h++){
F(m=0;m<60;m++){
F(s=0;s<60;s+=.1){
G(35,12);
P("%2d:%2d:%3.1f",h,m,s);
F(i=0;i<4500;i++);
} } } }
