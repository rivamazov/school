#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct functions_struct {
	int count; // Number of functions described
	int max; // Number of functions which can be included
	function * fnVecPtr; // Pointer to the first in a list of functions
};

functions functions_new() {
	functions this=malloc(sizeof(struct functions_struct));
	this->count=0;
	this->max=16;
	this->fnVecPtr=malloc(this->max * sizeof(function));
	if (this->fnVecPtr==NULL) return NULL;
	return this;
}

bool functions_delete(functions fl,bool deleteMembers) {
	int i;
	if (deleteMembers) {
		for(i=0; i<fl->count; i++) function_delete(*(fl->fnVecPtr+i));
	}
	free(fl->fnVecPtr);
	free(fl);
	return true;
}

bool functions_add(functions fl,function fn) {
	// Probably want to check to make sure the function is not already defined here
	if (fl->count == fl->max) {
		fl->max *=2;
		fl->fnVecPtr=realloc(fl->fnVecPtr,fl->max * sizeof(function));
		if (fl->fnVecPtr==NULL) {
			fl->max=0;
			fl->count=0;
			return false;
		}
	}
	*(fl->fnVecPtr + fl->count) = fn;
	fl->count++;
	return true;
}

// Other method definitions go here

int functions_getCount(functions fl) {
	return fl->count;
}

bool functions_report(functions fl,bool reachable) {
	int i,j;
	char prefix[16];
	printf("Function list has %d functions...\n",fl->count);
	function tf;
	for(i=0,j=1; i<fl->count; i++) {
		tf=*(fl->fnVecPtr+i);
		// May need to figure out if this function is reachable here
		sprintf(prefix,"%3d. ",j++);
		function_report(tf,prefix);
	}
	return true;
}
