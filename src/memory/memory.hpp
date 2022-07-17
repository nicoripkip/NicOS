/** ===============================================================================================
 * @file memory.hpp
 * @author Niko van Ommen (nikovanommen.nvo@gmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * =============================================================================================== */

#pragma once

#ifndef __NICOS__SYSTEM__MEMORY__
#define __NICOS__SYSTEM__MEMORY__


namespace NICOS__Memory
{
    /**
     * @brief Collection of the statusses of the memory blocks
     * 
     */
    enum blockState_e 
    {
        OCCUPIED,
        FREE,
    };


    /**
     * @brief Structure of a memory block
     * 
     */
    struct block_t
    {
        int process_id;
        unsigned int type;
        unsigned int name;
        unsigned int address;
        int data_1;
        int data_2;
        enum blockState_e state;
    };


    void mem_init();
    void mem_insert(unsigned int, long, long, unsigned int);
    void mem_insert_p_id(unsigned int, long, long, unsigned int, unsigned int);
    struct block_t mem_free(unsigned int);
    void mem_copy(unsigned int, unsigned int);


    /**
     * @brief Class to construct a stack object
     * 
     * @tparam T 
     */
    template <class T>
    class Stack 
    {
        private:
            T head;
            T last;

        public:
            void push(const T);
            T pop();
            bool is_in_stack(const T);
            bool empty();
            void set_head(const T);
            T get_head();
            void set_last(const T);
            T get_last();
    };
}


#endif