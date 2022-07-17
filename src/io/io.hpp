/**
 * @file io.hpp
 * @author Niko van Ommen (nikovanommen.nvo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#ifndef __NICOS__SYSTEM__INPUT__OUTPUT__
#define __NICOS__SYSTEM__INPUT__OUTPUT__


#if defined(ARDUINO_AVR_UNO)
    #define UART_SUPPORT                true
    #define I2C_SUPPORT                 true
    #define SPI_SUPPORT                 true
    #define BLUETOOTH_SUPPORT           false
    #define WIFI_SUPPORT                false
#else
    #define UART_SUPPORT                false
    #define I2C_SUPPORT                 false
    #define SPI_SUPPORT                 false
    #define BLUETOOTH_SUPPORT           false
    #define WIFI_SUPPORT                false
#endif


namespace NICOS__IO
{
    void init();

    void set_gpio_pin(unsigned int, unsigned int, unsigned int);
    int read_gpio_pin(unsigned int);
    unsigned int find_io_pin(unsigned int, unsigned int);

    void send();
    void receive();
    bool is_available();
}


#endif