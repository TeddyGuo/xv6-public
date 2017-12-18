#include "types.h"
#include "user.h"
#include "signal.h"

void signal_handler(int signum)
{
    __asm__("mov $0x0,%ecx\n\t");
        // Add my code to skip the return ip below
    __asm__("addl $0x8, $0x18(%ebp)");
}

int main(void)
{
    register int ecx asm ("%ecx");
    
    signal(-1, (sighandler_t) restorer); // Save the address of restorer function inside the kernel.
    signal(SIGFPE, signal_handler); // Register the actual signal for divide by zero.

    int x = 1;
    int y = 0;

    ecx = 1;
    x /= y;

    if (ecx == 1)
    {
        printf(1, "Test Passed: Final value of ecx is %d...\n", ecx);
    }
    else
    {
        printf(1, "Test Failed: Final value of ecx is %d...\n", ecx);
    }

    exit();
}