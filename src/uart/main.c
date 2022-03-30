/* Copyright 2018 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <string.h>
#include <sysctl.h>
#include "pin_config.h"

void hardware_init(void)
{
    fpioa_set_function(PIN_UART_USB_RX, FUNC_UART_USB_RX);
    fpioa_set_function(PIN_UART_USB_TX, FUNC_UART_USB_TX);
}

int main(void)
{
    hardware_init();

    uart_init(UART_USB_NUM);
    uart_configure(UART_USB_NUM, 115200, UART_BITWIDTH_8BIT,
                   UART_STOP_1, UART_PARITY_NONE);

    uart_set_work_mode(UART_USB_NUM, UART_NORMAL);

    char *hello = {"hello world\n"};
    char *hello1 = {"hello pc\n"};
    uart_send_data(UART_USB_NUM, hello, strlen(hello));

    char recv = 0;
    while(1)
    {
        while(uart_receive_data(UART_USB_NUM, &recv, 1))
        {
            uart_send_data(UART_USB_NUM, hello1, strlen(hello1));
        }
    }

    return 0;
}
