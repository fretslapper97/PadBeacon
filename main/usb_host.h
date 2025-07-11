// main/usb_host.h
#pragma once
#include "gamepad.h"

void usb_host_init(void);
void usb_poll(gamepad_state_t *state);
