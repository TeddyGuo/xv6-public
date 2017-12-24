#ifndef __XV6_SIGNAL
#define __XV6_SIGNAL

#include "types.h"
#include "user.h"
#include "stat.h"

#define SIGFPE 0

typedef void (*sighadler_t)(int);

int signal(int signum, sighadler_t handler);

#endif