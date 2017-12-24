#ifndef _SIGNAL_H
#define _SIGNAL_H

#define SIGFPE 0

typedef void (*sighandler_t)(int);

int signal(int signum, sighandler_t handler);

#endif