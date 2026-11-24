#include "FreeRTOS.h"
#include "task.h"

#include "pyro_usb_cdc_drv.h"

#include <cstring>

using namespace pyro;

extern "C" {
    void test_thread(void *argument) {
        while (true) {
            usb_cdc_drv_t::instance().send(0, 0x01, (const uint8_t*)"Hello world!", 12);
            vTaskDelay(1);
        }
    }

    void test_init(void *argument) {
        xTaskCreate(test_thread, "test_thread", 512, nullptr,
            configMAX_PRIORITIES - 1, nullptr);

        vTaskDelete(nullptr);
    }
}