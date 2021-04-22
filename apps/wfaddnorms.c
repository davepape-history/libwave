#include <stdio.h>
#include <math.h>
#include "wave.h"

main(int argc,char **argv)
{
 wfObject *obj;
 int smooth=0,clockwise=0;
 FILE *fp;
 if (argc<3)
	{
	fprintf(stderr,"Usage: %s input.obj output.obj [smoothflag clockwiseflag]\n",argv[0]);
	exit(1);
	}
 if (!(obj = wfReadObject(argv[1])))
	exit(1);
 if (argc>3)
	smooth = atoi(argv[3]);
 if (argc>4)
	clockwise = atoi(argv[4]);
 wfComputeNormals(obj,smooth,clockwise);
 if (!(fp = fopen(argv[2],"w")))
	{
	perror(argv[2]);
	exit(1);
	}
 wfWriteObject(fp,obj);
 fclose(fp);
}

