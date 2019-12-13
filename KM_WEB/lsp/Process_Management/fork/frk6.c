
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# define CHILD 0

int global = 20;

main(){
	char buf[2];
        int global;
        pid_t pid;	
	int childstatus;
	pid = fork();
	global = 1;
	if( pid == CHILD){
		global = 10;
		printf(" in child global %d\n",global);
	}
	// parent
	else{
		wait(&childstatus);
		printf(" in parent global %d\n",global);
	}
}
		

