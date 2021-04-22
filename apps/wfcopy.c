#include <stdio.h>
#include <math.h>
#include "wave.h"

main(int argc,char **argv)
{
 wfObject *obj;
 FILE *fp;
 if (argc<3)
	{
	fprintf(stderr,"Usage: %s input.obj output.obj\n",argv[0]);
	exit(1);
	}
 wfEnable(WF_INCLUDE_ALL_PARTS);
 if (!(obj = wfReadObject(argv[1])))
	exit(1);
 if (!(fp = fopen(argv[2],"w")))
	{
	perror(argv[2]);
	exit(1);
	}
 wfWriteObject(fp,obj);
 fclose(fp);
}

