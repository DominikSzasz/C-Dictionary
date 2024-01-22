#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

int main() {
    Dictionary dict;
    dict.size = 0;
    addToDict(&dict, "first ID");
    addToDict(&dict, "second ID");

    char* test1 = (char*)dict.pair[getIndex(&dict, "first ID")].valptr; 
    char* test2 = (char*)dict.pair[getIndex(&dict, "second ID")].valptr; 

    strcpy(test1, "first Value");
    strcpy(test2, "second Value");

    printf("Result: %s\n", test1);
    printf("Result: %s\n", test2);


    freeDictionary(&dict);

    return 0;
}