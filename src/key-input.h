#ifndef KEY_INPUT_H
#define KEY_INPUT_H
#include <stdint.h>


typedef enum {
    GPIO_PORT_INPUT = 0,
    GPIO_PORT_OUTPUT = 1
} GPIODirection;

typedef struct {
    uint8_t port;
    uint8_t number;
    GPIODirection isOutputPort;
    uint8_t hid_key;
} PortData;


extern const PortData PortC0;


void key_input_init_gpio_all_pins();
int  key_input_read_gpio_pin(PortData port);
void key_input_write_gpio_pin(PortData port, int value);

int key_input_update_keys(volatile uint8_t keys[], unsigned int length);


#endif
