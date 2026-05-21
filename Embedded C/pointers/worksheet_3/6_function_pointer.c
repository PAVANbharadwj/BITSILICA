#include <stdio.h>
void init(void)  
{
     printf("Device Initialized\n");
}
void start(void)
{
     printf("Device Started\n");
}
void stop(void) 
{
     printf("Device Stopped\n");
}
void (*cmd_table[])(void) = { init, start, stop };
int main(void)
{
    int cmd;

    printf("Enter command (0 = init, 1 = start, 2 = stop): ");
    scanf("%d", &cmd);
    if (cmd >= 0 && cmd < 3)
        cmd_table[cmd](); 
    else
        printf("Invalid command\n");
}

