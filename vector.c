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

#include "vector.h"
#include <stdlib.h>

/*
 * Initializes a vector with the capacity set to i_capacity.
 * The allocated memory has to be freed with vector_free()
 */
int 
vector_init(vector *v, size_t i_capacity){
    size_t capacity;

    if (i_capacity<1)
        capacity = DEFCAPACITY;
    else
        capacity = i_capacity;

    if ((v->elements = malloc(sizeof(struct item *) * capacity)) == NULL)
        return (-1);

    v->size = 0;
    v->capacity = capacity;

    return 0;
}

/* 
 * Return the size of the vector, i.e. how many items the vector
 * currently has
 */
size_t
vector_size(vector *v){
    return v->size;
}

/* 
 * Return the capacity of the vector, i.e. how many items the vector
 * can have
 */
size_t
vector_capacity(vector *v){
    return v->capacity;
}

/* 
 * Tests whether a given vector is empty
 */
bool
vector_empty(vector *v){
    return (v->size == 0);
}

/* 
 * Appends the given item at the end of the vector. If the current capacity
 * of the vector is not sufficient to add a new item, the capacity of the
 * vector is increased (doubled in this implementation)
 */
int
vector_push_back(vector *v, struct item *i){
    if (v->size == v->capacity) {
        size_t new_capacity = (v->capacity == 0)? DEFCAPACITY : 
                                                    v->capacity * 2;
        struct item **new;
        if ((new = realloc(v->elements, 
            sizeof(struct item *) * new_capacity)) == NULL) {
            return (-1);
        }
        v->elements = new;
        v->capacity = new_capacity;
    }
    v->elements[v->size++] = i;

    return 0;
}

/*
 * Removes the last element of the vector.
 */
int
vector_pop_back(vector *v){
    if (v->size > 0){
        v->elements[v->size--] = NULL;
        return 0;
    }
    return (-1);
}

/* 
 * Returns the last element in the vector
 */
struct item*
vector_back(vector *v){
    return vector_at(v, vector_size(v)-1);
}

/*
 * Inserts items at the specified location in the vector.
 */
int
vector_insert(vector *v, struct item *it, size_t pos){
    size_t i, last;
    if (pos >= 0 && pos <= v->size){
        if (pos == v->size || pos == 0){
            return vector_push_back(v, it);
        } else {
            if (vector_push_back(v, vector_back(v)) < 0)
                return (-1);
            for (i = v->size-2; i!=pos; i--)
                v->elements[i] = v->elements[i-1];
            v->elements[i] = it;
            return 0;
        }
    }
    return (-1);
}

/*
 * Returns a pointer to the item at specified location pos, 
 * with bounds checking.
 */
struct item*
vector_at(vector *v, size_t pos) {
    if (pos < v->size){
        return v->elements[pos];
    } else {
        return NULL;
    }
}

/*
 * Removes the item at specified location pos.
 */
int
vector_erase(vector *v, size_t pos){
    int i;
    if (pos >= 0 && pos < v->size){
        v->size--;
        for (i = pos; i < v->size; i++)
            v->elements[i] = v->elements[i+1];
        v->elements[i] = NULL;
        return 0;
    }
    return (-1);
}

/*
 * Returns the allocated memeory to the operating system.
 * This function has to be called when the vector is no longer needed.
 */
void
vector_free(vector *v){
    free(v->elements);
    v->capacity = 0;
    v->size = 0;
}