#include <stdio.h>
#include "led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "exit.h"

void app_main(void)
{
    led_init();
    Exit_init();

    printf("hello world\n");

    while (1)
    {

        vTaskDelay(1);
    }
}