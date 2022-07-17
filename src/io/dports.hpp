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
    #define DIGITAL_PORT_1              0x01
    #define DIGITAL_PORT_2              0x02
    #define DIGITAL_PORT_3              0x03
    #define DIGITAL_PORT_4              0x04
    #define DIGITAL_PORT_5              0x05
    #define DIGITAL_PORT_6              0x06
    #define DIGITAL_PORT_7              0x07
    #define DIGITAL_PORT_8              0x08
    #define DIGITAL_PORT_9              0x09
    #define DIGITAL_PORT_10             0x0A
    #define DIGITAL_PORT_11             0x0B
    #define DIGITAL_PORT_12             0x0C
    #define DIGITAL_PORT_13             0x0D

    #define PWM_PORT_1                  0x03
    #define PWM_PORT_2                  0x05
    #define PMW_PORT_3                  0x06
    #define PWM_PORT_4                  0x09
    #define PWM_PORT_5                  0x0A
    #define PWM_PORT_6                  0x0B
#else
    #define NO_DIGITAL_PORTS_DEFINED    true
#endif


#endif