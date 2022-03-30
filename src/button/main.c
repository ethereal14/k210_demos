#include "gpiohs.h"
#include "pin_config.h"
#include "plic.h"
#include "sleep.h"
#include "sysctl.h"

uint32_t g_count;

void hardware_init(void)
{
    fpioa_set_function(PIN_RGB_R, FUNC_RGB_R);
    fpioa_set_function(PIN_RGB_G, FUNC_RGB_G);
    fpioa_set_function(PIN_RGB_B, FUNC_RGB_B);
    fpioa_set_function(PIN_KEY, FUNC_KEY);
}

void rgb_all_off(void)
{
    gpiohs_set_pin(RGB_R_GPIONUM, GPIO_PV_HIGH);
    gpiohs_set_pin(RGB_G_GPIONUM, GPIO_PV_HIGH);
    gpiohs_set_pin(RGB_B_GPIONUM, GPIO_PV_HIGH);
}

void init_rgb(void)
{
    gpiohs_set_drive_mode(RGB_R_GPIONUM, GPIO_DM_OUTPUT);
    gpiohs_set_drive_mode(RGB_G_GPIONUM, GPIO_DM_OUTPUT);
    gpiohs_set_drive_mode(RGB_B_GPIONUM, GPIO_DM_OUTPUT);

    rgb_all_off();
}

int key_irq_cb(void *ctx)
{
    gpio_pin_value_t key_state = gpiohs_get_pin(KEY_GPIONUM);

    printf("IRQ The PIN is %d\n", key_state);

    uint32_t *tmp = (uint32_t *)(ctx);
    printf("count is %d\n", (*tmp)++);

    if(!key_state)
        gpiohs_set_pin(RGB_R_GPIONUM, GPIO_PV_LOW);
    else
        gpiohs_set_pin(RGB_R_GPIONUM, GPIO_PV_HIGH);

    return 0;
}

void init_key(void)
{
    gpiohs_set_drive_mode(KEY_GPIONUM, GPIO_DM_INPUT_PULL_UP);
    gpiohs_set_pin_edge(KEY_GPIONUM, GPIO_PE_BOTH);
    gpiohs_irq_register(KEY_GPIONUM, 1, key_irq_cb, &g_count);
}

int main(void)
{
    hardware_init();
    plic_init();
    sysctl_enable_irq();

    init_rgb();
    init_key();

    while(1)
        ;
    return 0;
}