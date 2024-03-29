#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdbool.h>

typedef struct function_struct * function;
#include "functions.h"

/* --------------------------------------------------------------------------------------------
	C Object Oriented definitions for a function

	Methods:
		function function_new(char *name, void* fnstart)
			Creates a new function
		bool function_delete(function fn)
			Deletes a function

		getters/setters:
			char * function_getName(function fn)
			...

		...
		bool function_report(function fn,char *prefix)


---------------------------------------------------------------------------------------------*/


function function_new(char *name);
bool function_delete(function fn);

bool function_discovered(function fn);
void function_setDiscovered(function fn);

char * function_getName(function fn);

void * function_getStartAddr(function fn);
void function_setStartAddr(function fn, void *startAddress);

int function_getSize(function fn);
int function_getCalledSize(function fn);
int function_getCalledBySize(function fn);
void function_setSize(function fn, int sz);

void function_printCalledFunctions(function fn);
char* function_getCalledFunction(function fn, int i);
void function_setCalledFunction(function fn, const char* FunctionName);

void function_printCalledByFunctions(function fn);
char* function_getCalledByFunction(function fn, int i);
void function_setCalledByFunction(function fn, const char* FunctionName);

bool function_calledByMain(function fn);
void function_setReachable(function fn);
bool function_getReachable(function fn);

// Function declarations for other methods go here...
bool function_report(function fn,char *prefix);
bool function_containsFuncInArray(char StringArray[50][256], const char* item, int size);


#endif
