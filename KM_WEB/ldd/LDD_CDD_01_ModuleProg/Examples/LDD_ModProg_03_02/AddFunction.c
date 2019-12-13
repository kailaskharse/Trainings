/*
 *This is a simple Hello World program to introduce Module Programming.......
 * 
 */


// Include Section///////////////////////////////////////////////////////////////////////////////////////////
#include <linux/init.h>//Required header for the Intialization and Cleanup Functionalities....
#include <linux/module.h>//This Header contains the necessary stuff for the Module
#include <linux/moduleparam.h>//This header allows the passing of parameters to the modules during insertion
#include <linux/kernel.h>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int HelloWorld_add(int a, int b);

MODULE_LICENSE("GPL");//MACRO that decides the licensing of the module
MODULE_AUTHOR("Kernel Masters");


//Make the Variable mentioned below availible to other modules for use.....
int HelloWorld_type=1;
EXPORT_SYMBOL(HelloWorld_add);

//INITIALIZATION function for the program.................
static int __init  hello_init(void)
{
	printk(KERN_ALERT "In Init Module.......The Module Parameter is %d\n",HelloWorld_type);
	printk(KERN_ALERT "Hello, World\n");
	return  0;//Has a Very Important Significance........Comment it and learn a lot...........
}

int HelloWorld_add(int a, int b)
{
	//int sum;
	printk(KERN_ALERT "\nIn Function HelloWorld_add of Module.....ADD\n");
	return(a+b);
}

//CLEAN UP function.........
static void __exit  hello_exit(void)
{
	printk(KERN_ALERT "In Cleanup Module......The Module Parameter is %d\n",HelloWorld_type);
	printk(KERN_ALERT "Goodbye, World\n");
}


//MACROS that allow the user to override the names of the above mentioned functions with their own choice....
module_init(hello_init);//for INITIALIZATION function
module_exit(hello_exit);//for CLEAN UP FUNCTION........

//Module PArameter for HelloWorld_type integer
module_param(HelloWorld_type,int,S_IRUGO);
