#include "FreeRTOS.h"
#include "task.h"

extern "C" {

    extern void pyro_init_thread(void *argument);
    extern void test_init(void *argument);

    void start_mission_planer_task(void const *argument) {
        xTaskCreate(pyro_init_thread, "pyro_init_thread", 512, nullptr,
                    configMAX_PRIORITIES - 1, nullptr);

        xTaskCreate(test_init, "test_init", 512, nullptr,
                    configMAX_PRIORITIES - 1, nullptr);

        vTaskDelete(nullptr);
    }
}