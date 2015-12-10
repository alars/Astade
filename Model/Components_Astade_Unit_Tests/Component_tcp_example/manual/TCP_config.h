#ifndef __TCP_CONFIG_H
#  define __TCP_CONFIG_H

/**
    The maximum number of tcp drivers (port handlers) that can be registered.
*/
#define TCP_MAX_COUNT 4

/**
    The size of the tcp receive buffer
*/
#define TCP_RCV_BUFFER_SIZE 256

/**
    The size of the tcp send buffer
*/
#define TCP_SND_BUFFER_SIZE 256

#endif
