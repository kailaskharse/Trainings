#include<stdio.h>
#include<sys/syscall.h>

int main(){
int ret;
printf("Entered main function…!\n");
/*here starts system call*/
ret = syscall(326);
//ret = syscall(39);
//ret = syscall(311);
printf("ret: %d\n",ret);
return 0;
}
