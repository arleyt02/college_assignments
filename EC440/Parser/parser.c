#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h> 
#include <sys/wait.h>


#define MAXARGS 100


int main(int argc, char *argv[]){

  char name[512]; //input could only be 512 characters long
  char * pch; //pch is a char pointer for all my tokens when using strtok
  char * tok_array[512][512];
  int pid;
  int status;
  char  current_token = 'G';

  const char *cmd = "ls";
  char *test[3];
  test[0] = "ls";
  //test[1] = "-la";
  test[1] = NULL;


  
  

  signed int is_command = 0; 
  signed int is_argument = 0;
  signed int is_pipe = 0;
  signed int is_redirect = 0;
  signed int is_background = 0;

  char *myargv[MAXARGS]; 

  
  for (;;) { //runs forever until loop is broken
  	  pid = fork();

  if (pid ){
  	wait(&status);
  }
  else {
  	execvp(cmd,test);
  }
    printf ("my_parser> ");

    /* variables to check if tokens are commands, arguments, pipes, etc.*/
    is_command = 0; 
    is_argument = 0;
    is_pipe = 0;
    is_redirect = 0;
    is_background = 0;

    fflush (NULL);

    if (fgets(name,512,stdin) == NULL) break; //break loop if CTRL-D is entered

    else {

        /* get first token */
        pch = strtok(name," \n\t"); //seperate inputs by spaces and newlines


    /* process tokens */
    while (pch != NULL) {

      /* handling if token is a pipe and has a whitespace next to it. Ex: cat | file ===> command, pipe, command set everything to 0  */

    	if (strcmp(pch,"|")==0){ //strcmp compares two blocks of memory character by character, does pch = '|'
    		is_argument=0;
    		is_command=0;
    		printf("| - pipe\n");
    	}

      /* handling if token is a background and has a whitespace next to it. Ex: cat & file ===> command, background, command set everything to 0  */
    	else if (strcmp(pch,"&")==0){
    		is_argument=0;
    		is_command=0;
    		printf("& - background \n");
    	}

            /* handling if token is a output redirect and has a whitespace next to it. Ex: cat > file ===> command, output redirect, argument */
    	else if (strcmp(pch,">")==0){ 

    		printf("> - output redirect\n");
    	}

       /* handling if token is a input redirect and has a whitespace next to it. Ex: cat < file ===> command, input redirect, argument */
    	else if (strcmp(pch,"<")==0){ 

    		printf("< - input redirect \n");
    	}


    	/*   Command management                            */
		else if (is_command == 0) {

			is_command = 1; //acknowledge that we just had a command

		for (int x =0; pch[x] != '\0'; x++){ //process command by character, looking for certain characters
			
			/*  command contains pipe, next token is a command         */
			if (pch[x] == '|'){

				if (pch[0] == '|'){
				is_command = 1; 
				is_argument = 0;
				printf("| - pipe\n");
				}

				else {
				printf (" - command\n");
				is_command = 1; 
				is_argument = 0;
				printf("| - pipe\n");
			}
			}

			/*  command contains output redirect, next token in an argument if we are still in command phase or not*/
			else if (pch[x] == '>'){

				if (pch[0] == '>'){
					if (is_command == 1){
						
						is_command = 0; 
						is_argument = 1;
						printf("> - output redirect\n");
					}		

					else {
						//printf (" - argument\n");
						printf("> - output redirect\n");
					}
				}
				else {
					if (is_command == 1){
						printf (" - command\n");
						is_command = 0; 
						is_argument = 1;
						printf("> - output redirect\n");
					}

					else {
						printf (" - argument\n");
						printf("> - output redirect\n");
					}	
			}
		}

			/*  command contains input redirect, next token in an argument if we are still in command phase or not*/

			else if (pch[x] == '<'){
				if (pch[0] == '<'){
					if (is_command == 1){
						
						is_command = 0; 
						is_argument = 1;
						printf("< - input redirect\n");
					}		

					else {
						//printf (" - argument\n");
						printf("< - input redirect\n");
					}
				}
				else {
					if (is_command == 1){
						printf (" - command\n");
						is_command = 0; 
						is_argument = 1;
						printf("< - input redirect\n");
					}

					else {
						printf (" - argument\n");
						printf("< - input redirect\n");
					}	
			}
}

			/* command contains a background*/
			else if (pch[x] == '&'){
				if (is_command == 1){
				printf (" - command\n");
				is_command = 0; 
				is_argument = 1;
				printf("& - background\n");


			}

				else {
					printf (" - argument\n");
					printf("& - background\n");
				}
			}


			/*  just print out the char if you didn't reach any weird character  */
			else {

				
				printf ("%c",pch[x]);
			
			}

				}
				/* print out the corresponding result for the token depending on the variables  */

			if (is_command == 1 && is_argument != 1){
				//is_command =0;
				printf (" - command\n");
			}

			else if (is_argument == 1 ){
				printf (" - argument\n");
			}

			else
			printf("\n"); 

	
			} //end of command management
 

		/*        argument management               */


			/* similar to command control but modifed to get the necessary responses*/

		else if ((is_command == 1 && is_pipe == 0) && (pch && pch[0])) {
			
	  		is_argument = 1;
	  		is_command =0;
	  		for (int x =0; pch[x] != '\0'; x++){
			

			if (pch[x] == '|'){

				if (pch[0] == '|'){

					is_command = 1; 
					is_argument = 0;
					printf("| - pipe\n");
				}

				else {


				if (is_command == 0){
					printf (" - argument\n");
					is_command = 1; 
					is_argument = 0;
					printf("| - pipe\n");
				}

				else {
					printf (" - command\n");
					is_command = 1; 
					is_argument = 0;
					printf("| - pipe\n");
				}
			}
		}

			else if (pch[x] == '>'){

				if (pch[0] == '>'){
					if (is_command == 1){
						
						is_command = 0; 
						is_argument = 1;
						printf("> - output redirect\n");
					}		

					else {
						//printf (" - argument\n");
						printf("> - output redirect\n");
					}
				}
				else {
					if (is_command == 1){
						printf (" - command\n");
						is_command = 0; 
						is_argument = 1;
						printf("> - output redirect\n");
					}

					else {
						printf (" - argument\n");
						printf("> - output redirect\n");
					}	
			}
}
			else if (pch[x] == '<'){
				if (pch[0] == '<'){
					if (is_command == 1){
						
						is_command = 0; 
						is_argument = 1;
						printf("< - input redirect\n");
					}		

					else {
						//printf (" - argument\n");
						printf("< - input redirect\n");
					}
				}
				else {
					if (is_command == 1){
						printf (" - command\n");
						is_command = 0; 
						is_argument = 1;
						printf("< - input redirect\n");
					}

					else {
						printf (" - argument\n");
						printf("< - input redirect\n");
					}	
			}

}
			else if (pch[x] == '&'){
				if (is_command == 1){
				printf (" - command\n");
				is_command = 0; 
				is_argument = 1;
				printf("& - background\n");

			}

				else {
					printf (" - argument\n");
					printf("& - background\n");
				}
			}

			else {

				printf ("%c",pch[x]);

			}
		}


			if (is_command == 1 && is_argument != 1){
				printf (" - command\n");
			}

			else if (is_argument == 1 ){
				printf (" - argument\n");
			}

			else
			printf("\n");


		} //end of argument control 




		else{

	 	}

      	pch = strtok (NULL, " \n\t"); //get the next token in the input
      
     
      }
    }
  }

  return 0;
}
