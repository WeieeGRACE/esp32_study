#ifndef _exit_h_
#define _exit_h_

#include "driver/gpio.h"
#include "esp_system.h"
#include "led.h"

#define BOOT_INT_GPIO_PIN GPIO_NUM_0

#define BOOT gpio_get_level(BOOT_INT_GPIO_PIN)

void Exit_init(void);

#endif