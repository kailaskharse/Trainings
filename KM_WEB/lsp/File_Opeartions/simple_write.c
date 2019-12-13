#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()

{
int count;

    if ((write(1, "Here is some data\n", 17)) != 18)
	{
        count = write(2, "A write error has occurred on file descriptor 1\n",48);
	printf ("count:%d\n",count);
	}
    exit(0);
}

