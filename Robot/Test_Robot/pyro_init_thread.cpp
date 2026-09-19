#include "pyro_dwt_drv.h"
#include "pyro_usb_cdc_drv.h"

namespace pyro {

extern "C" {
    void pyro_init_thread(void *argument) {
        dwt_drv_t::init(480);

#ifdef TEST_USB_CDC
        usb_cdc_drv_t::instance().start();
        usb_cdc_drv_t::instance().enable_rx();
#endif

        vTaskDelete(nullptr);
    }
}

}