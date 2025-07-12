#include "display.h"

bool display_detect(void) { return false; }
void display_init(void) {}
void display_write_line(int line, const char *text) {
    (void)line;
    (void)text;
}
