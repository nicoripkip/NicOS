/** ===============================================================================================
 * @file main.cpp
 * @author Niko van Ommen (nikovanommen.nvo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * =============================================================================================== */ 


#include <Arduino.h>


#define RUN_FLAG true


void run();


/**
 * @brief Heart of the program
 * 
 * @return int 
 */
int main() 
{
    pinMode(2, OUTPUT);

    Serial.begin(115200);

    run();

    return 0;
}


/**
 * @brief Function for repeating functions of the operating system
 * 
 */
void run()
{
    while (RUN_FLAG) {
        Serial.println("[info]\t\tMain program runs!!!");
        delayMicroseconds(500);
    }
}