#include<stdio.h>
#include<stdlib.h>

void start(){

  double xyz[135168];
  char str[20];

  xyz[0] = 1.2;

  sprintf(str,"pmap %d",getpid());
  system(str);

  start();
}

int main(){

  char str[20];

  sprintf(str,"pmap %d",getpid());
  system(str);

  printf ("after system\n %s", str);
  printf("entering start()\n");
  start();    

  return 0;
}
