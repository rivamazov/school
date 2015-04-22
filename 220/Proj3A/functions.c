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

void functions_insertCalledByFunctions(functions fl) {
	int i, j;
	function tf;
	for (i=0;i<fl->count;i++) {
		tf=*(fl->fnVecPtr+i);
		for (j=0;j<function_getCalledSize(tf);j++) {
			char* funcName=function_getName(tf);
			char* calledFuncName=function_getCalledFunction(tf, j);
			function calledFunc;
			calledFunc=(functions_nameToFunction(fl, calledFuncName));
			function_setCalledByFunction(calledFunc, funcName);
		}
	} 
}

int functions_getCount(functions fl) {
	return fl->count;
}

bool functions_report(functions fl,bool reachable) {
	int i,j;
	char prefix[16];
	printf("Function list has %d functions...\n",fl->count);
	functions_insertCalledByFunctions(fl);
	function tf;
	for(i=0,j=1; i<fl->count; i++) {
		tf=*(fl->fnVecPtr+i);
		if (!reachable) {
			sprintf(prefix,"%3d. ",j++);
			function_report(tf,prefix);
		}
		else {
			if (function_calledByMain(tf) || strcmp(function_getName(tf),"main")==0) {
				if (!function_discovered(tf)) {
					sprintf(prefix,"%3d. ",j++);
					function_report(tf,prefix);
					function_setDiscovered(tf);
				}
				j = functions_printCalled(fl, tf, prefix, j);
			}
			if (strcmp(function_getName(tf),"main")==0) {
				j = functions_printCalled(fl, tf, prefix, j);
			}
			if (function_getReachable(tf)) {
				if (!function_discovered(tf)) {
					sprintf(prefix,"%3d. ",j++);
					function_report(tf,prefix);
					function_setDiscovered(tf);
				}
				j = functions_printCalled(fl, tf, prefix, j);
			}
		}
	}
	return true;
}

int functions_printCalled(functions fl, function fn, char* prefix, int j) {
	int i, k;
	function_setReachable(fn);
	for (i=0;i<function_getCalledSize(fn);i++) {
		char* funcName = function_getCalledFunction(fn, i);
		function tf = functions_nameToFunction(fl, funcName);
		function_setReachable(tf);
		if (!function_discovered(tf)) {
			sprintf(prefix,"%3d. ",j++);
			function_report(tf,prefix);
			function_setDiscovered(tf);
		}
		for (k=0;k<function_getCalledSize(tf);k++) {
			char* calledFuncName = function_getCalledFunction(tf, k);
			function calledtf = functions_nameToFunction(fl, calledFuncName);
			function_setReachable(calledtf);
		}
	}
	return j;
}

function functions_nameToFunction(functions fl, char *fnName) { //finds function by name
	int i;
	function tf;
	for (i=0;i<fl->count;i++) {
		tf=*(fl->fnVecPtr+i);
		if (strcmp(function_getName(tf),fnName)==0)
			return tf;
	}
	return NULL;
}


