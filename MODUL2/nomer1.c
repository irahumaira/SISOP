#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void  parse(char *line, char **argv) {
	while (*line != '\0') {       // if not the end of line .......  
		while (*line == ' ' || *line == '\t' || *line == '\n')	*line++ = '\0';
          	*argv++ = line;
		while (*line != '\0' && *line != ' ' &&  *line != '\t' && *line != '\n') line++;
	}
	*argv = '\0';                 // mark the end of argument list
}

int  exec(char **argv, int back) {
     	pid_t  pid;
     	int status;
     	if ((pid = fork()) < 0) {
		printf("*** ERROR: forking child process failed\n");
		exit(1);
     	}
   	else if (pid == 0) {
		if (execvp(*argv, argv) < 0) {
              	 	printf("*** ERROR: exec failed\n");
              	 	exit(1);
		}
    	}
     	else {
         	if(back==0) while (wait(&status) != pid);
	}
}

void sighandler(int signum) {
	char tmp[30];
	getcwd(tmp, sizeof(tmp));
	printf("\npraktikum2:~%s ", tmp);
	fflush(stdout);
}


int main() {
	signal(SIGINT, sighandler);
	signal(SIGTSTP, sighandler);
	
	char line[1024],*argv[64];
	char tmp[30],ori[30];
	while(1) 
	{
		getcwd(tmp, sizeof(tmp));
	        printf("praktikum2:~ %s$ ", tmp);
		scanf("%[^\n]",line);
		if(getchar()==EOF) exit(1);
		printf(">> %s\n",line);
		
		if(strcmp(line,"exit")!=0) {
			if(strncmp("cd",line,2)!=0) {
				parse(line,argv);
				exec(argv,0);
			}
			else {
				char *inp,*split=strtok(line," ");
				while(split!=NULL) {
				        inp=split;
					split=strtok(NULL," ");
				}
				chdir(inp);
			}
		}
		else exit(1);
		strcpy(line,"");
	}
}

