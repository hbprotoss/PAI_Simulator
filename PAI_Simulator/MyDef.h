#ifndef MYMACRO_H
#define MYMACRO_H

#include "stdafx.h"

#define ORG_X 50
#define ORG_Y 50

#define EDGE 300

typedef struct
{
	CWnd	*pWnd;
	BOOL	bRunning;
	int	iCount;
}ThreadData, *pThreadData;

#endif