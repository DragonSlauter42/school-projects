

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

struct hashStruct
{
    char key[5]; // Four-letter keys plus null terminator
    int data;
};

class hash_methods
{
private:
    static const int TABLESIZE = 100; // Table size remains static and constant
    static const int KEYSIZE = 4;
    const char emptyKey[5] = "----";

public:
    hash_methods();
    ~hash_methods();
    int hashInsert(const char key[], char data, int hashNum, int dHashNum);

    hashStruct hashTable[TABLESIZE];

    // Base Hash functions
    int hash_1(const char key[]);
    int hash_2(const char key[]);
    int hash_3(const char key[]);
    // Double Hash functions. Combination of the base function, plus another one.
    int probeDec_1(const char key[]);
    unsigned int probeDec_2(const char key[]);
    unsigned long probeDec_3(const char key[]);


};

// Implementation of the constructor and other methods would follow here


