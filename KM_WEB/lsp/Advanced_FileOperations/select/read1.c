#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd1,retfd;
	char buf[4096];
	int val;

	fd1=open("/dev/input/event1",O_RDONLY);
	if(fd1<0)
		printf("error while open the file event1\n");
	
	retfd=read(fd1,buf,4096);
	printf("Read return value - fd1 - power button:%d\n",retfd);
	if(retfd<0){
		printf("read is failed\n");
		return -1;
		}

	return 0;
}
		
