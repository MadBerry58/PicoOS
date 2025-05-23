#include "canIf.h"
#include <stdint.h>
#include "hardware/spi.h"

typedef struct canController
{
    uint8_t   csPin;
    uint8_t   clkPin;
    uint8_t   misoPin;
    uint8_t   mosiPin;
    uint8_t   frequencyMhz;
    uint32_t  baudrate;
};

uint8_t setupCanController( uint8_t csPin,        uint8_t   clkPin, 
                            uint8_t misoPin,      uint8_t   mosiPin, 
                            uint8_t frequencyMhz, uint32_t  baudrate
                          )
{
    spi_init          (spi_default, frequencyMhz * 1000 * 1000);
    gpio_set_function (misoPin, GPIO_FUNC_SPI);
    gpio_init         (csPin);
    gpio_set_function (clkPin,  GPIO_FUNC_SPI);
    gpio_set_function (mosiPin, GPIO_FUNC_SPI);
}