#include "function.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXCALLEDFUNCS 50;

struct function_struct {
	char *name;
	void *startAddr;
	int size;
	char calledFunctions[50][256];
	int calledSize;
	char calledByFunctions[50][256];
	int calledBySize;
	bool discovered;
	bool reachable;
};

function function_new(char *name) {
	function this = malloc(sizeof(struct function_struct));
	this->name=strdup(name);
	this->size=0;
	this->calledSize=0;
	this->calledBySize=0;
	this->discovered=false;
	this->reachable=false;
/* DBG	printf("Created function object for function %s\n",name); */
	return this;
}

bool function_discovered(function fn) {
	return fn->discovered;
}

void function_setDiscovered(function fn) {
	fn->discovered = true;
}


bool function_delete(function fn) {
	free(fn->name);
	fn->size=0;
	//Free other alocated sub-fields here
	free(fn);
	return true;
}

char * function_getName(function fn) {
	return fn->name;
}

void * function_getStartAddr(function fn) {
	return fn->startAddr;
}

void function_setStartAddr(function fn, void* StartAddr) {
	fn->startAddr=StartAddr;
}

int function_getSize(function fn) {
	return fn->size;
}

int function_getCalledBySize(function fn) {
	return fn->calledBySize;
}

int function_getCalledSize(function fn) {
	return fn->calledSize;
}

void function_setSize(function fn, int sz) {
	fn->size = sz;
}

void function_printCalledFunctions(function fn) {
	if (fn->calledSize==0) return;
	int i;
	printf("        Called Functions   : ");
	for (i=0;i<fn->calledSize-1;i++) {
		printf("%s, ", fn->calledFunctions[i]);
	}
	printf("%s\n", fn->calledFunctions[fn->calledSize-1]);
}

char* function_getCalledFunction(function fn, int i) {
	return fn->calledFunctions[i];
}

void function_setCalledFunction(function fn, const char* FunctionName) {
	if (function_containsFuncInArray(fn->calledFunctions,FunctionName, fn->calledSize)) {
		return;
	}
	strcpy(fn->calledFunctions[fn->calledSize],FunctionName);
	fn->calledSize++;
}

void function_printCalledByFunctions(function fn) {
	if (fn->calledBySize==0) return;
	int i;
	printf("        Called By Functions: ");
	for (i=0;i<fn->calledBySize-1;i++) {
		printf("%s, ", fn->calledByFunctions[i]);
	}
	printf("%s\n", fn->calledByFunctions[fn->calledBySize-1]);
}


void function_setCalledByFunction(function fn, const char* FunctionName) {
	strcpy(fn->calledByFunctions[fn->calledBySize], FunctionName);
	fn->calledBySize++;
}

char* function_getCalledByFunction(function fn, int i) {
	return fn->calledByFunctions[i];
}

bool function_calledByMain(function fn) {
	if (function_containsFuncInArray(fn->calledByFunctions, 
		"main", fn->calledBySize)) {
		return true;
	}
	if (function_containsFuncInArray(fn->calledFunctions,
		"main", fn->calledSize)) {
		return true;
	}
	else return false;
}

void function_setReachable(function fn) {
	fn->reachable=true;
}

bool function_getReachable(function fn) {
	return fn->reachable;
}


// Other function methods go here

bool function_report(function fn,char *prefix) {
	if (function_calledByMain(fn)
		|| strcmp(function_getName(fn),"main")==0) {
		printf("%sFunction @ %p size=  %i %s\n",prefix,fn->startAddr,fn->size,fn->name);

	}
	else {
		printf("%sFunction @ %p size= %i %s\n",prefix,fn->startAddr,fn->size,fn->name);
	}
	function_printCalledFunctions(fn);
	function_printCalledByFunctions(fn);
	return true;
}




bool function_containsFuncInArray(char StringArray[50][256], const char *item, int size) {
	int i;
	for (i=0;i<size;i++) {
		if (strcmp(item, StringArray[i])==0) {
			return true;
		}
	}
	return false;
}




