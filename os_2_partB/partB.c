#include<stdio.h>
#include<unistd.h>
#include<linux/unistd.h>
#include<linux/time.h>
#define _NR_SYS_MY_XTIME 326
int main(){
struct timespec current_time;
int ret;
ret = syscall(_NR_SYS_MY_XTIME,&current_time);
printf("The ret value is :%d\n",ret);
printf("the use-level time is %ld\n",current_time.tv_nsec);
return 0;
}


