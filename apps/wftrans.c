#include <stdio.h>
#include <math.h>
#include "wave.h"

main(int argc,char **argv)
{
 wfObject *obj;
 float tx,ty,tz;
 int i;
 FILE *fp;
 if (argc<6)
	{
	fprintf(stderr,"Usage: %s input.obj output.obj transX transY transZ\n",argv[0]);
	exit(1);
	}
 if (!(obj = wfReadObject(argv[1])))
	exit(1);
 tx = atof(argv[3]);
 ty = atof(argv[4]);
 tz = atof(argv[5]);
 for (i=0; i<obj->nverts; i++)
	{
	obj->vert[i][0] += tx;
	obj->vert[i][1] += ty;
	obj->vert[i][2] += tz;
	}
 if (!(fp = fopen(argv[2],"w")))
	{
	perror(argv[2]);
	exit(1);
	}
 wfWriteObject(fp,obj);
 fclose(fp);
}

