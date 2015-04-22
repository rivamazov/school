#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"
#include "function.h"

bool readObject(char * objFile,functions fnList);

int main(int argc, char **argv) {

	setbuf(stdout,0);
	setbuf(stderr,0);

	if (argc!=2) {
		printf("Invocation: %s <executable_file>\n",argv[0]);
		exit(0);
	}
	functions fnList = functions_new();
	readObject(argv[1],fnList);
	// May need to do something here to find out if a function is reachable from main
	
	functions_report(fnList,true);
	functions_delete(fnList,true);
	exit(1);
}

bool readObject(char * objFile,functions fnList) {

	char pcmd[1024] = "objdump -d ";
	char dumpLine[1024];
	strcat(pcmd,objFile);

	FILE *pipe;
	pipe=popen(pcmd,"r");
	if (!pipe) {
		perror("Unable to open objdump command");
		return false;
	}

	bool inFunction=false;
	void *addr;
	void *fnStart;
	void *prevFunctionStart = 0;
	char fnName[1024];
	function current;

	while(fgets(dumpLine,sizeof(dumpLine),pipe)) {

		// D: 0000000100401000 <WinMainCRTStartup>:
		if (2==sscanf(dumpLine,"%p <%[^>]>:\n",&addr,fnName)) {
			inFunction=true;
			fnStart=addr;
/* DBG printf("In function: %s which starts at %p\n",fnName,fnStart); */
			current = function_new(fnName);
			functions_add(fnList,current);
			continue;
		}
		if (0==strcmp(dumpLine,"\n")) {
			inFunction=false;
			continue;
		}
		if (inFunction) {
			unsigned char opCode;
			char mnemonic[20]="???";
			char parms[100]="";
			int offset,nr;
			int objBytes=0;
			int totalObjBytes=0;
			char *rest;
			if (1==sscanf(dumpLine," %p:\t%n",&addr,&nr)) {
				rest=dumpLine+nr;
				char objText[64];
				if (1==sscanf(rest,"%[^\t]\t%n",objText,&nr)) {
					int l=strlen(objText)-1;
					while (l>=0 && objText[l]==' ') { // Strip trailing blanks
						objText[l]='\0';
						l--;
					}
					objBytes = (strlen(objText)+1)/3;
					sscanf(objText,"%02hhx",&opCode);
					rest=rest+nr;
					sscanf(rest,"%s %[^\n]\n",mnemonic,parms);
				}
			}
			offset=addr - fnStart;
			totalObjBytes+=objBytes+nr;
/* DBG printf ("<%s+%03x> %s %s\n",fnName,offset,mnemonic,parms); */
			// May want to set other attributes of a function here

			if (0==strncmp(mnemonic,"call",4)) { //if call occurs
				char calledFunc[256]="";
				char * parmPtr=parms;
				void * calledAddr;
				if (1==sscanf(parmPtr,"*%[^#]#%n",calledFunc,&nr)) {
					parmPtr +=nr;
					calledFunc[0]='\0';
				}
				if (2==sscanf(parmPtr,"%p <%[^>]>",&calledAddr,calledFunc)) {
/* DBG  printf("Calling %s @ %p\n",calledFunc,calledAddr); */
					// Handle calling of lower level functions from here


					function_setCalledFunction(current, calledFunc);
				} else {
					function_setSize(current, offset+1);
/* DBG printf("Not sure what is being called in %s\n",parms); */
				}
			}
			function_setStartAddr(current, fnStart);
			function_setSize(current, offset+1);			
		}
	}
	pclose(pipe);
	return true;
}
