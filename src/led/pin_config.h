#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include "fpioa.h"

#define PIN_LED_0 (0)
#define PIN_LED_1 (17)

#define LED0_GPIONUM (0)
#define LED1_GPIONUM (1)

#define FUNC_LED0 (FUNC_GPIO0 + LED0_GPIONUM)
#define FUNC_LED1 (FUNC_GPIO0 + LED1_GPIONUM)

#endif // PIN_CONFIG_H