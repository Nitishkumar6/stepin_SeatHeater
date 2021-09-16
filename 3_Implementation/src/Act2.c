#include <avr/io.h>
#include "Act2.h"
#define _Act1_h_
#include <util/delay.h>
void LCD_CMD( unsigned char command)
{

    PORT_B = (PORT_B & 0X0F) | ( command & 0XF0);
    PORT_B &= ~(1<<LCD_RS);
    PORT_B |= (1<<LCD_EN);
    _delay_us(5);
    PORT_B &= ~(1<<LCD_EN);
    _delay_us(250);

    PORT_B = (PORT_B & 0X0F) | ( command<<4);
    PORT_B |=(1<<LCD_EN);
    _delay_us(5);
    PORT_B &= ~(1<<LCD_EN);
    _delay_ms(50);
}
 void LCD_CHAR_WISE(unsigned char ch)
 {

     PORT_B = (PORT_B & 0X0F) | (ch & 0XF0);
     PORT_B |=(1<<LCD_RS);
     PORT_B |= (1<<LCD_EN);
     _delay_us(5);
     PORT_B &= ~(1<<LCD_EN);

     _delay_us(250);
     PORT_B = (PORT_B & 0X0F) | (ch<<4);
     PORT_B |= (1<<LCD_EN);
     _delay_us(5);
     PORT_B &= ~(1<<LCD_EN);
     _delay_ms(50);
 }
 void LCD_INITIALIZATION(void)
 {

     LCD_DIRECTION =0XFF;
     _delay_ms(50);
     LCD_CMD(0x02);
     LCD_CMD(0x28);
     LCD_CMD(0x0c);
     LCD_CMD(0x06);
     LCD_CMD(0x01);

     _delay_ms(5);
 }
 void LCD_DISPLAY (char *temperature_value)
 {
     int Index;
     for(Index=0;temperature_value[Index]!=0;Index++)
     {
         LCD_CHAR_WISE(temperature_value[Index]);
     }
 }
 void CLEAR_LCD()
 {
     LCD_CMD (0x01);
     _delay_ms(50);
     LCD_CMD(0x80);
 }
 void InitADC()
 {
     ADMUX=(1<<REFS0);
     ADCSRA=(1<<ADEN)| (7<<ADPS0);
 }
 uint16_t ReadADC(uint8_t ch)
 {
     ADMUX&=0xF8;
     ch=ch&0b00000111;
     ADMUX|=ch;
     ADCSRA|=(1<<ADSC);
     while(!(ADCSRA & (1<<ADIF)));
     ADCSRA|=(1<<ADIF);
     return (ADC);
 }
 void Act2()
 {
     InitADC();
     uint16_t temp=0;
     temp=ReadADC(0);
     _delay_ms(200);
 }
