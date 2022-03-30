#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include "fpioa.h"

#define PIN_RGB_R (6)
#define PIN_RGB_G (7)
#define PIN_RGB_B (8)

#define RGB_R_GPIONUM (0)
#define RGB_G_GPIONUM (1)
#define RGB_B_GPIONUM (2)

#define FUNC_RGB_R (FUNC_GPIOHS0 + RGB_R_GPIONUM)
#define FUNC_RGB_G (FUNC_GPIOHS0 + RGB_G_GPIONUM)
#define FUNC_RGB_B (FUNC_GPIOHS0 + RGB_B_GPIONUM)

#define PIN_LED_0 (0)
#define PIN_LED_1 (17)

#define LED0_GPIONUM (0)
#define LED1_GPIONUM (1)

#define FUNC_LED0 (FUNC_GPIO0 + LED0_GPIONUM)
#define FUNC_LED1 (FUNC_GPIO0 + LED1_GPIONUM)

#endif // PIN_CONFIG_H