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
			calledFunc=*(functions_nameToFunction(fl, calledFuncName));
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
	}

		/*
		else { //print reachable functions
				if (strcmp(function_getName(tf), "main")==0) {
					int k, j, l;
					function *tmp;
					function *currentFunc = functions_nameToFunction(fl, "main");
					function_setDiscovered(*currentFunc, true);
					while (true) {
						for (k=0;k<function_getCalledSize(*currentFunc);k++) {
							char* calledFuncName = function_getCalledFunction(*currentFunc, k);

							if (!function_discovered(*tmp)) {
								sprintf(prefix,"%3d. ",j++);
								function_report(tf, prefix);
								function_setDiscovered(tf, true);
							}
						}
						tmp = currentFunc;
						for (l=0;l<function_getCalledBySize(*currentFunc);l++) {
							char* calledFuncName = function_getCalledByFunction(*currentFunc, l);

							if (!function_discovered(*tmp)) {
								sprintf(prefix,"%3d. ",j++);
								function_report(tf, prefix);
								function_setDiscovered(tf, true);
							}
						}
					}

				}
				else if (function_reachableByMain(tf) && !function_discovered(tf)) { //find main
					sprintf(prefix,"%3d. ",j++);
					function_report(tf, prefix);
					function_setDiscovered(tf, true);
				}

				else if (!function_reachableByMain(tf)) { //find functions not connected to main
					function_setDiscovered(tf, true);
				}
				
		}
	} */
	return true;
}


function * functions_nameToFunction(functions fl, char *fnName) { //finds function by name
	int i;
	function tf;
	for (i=0;i<fl->count;i++) {
		tf=*(fl->fnVecPtr+i);
		if (strcmp(function_getName(tf),fnName)==0)
			return fl->fnVecPtr+i;
	}
	return NULL;
}

void functions_setReachables(functions fl) {
	int i;
	function tf;
	for (i=0;fl->fnVecPtr+i;i++) {
		tf=*(fl->fnVecPtr+i);
		if (function_reachableByMain(tf)) {
			functions_setReachable(tf);
		}
	}
}


