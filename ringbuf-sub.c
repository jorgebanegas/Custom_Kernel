#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>

#include "ringbuf.h"
#include "mysyscalls.h"

/*
 * author: Jorge Banegas
 * date: Oct 20 2017
 * pledge: this is my own work, unless otherwise noted
 *
 * 
 *
 * update: 
 */

int g_debug = 0 ;
int is_verbose = 0 ;

int rb_ioctl(int op) {
	switch (op) {
	case RB_Q_SIZE:
		return syscall(RB_IOCTL, RB_OP_SIZE);
	
	case RB_IS_EMPTY:
		return syscall(RB_IOCTL, RB_OP_ISEMPTY);
	case RB_IS_FULL:
		return syscall(RB_IOCTL, RB_OP_ISFULL);
	case RB_Q_COUNT:
		return syscall(RB_IOCTL, RB_OP_COUNT);
	default:
		return 0;
	}
}

int rb_enqueue(int ele) {
	return syscall(RB_ENQUEUE, ele);
}

int rb_dequeue(void) {
	return syscall(RB_DEQUEUE);
}

