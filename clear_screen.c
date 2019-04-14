#include "config.h"
#include "lcdWrite.h"
void clear_screen(void)
{
    uchar x, y;
    for (y = 0; y < 6; y++)
    {
        lcdWrite(SET_Y|y, LOW);
        for(x = 0; x < 84; x++)
        {
            lcdWrite(0x00, HIGH);   // clear screen
            __delay_ms(1);
        }
    }
}
