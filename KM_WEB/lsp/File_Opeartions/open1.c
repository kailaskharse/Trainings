/* THis is open system call example */


//#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


main ()
{
	int ret;

	ret = open ("test",O_RDONLY | O_CREAT);
	printf ("open system call return value:%d\n",ret);



}


