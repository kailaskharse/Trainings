#include <stdio.h>

void my_fun(int x)
{
printf ("x value:%d\n",x);
}

int main ()
{

void (*fun_ptr) (int ); // dec of function pointer

fun_ptr = &my_fun;// Int. of function pointer

fun_ptr(3);

(*fun_ptr)(4);

my_fun(2);

return 0;
}
