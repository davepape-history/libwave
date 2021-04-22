#include <stdio.h>
#include <math.h>
#include "wave.h"

main(int argc,char **argv)
{
 wfObject *obj;
 float scale;
 int i;
 FILE *fp;
 if (argc<4)
	{
	fprintf(stderr,"Usage: %s input.obj output.obj scale\n",argv[0]);
	exit(1);
	}
 if (!(obj = wfReadObject(argv[1])))
	exit(1);
 scale = atof(argv[3]);
 for (i=0; i<obj->nverts; i++)
	{
	obj->vert[i][0] *= scale;
	obj->vert[i][1] *= scale;
	obj->vert[i][2] *= scale;
	}
 if (!(fp = fopen(argv[2],"w")))
	{
	perror(argv[2]);
	exit(1);
	}
 wfWriteObject(fp,obj);
 fclose(fp);
}

