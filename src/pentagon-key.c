#include "ch32fun.h"
#include "rv003usb.h"
#include "ch32v003_GPIO_branchless.h"
#include "key-input.h"


volatile uint8_t KeyInput[2][8] = { { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                                    { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 } };
volatile uint8_t KeyInputIndex = 0;

int main()
{
	SystemInit();
	Delay_Ms(100); // Ensures USB re-enumeration after bootloader or reset; Spec demand >2.5µs ( TDDIS )

    key_input_init_gpio_all_pins();
	usb_setup();
    
	while (1)
	{
        uint8_t writeIndex = KeyInputIndex ^ 1;
        if (key_input_update_keys(KeyInput[writeIndex], 8) > 0)
            key_input_write_gpio_pin(PortC0, 1);
        else
            key_input_write_gpio_pin(PortC0, 0);

        KeyInputIndex = writeIndex;

        Delay_Ms(8);
	}
}


void usb_handle_user_in_request( struct usb_endpoint * e, uint8_t * scratchpad, int endp, uint32_t sendtok, struct rv003usb_internal * ist )
{
    uint8_t send_data[8];

	if (endp == 1)
	{
        for(uint8_t k=0 ;k<8; k++)
            send_data[k] = KeyInput[KeyInputIndex][k];
        
		usb_send_data(send_data, 8, 0, sendtok);
    } else {
		usb_send_empty(sendtok);
	}
}
