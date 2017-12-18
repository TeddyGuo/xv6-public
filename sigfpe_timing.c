#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

static int count = 0;

void signal_handler(int signum)
{
    if (count < 10000)
    {
        count++;
        printf(1, "count = %d", count);
        __asm__("mov  0x4(%ebp), %eax");
        __asm__("mov  %eax, 0x8(%ebp)");
        __asm__("mov  0x0(%ebp), %eax");
        //__asm__("mov  %eax, 0x4(%ebp)");
        __asm__("addl $0x4, %ebp");
    }
    else
    {
        __asm__("addl $0x8, 0x4(%ebp)");
    }
}

int main(int argc, char* argv[])
{
    int x = 1;
    int y = 0;
    uint tick1 = 0;
    uint tick2 = 0;
    uint tickr = 0;
    uint rtime = 0;

    // tick1 = uptime();

    signal(SIGFPE, signal_handler);

    tick1 = uptime();

    x /= y;

    tick2 = uptime();

    tickr = tick2 - tick1;

    rtime = tickr / count * 10000;

    printf(1, "Traps performed = %d\n", count);
    printf(1, "Total elapsed time: %d\n", tickr * 10000);
    printf(1, "Average time per traps: %d us\n", rtime);

    exit();
}