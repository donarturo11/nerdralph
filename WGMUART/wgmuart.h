#ifndef WGMUART_H
#define WGMUART_H

#ifndef BAUD_RATE
#define BAUD_RATE 57600
#endif

/* GPIO for receive */
#define WGMRXBIT    1
#define WGMRXPORT   PORTB
#define WGMRXPIN    PINB

/* GPIO for transmit (OC0A) */
#ifndef OC0A_BIT
#define OC0A_BIT    PB0
#define OC0A_DDR    DDRB
#define OC0A_PORT   PORTB
#endif

#ifndef PCMSK
#define PCMSK PCMSK0
#define PCIE PCIE0
#endif

#ifndef TIMSK
#define TIMSK TIMSK0
#define TIFR TIFR0
#endif
#ifndef PRESCALER
#define PRESCALER 8L
#endif
#ifndef __ASSEMBLER__
void WGMUART_init();
void WGMUART_putch(uint8_t c);
void prints_P(const __flash char* s);
uint8_t WGMUART_getch();
// returns true when there is data to read
uint8_t WGMUART_data_ready();
#endif // __ASSEMBLER__
#endif // WGMUART_H

