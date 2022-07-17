/**
 * @file memory.cpp
 * @author Niko van Ommen (nikovanommen.nvo@gmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "memory.hpp"


#if defined(ARDUINO_AVR_UNO)
    #define MAX_MEMORY_ALLOCATION       50
    #define MAX_STACK_ALLOCATION        20  
#else
    #define MAX_MEMORY_ALLOCATION       150
    #define MAX_STACK_ALLOCATION        70
#endif


using namespace NICOS__Memory;


static struct block_t memory[MAX_MEMORY_ALLOCATION];
unsigned int pc;


/**
 * @brief Function to setup the memory structure
 * 
 */
void NICOS__Memory::mem_init()
{
    unsigned int i;

    for (i = 0; i < MAX_MEMORY_ALLOCATION; i++) {
        memory[i].process_id = -1;
        memory[i].address = i;
        memory[i].state = blockState_e::FREE;
    }

    pc = 0;
}


/**
 * @brief Function to insert data into the memory structure
 * 
 * @param name 
 * @param data_1 
 * @param data_2 
 * @param type 
 */
void NICOS__Memory::mem_insert(unsigned int name, long data_1, long data_2, unsigned int type)
{
    unsigned int i;

    for (i = 0; i < MAX_MEMORY_ALLOCATION; i++) {
        if (memory[i].state == blockState_e::FREE) {
            break;
        }
    }

    memory[i].process_id = ++pc;
    memory[i].name = name;
    memory[i].data_1 = (int)data_1;
    memory[i].data_2 = (int)data_2;
    memory[i].type = type;
    memory[i].state = blockState_e::OCCUPIED;
}


/**
 * @brief Function to free a block from memory
 * 
 * @param address 
 * @return struct block_t 
 */
struct block_t NICOS__Memory::mem_free(unsigned int address)
{
    memory[address].process_id = -1;
    memory[address].state = blockState_e::FREE;
    return memory[address];
}


/** ========================================
 *              Stack Region
 *  ======================================== */


template <class T>
void NICOS__Memory::Stack<T>::push(const T value)
{
    if (head.empty()) {
        
    }
}