/*
 * mysyslog.c
 *
 * implements the mysyslog command, taking the command line argument and sending it
 * to the syslog using our new my_syslog system call.
 *
 * author: Jorge Banegas
 * created: Oct 18 2017
 * updated: Oct 20 2017
 *
 * returns the error value of syscall and command result
 *
 */
 
#include<unistd.h>
#include<stdio.h>
#include "mysyscalls.h"

#define USAGE "mysyslog _message_"

int main(int argc, char * argv[]) {
	if (argc!=2) {
		printf("%s\n", USAGE) ;
		return 0 ;
	}
	return syscall(MY_SYSLOG, argv[1]) ;
}

