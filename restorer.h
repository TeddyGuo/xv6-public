// TeddyGuo

void restorer(void)
{
    __asm__("pop %ebp");
    __asm__("pop %edx");
    __asm__("pop %edx");
    __asm__("pop %ecx");
    __asm__("pop %eax");
    __asm__("ret");

}