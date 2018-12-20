#include <avr/io.h>
#include <util/delay.h>

#define LED_PORT_1 PB1
#define LED_PORT_2 PB2

void blinkEm(uint8_t count);

int main() {
    DDRB |= (_BV(LED_PORT_1) | _BV(LED_PORT_2));

    while (1) {
        blinkEm(1);
    }
}

void blinkEm(uint8_t count) {
    while (count > 0) {
        PORTB |= _BV(LED_PORT_1);
        PORTB &= ~_BV(LED_PORT_2);
        _delay_ms(1000);
        PORTB &= ~_BV(LED_PORT_1);
        PORTB |= _BV(LED_PORT_2);
        _delay_ms(1000);
        PORTB &= ~_BV(LED_PORT_1);
        PORTB &= ~_BV(LED_PORT_2);
        _delay_ms(1000);
        PORTB |= _BV(LED_PORT_1);
        PORTB |= _BV(LED_PORT_2);
        _delay_ms(1000);
        PORTB &= ~_BV(LED_PORT_1);
        PORTB &= ~_BV(LED_PORT_2);
        _delay_ms(1000);
        count--;
    }
}
