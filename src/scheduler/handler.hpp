/** ===============================================================================================
 * @file handler.hpp
 * @author Niko van Ommen (nikovanommen.nvo@gmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * =============================================================================================== */

#pragma once

#ifndef __NICOS__SYSTEM__HANDLER__
#define __NICOS__SYSTEM__HANDLER__


#include "memory/memory.hpp"


using namespace NICOS__Memory;


namespace NICOS__Handle
{
    /**
     * @brief Structure to 
     * 
     */
    struct handle_t 
    {
        unsigned int max_handles;
        unsigned int current_executed_handle;
        Stack<block_t> handles;
    };
}


#endif