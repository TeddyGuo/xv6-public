#ifndef _XV6_SIGNAL
#define _XV6_SIGNAL

#define SIGFPE 0

typedef void (*sighandler_t)(int);

int signal(int signum, sighandler_t handler);

#endif