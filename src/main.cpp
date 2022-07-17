/** ===============================================================================================
 * @file main.cpp
 * @author Niko van Ommen (nikovanommen.nvo@gmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * =============================================================================================== */ 


#include <Arduino.h>
#include "scheduler/scheduler.hpp"
#include "io/io.hpp"
#include "memory/memory.hpp"


#define RUN_FLAG true
#define SERIAL_BAUD_RATE 0x01C200


void run();
void read();


unsigned int data;


/**
 * @brief Function to setup the operating system components stuff
 * 
 */
void setup()
{
    // init fase
    NICOS__IO::init();
    NICOS__Memory::mem_init();
    NICOS__Scheduler::init();

    // Setup pins
    pinMode(2, OUTPUT);

    // Setup communication links
    Serial.begin(SERIAL_BAUD_RATE);
}


/**
 * @brief Function to run sertain components from the operating system
 * 
 */
void loop()
{
    read();
}


/**
 * @brief Function to read incoming data from the command line
 * 
 */
void read()
{
    if (Serial.available()) {
        data = Serial.read();
    }

    Serial.print("[info]\t\tData: ");
    Serial.println(data);
}