#include<stdio.h>

void fun1(int );
void fun2(int );


main ()
{

void (*fptr) (int ); // function pointer Declaration
fptr = &fun1;
fptr(2);

fptr = &fun2;

fptr(3);


}

void fun1(int x)
{
	printf("fun1 x:%d\n",x);
}


void fun2(int x)
{
	printf("fun2 x:%d\n",x);
}

