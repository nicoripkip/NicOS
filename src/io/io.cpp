/**
 * @file io.cpp
 * @author Niko van Ommen (nikovanommen.nvo@gmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "io/io.hpp"
#include "io/dports.hpp"
#include <Arduino.h>


#define UART_BAUD_RATE              0x01C200


using namespace NICOS__IO;


void uart();
void i2c();
void spi();
void bluetooth();
void wifi();


/**
 * @brief Function to init the io ports
 * 
 */
void NICOS__IO::init()
{
    #if defined(NO_DIGITAL_PORTS_DEFINED)
        Serial.println("[info]\t\tNo digital ports found on the system");
    #endif

    #if defined(NO_ANALOG_PORTS_DEFINED)
        Serial.println("[info]\t\tNo analog ports found on the system");
    #endif
}


/**
 * @brief Function to init the uart communication protocol on the microcontroller
 * 
 */
void uart()
{
    
}


/**
 * @brief Function to init the i2c communication protocol on the microcontroller
 * 
 */
void i2c()
{

}
