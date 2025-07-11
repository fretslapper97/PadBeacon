// main/ble_output.h
#pragma once
#include "gamepad.h"

void ble_init(void);
void ble_send_gamepad_report(const gamepad_state_t *state);
