#include <stdio.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BLINK_GPIO GPIO_NUM_13

static uint8_t s_led_state = 0;

void app_main(void)
{
  gpio_reset_pin(BLINK_GPIO);
  gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
  gpio_set_level(BLINK_GPIO, 1);
  while (1) {
    gpio_set_level(BLINK_GPIO, s_led_state);
    s_led_state = !s_led_state; 
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
