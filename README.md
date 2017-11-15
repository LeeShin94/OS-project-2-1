# OS-project-2-1
create a system call to verify valid address

System call file: isReadable.c
One can test the system call by executing a simple c file that calls the system call.
After execution, use dmesg to check what is being executed in kernel space.
The full code is in main.c file.
One can also call cat /proc/[pid]/maps to see the access permissions of the virtual memory address space. This method is to let the kernel go through the linked list of VMA of the process and print out each one.e.g. x-executable, r-readable, w-writable

During the construction of system call, some founded API can be used to allocate memory in user space:
  access_ok		        Checks the validity of the user space memory pointer
  get_user		        Gets a simple variable from user space
  put_user		        Puts a simple variable to user space
  clear_user		      Clears a block in user space
  copy_to_user	      Copies a block from user space to kernel
  strlen_user		      Gets the size of a string buffer in user space
  strncpy_from_user	  Copies a string from user space into the kernel
