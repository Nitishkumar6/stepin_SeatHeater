#include<avr/io.h>
#include<util/delay.h>
#include"Act1.h"

void Act1()
{

    DDRD &= ~(1<<PD0);   //INPUT PIN FOR PORTD PIN0
    DDRD &= ~(1<<PD1);   //INPUT PIN FOR PORTD PIN1

        PORTD |= (1<<PD0); // LOGIC HIGH FOR INPUT PINS
        PORTD |= (1<<PD1); //LOGIC HIGH FOR INPUT PINS


        DDRB |= (1<<PB0); //OUTPUT PIN FOR PORTB PIN0

        if ( ( ! (PIND & (1<<PD0)))  & (!(PIND &(1<<PD1))))
        {

            PORTB |= (1<<PB0); //TURNS THE LED ON IF BOTH SWITCHES ARE Off
            _delay_ms(1000);
        }
        else
            {
            PORTB &= ~(1<<PB0); // LED IS OFF
            _delay_ms(1000);
        }
}

