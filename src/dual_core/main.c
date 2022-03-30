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

#include <stdio.h>
#include "bsp.h"
#include "sleep.h"
#include "sysctl.h"

int core1_main(void *ctx)
{
    int state = 1;
    uint64_t core = current_coreid();
    printf("Core %ld say: Hello Core1\n", core);

    while(1)
    {
        msleep(500);
        if(state = !state)
        {
            printf("Core %ld is running too!\n", core);
        } else
        {
            printf("Core %ld is running faster!\n", core);
        }
    }
}

int main(void)
{
    uint64_t core = current_coreid();

    printf("Core %ld say: Hello Core0\n", core);

    register_core1(core1_main, NULL);

    while(1)
    {
        sleep(1);
        printf("Core %ld is running\n", core);
    }

    return 0;
}
