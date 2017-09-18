#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

int main(int argc, char **argv){
  char name[512];
  char * pch;
  signed int is_command = 0; 
  signed int is_argument = 0;
  signed int is_pipe = 0;
  signed int is_redirect = 0;
  signed int is_background = 0;
  
  //char *s= " \n\t";

  for (;;) {
    printf ("my_parser> ");
    is_command = 0;
    is_argument = 0;
    is_pipe = 0;
    is_redirect = 0;
    is_background = 0;
    fflush (NULL);
    if (fgets(name,512,stdin) == NULL) break;

    else {
      // int rv = sprintf(buffer,name);
      //  printf("who are you");
        pch = strtok(name," \n\t"); //seperate by space 
      //   pch = strtok(name, ">"); //seperate by >


    while (pch != NULL) {
	//  printf("Glad to meet you, %s",name);

    	if (strcmp(pch,"|")==0){ //strcmp compares two blocks of memory character by character
    		is_argument=0;
    		is_command=0;
    		printf("| - pipe\n");
    	}
    	else if (strcmp(pch,"&")==0){
    		is_argument=0;
    		is_command=0;
    		printf("& - background \n");
    	}
    	else if (strcmp(pch,">")==0){ 
    		//is_argument=0;
    		//is_command=0;
    		printf("> - output redirect\n");
    	}
    	else if (strcmp(pch,"<")==0){ 
    		//is_argument=0;
    		//is_command=0;
    		printf("< - input redirect \n");
    	}
		else if (is_command == 0) {
		for (int x =0; pch[x] != '\0'; x++){
			
			printf ("%c loop reached",pch[x]);
			//	if (strcmp(pch[x],"A")==0){
					//printf ("loop confirmed %s", pch[x]);
				}
				//else{}

				  	is_command = 1;
	  	printf ("%s - command\n",pch);
	
			}


	
		else if ((is_command == 1 && is_pipe == 0) && (pch && pch[0]) /*|| is_argument == 1*/ ) {
			//if (pch == )
	  		is_argument = 1;
	  		printf ("%s",pch);
	  		printf("- argument\n");

		}
		else{
	 		//printf ("%s",pch);
	 	}
      	pch = strtok (NULL, " \n\t");
      
	//	pch = strtok (NULL, ">");
	
     
      }
    }
  }
  // while (fgets(name,10,stdin)!= NULL) {

 // printf("\n");
  // }
  return 0;
}
