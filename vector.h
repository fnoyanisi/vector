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
#ifndef GUARD_VECTOR_H
#define GUARD_VECTOR_H

#include <stdio.h>
#include <stdbool.h>

/*
 * This struct can be modified to wrap any data type
 */
#define NAMLEN 64
#define VALLEN 64

struct item {
    char name[NAMLEN];
    char value[VALLEN];
};

typedef struct vector_t {
    struct item **elements;
    size_t size;
    size_t capacity;
} vector;

int vector_init(vector *v, size_t i_capacity);
size_t vector_size(vector *v);
size_t vector_capacity(vector *v);
bool vector_empty(vector *v);
int vector_push_back(vector *v, struct item *item);
void vector_pop_back(vector *v);
void vector_erase(vector *v, size_t pos);
struct item *vector_at(vector *v, size_t index);
void vector_free(vector *v);

#endif