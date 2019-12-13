#include <stdio.h>
int main (void)
{
int stackVar = 3;
char szCommand[64];
printf (" Address of stackVar is 0x%x\n\n", &stackVar);
sprintf (szCommand, "cat /proc/%d/maps", getpid() );
system (szCommand);
return 0;
}
