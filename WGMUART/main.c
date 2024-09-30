#include <avr/io.h>
#include <avr/pgmspace.h>
#include "wgmuart.h"
const int LED = 4;
void main() {
    WGMUART_init();
    DDRB |= 1<<LED;
    prints_P(PSTR("\nwgmUART echo\n"));
    const unsigned ovf_per_sec = F_CPU / PRESCALER / 256;
    unsigned overflows = 0;
    while (1) {
        if ( WGMUART_data_ready() ) {
            //_delay_ms(500);             // for rx FIFO testing
            WGMUART_putch( WGMUART_getch() ); 
        }
        if (TIFR & 1<<TOV0) {
            TIFR = 1<<TOV0;             // clear overflow flag
            overflows++;
        }
        // write a dot and toggle LED every second
        if ( overflows == (ovf_per_sec) ) {
            overflows = 0;
            WGMUART_putch('.');
            PINB |= 1<<LED;
        }
    }
}
