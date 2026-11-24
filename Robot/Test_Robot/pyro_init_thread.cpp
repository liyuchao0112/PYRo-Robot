#include "pyro_dwt_drv.h"
#include "pyro_usb_cdc_drv.h"

namespace pyro {

extern "C" {
    void pyro_init_thread(void *argument) {
        dwt_drv_t::init(480);

        usb_cdc_drv_t::instance().init("PYRO-UNK-DEV");
        usb_cdc_drv_t::instance().enable_rx(0);
        usb_cdc_drv_t::instance().enable_rx(1);


        vTaskDelete(nullptr);
    }
}

}