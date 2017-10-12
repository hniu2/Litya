#include <linux/linkage.h>
#include <linux/export.h>
#include <linux/time.h>
#include <asm/uaccess.h>
#include <linux/printk.h>
#include <linux/slab.h>
asmlinkage int sys_my_xtime(struct timespec *current_time)
{
	struct timespec flag;
	if(!access_ok(VERIFY_WRITE,current_time,sizeof(struct timespec)))
	{return -EFAULT;}
	else
	{
	flag=current_kernel_time();
	copy_to_user(current_time,&flag,sizeof(struct timespec));
	printk("The time is %ld\n",flag.tv_nsec);
	}
 return 0;
}
EXPORT_SYMBOL(sys_my_xtime);
