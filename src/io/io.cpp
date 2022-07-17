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


#include <Arduino.h>
#include "io/io.hpp"
#include "io/dports.hpp"


#define UART_BAUD_RATE              0x01C200


using namespace NICOS__IO;


void uart();
void i2c();
void spi();
void bluetooth();
void wifi();


bool register_not_found = false;


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
 * @brief Function to find the correct pin for the io function
 * 
 * @param pin 
 * @param reg
 * @return unsigned int 
 */
unsigned int find_io_pin(unsigned int pin, unsigned int reg)
{
    unsigned short i, j;
    register_not_found = false;

    for (i = 0; i < 4; i++) {
        if (i == reg) {
            for (j = 0; j < 8; j++) {
                if (j == pin) {
                    return PINMODE[i][1][j];
                } else {
                    Serial.println("[error]\t\tPin don't exist in register!");
                    break;
                }
            }

            break;
        }

        if (i == 4) {
            register_not_found = true;
        }
    }

    if (register_not_found) {
        Serial.println("[error]\t\tCan't find register on system!");
        return 0;
    }   
}


/**
 * @brief Function to set a digital io pin
 * 
 * @param pin 
 * @param reg
 * @param mode 
 */
void NICOS__IO::set_gpio_pin(unsigned int pin, unsigned int reg, unsigned int mode)
{
    unsigned short i, j;
    unsigned p;

    for (i = 0; i < 3; i++) {
        if (i == reg) {
            for (j = 0; j < 8; j++) {
                
            }

            break;
        }
    }
}


/**
 * @brief Function to read a digital pin
 * 
 * @param pin 
 * @return int 
 */
int NICOS__IO::read_gpio_pin(unsigned int pin)
{

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
