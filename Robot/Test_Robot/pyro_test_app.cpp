#include "pyro_serial_itf.h"
#include "pyro_usb_cdc_drv.h"
#include "task.h"

#include <cstring>

using namespace pyro;

extern "C" {
    void test_thread(void *argument) {
        while (true) {
            usb_cdc_drv_t::instance().set_frame_config(0xA5, 10);
            uint8_t *a = new uint8_t[10];
            usb_cdc_drv_t::instance().add_rx_event_callback(
                [a](uint8_t *p, uint16_t size, BaseType_t &woken) -> bool
                {
                    (void)woken;
                    if (size != 10 || p[0] != 0xA5)
                        return false;
                    memcpy(a, p, sizeof(a));
                    return true;
                }, reinterpret_cast<uint32_t>(nullptr));
            if (usb_cdc_drv_t::instance())
            usb_cdc_drv_t::instance().write(a, sizeof(a));
            vTaskDelay(100);
        }
    }

    void test_init(void *argument) {
        xTaskCreate(test_thread, "test_thread", 256, nullptr,
                    configMAX_PRIORITIES - 1, nullptr);

        vTaskDelete(nullptr);
    }
}