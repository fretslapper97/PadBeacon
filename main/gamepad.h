// main/gamepad.h
#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int16_t lx, ly, rx, ry;
    uint16_t buttons;
    uint8_t lt, rt;
    bool connected;
} gamepad_state_t;

#endif
