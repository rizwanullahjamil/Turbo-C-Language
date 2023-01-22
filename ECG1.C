#include <graphics.h>
#include <dos.h>
#include <math.h>

#define MAX        100
#define UPPERLEFT   40
#define LOWERRIGHT  90
#define LASTX      639
#define FIRSTX       2              /* must be greater than zero */
#define BASELINE    50

   int dat[MAX] = {  0,   0,  -1,  -4,  -7,  -6,  -5,  -2,  -2,  10,
		    20,  30,  40,  25,   1,  -3,  -6,  -5,  -5,  -2,
		     0,  -2,  -2,  -1,  -1,   0,   0,  -1,  -4,  -7,
		    -6,  -5,  -2,  -2,  10,  20,  30,  40,  25,   1,
		    -3,  -6,  -5,  -5,  -2,   0,  -2,  -2,  -1,  -1,
		     0,   0,  -1,  -4,  -7,  -6,  -5,  -2,  -2,  10,
		    20,  30,  40,  25,   1,  -3,  -6,  -5,  -5,  -2,
		     0,  -2,  -2,  -1,  -1,   0,   0,  -1,  -4,  -7,
		    -6,  -5,  -2,  -2,  10,  20,  30,  40,  25,   1,
		    -3,  -6,  -5,  -5,  -2,   0,  -2,  -2,  -1,  -1
		  };

int xdat[LASTX];

void main(void)

{  int driver = 1; int mode = 4;
   int index, cycle;
   struct time stime, etime;
   void *buff1, *buff2;
   unsigned size1;
   for( cycle = 0; cycle <= LASTX; cycle++ ) xdat[cycle] = 0;
   initgraph( &driver, &mode, "c:\\tc\\bgi");
   size1 = imagesize( FIRSTX, UPPERLEFT, LASTX, LOWERRIGHT );
   buff1 = ( void * )malloc( size1 );
   cycle = index = 0;
   do
   { gettime( &stime );
     for( index = 0; index < MAX; index++ )
     {
       line( LASTX-2, xdat[LASTX-1]+BASELINE, LASTX, xdat[LASTX]+BASELINE );
       getimage( FIRSTX, UPPERLEFT, LASTX, LOWERRIGHT ,buff1 );
       putimage( FIRSTX-2, UPPERLEFT, buff1, COPY_PUT );
       setcolor(0);
       line( LASTX-2, xdat[LASTX-1]+BASELINE, LASTX, xdat[LASTX]+BASELINE );
       setcolor(1);
       xdat[LASTX-1] = xdat[LASTX];
       xdat[LASTX] = dat[index];
     }
     gettime( &etime );
     printf( "\nElapsed time = %d.%d", etime.ti_sec  - stime.ti_sec,
				       etime.ti_hund - stime.ti_hund );
   }
   while( !kbhit() );
   closegraph();
}
