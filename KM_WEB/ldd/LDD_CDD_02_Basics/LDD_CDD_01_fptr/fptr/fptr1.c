#include <stdio.h>

void my_fun(int x)
{
	printf ("x value:%d\n",x);
}

void (*fptr) (int);

int main ()
{

fptr = &my_fun;

my_fun(2);
fptr(3);
(*fptr)(4);


return 0;
}

