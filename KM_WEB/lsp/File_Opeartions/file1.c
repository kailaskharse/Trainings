#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main ()
{
int fd,count;

fd = open ("test",O_RDWR|O_CREAT);

count = write (fd,"KERNEL",6);

printf ("fd:%d count:%d\n",fd,count);

getchar();

close(fd);

return 0;
}


