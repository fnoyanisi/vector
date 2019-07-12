# vector
C++ std::vector like API for C

A very simple vector implementation in C.

Compiling and testing

```
darwin% cc vector.c vector_test.c -o cvector
darwin% ./cvector                           
initialization successful
current size = 0, capacity = 2
item number 0 added successfully
item number 1 added successfully
item number 2 added successfully
item number 3 added successfully
item number 4 added successfully
current size = 5, capacity = 8
contents of item at position 0 -> name0 , value0
contents of item at position 1 -> name1 , value1
contents of item at position 2 -> name2 , value2
contents of item at position 3 -> name3 , value3
contents of item at position 4 -> name4 , value4
erasing item at position 2
current size = 4, capacity = 8
contents of item at position 0 -> name0 , value0
contents of item at position 1 -> name1 , value1
contents of item at position 2 -> name3 , value3
contents of item at position 3 -> name4 , value4
freeing....
current size = 0, capacity = 0
reinitializing the vector...
current size = 0, capacity = 12
push_back...
current size = 1, capacity = 12
contents of item at position 0 -> nameX , valueX
darwin% 
```
