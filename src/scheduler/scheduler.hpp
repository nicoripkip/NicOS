#pragma once

#ifndef __NICOS__SYSTEM__SCHEDULER__
#define __NICOS__SYSYEM__SCHEDULER__


#include "scheduler/handler.hpp"


namespace NICOS__Scheduler
{
    /**
     * @brief Collection of the states the task can be in the scheduler
     * 
     */
    enum TaskState_e 
    {
        SUCCEED,
        SUSPENDED,
        IDLE,
        RUNNING,
        EMPTY,
    };


    /**
     * @brief Structure for all the taskdata
     * 
     */
    struct Task_t
    {
        char *title;
        enum TaskState_e state;
        int position;
        char *file;
        struct NICOS__Handle::Handle_t *handle;
    };


    void init();
    void add_task(char *, char *);
    struct Task_t remove_task(unsigned int);
    unsigned int get_max_tasks();
    void print_tasks();
}


#endif