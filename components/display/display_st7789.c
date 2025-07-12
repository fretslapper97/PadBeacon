// SPDX-License-Identifier: GPL-3.0-or-later

#if CONFIG_PADBEACON_HAS_DISPLAY && CONFIG_DISPLAY_DRIVER_ST7789

#include "display.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "display_st7789";
static bool s_present = false;

// ST7789 pins – adjust as needed per board
#define PIN_NUM_MOSI  13
#define PIN_NUM_CLK   14
#define PIN_NUM_CS    15
#define PIN_NUM_DC     5
#define PIN_NUM_RST    9

static spi_device_handle_t spi = NULL;

// -- Display Detection (probing ID) --
bool display_detect(void)
{
    if (s_present) return true;

    spi_bus_config_t buscfg = {
        .miso_io_num = -1,
        .mosi_io_num = PIN_NUM_MOSI,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
    };

    if (spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO) != ESP_OK) {
        ESP_LOGW(TAG, "SPI bus init failed");
        return false;
    }

    spi_device_interface_config_t devcfg = {
        .mode = 0,
        .clock_speed_hz = 10 * 1000 * 1000,
        .spics_io_num = PIN_NUM_CS,
        .queue_size = 1,
        .flags = SPI_DEVICE_NO_DUMMY,
    };

    if (spi_bus_add_device(SPI2_HOST, &devcfg, &spi) != ESP_OK) {
        ESP_LOGW(TAG, "SPI device add failed");
        spi_bus_free(SPI2_HOST);
        return false;
    }

    uint8_t cmd = 0x04;
    uint8_t rx[3] = {0};

    spi_transaction_t t = {
        .tx_buffer = &cmd,
        .length = 8,
        .flags = SPI_TRANS_USE_TXDATA
    };
    spi_device_polling_transmit(spi, &t);

    t.tx_buffer = NULL;
    t.rxlength = 24;
    t.length   = 24;
    spi_device_polling_transmit(spi, &t);
    memcpy(rx, t.rx_data, 3);

    if ((rx[0] == 0x00 && rx[1] == 0x00 && rx[2] == 0x00) ||
        (rx[0] == 0xFF && rx[1] == 0xFF && rx[2] == 0xFF)) {
        ESP_LOGI(TAG, "No ST7789 display detected");
        spi_bus_remove_device(spi);
        spi_bus_free(SPI2_HOST);
        return false;
    }

    ESP_LOGI(TAG, "ST7789 display detected (ID: %02X %02X %02X)", rx[0], rx[1], rx[2]);
    s_present = true;
    return true;
}

// -- Display Init (minimal stub, add real init later) --
void display_init(void)
{
    if (!s_present) return;

    // TODO: implement real ST7789 init sequence here
    ESP_LOGI(TAG, "display_init() called (stub)");
}

// -- Simple line display function --
void display_write_line(int line, const char *text)
{
    if (!s_present) return;

    // TODO: implement real text-drawing logic
    ESP_LOGI(TAG, "[LCD] Line %d: %s", line, text);
}

#endif // CONFIG_PADBEACON_HAS_DISPLAY && CONFIG_DISPLAY_DRIVER_ST7789
