// main/ble_output.c
#include "ble_output.h"
#include <stdio.h>

void ble_init(void) {
    printf("BLE HID initialized (stub)\n");
}

void ble_send_gamepad_report(const gamepad_state_t *state) {
    printf("BLE Report → LX=%d LY=%d Buttons=0x%04X\n",
        state->lx, state->ly, state->buttons);
}
