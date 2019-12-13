#include <stdio.h>

main ()
{

myfunction();

}

void myfunction()
{
   char big[100000];
   // do something that only uses for first 1K of big 99% of the time.
}


