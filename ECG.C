#include <graphics.h>
#include <math.h>
#define MAX   100
#define UPPER 50
#define LOWER 150
#define LASTX 100
#define BASELINE 50
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

int xdat[LASTX];
void refresh(void);

void main(void)

{  int driver = 1; int mode = 0;
   int index;
   for( index = 0; index <= LASTX; index++ ) xdat[index] = 0;
   initgraph( &driver, &mode, "d:\tc");
   do
   { for( index = 0; index < MAX; index++ )
     {  refresh();
	xdat[LASTX] = dat[index];
	line( LASTX-1, xdat[LASTX-1]+BASELINE, LASTX, xdat[LASTX]+BASELINE );
     }
   }
   while( !kbhit() );
   closegraph();
}

void refresh()
{ int i;
  for( i = 0; i < LASTX-1; i++ )
  { setcolor(0);
    line( i, xdat[i]+BASELINE, i+1, xdat[i+1]+BASELINE );
    xdat[i] = xdat[i+1];
    setcolor(1);
    line( i, xdat[i+1]+BASELINE, i+1, xdat[i+2]+BASELINE );
  }
  setcolor(0);
  line( LASTX-1, xdat[LASTX-1]+BASELINE, LASTX, xdat[LASTX]+BASELINE );
  xdat[LASTX-1] = xdat[LASTX];
  setcolor(1);
}

