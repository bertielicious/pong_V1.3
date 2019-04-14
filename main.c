/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 04 March 2019, 19:24
 * 
1) Keep your pull requests small and digestible
2) Write a design doc before coding to save time and prevent spaghetti code
3) Keep your eye on the end goal (i.e. shipping products) and don't surf reddit at work ¯\_(?)_/¯
4) Lose the ego and arrogance, don't be afraid to ask questions, and don't try to write "clever" unintelligible code
5) Respect The Tech Lead, buy them coffee or they'll get you fired?
 */
/* Design document for Pong game
 * This version of pong is a one (human) player game (LHS) who plays against the PIC microcontroller (RHS). Whenever the puck is successfully returned, 
 * one point is scored. When the puck is missed and goes out of play behind the paddle, a point is deducted from that player. 
 * Whoever is the first player to reach 10 is the winner. If the puck is returned from the top or bottom of the paddle, the angle of the deflected ball is 45 deg.
 * If the puck is returned from the middle area of the paddle, the angle of the return is 180 deg. The puck can only rebound from the top or bo ttom walls, 
 * not from the wall at extreme left or right of the screen. The game starts whenever the human moves the paddle for the first time.
 */

#include "config.h"
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "lcdWrite.h"
#include "clear_screen.h"



void main(void) 
{
   uchar puck = 0xff; 
    uchar i, j ,k, x, y;  
    uchar x_offset = 6;
    uchar setx = 0;
    uchar sety = 0x40;
    config_osc();
    setup_ports();
    init_spi();
    
    
    RST = LOW;
    __delay_ms(1);
    RST = HIGH;
    
    lcdWrite(FUNC_SET_EXTEND, LOW); // function set command LCD active, Horiz mode, extended instruction set
    lcdWrite(LCD_CONTRAST, LOW); // set LCD Vop contrast
    lcdWrite(LCD_TEMP_COEFF, LOW); // set temp coefficient
    lcdWrite(LCD_BIAS, LOW); // LCD bias mode
    lcdWrite(BASIC_IS, LOW); // LCD basic instruction set
    lcdWrite(NORMAL_MODE, LOW); // normal display mode
    
    lcdWrite(SET_Y, LOW);       // sets address at top LH corner (origin) of LCD)
    lcdWrite(SET_X|0x00, LOW);
    lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
    
    clear_screen();             // clears any random data presented on the LCD at power on
    
    // Vertical line LHS
   /* lcdWrite(VERT_ADDR, LOW);   // vertical addressing mode
    lcdWrite(SET_Y, LOW);       // sets address at top LH corner (origin) of LCD)
    lcdWrite(SET_X, LOW);
    for( j = 0; j < 6 ; j++)    // draw vertical line at column 0
    {
      lcdWrite(puck, HIGH);     // writes a byte of 1's to LCD (--------)
      __delay_ms(100);
    }
     // Vertical line RHS
    lcdWrite(SET_X|0x53, LOW);  // draw vert line at column 83 (0x53))
    //lcdWrite(SET_X|0x29, LOW);
    for( j = 0; j < 6 ; j++)
    {
      lcdWrite(puck, HIGH);
      __delay_ms(100);
    }
     // Horizontal line top of screen
    lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
    lcdWrite(SET_X, LOW);
    for (i = 1; i < 83; i++)
    {     
            lcdWrite(SET_X|i, LOW);
            lcdWrite(0x01, HIGH);
    }
    
    // Horizontal line bottom of screen
    lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
    lcdWrite(SET_Y|0x05, LOW);
    for (i = 1; i < 83; i++)
    {     
            lcdWrite(SET_X|i, LOW);
            lcdWrite(0x80, HIGH);
    }*/
    
   /* Diagonal line*/ 
    for (y = 0; y < 6; y++)
    {   
        lcdWrite(VERT_ADDR, LOW);   // vertical addressing mode
       // lcdWrite(SET_Y|y, LOW);       // sets address at top LH corner (origin) of LCD
        lcdWrite(sety|y, LOW);       // sets address at top LH corner (origin) of LCD)
        for (x= 0; x <8; x++)
        {
             lcdWrite(HORIZ_ADDR, LOW);  // horizontal addressing mode
            // lcdWrite(SET_X|x, LOW);
             lcdWrite(setx|x, LOW);
             lcdWrite(0x01<<x, HIGH);
        }  
    }
    
    
    
    while(1)
    {
        
    }
}