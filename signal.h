#ifndef __XV6_SIGNAL
#define __XV6_SIGNAL
#define _sigfpe_firstest
#define _sigfpe_timing
#define _sigfpe_secondtest

#define SIGFPE 0

typedef void (*sighadler_t)(int);

int signal(int signum, sighadler_t handler);

#endif