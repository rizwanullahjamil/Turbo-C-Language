#include <graphics.h>
#include <math.h>
#define MAX   100
#define UPPER 50
#define LOWER 150
#define LASTX 639

   int dat[MAX] = {  0,   0,  -1,  -2,  -4,  -6,  -7,  -6,  -4,  -1,
		     2,   5,   7,  10,  15,  20,  30,  40,  35,  25,
		    15,   8,   1,  -3, -10,  -5,  -0,   1,   2,   2,
		     3,   4,   4,   5,   8,   8,   8,   6,   3,   0,
		     0,   1,  -1,  -2,   2,   3,   3,   5,   4,   3,
		     2,   1,   0,  -3,  -5,  -5,  -5,  -5,  -3,   2,
		     2,   3,   4,   6,  11,  15,  15,  20,  35,  30,
		    30,  15,  10,   4,  -4,  -2,  -1,  -1,   0,   0,
		     1,   5,   6,   8,   6,   5,   5,   3,   3,   0,
		    -2,  -1,  -1,  -1,   2,   3,   4,   4,   3,   2
		  };

void main(void)

{  int driver = 1; int mode = 4;
   int x, shift, index, baseline, initial;
   void *buff1, *buff2;
   unsigned size1, size2;
   initgraph( &driver, &mode, "d:\tc");
   size1 = imagesize( 0, 0, LASTX, 99 );
   size2 = imagesize( 0, 100, LASTX, 199);
   buff1 = ( void * )malloc( size1 );
   buff2 = ( void * )malloc( size2 );
   line( 0, 49, LASTX, 49 );
   line( 0, 149, LASTX, 149 );
   getimage( 0, 0, LASTX, 99, buff1 );
   getimage( 0, 100, LASTX, 199, buff2 );
   baseline = UPPER;
   shift = -1;
   initial = 0;
   x = 0;
   do
   {  for( index=1; index<LASTX; index++ )
      {  line( index-1, xdat[index]+baseline, index, xdat[index+1]+baseline );
	 xdat[index] = xdat[index+1];
      }
      xdat[LASTX] = dat[cycle];
   }
   while( !kbhit() );
   closegraph();
}