#include <stdio.h>
#include "hello.h" 

int km1_open (int x);
int km1_read (int z);
void fun_km2(void);
struct  hello km1 = {
 	"KM_Driver",
	.open = km1_open,
	.read = km1_read,
};

int km1_open (int x)
{
	printf("km1_open:%d\n",x);
}

int km1_read (int z)
{
	printf("km1_read:%d\n",z);
}

main ()
{
struct hello *fops1 = &km1;
fops1->open(5);
fops1->read(8);
fun_km2();
}





