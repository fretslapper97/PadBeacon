#pragma once

#include <stdbool.h>

// Call once at boot. Returns true if a supported display responds.
bool display_detect(void);

// Call after detect, if true. Initializes the display.
void display_init(void);

// Print text to a given line (0-based). No-op if no display.
void display_write_line(int line, const char *text);
