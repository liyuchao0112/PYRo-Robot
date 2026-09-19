#include "pyro_serial_itf.h"
#include "pyro_usb_cdc_drv.h"
#include "task.h"

#include <cstring>

using namespace pyro;

extern "C" {
    void test_thread(void *argument) {
        while (true) {
            uint8_t a[13] = "test_message";
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