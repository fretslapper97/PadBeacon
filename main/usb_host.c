// main/usb_host.c
#include "usb_host.h"
#include "gamepad.h"
#include <stdio.h>

void usb_host_init(void) {
    printf("USB host initialized (stub)\n");
}

void usb_poll(gamepad_state_t *state) {
    state->lx = 127;
    state->ly = -64;
    state->buttons = 0x0004;
    state->connected = true;
}
