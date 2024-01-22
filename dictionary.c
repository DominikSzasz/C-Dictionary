#include <sys/mman.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addToDict(Dictionary* dict, char* id) {
    strcpy(dict->pair[dict->size].id, id);
    dict->pair[dict->size].valptr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (dict->pair[dict->size].valptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Update the size field
    dict->size++; // Assuming you only added one element to the dictionary
}
int getIndex(Dictionary* dict, char* id)
{
    for (int i = 0; i < dict->size; i++)
    {
        if(strcmp(dict->pair[i].id, id) == 0)
        {
            return i;
        }
    }
    exit(EXIT_FAILURE);
}
void freeDictionary(Dictionary* dict)
{
    // Release the allocated memory for each element in dict.pair
    for (size_t i = 0; i < dict->size; i++) {
        if (munmap(dict->pair[i].valptr, 1024) == -1) {
            perror("munmap");
            exit(EXIT_FAILURE);
        }
    }
}