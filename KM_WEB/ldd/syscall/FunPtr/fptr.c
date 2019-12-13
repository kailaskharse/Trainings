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

/*int main(void)
{
	// shout 
	say = say_loud;
	say("WHAT");

	// whisper 
	say = say_soft;
	say("I know a secret!");

	return 0;
}*/
/* The code above uses a bit of syntactic sugar. Firstly, the functions say_soft and say_loud themselves are not being assigned to the say function pointer; their addresses are. Secondly, when calling the function, the function pointer has to be dereferenced first. Therefore, a “better” version of the main function would be this:
*/
int main(void)
{
	/* shout */
	say = &say_loud;
	(*say)("WHAT");

	/* whisper */
	say = &say_soft;
	(*say)("I know a secret!");

	return 0;
}

