# PadBeacon

Bridge USB gamepads to Bluetooth using ESP32-S3.

![status](https://img.shields.io/badge/status-in%20development-orange)

> 🚧 **Project Status: In Development / Testing**  
> This firmware is in early development. Core logic is scaffolded, but it is **not yet functional**.  
> USB and BLE features are currently using **stubbed input/output**.  
> Hardware testing will begin once the ESP32-S3 arrives.

## ⚠️ Current Development Stage

- ✅ Licensing and repository structure complete
- ✅ Modular display system (auto-probed; ST7789 supported)
- ✅ Display fallback stub for headless boards
- ✅ Core input/output logic scaffolded (USB → BLE architecture)
- 🔄 BLE output and USB parsing still use stub data
- 🚚 ESP32-S3 hardware is ordered — bring-up pending
- ❌ Gamepad passthrough and HID translation not functional yet

Use this codebase at your own risk — it's a work in progress.

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
