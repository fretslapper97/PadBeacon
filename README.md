# PadBeacon

Bridge USB gamepads to Bluetooth using ESP32-S3.

## Third-Party Code & Licenses

PadBeacon uses or depends on the following third-party libraries:

- [ESP-IDF](https://github.com/espressif/esp-idf) – Apache 2.0
- [TinyUSB](https://github.com/hathach/tinyusb) – MIT License
- [ESP-NimBLE](https://github.com/espressif/esp-nimble) – Apache 2.0

License texts for these components are included in the `LICENSES/` directory.

### SPDX Header Tool

This repository includes a script (`add_spdx.sh`) to automatically add SPDX license identifiers to all `.c` and `.h` source files. This helps maintain GPLv3 compliance and improves automated license scanning.

To use:

```bash
./add_spdx.sh
