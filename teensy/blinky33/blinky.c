#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "usb_debug_only.h"
#include "print.h"


// Teensy 2.0: LED is active high
#if defined(__AVR_ATmega32U4__) || defined(__AVR_AT90USB1286__)
#define LED_ON1		(PORTB |= (1<<4))
#define LED_OFF1		(PORTB &= ~(1<<4))
#define LED_ON2		(PORTB |= (1<<5))
#define LED_OFF2		(PORTB &= ~(1<<5))
#define LED_ON3		(PORTB |= (1<<6))
#define LED_OFF3		(PORTB &= ~(1<<6))

// Teensy 1.0: LED is active low
#else
#define LED_ON	(PORTD &= ~(1<<6))
#define LED_OFF	(PORTD |= (1<<6))
#endif

#define LED_CONFIG1	(DDRB |= (1<<4))
#define LED_CONFIG2	(DDRB |= (1<<5))
#define LED_CONFIG3	(DDRB |= (1<<6))
#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))
#define DIT 80		/* unit time for morse code */


int main(void)
{
    // set for 16 MHz clock, and make sure the LED is off
    CPU_PRESCALE(0);
    LED_CONFIG1;
    LED_CONFIG2;
    LED_CONFIG3;
    LED_OFF1;
    LED_OFF2;
    LED_OFF3;

    // initialize the USB, but don't want for the host to
    // configure.  The first several messages sent will be
    // lost because the PC hasn't configured the USB yet,
    // but we care more about blinking than debug messages!
    usb_init();

    // blink morse code messages!
    while (1) {
        LED_ON1;
        _delay_ms(1500);
        LED_OFF1;
        LED_ON2;
        _delay_ms(1500);
        LED_OFF2;
        LED_ON3;
        _delay_ms(1500);
        LED_OFF3;
    }
}
