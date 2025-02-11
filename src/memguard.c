#include "memguard.h"

memguard* pool;

void init_memguard()
{
    pool = (memguard *)malloc(sizeof(memguard));
    pool->size = 0;
    pool->max_length = 1000;
    pool->chunks = (memory_chunk *)malloc(sizeof(memory_chunk) * pool->max_length);
}

void *new_memory(size_t size)
{
    void *memory = malloc(size);
    pool->chunks[pool->size] = memory;
    pool->size++;
    if (pool->size == pool->max_length)
    {
        pool->chunks = (memory_chunk *)realloc(pool->chunks, sizeof(memory_chunk) * (pool->size + 1000));
    }
    return memory;
}

void free_memory(void *mem)
{
    if (mem == NULL)
    {
        return;
    }

    for (int i = 0; i < pool->size; i++)
    {
        if (pool->chunks[i] == mem)
        {
            free(pool->chunks[i]);
            pool->chunks[i] = NULL;
            break;
        }
    }
}

void destroy_memguard()
{
    for (int i = 0; i < pool->size; i++)
    {
        if (pool->chunks[i] != NULL)
        {
            free(pool->chunks[i]);
        }
    }
    free(pool->chunks);
    free(pool);
}