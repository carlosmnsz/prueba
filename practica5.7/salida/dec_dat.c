#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_SIZE 500

typedef struct { 
    size_t size; 
    size_t capacity; 
    int* array; 
}listOfInt; 

struct listOfChar{
    char data;
    struct listOfChar *next;
};

struct listOfBool{
    bool data;
    struct listOfBool *next;
};

struct listOfFloat{
    float data;
    struct listOfFloat *next;
};