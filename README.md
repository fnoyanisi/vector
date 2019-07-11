# vector
Simple C++ std::vector like API for C

Compiling and testing

```
darwin% cc vector_test.c vector.c -o cvector
darwin% ./cvector                           
allocation successful
size = 0, capacity = 2
item 0 added successfully
item 1 added successfully
item 2 added successfully
item 3 added successfully
item 4 added successfully
size = 5, capacity = 8
contents of item 0 -> name0 , value0
contents of item 1 -> name1 , value1
contents of item 2 -> name2 , value2
contents of item 3 -> name3 , value3
contents of item 4 -> name4 , value4
erasing item at position 2
size = 4, capacity = 8
contents of item 0 -> name0 , value0
contents of item 1 -> name1 , value1
contents of item 2 -> name3 , value3
contents of item 3 -> name4 , value4
darwin%
```
