#ifndef __SIGNAL_H
#define __SIGNAL_H

#define SIGFPE 0

typedef void (*sighandler_t)(int);

int signal(int signum, sighandler_t handler);

#endif