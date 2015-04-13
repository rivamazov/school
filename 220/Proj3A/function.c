#include "function.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct function_struct {
	char *name;
	// Other fields go here 
};

function function_new(char *name) {
	function this = malloc(sizeof(struct function_struct));
	this->name=strdup(name);
	// Initalize fields here
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

// Other function methods go here

bool function_report(function fn,char *prefix) {
	printf("%sFunction %s\n",prefix,fn->name);
	// expand this function report method to print interesting things about this function
	return true;
}
