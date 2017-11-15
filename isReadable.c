#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/mm.h>

asmlinkage long sys_isReadable(void *p){
	unsigned long ptr = (unsigned long) p;
	struct vm_area_struct *vma = find_vma(get_current()->mm, ptr);
	
	if((vma->vm_flags & VM_READ) == VM_READ){
		printk("READ");
		return 0;	
	}
	if((vma->vm_flags & VM_EXEC) == VM_EXEC){
		printk("EXEC");
		return 0;	
	}
	printk("No safe");
	return -1;
}
