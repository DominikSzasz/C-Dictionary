#ifndef DICTIONARY_H
#define DICTIONARY_H
typedef struct {
    char id[100];
    void* valptr;
} dictPair;

typedef struct {
    size_t size;
    dictPair pair[100];
} Dictionary;
void addToDict(Dictionary* dict, char* id);
int getIndex(Dictionary* dict, char* id);
void freeDictionary(Dictionary* dict);
#endif