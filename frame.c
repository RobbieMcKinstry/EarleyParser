#include <stdlib.h>
#include "frame.h"

Frame* newFrame() {
	Frame* result = (Frame*) malloc(sizeof(Frame));
	result->column = 0;
	result->caller = NULL;
	result->parseTree = NULL;
	result->ic = 0;
	result->qLink = NULL;
	return result;
}
