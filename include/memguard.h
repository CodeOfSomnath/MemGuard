#ifndef SN_MEMGUARD_MEMGUARD_H
#define SN_MEMGUARD_MEMGUARD_H

/*

Memguard is a library which makes a new way for memory managment for c users.
it is creatd to prevent memory related bugs with simple checking using this 
library functions.
it is like a manually controlled garbage collector. Using these library functions
you can free modify and manage the memory better way. 

Advantages:
1. It can use to prevent the double free 
2. it can clean up all the memory with single function
3. you can use it for your memory managment and it will be easier to debug
 and find the bug.

Diadvantages: 
1. It not support all allocation functions 
2. It cannot prevent user from using a null pointer
3. It cannot prevent user from freeing the memory manually
4. user have to free the memory using it functions only
5. it not consider the thread safe

Note: 
it is still under-devlopment, we can change its way of working 
and add new functions to prevent these mistakes.

*/


// include
#include <stdlib.h>

typedef void *memory_chunk;

typedef struct memguard
{
    memory_chunk *chunks;
    int size;
    int max_length;
} memguard;




// This is the init function for the memory pool you have to call it 
// to use the memorypool functions
void init_memguard();

// This allocates memory of the size and return a void pointer
// You need to call the init_memguard() function first.
void *new_memory(size_t size);

// This function free a specific memory, not the entire pool
// it protects from double free using a checking
void free_memory(void *mem);

// This free all the memory created using memguard.
void destroy_memguard();


#endif // SN_MEMGUARD_MEMGUARD_H