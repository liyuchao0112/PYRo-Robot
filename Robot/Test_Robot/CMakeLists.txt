add_library(Test_Robot OBJECT)

set_target_properties(Test_Robot PROPERTIES
        VERSION 0.0.1    # 通过版本号来辅助判断代码情况
)

target_sources(Test_Robot PRIVATE
        pyro_test_app.cpp

        pyro_init_thread.cpp
        pyro_mission_planer.cpp
)

target_include_directories(Test_Robot PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(PYRo PUBLIC
        TEST_USB_CDC=1 # 开启USBCDC
)

target_link_libraries(Test_Robot PUBLIC
        stm32cubemx
        dsppp_lib
        PYRo
)