# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/wait.h>

void sighand(int signum){
	printf(" I am in sig handler \n");
}

main(){
        pid_t pid;	
	int childstatus;
	pid = fork();
	if( pid == 0){
		while(1); // infinite loop.
	}
	// parent
	else{
		signal(1,sighand);
		wait(&childstatus);
		if(WIFSIGNALED(childstatus)){
			printf(" child was killed due to uncaught sig\n");
		}
	}
}
		

