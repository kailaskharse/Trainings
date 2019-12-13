#include <stdio.h>

int main(void) 
{
__asm__("movl $313,%eax");
__asm__("int $0x80");
//__asm__ ("movl %eax, -8(%ebp)");
}
