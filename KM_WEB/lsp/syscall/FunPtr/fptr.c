#include <stdio.h>

/* shouting */
void say_loud(char *a_message)
{
    printf("\"%s!!!\" you shout.\n", a_message);
}
/* whispering */
void say_soft(char *a_message)
{
    printf("\"%s\" you whisper.\n", a_message);
}
/* say function pointer */
void (*say)(char *a_message) = NULL;
int main(void)
{

//say_soft("hello");
//say_loud("World");
	/* shout */
	say = &say_loud;
	(*say)("WHAT");

	/* whisper */
	say = &say_soft;
	(*say)("I know a secret!");

	return 0;
}

