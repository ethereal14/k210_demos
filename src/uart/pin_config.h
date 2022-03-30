#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include "fpioa.h"
#include "uart.h"

#define PIN_UART_USB_RX (4)
#define PIN_UART_USB_TX (5)

#define UART_USB_NUM UART_DEVICE_3

#define FUNC_UART_USB_RX (FUNC_UART1_RX + UART_USB_NUM * 2)
#define FUNC_UART_USB_TX (FUNC_UART1_TX + UART_USB_NUM * 2)
#endif // PIN_CONFIG_H