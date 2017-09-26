
#include <memory.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h> 
#include <sys/wait.h>
//#pragma GCC diagnostic ignored "-Wwrite-strings"

int main (int argc, char* argv[]) {

	const char* str1;
	const char* str2;
	const char* str4;
	str1 = "sssss";
	str2 = "ffff";
	str4 = "pppppppppp";
	char * str3 = (char *) malloc(100 + strlen(str1) + strlen(str2));
	strcpy (str3, str1);
	strcat(str3, str2);
	strcat(str3,str4);
	printf("%s", str3);
	return 0;
	free(str3);
}