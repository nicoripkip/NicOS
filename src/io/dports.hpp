/**
 * @file dports.hpp
 * @author Niko van Ommen (nikovanommen.nvo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#ifndef __NICOS__DIGITAL__PORTS__
#define __NICOS__DIGITAL__PORTS__


#if defined(ARDUINO_AVR_UNO)
    #define MCU_CONTROL_REGISTER        0x35

    #define REGISTER_B                  0x24
    #define REGISTER_C                  0x27
    #define REGISTER_D                  0x2A

    #define PORTB                       0x25
    #define PORTC                       0x28
    #define PORTD                       0x2B

    #define PINB                        0x23
    #define PINC                        0x26
    #define PIND                        0x29


    /**
     * @brief Structure containing all pinmode options
     * 
     */
    unsigned int PINMODE[3][2][8] = {
        { 
            DDRB, 
            {
                0b00000001,
                0b00000010,
                0b00000100,
                0b00001000,
                0b00010000,
                0b00100000,
                0b01000000,
                0b10000000,
            },
        },
        {
            DDRC,
            {
                0b00000001,
                0b00000010,
                0b00000100,
                0b00001000,
                0b00010000,
                0b00100000,
                0b01000000,
                0b10000000,
            },
        },
        {
            DDRD,
            {
                0b00000001,
                0b00000010,
                0b00000100,
                0b00001000,
                0b00010000,
                0b00100000,
                0b01000000,
                0b10000000,
            },
        },
    }                       

#elif defined(ESP32)
    #define DIGITAL_GPIO_1              0x01
    #define DIGITAL_GPIO_2              0x02
    #define DIGITAL_GPIO_3              0x03
    #define DIGITAL_GPIO_4              0x04
    #define DIGITAL_GPIO_5              0x05
    #define DIGITAL_GPIO_6              0x06
    #define DIGITAL_GPIO_7              0x07
    #define DIGITAL_GPIO_8              0x08
    #define DIGITAL_GPIO_9              0x09
    #define DIGITAL_GPIO_10             0x0A
    #define DIGITAL_GPIO_11             0x0B
    #define DIGITAL_GPIO_12             0x0C
    #define DIGITAL_GPIO_13             0x0D
    #define DIGITAL_GPIO_14             0x0E
    #define DIGITAL_GPIO_15             0x0F
    #define DIGITAL_GPIO_16             0x10
    #define DIGITAL_GPIO_17             0x11
    #define DIGITAL_GPIO_18             0x12
    #define DIGITAL_GPIO_19             0x13
    #define DIGITAL_GPIO_20             0x14
    #define DIGITAL_GPIO_21             0x15
    #define DIGITAL_GPIO_22             0x16
    #define DIGITAL_GPIO_23             0x17
    #define DIGITAL_GPIO_24             0x18
    #define DIGITAL_GPIO_25             0x19
    #define DIGITAL_GPIO_26             0x1A
    #define DIGITAL_GPIO_27             0x1B
    #define DIGITAL_GPIO_28             0x1C
    #define DIGITAL_GPIO_29             0x1D
    #define DIGITAL_GPIO_30             0x1E
    #define DIGITAL_GPIO_31             0x1F
    #define DIGITAL_GPIO_32             0x20
    #define DIGITAL_GPIO_33             0x21
    #define DIGITAL_GPIO_34             0x22
    #define DIGITAL_GPIO_35             0x23
    #define DIGITAL_GPIO_36             0x24
    #define DIGITAL_GPIO_37             0x25
    #define DIGITAL_GPIO_38             0x26
    #define DIGITAL_GPIO_39             0x27
    #define DIGITAL_GPIO_40             0x28
    #define DIGITAL_GPIO_41             0x29
    #define DIGITAL_GPIO_42             0x2A
#else
    #define NO_DIGITAL_PORTS_DEFINED    true
    unsigned int PINMODE[3][2][8];
#endif


#endif