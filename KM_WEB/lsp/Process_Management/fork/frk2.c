# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/wait.h>

main(){
       pid_t pid;	
	int childstatus;
	int k=10;
	printf(" My pid = %d \n", getpid());
	getchar();
	pid = fork();
	if( pid == 0) // child
		{
		printf(" child: My pid = %d \n", getpid());
		k=44;
		printf(" end of child k = %d\n",k);
		exit(100);
	}
	// parent
	else{
		printf(" My pid = %d \n", getpid());
		printf(" Newly created child pid = %d \n", pid);
		printf(" **** of parent k = %d\n",k);
		wait(&childstatus);
		printf("end of parent k = %d\n",k);
		printf("Child status = %d\n",WEXITSTATUS(childstatus));
	}
}
		

