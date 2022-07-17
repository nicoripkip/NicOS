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


void run();
void read();


unsigned int data;


/**
 * @brief Heart of the program
 * 
 * @return int 
 */
int main() 
{
    // init fase
    NICOS__IO::init();
    NICOS__Memory::mem_init();
    NICOS__Scheduler::init();

    // Setup pins
    pinMode(2, OUTPUT);

    // Setup communication links
    Serial.begin(115200);

    // Setup loop
    run();

    return 0;
}


/**
 * @brief Function for repeating functions of the operating system
 * 
 */
void run()
{
    // Flag that determines the state of the running system
    while (RUN_FLAG) {
        // Serial.print("[info]\t\tMaximaal aantal taken: ");
        // Serial.println(NICOS__Scheduler::get_max_tasks());
        // NICOS__Scheduler::print_tasks();

        read();
    }
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