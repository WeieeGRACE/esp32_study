#include <stdio.h>
#include "led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "exit.h"
#include "gptim.h"
#include "driver/timer.h"
#include "esp_log.h"

void app_main(void)
{
    timg_config_t *timg_config = malloc(sizeof(timg_config_t));
    timg_config->clk_src = TIMER_SRC_CLK_APB;
    timg_config->timer_group = TIMER_GROUP_0;
    timg_config->timer_count_value = 0;
    timg_config->timer_idx = TIMER_0;
    timg_config->timing_time = 1 * 1000000; // 1 second
    timg_config->alarm_value = timg_config->timing_time;
    timg_config->auto_reload = TIMER_AUTORELOAD_EN;
    timg_init(timg_config);

    led_init();
    // Exit_init();

    printf("hello world\n");

    while (1)
    {

        if (timg_config->timer_count_value != 0)
        {
            ESP_LOGI("GPTIMER", "Timer count value: %llu", timg_config->timer_count_value);
            timg_config->timer_count_value = 0;
        }
        vTaskDelay(10);
    }
}