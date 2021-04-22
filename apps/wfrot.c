#include <stdio.h>
#include <math.h>
#include "wave.h"

main(int argc,char **argv)
{
 wfObject *obj;
 float angle,x,y,z;
 int i;
 FILE *fp;
 if (argc<7)
	{
	fprintf(stderr,"Usage: %s input.obj output.obj angle x y z\n",argv[0]);
	exit(1);
	}
 if (!(obj = wfReadObject(argv[1])))
	exit(1);
 angle = atof(argv[3]);
 x = atof(argv[4]);
 y = atof(argv[5]);
 z = atof(argv[6]);
 wfRotateObject(obj,angle,x,y,z);
 if (!(fp = fopen(argv[2],"w")))
	{
	perror(argv[2]);
	exit(1);
	}
 wfWriteObject(fp,obj);
 fclose(fp);
}

