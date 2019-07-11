#include <stdio.h>
#include <stdbool.h>

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