#include "display.h"

void app_main(void)
{
    usb_host_init();

    if (display_detect()) {
        display_init();
        display_write_line(0, "PadBeacon boot");
    }

    ble_init();

    while (1) {
        gamepad_state_t st = {0};
        usb_poll(&st);

        if (st.connected) {
            ble_send_gamepad_report(&st);
        }

        if (st.connected && s_present) {
            display_write_line(1, "USB OK");
        }

        vTaskDelay(pdMS_TO_TICKS(16));
    }
}

#include "usb_host.h"
#include "ble_output.h"
#include "gamepad.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void) {
    usb_host_init();
    ble_init();

    while (1) {
        gamepad_state_t state = {0};
        usb_poll(&state);
        if (state.connected) {
            ble_send_gamepad_report(&state);
        }
        vTaskDelay(pdMS_TO_TICKS(16));  // ~60Hz
    }
}
