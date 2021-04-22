#include <stdio.h>
#include "wave.h"

void adjust_indices(wfObject *obj,int nverts,int nnorms,int ntexcoords);
void adjust_face_indices(wfFace *line,int nverts,int nnorms,int ntexcoords);
void adjust_line_indices(wfLine *line,int nverts,int nnorms,int ntexcoords);

main(int argc,char **argv)
{
 wfObject **obj;
 int i,numobjs,nverts,nnorms,ntexcoords;
 if (argc<2)
	{
	fprintf(stderr,"Usage: %s file1.obj file2.obj ... > merge.obj\n",argv[0]);
	exit(1);
	}
 numobjs = argc-1;
 obj = (wfObject **) malloc((numobjs)*sizeof(wfObject *));
 for (i=0; i<numobjs; i++)
	if (!(obj[i] = wfReadObject(argv[i+1])))
		exit(1);
 wfWriteObject(stdout,obj[0]);
 nverts = obj[0]->nverts;
 nnorms = obj[0]->nnorms;
 ntexcoords = obj[0]->ntexcoords;
 for (i=1; i<numobjs; i++)
	{
	adjust_indices(obj[i],nverts,nnorms,ntexcoords);
	wfWriteObject(stdout,obj[i]);
	nverts += obj[i]->nverts;
	nnorms += obj[i]->nnorms;
	ntexcoords += obj[i]->ntexcoords;
	}
}

void adjust_indices(wfObject *obj,int nverts,int nnorms,int ntexcoords)
{
 wfPart *part;
 int i;
 for (part=obj->parts; part; part=part->next)
	{
	if (part->parttype == WF_FACE)
		adjust_face_indices(&(part->part.face),nverts,nnorms,ntexcoords);
	else if (part->parttype == WF_LINE)
		adjust_line_indices(&(part->part.line),nverts,nnorms,ntexcoords);
	}
}

void adjust_face_indices(wfFace *face,int nverts,int nnorms,int ntexcoords)
{
 int i;
 for (i=0; i<face->nverts; i++)
	{
	face->vert[i] += nverts;
	if (face->tex[i])
		face->tex[i] += ntexcoords;
	if (face->norm[i])
		face->norm[i] += nnorms;
	}
}

void adjust_line_indices(wfLine *line,int nverts,int nnorms,int ntexcoords)
{
 int i;
 for (i=0; i<line->nverts; i++)
	{
	line->vert[i] += nverts;
	}
}
