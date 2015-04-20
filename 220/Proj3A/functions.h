#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdbool.h>
typedef struct functions_struct * functions;
#include "function.h"

/* --------------------------------------------------------------------------------------------
	C Object Oriented definitions for a function dictionary

	Methods:
		functions functions_new()
			Creates a new list of functions
		bool functions_delete(functions fl,bool deleteMembers)
			Deletes a list of functions. if deleteMembers, deletes member functions

		bool functions_add(functions fl,function fn)
			Adds function object to the list of functions
		...

		getter/setter methods
			int functions_getCount(functions fl)
			...

		bool functions_report(functions fl,bool reachable);
			Reports on the list of functions


---------------------------------------------------------------------------------------------*/

functions functions_new();
bool functions_delete(functions fl,bool deleteMembers);

bool functions_add(functions fl,function fn);
function functions_find(functions fl,char * fnName);
function functions_next(functions fl,function fn);
void functions_insertCalledByFunctions();

int functions_getCount(functions fl);

bool functions_report(functions fl,bool reachable);
function * functions_nameToFunction(functions fl, char * fnName);

#endif
