#include "key-input.h"
#include "rv003usb.h"
#include "ch32v003_GPIO_branchless.h"


#define KEY_MAP_LEFT
// #define KEY_MAP_MIDDLE
// #define KEY_MAP_RIGHT
// #define KEY_MAP_MOD_TEST

#if defined(KEY_MAP_LEFT)
  #include "keymap/left.c"
#elif defined(KEY_MAP_MIDDLE)
  #include "keymap/middle.c"
#elif defined(KEY_MAP_RIGHT)
  #include "keymap/right.c"
#elif defined(KEY_MAP_MOD_TEST)
  #include "keymap/mod-test.c"
#endif

const PortData PortC0 = { GPIO_port_C, 0, GPIO_PORT_OUTPUT, 0 };


static void gpio_init_pin(PortData port) {
    if (port.isOutputPort)
        GPIO_pinMode(GPIOv_from_PORT_PIN(port.port, port.number),
                     GPIO_pinMode_O_pushPull,
                     GPIO_Speed_10MHz);
    else
        GPIO_pinMode(GPIOv_from_PORT_PIN(port.port, port.number),
                     GPIO_pinMode_I_pullUp,
                     GPIO_Speed_10MHz);
}

void key_input_init_gpio_all_pins()
{
    GPIO_port_enable(GPIO_port_A);
    GPIO_port_enable(GPIO_port_C);
    GPIO_port_enable(GPIO_port_D);

    gpio_init_pin(PortC0);

    for (int i=0; i<sizeof(PortList)/sizeof(PortList[0]); i++) {
        gpio_init_pin(PortList[i]);
    }
}

int key_input_read_gpio_pin(PortData port)
{
    return GPIO_digitalRead(GPIOv_from_PORT_PIN(port.port, port.number));
}

void key_input_write_gpio_pin(PortData port, int value)
{
    if (value) 
        GPIO_digitalWrite(GPIOv_from_PORT_PIN(port.port, port.number), high);
    else
        GPIO_digitalWrite(GPIOv_from_PORT_PIN(port.port, port.number), low);
}

static uint8_t generateModifierBit(uint8_t hidKey)
{
    if ((hidKey < 0xE0) || (hidKey > 0xE7))
        return 0;

    return 1 << (hidKey - 0xE0);
}

int key_input_update_keys(volatile uint8_t keys[], unsigned int length)
{
    for (int i=0; i<length; i++)
        keys[i] = 0;

    // keys[0] == modifier, keys[1] == reserved
    int inputIndex = 2;
    uint8_t modifierCount = 0;
    for (int i=0; i<sizeof(PortList)/sizeof(PortList[0]); i++) {
        if (!key_input_read_gpio_pin(PortList[i])) {
            uint8_t modifier = generateModifierBit(PortList[i].hid_key);

            if (modifier != 0) {
                keys[0] |= modifier;
                modifierCount++;
            } else if (inputIndex < length) {
                keys[inputIndex] = PortList[i].hid_key;
                inputIndex++;
            }
        }
    }

    return inputIndex + modifierCount - 2;
}
