# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>


main(){
       pid_t pid;	
	printf(" My pid = %d \n", getpid());
	getchar();
	pid = fork();
	if( pid == 0){ // child
		printf(" child: My pid = %d \n", getpid());
		printf(" child: My parent pid = %d \n", getppid());
		while(1);
	}
	// parent
	else{
		printf(" Parent: My pid = %d \n", getpid());
		printf(" Parent: My parent pid = %d \n", getppid());
		printf(" Newly created child pid = %d \n", pid);
	}
}
		

