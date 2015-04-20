#include "function.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXCALLEDFUNCS = 50;

struct function_struct {
	char *name;
	void *startAddr;
	int size;
	char calledFunctions[50][256];
	int calledSize;
	char calledByFunctions[50][256];
	int calledBySize;
};

function function_new(char *name) {
	function this = malloc(sizeof(struct function_struct));
	this->name=strdup(name);
	this->size=0;
	this->calledSize=0;
	this->calledBySize=0;
/* DBG	printf("Created function object for function %s\n",name); */
	return this;
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
	printf("\tCalled Functions\t: ");
	for (i=0;i<fn->calledSize-1;i++) {
		printf("%s,", fn->calledFunctions[i]);
	}
	printf("%s\n", fn->calledFunctions[fn->calledSize-1]);
}

char* function_getCalledFunction(function fn, int i) {
	return fn->calledFunctions[i];
}

void function_setCalledFunction(function fn, const char* FunctionName) {
	strcpy(fn->calledFunctions[fn->calledSize],FunctionName);
	fn->calledSize++;
}

void function_printCalledByFunctions(function fn) {
	if (fn->calledBySize==0) return;
	int i;
	printf("\tCalled By Functions\t: ");
	for (i=0;i<fn->calledBySize-1;i++) {
		printf("%s,", fn->calledByFunctions[i]);
	}
	printf("%s\n", fn->calledByFunctions[fn->calledBySize-1]);
}

void function_setCalledByFunction(function fn, const char* FunctionName) {
	strcpy(fn->calledByFunctions[fn->calledBySize], FunctionName);
	fn->calledBySize++;
}

// Other function methods go here

bool function_report(function fn,char *prefix) {
	printf("%sFunction @ 0x%x size=	%i %s\n",prefix,fn->startAddr,fn->size,fn->name);
	function_printCalledFunctions(fn);
	function_printCalledByFunctions(fn);
	// expand this function report method to print interesting things about this function
	return true;
}

bool function_isReachable(function fn) {

}


