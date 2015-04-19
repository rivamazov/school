#include "function.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct function_struct {
	char *name;
	void* startAddr;
	int size;
	char** calledFunctions;
	char** calledByFunctions;
};

function function_new(char *name) {
	function this = malloc(sizeof(struct function_struct));
	this->name=strdup(name);
/* DBG	printf("Created function object for function %s\n",name); */
	return this;
}

bool function_delete(function fn) {
	free(fn->name);
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

void function_setStartAddr(function fn, void* StartAddr){
	fn->startAddr=StartAddr;
}

int function_getSize(function fn) {
	return fn->size;
}

void function_setSize(function fn, int sz) {
	fn->size = sz;
}





// Other function methods go here

bool function_report(function fn,char *prefix) {
	printf("%sFunction @ 0x%x size=	%i %s\n",prefix,fn->startAddr,fn->size,fn->name);
	// expand this function report method to print interesting things about this function
	return true;
}
