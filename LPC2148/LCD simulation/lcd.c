#include <lpc214x.h>

#define LCD_DATA_DIR IO1DIR
#define LCD_DATA_SET IO1SET
#define LCD_DATA_CLR IO1CLR
#define LCD_CTRL_DIR IO0DIR
#define LCD_CTRL_SET IO0SET
#define LCD_CTRL_CLR IO0CLR

#define RS (1 << 16)   // P0.16
#define RW (1 << 17)   // P0.17
#define EN (1 << 18)   // P0.18

void delay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 500; j++);
}

void lcd_cmd(unsigned char cmd)
{
    LCD_DATA_CLR = 0x00FF0000;
    LCD_DATA_SET = (cmd << 16);
    LCD_CTRL_CLR = RS;    // RS=0 for command
    LCD_CTRL_CLR = RW;    // RW=0 for write
    LCD_CTRL_SET = EN;
    delay(1);
    LCD_CTRL_CLR = EN;
    delay(5);
}

void lcd_data(unsigned char data)
{
    LCD_DATA_CLR = 0x00FF0000;
    LCD_DATA_SET = (data << 16);
    LCD_CTRL_SET = RS;    // RS=1 for data
    LCD_CTRL_CLR = RW;    // RW=0 for write
    LCD_CTRL_SET = EN;
    delay(1);
    LCD_CTRL_CLR = EN;
    delay(5);
}

void lcd_init(void)
{
    LCD_DATA_DIR |= 0x00FF0000;   // P1.16 - P1.23 as output
    LCD_CTRL_DIR |= RS | RW | EN; // Control pins as output

    delay(20);
    lcd_cmd(0x38);  // 8-bit, 2 line, 5x7
    lcd_cmd(0x0C);  // Display ON, Cursor OFF
    lcd_cmd(0x06);  // Auto increment
    lcd_cmd(0x01);  // Clear display
    delay(10);
}

void lcd_string(char *str)
{
    while (*str)
    {
        lcd_data(*str++);
    }
}

int main(void)
{
    lcd_init();
    lcd_cmd(0x80);               // 1st line start
    lcd_string("LPC2148 LCD DEMO");
    lcd_cmd(0xC0);               // 2nd line start
    lcd_string("Hello World");

    while (1);
}
