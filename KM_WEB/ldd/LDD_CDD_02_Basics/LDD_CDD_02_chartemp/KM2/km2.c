#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/fs.h>

int km2_open (struct inode *, struct file *);
ssize_t km2_read (struct file *, char __user *, size_t, loff_t *);
ssize_t km2_write (struct file *, const char __user *, size_t, loff_t *);
int km2_close (struct inode *, struct file *);

struct file_operations km2_ops = {
	.open = km2_open,
	.read = km2_read,
	.write = km2_write,
	.release = km2_close,
}; 

int km2_open (struct inode *fptr, struct file *fptr2)
{
	printk("This is km2_open function\n");
	return 0;
}
ssize_t km2_read (struct file *fptr1, char __user *fptr2, size_t len, loff_t *fptr3)
{
	printk("This is km2_read function\n");
	return 0;
}
ssize_t km2_write (struct file *fptr1, const char __user *fptr2, size_t len, loff_t *fptr3)
{
	printk("This is km2_write function\n");
	return len;

}
int km2_close (struct inode *fptr1, struct file *fptr2)
{
	printk("This is km2_close function\n");
	return 0;
}

static int km2_init(void) {
	int ret;
	printk ("This is km2 init function\n");
	ret = register_chrdev(61,"km2",&km2_ops);
	if (ret != 0)
	return -1;

	return 0;
}


static void km2_exit(void) {
	printk ("This is km2 exit function\n");
	unregister_chrdev(61,"km2");

}

module_init(km2_init);
module_exit(km2_exit);
