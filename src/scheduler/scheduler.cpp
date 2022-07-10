/** ===============================================================================================
 * @file scheduler.c
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
#include "scheduler/handler.hpp"


using namespace NICOS__Scheduler;


#if defined(ARDUINO_AVR_UNO)
    #define MAX_TASK_IN_SCHEDULER 10
#else
    #define MAX_TASK_IN_SCHEDULER 50
#endif


static struct Task_t scheduler_structure[MAX_TASK_IN_SCHEDULER];


/**
 * @brief Function to setup the scheduler
 * 
 */
void NICOS__Scheduler::init()
{
    unsigned int i;

    for (i = 0; i < MAX_TASK_IN_SCHEDULER; i++) {
        scheduler_structure->title = "";
        scheduler_structure->state = TaskState_e::EMPTY;
        scheduler_structure->position = i;
        scheduler_structure->file = "";
    }
}


/**
 * @brief Function to add a task to the scheduler
 * 
 * @param title 
 * @param file 
 */
void NICOS__Scheduler::add_task(char *title, char *file)
{
    unsigned int i;

    for (i = 0; i < MAX_TASK_IN_SCHEDULER; i++) {
        if (scheduler_structure[i].state == TaskState_e::EMPTY || scheduler_structure[i].state == TaskState_e::SUSPENDED) {
            break;
        }
    }

    scheduler_structure[i].title = title;
    scheduler_structure[i].state = TaskState_e::IDLE;
    scheduler_structure[i].position = (int)i;
    scheduler_structure[i].file = file;
}


/**
 * @brief Function to remove a task from scheduler
 * 
 * @param position 
 * @return struct Task_t 
 */
struct Task_t NICOS__Scheduler::remove_task(unsigned int position)
{
    scheduler_structure[position].state = TaskState_e::EMPTY;
    return scheduler_structure[position];
}


/**
 * @brief Get the max tasks object
 * 
 * @return unsigned int 
 */
unsigned int NICOS__Scheduler::get_max_tasks()
{
    return MAX_TASK_IN_SCHEDULER;
}


/**
 * @brief Function to print all the current tasks that are present in the scheduler
 * 
 */
void NICOS__Scheduler::print_tasks()
{
    unsigned int i;

    for (i = 0; i < MAX_TASK_IN_SCHEDULER; i++) {
        Serial.print("[info]\t\tHuidige taak: ");
        Serial.print(scheduler_structure[i].title);
        Serial.print(" op positie: ");
        Serial.println(scheduler_structure[i].position);
    }
}