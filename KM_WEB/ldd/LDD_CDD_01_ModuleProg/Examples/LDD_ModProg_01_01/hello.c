#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

MODULE_DESCRIPTION("This is a sample module template");
MODULE_AUTHOR("Kernel masters");


static int Hello_init (void)
{
	printk ("This is Hello init function\n");
	return 0;
}


static void Hello_exit (void)
{
	printk ("This is Hello exit function\n");
}


module_init(Hello_init);
module_exit(Hello_exit);


