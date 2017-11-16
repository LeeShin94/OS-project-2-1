#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/mm.h>

asmlinkage long sys_isReadable(char* p){
	struct vm_area_struct *vma = find_vma(get_current()->mm, (unsigned long)p);
	if ((vma->vm_flags & VM_READ) == VM_READ){
		printk("READ");	
		return 0;
	}
	if ((vma->vm_flags & VM_EXEC) == VM_EXEC){
		printk("EXEC");	
		return 0;
	}
	printk("No safe reading");
	return -1;
}
