#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int main(){
    vector v;
    struct item items[5], *item_p;
    int i;

    if (vector_init(&v,2) < 0){
        printf("failed to allocate\n");
        return 1;
    } else {
        printf("allocation successful\n");
    }

    printf("size = %ld, capacity = %ld\n", vector_size(&v), 
        vector_capacity(&v));

    for (i = 0; i < 5; i++){
        sprintf(items[i].name,"name%d", i);
        sprintf(items[i].value,"value%d", i);

        if(vector_push_back(&v, &items[i]) != 0) {
            printf("failed to add item %d\n", i);
            return 1;
        } else {
            printf("item %d added successfully\n", i);
        }
    }

    printf("size = %ld, capacity = %ld\n", vector_size(&v), 
        vector_capacity(&v));
    
    for (i=0; i < vector_size(&v); i++){
        item_p = vector_at(&v, i);
        if (item_p != NULL)
            printf("contents of item %d -> %s , %s\n", i, item_p->name, 
                item_p->value);
    }

    printf("erasing item at position 2\n");
    vector_erase(&v, 2);

    printf("size = %ld, capacity = %ld\n", vector_size(&v), 
        vector_capacity(&v));
    
    for (i=0; i < vector_size(&v); i++){
        item_p = vector_at(&v, i);
        if (item_p != NULL)
            printf("contents of item %d -> %s , %s\n", i, item_p->name, 
                item_p->value);
    }

    return 0;
}