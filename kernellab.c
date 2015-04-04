/*
 * Kernellab
 */
#include <linux/types.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>

#include "pidinfo.h"

/* Part I */
static ssize_t kcurrent_write(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{

        /* Your code here. */
	int errno;
	int current_pid = (int)current->pid;
	
	void* dest;
	sscanf(buf, "%s", (char*)&dest);
	printk("buf: %s\n", buf);
	printk("pid: %d\n", current_pid);
	printk("dest: %p\n", dest);
	if((errno = copy_to_user(dest, (void*)&current_pid, sizeof(pid_t))) < 0)
		return -EFAULT;
	
  	return count;
}

static struct kobj_attribute kcurrent_attribute =
	__ATTR(kcurrent, 0220, NULL, kcurrent_write);


/* Part II */
static ssize_t pid_write(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
 
       /* Your code here. */

  	return count;
}

static struct kobj_attribute pid_attribute =
	__ATTR(pid, 0220, NULL, pid_write);

/* Setup  */
static struct attribute *attrs[] = {
	&kcurrent_attribute.attr,
	&pid_attribute.attr,
	NULL,
};
static struct attribute_group attr_group = {
	.attrs = attrs,
};

static struct kobject *kernellab_kobj;

static int __init kernellab_init(void)
{

	struct task_struct *task;
	int retval;
	printk("kernellab module INJECTED\n");
	for_each_process(task) {
		if(task->pid == 1)
			printk("Command: %s\n", task->comm);
	}

	kernellab_kobj = kobject_create_and_add("kernellab", kernel_kobj);
	if (!kernellab_kobj)
		return -ENOMEM;

	retval = sysfs_create_group(kernellab_kobj, &attr_group);
	if (retval) 
		kobject_put(kernellab_kobj);
	return retval;
}

static void __exit kernellab_exit(void)

{
	printk("kernellab module UNLOADED\n");

	kobject_put(kernellab_kobj);
}

module_init(kernellab_init);
module_exit(kernellab_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Student Studentson <student14@ru.is");
MODULE_AUTHOR("Student Secondson <student13@ru.is");
