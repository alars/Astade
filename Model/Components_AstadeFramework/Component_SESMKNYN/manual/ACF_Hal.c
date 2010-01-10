/* Implement all hardware dependend stuff here */

#include "ACF_Hal.h"
#include <stdio.h>

void ACF_tracePtr(void* x)
{
    char buffer[2*sizeof(int*)+4];
    snprintf(buffer,sizeof(buffer),"%p:",x);
    ACF_trace(buffer);
}

#ifdef LINUX

#include "stdio.h"
#include <sys/time.h>

void ACF_init(void)
{
    ACF_trace("Initialisation done!\n");
}

void ACF_trace(const char* x)
{
    printf("%s",x);
}

unsigned int ACF_getTimeTick(void)
{
    timeval time;
    gettimeofday(&time,0);
    return ((time.tv_sec*1000)+(time.tv_usec/1000)); //I want milliseconds
}

void ACF_interrupts_off()
{
}

void ACF_interrupts_on()
{
}

#endif //__LINUX__

#ifdef __AVR_ATmega128__

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <avr/iom128.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 7372800
#endif

char ACF_trace_buffer[800];
volatile unsigned int ACF_next_read = 0;
volatile unsigned int ACF_next_write = 0;
volatile unsigned int ACF_TimeCounter = 0;

ISR (USART0_UDRE_vect)
{
    if (ACF_next_read != ACF_next_write)
    {
        if (UCSR0A & (1<<UDRE))
        {
            UDR0 = ACF_trace_buffer[ACF_next_read++];
            if (ACF_next_read >= sizeof(ACF_trace_buffer))
                ACF_next_read = 0;
        }
    }
    else
        UCSR0B &= ~(1<<UDRIE0);  //Disable data register empty interrupt
}

ISR(TIMER0_COMP_vect)
{
    ++ACF_TimeCounter; 
}

const uint32_t ACF_predivtable[] = {1,8,32,64,128,256,1024};

void ACF_InitTimerTick(uint32_t uLTickFrequenz)
{
	uint8_t i;
	uint32_t teiler;

	for (i=0;i<sizeof(ACF_predivtable)/sizeof(uint32_t);i++)
	{
		teiler =((F_CPU / (uLTickFrequenz * ACF_predivtable[i])) - 1);
		if ( teiler <= 255)
		{
			OCR0 = (uint8_t) teiler;
			TCCR0 = 0x08 | (i + 1);
			return;
		}
	}
}

void ACF_USART0_Init( unsigned long baud )
{
  unsigned int ubrr = (unsigned int) (F_CPU/16uL/ (unsigned long) (baud)) - 1;    //example: ubrr should be 47 at 9600 baud!
    // Set the baud rate registers
    UBRR0H = (unsigned char) (ubrr >> 8);
    UBRR0L = (unsigned char) ubrr;
    // Enable receiver and transmitter and enable receive and transmit complete interrupts
    UCSR0B = (/*(1<<RXCIE0)|(1<<TXCIE0)|(1<<RXEN)|*/(1<<TXEN));
    // Set frame format: 8data, 1stop bit
    UCSR0C = ((0<<USBS)|(3<<UCSZ0));
}

void ACF_init(void)
{
    ACF_USART0_Init(38400);
    ACF_InitTimerTick(1000);
	TIMSK |= (1<<OCIE0); //Enable tick interrupt
  	sei();
    ACF_trace("Initialisation done!\n");
}

int8_t ACF_trace_putchar(char ch)
{
    unsigned int next = ACF_next_write + 1;
    if (next >= sizeof(ACF_trace_buffer))
        next = 0;

    if (next == ACF_next_read) // buffer full
    {
        return -1;
    }

    ACF_trace_buffer[ACF_next_write] = ch;

    ACF_next_write = next;
    
    if (UCSR0A & (1<<UDRE))
        UCSR0B |= (1<<UDRIE0);  //Enable data register empty interrupt - force interrupt trigger
        
    return 0;
}    

void ACF_trace(const char* x)
{
    while (*x)
    {
        while(ACF_trace_putchar(*x) == -1)
        ;
        x++;
    }
}

unsigned int ACF_getTimeTick(void)
{
    unsigned int ret;
    cli();
    ret = ACF_TimeCounter;
    sei();
    return ret;
}

void ACF_interrupts_off()
{
    cli();
}

void ACF_interrupts_on()
{
	sei();
}

#endif //__AVR_ATmega128__
