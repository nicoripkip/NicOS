/**
 * @file scheduler.hpp
 * @author Niko van Ommen (nikovanommen.nvo@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
    enum taskState_e 
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
    struct task_t
    {
        char *title;
        enum taskState_e state;
        int position;
        char *file;
        struct NICOS__Handle::handle_t *handle;
    };


    void init();
    void add_task(char *, char *);
    struct task_t remove_task(unsigned int);
    unsigned int get_max_tasks();
    void print_tasks();
}


#endif