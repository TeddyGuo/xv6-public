#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

void signal_handler(int signum)
{
    printf(1, "Got signal %d...\n", signum);
    
    if (signum == SIGFPE)
    {
        printf(1, "Test passed !\n");
    }
    else
    {
        printf(1, "Test failed: wrong signal sent %d\n", signum);
    }

    exit();
}
int main(int argc, char* argv[])
{
    int x = 1;
    int y = 0;

    signal(SIGFPE, signal_handler);

    x = x / y;

    exit();
}