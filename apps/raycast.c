#include <stdio.h>
#include <math.h>
#include "wave.h"

main(int argc,char **argv)
{
 wfObject *obj;
 FILE *fp;
 float y,x;
 float p0[3],delta[3];
 if (argc<2)
	{
	fprintf(stderr,"Usage: %s input.obj\n",argv[0]);
	exit(1);
	}
 if (!(obj = wfReadObject(argv[1])))
	exit(1);
 delta[0] = 0;
 delta[1] = 0;
 delta[2] = -1;
 p0[2] = 10;
clock();
 for (y=10; y>-10; y-=.5)
    {
    p0[1] = y;
    for (x=-10; x<10; x+=.25)
	{
	p0[0] = x;
	if (wfRayHits(obj,p0,delta))
		printf("X");
	else
		printf(" ");
	}
    printf("\n");
    }
fprintf(stderr,"%f\n",clock()/1000000.0f);
}

