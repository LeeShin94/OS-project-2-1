#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/types.h>

#include "isReadable.h"

asmlinkage int sys_isReadable(char *p){
	if(current==NULL){
		return -1;
	}
	struct mm_struct *mm = current->mm;
	if(mm == NULL){
		return -1;
	}
	struct vm_area_struct *mmap = mm->mmap;
	while (mmap != NULL){
		if((unsigned long)p>=mmap->vm_start && (unsigned long)p<=mmap->vm_end){
			if(((mmap->vm_flags & VM_READ)||(mmap->vm_flags & VM_EXEC))&&((mmap->vm_flags & VM_IO) == 0)){
				return 0;
			}else{
				return -1;
			}
		}
		mmap = mmap->vm_next;
	}
	return -1;
}
