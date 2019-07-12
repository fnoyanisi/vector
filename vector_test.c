/******************************************************************************
* Copyright (c) 2019, Fehmi Noyan ISI fnoyanisi@yahoo.com
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY Fehmi Noyan ISI ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Fehmi Noyan ISI BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* Simple test program for the vector API */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int main(){
    vector v;
    struct item items[5], *item_p;
    int i;

    if (vector_init(&v,2) < 0){
        printf("failed to initialize the vector\n");
        return 1;
    } else {
        printf("initialization successful\n");
    }

    printf("current size = %ld, capacity = %ld\n", vector_size(&v), 
        vector_capacity(&v));

    for (i = 0; i < 5; i++){
        sprintf(items[i].name,"name%d", i);
        sprintf(items[i].value,"value%d", i);

        if(vector_push_back(&v, &items[i]) != 0) {
            printf("failed to add item %d\n", i);
            return 1;
        } else {
            printf("item number %d added successfully\n", i);
        }
    }

    printf("current size = %ld, capacity = %ld\n", vector_size(&v), 
        vector_capacity(&v));
    
    for (i=0; i < vector_size(&v); i++){
        item_p = vector_at(&v, i);
        if (item_p != NULL)
            printf("contents of item at position %d -> %s , %s\n", i, 
                item_p->name, item_p->value);
    }

    printf("erasing item at position 2\n");
    vector_erase(&v, 2);

    printf("current size = %ld, capacity = %ld\n", vector_size(&v), 
        vector_capacity(&v));
    
    for (i=0; i < vector_size(&v); i++){
        item_p = vector_at(&v, i);
        if (item_p != NULL)
            printf("contents of item at position %d -> %s , %s\n", i, 
                item_p->name, item_p->value);
    }

    printf("freeing....\n");
    vector_free(&v);

    /* State after free()ing the vector */
    printf("current size = %ld, capacity = %ld\n", vector_size(&v), 
        vector_capacity(&v));

    printf("reinitializing the vector...\n");
    vector_init(&v,12);

    printf("current size = %ld, capacity = %ld\n", vector_size(&v), 
        vector_capacity(&v));

    struct item it;
    sprintf(it.name,"nameX");
    sprintf(it.value,"valueX");
    printf("push_back...\n");
    vector_push_back(&v, &it);
    
    printf("current size = %ld, capacity = %ld\n", vector_size(&v), 
        vector_capacity(&v));
    printf("contents of item at position %d -> %s , %s\n", 0, 
        vector_at(&v,0)->name, vector_at(&v,0)->value);

    return 0;
}