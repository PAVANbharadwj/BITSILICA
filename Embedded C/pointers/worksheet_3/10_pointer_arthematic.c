#include <stdio.h>
struct Peripheral
{
    int status;
    int control;
    int data;
};
int main(void)
{
    struct Peripheral regs[5];   
    struct Peripheral *ptr = regs;  
    for (int i = 0; i < 5; i++)
    {
        (ptr + i)->status  = i;
        (ptr + i)->control = i + 10;
        (ptr + i)->data    = (i + 1) * 100;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Reg[%d]: status=%u, control=%u, data=%u\n",
               i, (ptr + i)->status, (ptr + i)->control, (ptr + i)->data);
    }
}
