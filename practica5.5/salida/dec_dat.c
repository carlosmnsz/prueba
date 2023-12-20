#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct listOfInt{
    int data;
    struct listOfInt *next;
};

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