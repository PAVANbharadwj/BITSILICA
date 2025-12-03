#ifndef __DS1307_H__
#define __DS1307_H__

void DS1307_SetTime(unsigned char h, unsigned char m, unsigned char s);
void DS1307_GetTime(unsigned char *h, unsigned char *m, unsigned char *s);

#endif
