#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/fs.h>

int km1_open (struct inode *, struct file *);
ssize_t km1_read (struct file *, char __user *, size_t, loff_t *);
ssize_t km1_write (struct file *, const char __user *, size_t, loff_t *);
int km1_close (struct inode *, struct file *);

struct file_operations km1_ops = {
	.open = km1_open,
	.read = km1_read,
	.write = km1_write,
	.release = km1_close,
}; 

int km1_open (struct inode *fptr, struct file *fptr2)
{
	printk("This is km1_open function\n");
	return 0;
}
ssize_t km1_read (struct file *fptr1, char __user *fptr2, size_t len, loff_t *fptr3)
{
	printk("This is km1_read function\n");
	return 0;
}
ssize_t km1_write (struct file *fptr1, const char __user *fptr2, size_t len, loff_t *fptr3)
{
	printk("This is km1_write function\n");
	return len;

}
int km1_close (struct inode *fptr1, struct file *fptr2)
{
	printk("This is km1_close function\n");
	return 0;
}

static int km1_init(void) {
	int ret;
	printk ("This is km1 init function\n");
	ret = register_chrdev(60,"km1",&km1_ops);
	if (ret != 0)
	return -1;

	return 0;
}


static void km1_exit(void) {
	printk ("This is km1 exit function\n");
//	unregister_chrdev(61,"km1");

}

module_init(km1_init);
module_exit(km1_exit);


