#ifndef __XV6_SIGNAL
#define __XV6_SIGNAL
#define __SIGFPE_FIRSTEST
#define __SIGFPE_TIMING
#define __SIGFPE_SECONDTEST

#define SIGFPE 0

typedef void (*sighadler_t)(int);

int signal(int signum, sighadler_t handler);

#endif