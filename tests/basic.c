#include <stdio.h>
#include <memguard.h>

struct node
{
    int * values;
    int len;
};

struct node newNode() {
    struct node n;
    n.len = 10;
    n.values = (int *)new_memory(sizeof(int) * 10);
    return n;
}

void freeNode(struct node * n) {
    free_memory(n->values);
    // free_memory(n);
}


struct arraylist
{
    struct node * array;
    int len;
};


void newList(struct arraylist ** list) {
    (*list) = (struct arraylist *)new_memory(sizeof(struct arraylist));
    (*list)->array = (struct node *)new_memory(sizeof(struct node) * 10);
    for (int i = 0; i < 10; i++)
    {
        (*list)->array[i] = newNode();
    }
    
    (*list)->len = 10;
}

void free_list(struct arraylist * list) {
    for (int i = 0; i < 10; i++)
    {
        freeNode(&list->array[i]);
    }
    free_memory(list);
}






int main(int argc, char const *argv[])
{
    // Enable memory leak detection
  
    init_memguard();
    struct arraylist * list;
    newList(&list);
    free_list(list);
    destroy_memguard();
    return 0;
}
