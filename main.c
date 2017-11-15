#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <syscall.h>

int readAddr(void *p, int a){
    long int result = syscall(318, p);
    //printf("system call returned %ld\n", result);
    if (result == 0){
        a = p;
        printf("%ld\n",a);
    }
}

int main()
{
    unsigned long PAGE_SIZE = 0, TASK_SIZE = 0;

    PAGE_SIZE = sysconf(_SC_PAGESIZE);
    if(sizeof(void*) == sizeof(int))// 32 bit
        TASK_SIZE = 0xc0000000UL;
    else //64 bit
        TASK_SIZE = (1UL << 47) - PAGE_SIZE;

    char *p = 0;
    for(;p< TASK_SIZE;p+= PAGE_SIZE*1024){
        int a = 0;
        readAddr(p, &a);
    }

    return 0;
}
