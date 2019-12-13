#include <stdio.h>
#include "hello.h" 

int km2_open (int x);
int km2_read (int z);
void fun_km2(void);

struct  hello km2 = {
 	"KM_Driver",
	.open = km2_open,
	.read = km2_read,
};

int km2_open (int x)
{
	printf("km2_open:%d\n",x);
}

int km2_read (int z)
{
	printf("km2_read:%d\n",z);
}

void fun_km2 ()
{
struct hello *fops2 = &km2;
fops2->open(9);
fops2->read(10);

}





