/*
 */

#include <avr/io.h>
#include"Act1.h"
#include"Act2.h"
#include"Act3.h"
#include<util/delay.h>


int main(void)
{

    LCD_INITIALIZATION();

    while(1)


    Act1();
    Act2();
    Act3();




    return 0;
}
