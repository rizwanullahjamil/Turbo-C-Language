# include<stdio.h>
# include<graphics.h>
# define CLS clrscr();
# define G gotoxy
# define P printf
# define F for
main(){
int h1,h2,m1,m2,s1,s2,t1,i;
CLS
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
F(h1=0;h1<3;h1++){
F(h2=0;h2<10;h2++){
F(m1=0;m1<6;m1++){
F(m2=0;m2<10;m2++){
F(s1=0;s1<6;s1++){
F(s2=0;s2<10;s2++){
F(t1=0;t1<10;t1++){
G(34,12);
P("%d%d:%d%d:%d%d.%d",h1,h2,m1,m2,s1,s2,t1);
F(i=0;i<4500;i++);
} } } } } } } }
