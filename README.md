# Custom_Kernel
NAME
    my_syslog -- kernel syslog system call
    mysyslog -- command line interface to my_syslog
    
SYNOPSIS
    takes a string argument, and kernel syslogs th string

DESCRIPTION
    The my_syslog takes a string argument, and kernel syslogs the argument. 
    It always returns 0.
    
    The mysyslog command calls my_syslog on the first argument.
---------------------------------------------------------------------------------------------------------------------------
NAME
    rb_ioctl, rb_enqueue, rb_dequeue -- ring buffer syscalls
    ringbuf -- command line interface to the rb_* system calls
    
SYNOPSIS
    rb_enqueue enqueues characters to a single, in-kernel ring buffer; re_dequeue 
    dequeues an enqueued character. rb_ioctl implements the control functions return
    if the queue is empty or full, depending on the control argument.

DESCRIPTION
    The rb_enqueue syscall takes a single character argument and returns the argument
    if the character can be enqueued, -1 else. For instance, it will return -1 if the
    ring buffer is full. 
    
    The rb_dequeue syscall takes no arguments are returns a single integer value, which
    is the dequeued character, -1 else. For instance, if will return -1 if the ring 
    buffer is empty.
    
    The rb_ioctl takes an integer argument giving the operation, as follows:
    
    Argument value:
      0 - return the size of the ring buffer.
    	1 - return 1 if ring buffer is empty, 0 else.
    	2 - return 1 if ring buffer is full, 0 else.
    	3 - return the current number of characters in the ring buffer
	
    On error, or an invalid argument value, return -1.
	
    The ring buffer is of fixed size. The kernel needs to be rebuilt if the ring buffer 
    is to be of a different size.
